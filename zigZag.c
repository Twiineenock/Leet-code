// https://leetcode.com/problems/zigzag-conversion/submissions/1683052420/?envType=problem-list-v2&envId=string
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* zigzagConversion(char *s, int rows);
char *convert(char *s, int rows);

int main() {
    char s[100] = "PAYPALISHIRING";
    int *zigZagSections = zigzagConversion(s, 3);
    for (int i = 0; i < (int)(strlen(s)); i++) {
        printf("%d ", zigZagSections[i]);
    }
    printf("\n");
    char *result = convert(s, 3);
    printf("%s\n", result);
    free(result);
    free(zigZagSections);
    return 0;
}

char **createStringArray(int n, int maxLength) {
    // Allocate memory for n string pointers
    char **strings = (char **)malloc(n * sizeof(char *));
    if (strings == NULL) {
        perror("Failed to allocate memory for string pointers");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for each individual string
    for (int i = 0; i < n; i++) {
        strings[i] = (char *)malloc((maxLength + 1) * sizeof(char)); // +1 for '\0'
        if (strings[i] == NULL) {
            perror("Failed to allocate memory for a string");
            exit(EXIT_FAILURE);
        }
        strings[i][0] = '\0'; // initialize to empty string
    }

    return strings;
}

int* zigzagConversion(char *s, int rows) {
    if (rows <= 1) {
        printf("Row count must be greater than 1.\n");
        return NULL;
    }

    int len = strlen(s);
    int *zigZagSections = (int *)malloc(sizeof(int) * len);

    int currentRow = 0;
    int direction = 1; // 1 means down, -1 means up

    for (int i = 0; i < len; i++) {
        zigZagSections[i] = currentRow;

        if (currentRow == 0) {
            direction = 1;
        } else if (currentRow == rows - 1) {
            direction = -1;
        }

        currentRow += direction;
    }
    
    return zigZagSections;
}

void appendChar(char *str, char c) {
    int len = strlen(str);
    str[len] = c;
    str[len + 1] = '\0';
}

// Function to concatenate all strings in the sections array
char* concatenateSections(char** sections, int rows) {
    // First calculate total length needed
    size_t total_length = 1; // Start with 1 for null terminator
    
    for (int i = 0; i < rows; i++) {
        total_length += strlen(sections[i]);
    }
    
    // Allocate memory for the result
    char* result = (char*)malloc(total_length);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    
    result[0] = '\0'; // Initialize as empty string
    
    // Concatenate all sections
    for (int i = 0; i < rows; i++) {
        strcat(result, sections[i]);
    }
    
    return result;
}

char *convert(char *s, int rows) {
    char **sections = createStringArray(rows, strlen(s));
    int len = strlen(s);
    int *reverse = zigzagConversion(s, rows);

    // Handle special cases early
    if (rows <= 1 || rows >= len) {
        return strdup(s);  // Just return the original string (copied)
    }

    for (int i = 0; i < len; i++) {
        appendChar(sections[reverse[i]], s[i]);
    }

    char* result = concatenateSections(sections, rows);
    return result;
}
