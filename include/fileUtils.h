#include <sys/types.h>

bool isSpace(const char c);

char *cleanBuffer(const char *readBuf, const size_t bufSize, size_t *numCleanBytes);

size_t getFileSize(const char *filePath);
//------------------------------------------------------------ 
//! Reads text from a file and returns a null-terminated buffer 
//!
//! @param[in]  filePath    Path to file
//!
//! @return     null-terminated char buffer in case of success, nullptr otherwise
//------------------------------------------------------------ 
char *readFile(const char *filePath);

int cleanFile(const char *filePath);