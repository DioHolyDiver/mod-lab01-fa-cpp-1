// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <cctype>
#include <cstring> 
unsigned int faStr1(const char *str) {
    unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    char copy[strlen(str) + 1];
    strcpy(copy, str);
    char *token = strtok(copy, " ");
    while (token != nullptr) {
        bool contains_digit = false;
        for (size_t j = 0; token[j] != '\0'; ++j) {
            if (std::isdigit(token[j])) {
                contains_digit = true;
                break;
            }
        }
        if (!contains_digit) {
            count++;
        }
        token = strtok(nullptr, " ");
    }
    return count;
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
