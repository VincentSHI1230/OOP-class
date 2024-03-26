#!py -3
# -*- coding: utf-8 -*-

"""
Vincent SHI | 史文朔 (c) 2024
date: 2024-03-21
本工具的功能是为 Windows 文件夹设置友好别名。
在资源管理器中，例如「用户」「桌面」「收藏夹」等文件夹将以中文显示，但不影响其原始路径 "Users", "Desktop" 和 "Favorites"。
在实践中，我们往往会遇到一些工具或项目不支持中文路径，但又希望在资源管理器中以中文显示，这时候就可以使用本工具为文件夹设置这样的友好别名。
请将本工具复制到需要设置或修改别名的文件夹下，然后运行。
注意，具有别名的文件夹不能够在资源管理器中重命名真实路径，你将需要借助本工具来删除别名或修改路径名称。
"""

import configparser
import ctypes
import os
import platform
import sys

try:
    if platform.system() != "Windows":
        input("本工具仅支持 Windows。")
        exit(-1)
    version = platform.version().split(".")[0]
    ENCODING = "utf-16" if version in ["10", "11"] else "ANSI"
    print("Windows 内核版本：" + version)
    full_dir, _ = os.path.split(__file__)
    print("当前路径：" + full_dir)

    if not ctypes.windll.shell32.IsUserAnAdmin():
        SW_NORMAL = 0x1
        ctypes.windll.shell32.ShellExecuteW(
            None, "runas", sys.executable, f'-u "{__file__}"', None, SW_NORMAL
        )
        print("请在新窗口完成操作... ")
        exit(0)

    print(__doc__)
    ini_file_path = os.path.join(full_dir, "desktop.ini")
    config = configparser.ConfigParser()
    config.read(ini_file_path, ENCODING)
    if config.has_option(".ShellClassInfo", "LocalizedResourceName"):
        parent_dir, dir_name = os.path.split(full_dir)
        alias = config.get(".ShellClassInfo", "LocalizedResourceName")
        option = input(
            f'文件夹 "{dir_name}" 已定义别名 "{alias}"。\n'
            "您希望 修改本名(0) / 修改别名(1) / 清除别名(2) / 取消(-1): "
        )
        if option == "0":
            dir_name = input("请输入修改的文件夹本名: ")
            os.rename(full_dir, os.path.join(parent_dir, dir_name))
            input("已修改。不影响别名的显示。")
            exit(0)
        elif option == "1":
            alias = input("请输入修改的文件夹别名: ")
            config.set(".ShellClassInfo", "LocalizedResourceName", alias)
        elif option == "2":
            config.remove_option(".ShellClassInfo", "LocalizedResourceName")
        else:
            input("已取消。")
            exit(0)
    elif config.has_section(".ShellClassInfo"):
        alias = input("请输入添加的文件夹别名: ")
        config.set(".ShellClassInfo", "LocalizedResourceName", alias)
    else:
        alias = input("请输入添加的文件夹别名: ")
        config.add_section(".ShellClassInfo")
        config.set(".ShellClassInfo", "LocalizedResourceName", alias)

    FILE_ATTRIBUTE_HIDDEN = 0x00000002
    FILE_ATTRIBUTE_SYSTEM = 0x00000004
    FILE_ATTRIBUTE_ARCHIVE = 0x00000020
    SHCNE_ATTRIBUTES = 0x00000002
    SHCNE_UPDATEDIR = 0x00001000
    SHCNE_UPDATEITEM = 0x00002000
    SHCNF_PATHW = 0x0005
    SHCNF_FLUSH = 0x1000
    ctypes.windll.kernel32.SetFileAttributesW(ini_file_path, FILE_ATTRIBUTE_ARCHIVE)
    with open(ini_file_path, "w", encoding=ENCODING) as configfile:
        config.write(configfile, space_around_delimiters=False)
    ctypes.windll.kernel32.SetFileAttributesW(
        ini_file_path,
        FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_ARCHIVE,
    )
    ctypes.windll.shell32.SHChangeNotify(
        SHCNE_ATTRIBUTES | SHCNE_UPDATEITEM,
        SHCNF_PATHW | SHCNF_FLUSH,
        ini_file_path,
        None,
    )
    ctypes.windll.shell32.SHChangeNotify(
        SHCNE_ATTRIBUTES | SHCNE_UPDATEDIR | SHCNE_UPDATEITEM,
        SHCNF_PATHW | SHCNF_FLUSH,
        full_dir,
        None,
    )
    input("已提交。Windows 将在几分钟内同步。")

except Exception as e:
    print(e)
    input("出现错误。")
