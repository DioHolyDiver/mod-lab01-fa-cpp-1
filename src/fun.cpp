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
unsigned int faStr2(const char *str) {
    unsigned int count = 0;
  bool in_word = false;
  bool valid_word = false;

  while (*str) {
    if (std::isalpha(*str)) {
      if (!in_word) {
        in_word = true;
        valid_word = std::isupper(*str);
      } else {
        if (!std::islower(*str)) {
          valid_word = false;
        }
      }
    } else {
      if (in_word) {
        in_word = false;
        if (valid_word) {
          count++;
        }
      }
    }
    str++;
  }
  if (in_word && valid_word) {
    count++;
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
