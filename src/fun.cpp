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
        } else if (isspace(*str) || ispunct(*str)) {
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
bool isUpperLatin(char c) {
    return (c >= 'A' && c <= 'Z');
}
bool isLowerLatin(char c) {
    return (c >= 'a' && c <= 'z');
}
unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    while (*str) {
        if (std::isspace(*str) || std::ispunct(*str)) {
            inWord = false;
        } else {
            if (!inWord) {
                if (std::isupper(*str)) {
                    count++;
                }
                inWord = true;
            }
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
    } else {
        return 0;
    }
}
