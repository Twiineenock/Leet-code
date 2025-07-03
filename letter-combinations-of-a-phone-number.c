/*
    LINK: https://leetcode.com/problems/letter-combinations-of-a-phone-number/solutions/6917109/cartesian-product-via-run-length-encodin-q0qq/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** letterCombinations(char* digits, int *returnSize);

int main() {
    const char *digits = "2345";
    int returnSize = 0;
    char **combinations = letterCombinations((char *)digits, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < (int)(strlen(combinations[i])); j++) {
            printf("%c ", combinations[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int *returnSize) {
    //if digits is empty, return an empty array
    if(digits == NULL || strlen(digits) == 0) {
        char** result = (char **)malloc(sizeof(char *) * 0); // or NULL
        *returnSize = 0;
        return result;
    }

    struct digitAndItsChars {
        char digit;
        const char *chars;
    };

    //map the digits to the corresponding chars
    struct digitAndItsChars digitAndItsChars[] = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    int digitsLen = (int)(strlen(digits));

    //create an array of strings to store the chars for each digit
    char **stringsToDigits = (char **)malloc(sizeof(char *) * digitsLen);


    for (int i = 0; i < digitsLen; i++) {
        stringsToDigits[i] = NULL; // initialize to NULL
        for (int j = 0; j < 8; j++) {
            if (digits[i] == digitAndItsChars[j].digit) {
                stringsToDigits[i] = (char *)digitAndItsChars[j].chars;
                break;
            }
        }
    }

    //number of indicies in one arraysToCombinationsIndices array = multiply all lengths of stringsToDigits
    int numberOfIndiciesInOneArraysToCombinationsIndicesArray = 1;
    for (int i = 0; i < digitsLen; i++) {
        numberOfIndiciesInOneArraysToCombinationsIndicesArray *= (int)(strlen(stringsToDigits[i]));
    }

    char **arraysToCombinationsStrings = (char **)malloc(sizeof(char *) * digitsLen);
    for (int i = 0; i < digitsLen; i++) {
        arraysToCombinationsStrings[i] = (char *)calloc(numberOfIndiciesInOneArraysToCombinationsIndicesArray + 1, sizeof(char));
    }

    int runLength = 1;
    for (int i = digitsLen - 1; i >= 0; i--) {
        int trackCurrentIndex = 0;
        int trackRunLength = 0;
        if(i == digitsLen - 1) {
            runLength = 0;
        } else {
            //runLength = previous runLength * the length of the previous string in stringsToDigits
            runLength = runLength * (int)(strlen(stringsToDigits[i + 1]));
            trackRunLength = 1;
        }

        for (int j = 0; j < numberOfIndiciesInOneArraysToCombinationsIndicesArray; j++) {
            arraysToCombinationsStrings[i][j] = stringsToDigits[i][trackCurrentIndex];
            if(i == digitsLen - 1) {
                if(trackRunLength == runLength) {
                    if(trackCurrentIndex == (int)(strlen(stringsToDigits[i])) - 1) {
                        trackCurrentIndex = 0;
                    } else {
                        trackCurrentIndex++;
                    }
                    trackRunLength = 0;
                } else {
                    trackRunLength++;
                }
            } else {
                if(trackRunLength == runLength) {
                    if(trackCurrentIndex == (int)(strlen(stringsToDigits[i])) - 1) {
                        trackCurrentIndex = 0;
                    } else {
                        trackCurrentIndex++;
                    }
                    trackRunLength = 1;
                } else {
                    trackRunLength++;
                }
            }
        }
        //after i = digitsLen - 1, set runLength to 1
        if(i == digitsLen - 1) {
            runLength = 1;
        }
    }

    //an array that will store combinations(strings)
    char **combinations = (char **)malloc(sizeof(char *) * numberOfIndiciesInOneArraysToCombinationsIndicesArray);
    for (int i = 0; i < numberOfIndiciesInOneArraysToCombinationsIndicesArray; i++) {
        combinations[i] = (char *)malloc(sizeof(char) * (digitsLen + 1));
        combinations[i][digitsLen] = '\0';  // Don't forget the null terminator
    }

    //starting from the first index of strings in arraysToCombinationsStrings, we are creating a combination string made up of the chars in the strings in arraysToCombinationsStrings at the same index
    for (int i = 0; i < numberOfIndiciesInOneArraysToCombinationsIndicesArray; i++) {
        for (int j = 0; j < digitsLen; j++) {
            combinations[i][j] = arraysToCombinationsStrings[j][i];
        }
    }

    *returnSize = numberOfIndiciesInOneArraysToCombinationsIndicesArray;
    return combinations;
}