// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <cctype>
unsigned int faStr1(const char *str) {
    unsigned int wordCount = 0;
    size_t len = strlen(str);
    bool inWord = false;
    bool hasDigit = false;
    for (size_t i = 0; i <= len; ++i) {
        if ((!isspace(str[i]) && !isdigit(str[i])) || i == len) {
            if (inWord && !hasDigit)
                wordCount++;
            inWord = false;
            hasDigit = false;
        } else if (isalnum(str[i])) {
            inWord = true;
            if (isdigit(str[i]))
                hasDigit = true;
        }
    }
    return wordCount;
}
unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    while (*str != '\0') {
        if (isupper(*str)) {
            const char* start_word = str;
            bool valid = true;
            for (++str; *str && !isspace(*str); ++str) {
                if (!islower(*str)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                count++;
            }
        } else {
            while (*str && !isspace(*str)) ++str;
        }
        while (*str && isspace(*str)) ++str;
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
