# Create-Copy-Delete
This repository contains Windows file system C++ APIs and an example console application.

Description: Includes APIs to:

- Create, copy, delete and move files and folders. Folders are copied, moved and deleted recursively.
- Get file size and folder size. Folder size is retrieved recursively.
- Set and clear read only flag on folders and files. Setting read only flag on a folder is done recursively.
- Get list of all file paths in a folder. This operation is done recursively.
- Write, append write, read and merge file operations.
- Find text in a file.
- Replace text in a file.
- Print all file paths and subfolder paths in a folder.
- Print file time info.
- Get drive space and drive type info.
- Zip and unzip operations.
- Add file to zip archive.
- Remove file from zip archive.
- Send file to default printer.
- Send all files in a folder to default printer.

Windows file systems NTFS/FAT32 stores file names in unicode. The implementation is based on std::wstring and WCHAR which are needed to access and create files with unicode characters.

Tools: Visual Studio 2022

Note: Tested on Windows 10 and Windows 11
