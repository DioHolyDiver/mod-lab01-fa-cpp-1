// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <cctype>
unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool validWord = true;
    while (*str) {
        if (std::isalpha(*str)) {
            if (!inWord) {
                inWord = true;
                validWord = true;
            }
        } else if (std::isdigit(*str)) {
            if (inWord) {
                validWord = false;
            }
        } else if (std::isspace(*str) || std::ispunct(*str)) {
            if (inWord) {
                if (validWord) {
                    count++;
                }
                inWord = false;
                validWord = true;
            }
        } else {
            if (inWord) {
                validWord = false;
            }
        }
        str++;
    }
    if (inWord && validWord) {
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
                    if (*(str + 1) == ' ' || *(str + 1) == '\0' || std::isspace(*(str + 1))) {
                        count++;
                    }
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
