// In word find puzzle, the player is asked to find each of a given set of words in a square table filled with single letters.

// - horizontally (left or right),
// - vertically (up or down), or
// - along a 45 degree diagonal (in any of the four directions) formed by consecutively adjacent cells of the table;
// - it may wrap around the table’s boundaries.

// but it must read in the same direction with no zigzagging.

// The same cell of the table may be used in different words, but, in a given word, the same cell may be used no more than once.

// Write a program to read the character 2d array (representing square table) and a string, `print true if string is present and false if not.`

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 50

bool checkRows(char matrix[MAX_SIZE][MAX_SIZE], char str[MAX_SIZE], int n, int len, int i, int j) {
    int k;
    bool forward = true;
    for (k = 1; k < len; k++) {
        // Forward check
        int adjusted_j = (j + k) % n;
        if (matrix[i][adjusted_j] != str[k]) forward = false;
    }

    if(forward) return true;

    if (k == len) return true;

    // Checking backwards
    for (k = 1; k < len; k++) {
        // Backward check
        int adjusted_j = (j - k + n) % n;
        if (matrix[i][adjusted_j] != str[k]) return false;
    }

    return true;
}

bool checkCols(char matrix[MAX_SIZE][MAX_SIZE], char str[MAX_SIZE], int n, int len, int i, int j) {
    int k;
    bool forward = true;
    for (k = 1; k < len; k++) {
        // Forward check
        int adjusted_i = (i + k) % n;
        if (matrix[adjusted_i][j] != str[k]) forward = false;
    }

    if(forward) return forward;

    if (k == len) return true;

    // Checking backwards
    for (k = 1; k < len; k++) {
        // Backward check
        int adjusted_i = (i - k + n) % n;
        if (matrix[adjusted_i][j] != str[k]) return false;
    }

    return true;
}

bool checkDiagonalTopRight(char matrix[MAX_SIZE][MAX_SIZE], char str[MAX_SIZE], int n, int len, int i, int j){
    bool forward = true;
    for(int k = 1; k < len; k++){
        // handling the wrapping
        int adjusted_i = (i - k + n) % n;
        int adjusted_j = (j + k) % n;
        if(matrix[adjusted_i][adjusted_j] != str[k]) forward = false;
    }

    if(forward) return true;

    // check backwards
    for(int k = 1; k < len; k++){
        // Backward check
        int adjusted_i = (i + k) % n;
        int adjusted_j = (j - k + n) % n;
        if(matrix[adjusted_i][adjusted_j] != str[k]) return false;
    }

    return true;
}

bool checkDiagonalTopLeft(char matrix[MAX_SIZE][MAX_SIZE], char str[MAX_SIZE], int n, int len, int i, int j){
    bool forward = true;
    for(int k = 1; k < len; k++){
        // handling the wrapping
        int adjusted_i = (i - k + n) % n;
        int adjusted_j = (j - k + n) % n;
        if(matrix[adjusted_i][adjusted_j] != str[k]) forward = false;
    }

    if(forward) return true;

    // Checking backwards
    for (int k = len - 1; k > 0; k--) {
        // Backward check
        int adjusted_i = (i + k) % n;
        int adjusted_j = (j + k) % n;
        if (matrix[adjusted_i][adjusted_j] != str[k]) return false;
    }
    return true;
}

bool checkDiagonalBottomLeft(char matrix[MAX_SIZE][MAX_SIZE], char str[MAX_SIZE], int n, int len, int i, int j){
    bool forward = true;
    for(int k = 1; k < len; k++){
        // handling the wrapping
        int adjusted_i = (i + k) % n;
        int adjusted_j = (j - k + n) % n;
        if(matrix[adjusted_i][adjusted_j] != str[k]) forward = false;
    }

    if(forward) return true;

    // checking backwards 
    for (int k = len - 1; k > 0; k--) {
        // Backward check
        int adjusted_i = (i + k) % n;
        int adjusted_j = (j + k) % n;
        if (matrix[adjusted_i][adjusted_j] != str[k]) return false;
    }
    return true;
}

bool checkDiagonalBottomRight(char matrix[MAX_SIZE][MAX_SIZE], char str[MAX_SIZE], int n, int len, int i, int j){
    bool forward = true;
    for(int k = 1; k < len; k++){
        // handling the wrapping
        int adjusted_i = (i + k) % n;
        int adjusted_j = (j + k) % n;
        if(matrix[adjusted_i][adjusted_j] != str[k]) forward = false;
    }

    if(forward) return true;

    // checking backwards 
    for (int k = len - 1; k > 0; k--) {
        // Backward check
        int adjusted_i = (i + k) % n;
        int adjusted_j = (j + k) % n;
        if (matrix[adjusted_i][adjusted_j] != str[k]) return false;
    }
    return true;
}

bool searchWordInMatrix(char matrix[MAX_SIZE][MAX_SIZE], char str[MAX_SIZE], int n, int len){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == str[0]){
                if(checkCols(matrix, str, n, len, i, j)) return true;
                if(checkRows(matrix, str, n, len, i, j)) return true;
                if(checkDiagonalTopRight(matrix, str, n, len, i, j)) return true;
                if(checkDiagonalTopLeft(matrix, str, n, len, i, j)) return true;
                if(checkDiagonalBottomRight(matrix, str, n, len, i, j)) return true;
                if(checkDiagonalBottomLeft(matrix, str, n, len, i, j)) return true;
            }
        }
    }

    return false;
}

int main(){
    int n;    
    // rows = cols
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // matrix
    char matrix[MAX_SIZE][MAX_SIZE];
    for(int i =0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf(" %c", &matrix[i][j]);
        }
    }

    // enter the string to search
    int maxi = ceil((double)(sqrt(2)*(double)n));

    // len of string
    printf("Enter the length of the key: ");
    int len; scanf("%d", &len);
    if(len > maxi){
        printf("false");
        return 0;
    }
    char str[len+1];
    scanf("%s", str);

    bool resp = searchWordInMatrix(matrix, str, n, len);

    if(resp){
        printf("true");
    }else{
        printf("false");
    }

    return 0;
}
