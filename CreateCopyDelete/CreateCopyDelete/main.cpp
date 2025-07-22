#include "CreateCopyDelete.h"

int main(int argc, char** argv)
{
  (void)argc;
  (void)argv;

  ::printf("**********************************************************************************\n");
  ::printf("   Create, copy and delete folders and files");
  ::printf("   Build time: %s %s\n", __DATE__, __TIME__);
  ::printf("**********************************************************************************\n");

  CreateCopyDelete createCopyDelete;

  uint64_t freeBytesAvailableToCaller, totalNumberOfBytes, totalNumberOfFreeBytes;
  createCopyDelete.getDiskCapacityInfo(L"C:\\", &freeBytesAvailableToCaller, &totalNumberOfBytes, &totalNumberOfFreeBytes);

  createCopyDelete.getDriveType(L"C:\\");

  createCopyDelete.createDir(L"C:\\temp\\fromCopy");

  createCopyDelete.createFile(L"C:\\temp\\fromCopy", L"test1.txt");

  createCopyDelete.createDir(L"C:\\temp\\fromCopy\\test2");

  createCopyDelete.createFile(L"C:\\temp\\fromCopy\\test2", L"test2.txt");

  createCopyDelete.copyDir(L"C:\\temp\\fromCopy", L"C:\\temp\\toCopy1");

  createCopyDelete.createDir(L"C:\\temp\\toCopy2");

  createCopyDelete.createFile(L"C:\\temp\\toCopy2", L"test3.txt");

  const WCHAR strTest1[] = L"Example text testing fileWrite1\n";
  createCopyDelete.fileWrite(L"C:\\temp\\toCopy2\\test3.txt", strTest1);

  createCopyDelete.createFile(L"C:\\temp\\toCopy2", L"test4.txt");

  const WCHAR strTest2[] = L"Example text testing fileWrite2\n";
  createCopyDelete.fileWrite(L"C:\\temp\\toCopy2\\test4.txt", strTest2);

  createCopyDelete.mergeFiles(L"C:\\temp\\toCopy2\\test3.txt", L"C:\\temp\\toCopy2\\test4.txt", L"C:\\temp\\toCopy2\\test5.txt", false);

  uint32_t size = 0;
  createCopyDelete.getFileSize(L"C:\\temp\\toCopy2\\test5.txt", &size);
  ::printf("File size: %d\n", size);

  WCHAR* strTestRead = (WCHAR*)::malloc(size);
  createCopyDelete.fileRead(L"C:\\temp\\toCopy2\\test5.txt", strTestRead);
  ::printf("Testing fileRead:\n");
  ::printf("%ws\n", strTestRead);
  ::free(strTestRead);

  uint32_t total = 0;
  createCopyDelete.findTextInFile(L"C:\\temp\\toCopy2\\test5.txt", L"testing", &total);
  createCopyDelete.replaceTextInFile(L"C:\\temp\\toCopy2\\test5.txt", L"testing", L"replacing", &total);

  createCopyDelete.deleteFile(L"C:\\temp\\toCopy2", L"test5.txt");

  createCopyDelete.deleteFile(L"C:\\temp\\toCopy2", L"test4.txt");

  std::vector<std::wstring> paths;
  paths.clear();
  createCopyDelete.getDirFilePaths(L"C:\\temp\\toCopy2", &paths);
  for (std::vector<std::wstring>::iterator it = paths.begin(); it != paths.end(); ++it)
  {
    std::wcout << *it << std::endl;
  }

  createCopyDelete.moveDir(L"C:\\temp\\toCopy2", L"C:\\temp\\toCopy3");

  createCopyDelete.moveFile(L"C:\\temp\\toCopy3", L"C:\\temp\\toCopy1", L"test3.txt");

  createCopyDelete.setDirReadOnly(L"C:\\temp\\toCopy3", true);

  createCopyDelete.setDirReadOnly(L"C:\\temp\\toCopy3", false);

  createCopyDelete.setReadOnly(L"C:\\temp\\toCopy1\\test3.txt", true);

  createCopyDelete.setReadOnly(L"C:\\temp\\toCopy1\\test3.txt", false);

  size = 0;
  createCopyDelete.getDirSize(L"C:\\temp\\toCopy1", &size);
  ::printf("Directory size: %d\n", size);

  const WCHAR str[] = L"Example text testing fileWrite\n";
  createCopyDelete.fileWrite(L"C:\\temp\\toCopy1\\test3.txt", str);

  const WCHAR strAppend[] = L"Example text testing fileAppendWrite\n";
  createCopyDelete.fileAppendWrite(L"C:\\temp\\toCopy1\\test3.txt", strAppend);

  size = 0;
  createCopyDelete.getFileSize(L"C:\\temp\\toCopy1\\test3.txt", &size);
  ::printf("File size: %d\n", size);

  createCopyDelete.printDirPaths(L"C:\\temp\\toCopy1", true);

  createCopyDelete.printFileTime(L"C:\\temp\\toCopy1\\test3.txt");

  createCopyDelete.deleteDir(L"C:\\temp\\toCopy3");

  createCopyDelete.zipAllFilesInFolder(L"C:\\temp\\fromCopy", L"C:\\temp\\fromCopy.zip");

  createCopyDelete.addFileToZip(L"C:\\temp\\toCopy1\\test3.txt", L"C:\\temp\\fromCopy.zip");

  createCopyDelete.removeFileFromZip(L"test3.txt", L"C:\\temp\\fromCopy.zip");

  createCopyDelete.unzipAllFilesToFolder(L"C:\\temp\\test2", L"C:\\temp\\fromCopy.zip");

  createCopyDelete.deleteFile(L"C:\\temp", L"fromCopy.zip");

  createCopyDelete.deleteDir(L"C:\\temp\\test2");

  createCopyDelete.deleteFile(L"C:\\temp\\toCopy1", L"test3.txt");

  createCopyDelete.deleteDir(L"C:\\temp\\toCopy1");

  createCopyDelete.deleteDir(L"C:\\temp\\fromCopy");

  createCopyDelete.createDir(L"C:\\temp\\testPrint");

  createCopyDelete.createFile(L"C:\\temp\\testPrint", L"test1.txt");

  const WCHAR strTest3[] = L"Testing file 1 print line 1\nTesting file 1 print line 2\nTesting file 1 print line 3\n";
  createCopyDelete.fileWrite(L"C:\\temp\\testPrint\\test1.txt", strTest3);

  createCopyDelete.createFile(L"C:\\temp\\testPrint", L"test2.txt");

  const WCHAR strTest4[] = L"Testing file 2 print line 1\nTesting file 2 print line 2\nTesting file 2 print line 3\n";
  createCopyDelete.fileWrite(L"C:\\temp\\testPrint\\test2.txt", strTest4);

  //createCopyDelete.printAllFilesInFolder(L"C:\\temp\\testPrint");

  createCopyDelete.deleteDir(L"C:\\temp\\testPrint");

  system("pause");

  return 0;
}