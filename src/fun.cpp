// Copyright 2022 UNN-IASR
#include "fun.h"
#include <string>
#include <algorithm>
#include <cmath>
#include <cctype>


unsigned int faStr1(const char *str) {
    bool hasDigit = false;
    bool inWord = false;
    int wordCount = 0;

    for (int i = 0; str[i]; ++i) {
        if (str[i] != ' ') {
            inWord = true;
            if (!hasDigit && isdigit(str[i])) {
                hasDigit = true;
            }
        } else {
            if (inWord && !hasDigit) {
                wordCount++;
            }
            inWord = false;
            hasDigit = false;
        }
    }
    if (inWord && !hasDigit) {
        wordCount++;
    }
    return wordCount;
}

unsigned int faStr2(const char *str) {
    bool startsWithUppercase = false;
    bool inWord = false;
    bool isFirstWord = true;
    int wordCount = 0;

    for (int i = 0; str[i]; ++i) {
        if (str[i] != ' ') {
            inWord = true;
            if (isFirstWord && isupper(str[i])) {
                startsWithUppercase = true;
                isFirstWord = false;
            } else if (startsWithUppercase && !islower(str[i])) {
                startsWithUppercase = false;
            }
        } else {
            if (inWord && startsWithUppercase) {
                wordCount++;
            }
            inWord = false;
            isFirstWord = true;
            startsWithUppercase = false;
        }
    }
    if (inWord && startsWithUppercase) {
        wordCount++;
    }
    return wordCount;
}

unsigned int faStr3(const char *str) {
    bool inWord = false;
    int wordLength = 0;
    int totalWordLength = 0;
    int wordCount = 0;

    for (int i = 0; str[i]; ++i) {
        if (str[i] != ' ') {
            if (!inWord) {
                inWord = true;
                wordCount++;
            }
            wordLength++;
        } else {
            inWord = false;
            totalWordLength += wordLength;
            wordLength = 0;
        }
    }

    if (inWord) {
        totalWordLength += wordLength;
    }

    if (wordCount == 0) {
        return 0; // Избегаем деления на ноль
    }

    int averageWordLength = round(static_cast<double>(totalWordLength)
    / static_cast<double>(wordCount));
    return averageWordLength;
}
