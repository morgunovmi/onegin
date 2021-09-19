#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

#include "../include/split.h"

line *splitBuffer(char *buffer, size_t bufSize, size_t *totalLines) {
    size_t arrSize = DEFAULT_ARR_SIZE;
    line *lineArray = (line *)calloc(arrSize, sizeof(*lineArray));
    if (lineArray == nullptr) {
        printf("There was an error allocating memory : %s\n", strerror(errno));
        return nullptr;
    }
    
    size_t lineNum = 0;
    char *start = buffer;
    while (true) {
        char *endLine = strchr(buffer, '\n');
        if (endLine != nullptr) {
            lineArray[lineNum] = {.ptr = buffer,
                                  .len = (size_t)(endLine - buffer)};
            *endLine = '\0';
            buffer = endLine + 1;
            ++lineNum;
        } else {
            lineArray[lineNum] = {.ptr = buffer,
                                  .len = bufSize - (size_t)(buffer - start)};
            ++lineNum;
            break;
        }
        if (lineNum == arrSize - 1) {
            arrSize *= 2;
            lineArray = (line *)realloc(lineArray, sizeof(*lineArray) * arrSize);
            if (lineArray == nullptr) {
                printf("There was an error allocating memory : %s\n", strerror(errno));
                return nullptr;
            }
        }
    }
    *totalLines = lineNum;
    return lineArray;
}