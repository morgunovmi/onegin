#include <stdlib.h>

#include "text.h"
#include "fileUtils.h"

void freeText(text_t *text) {
    free(text->lines);
    free(text->buffer);
}

int getText(const char *filePath, text_t *text) {
    size_t bufSize = 0;
    char *textBuffer = readFile(filePath, &bufSize);
    if (textBuffer == nullptr) {
        return 0;
    }

    size_t numLines = 0;
    line *array = splitBuffer(textBuffer, bufSize, &numLines); 
    if (array == nullptr) {
        free(textBuffer);
        return 0;
    }
    text->buffer = textBuffer;
    text->lines = array;
    text->numBytes = bufSize;
    text->numLines = numLines;
    return 1; 
}
