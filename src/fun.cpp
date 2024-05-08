// Copyright 2022 UNN-IASR
#include "fun.h"
#include <string>
#include <algorithm>
#include <cmath>

unsigned int faStr1(const char* str) {
    std::string word;
    unsigned int countWordsWithoutDigits = 0;

    // Разбиваем строку на слова
    for (const char* p = str; *p; ++p) {
        if (*p == ' ') {
            // Проверяем, содержит ли слово цифры
            if (!word.empty() && std::none_of(word.begin(), word.end(), ::isdigit)) {
                countWordsWithoutDigits++;
            }
            word.clear();
        } else {
            word += *p;
        }
    }
    // Проверяем последнее слово
    if (!word.empty() && std::none_of(word.begin(), word.end(), ::isdigit)) {
        countWordsWithoutDigits++;
    }

    return countWordsWithoutDigits;
}

unsigned int faStr2(const char* str) {
    std::string word;
    unsigned int countWordsCapitalLower = 0;

    // Разбиваем строку на слова
    for (const char* p = str; *p; ++p) {
        if (*p == ' ') {
            // Проверяем, начинается ли слово с заглавной буквы
            if (!word.empty() && std::isupper(word[0])) {
                // Проверяем, состоит ли слово только из строчных латинских букв
                if (word.length() == 1 || std::all_of(word.begin() + 1, word.end(), ::islower)) {
                    countWordsCapitalLower++;
                }
            }
            word.clear();
        } else {
            word += *p;
        }
    }
    // Проверяем последнее слово
    if (!word.empty() && std::isupper(word[0])) {
        if (word.length() == 1 || std::all_of(word.begin() + 1, word.end(), ::islower)) {
            countWordsCapitalLower++;
        }
    }

    return countWordsCapitalLower;
}

unsigned int faStr3(const char* str) {
    unsigned int totalWordLength = 0;
    unsigned int wordCount = 0;
    unsigned int lastWordLength = 0;

    // Разбиваем строку на слова
    for (const char* p = str; *p; ++p) {
        if (*p == ' ') {
            // Увеличиваем сумму длин слов
            totalWordLength += lastWordLength;
            wordCount++; // Увеличиваем счетчик слов
            lastWordLength = 0; // Сбрасываем счетчик для следующего слова
        } else {
            lastWordLength++; // Увеличиваем длину текущего слова
        }
    }
    // Проверяем последнее слово
    if (lastWordLength > 0) {
        totalWordLength += lastWordLength;
        wordCount++; // Увеличиваем счетчик слов
    }

    // Находим среднюю длину слова
    double averageWordLength = static_cast<double>(totalWordLength) / static_cast<double>(wordCount);

    // Округляем до целого значения
    unsigned int roundedAverageWordLength = static_cast<unsigned int>(std::round(averageWordLength));

    return roundedAverageWordLength;
}
