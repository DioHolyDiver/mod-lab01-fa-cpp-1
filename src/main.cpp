// Copyright 2022 UNN-IASR
#include "fun.h"
#include "fun.cpp"
#include <iostream>
int main() {
    const char* str1 = "Hello, World! This Is a Test String.";
    unsigned int result1 = faStr1(str1);
    std::cout << "Количество слов, начинающихся с заглавной буквы: " << result1 << std::endl;
    
    const char* str2 = "Hello, World! This Is a Test string.";
    unsigned int result2 = faStr2(str2);
    std::cout << "Количество слов, удовлетворяющих условиям: " << result2 << std::endl;
    
    // Пример использования функции faStr3
    const char* str3 = "The quick brown fox jumps over the lazy dog.";
    unsigned int result3 = faStr3(str3);
    std::cout << "Средняя длина слова в строке: " << result3 << std::endl;
    
    const char* str4 = "This string contains 3 words without digits.";
    return 0;
}
