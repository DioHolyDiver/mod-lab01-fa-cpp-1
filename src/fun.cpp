// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <cctype>
unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool isWord = false;
    while (*str) {
        if (isalpha(*str)) {
            isWord = true;
        }
        else if (isdigit(*str)) {
            isWord = false;
        }
        else if (isspace(*str) || ispunct(*str)) {
            if (isWord) {
                count++;
                isWord = false;
            }
        }
        str++;
    }
    if (isWord) {
        count++;
    }
    return count;
}
bool isUpperLatin(char c)
{
    return (c >= 'A' && c <= 'Z');
}
bool isLowerLatin(char c)
{
    return (c >= 'a' && c <= 'z');
}
unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool isWordStart = false;
    bool isValid = true;
    while (*str) {
        if (!isWordStart && isUpperLatin(*str)) {
            isWordStart = true;
            isValid = true;
        }
        else if (isWordStart && !isLowerLatin(*str)) {
            isValid = false;
        }
        else if (isWordStart && (*str == ' ' || *str == '\t' || *str == '\n' || !(*str))) {
            if (isValid) {
                count++;
            }
            isWordStart = false;
            isValid = true;
        }
        str++;
    }
    return count;
}
unsigned int faStr3(const char *str) {
    unsigned int totalLength = 0;
    unsigned int wordCount = 0;
    while (*str) {
        while (*str && !isalpha(*str)) {
            str++;
        }
        if (*str) {
            unsigned int wordLength = 0;
            while (*str && isalpha(*str)) {
                wordLength++;
                str++;
            }
            totalLength += wordLength;
            wordCount++;
        }
    }
    if (wordCount != 0) {
        return (totalLength + wordCount / 2) / wordCount;
    }
    else {
        return 0;
    }
}
