//
//  main.c
//  BOJ_1759
//
//  Created by 정구열 on 2018. 1. 26..
//  Copyright © 2018년 NinTenJ_HYU. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *sort(char []);
void combination(int [], char [], int , int , int , int );
void print_arr(int [], char [], int );

int main(void) {
    // insert code here...
    int L, C;
    char *alpha, c, buf;
    int *arr;
    int i = 0;
    
    scanf("%d %d", &L, &C);
    alpha = (char*) malloc(sizeof(char)*C);
    arr = (int*) malloc(sizeof(int)*C);
    scanf("%c", &buf);
    
    while(i < C) {
        if((c = getc(stdin)) != ' ')
            alpha[i++] = c;
    }
    alpha = sort(alpha);
    combination(arr, alpha, 0, C, L, 0);
    free(arr);
    free(alpha);
    return 0;
}

char *sort(char arr[]) {
    int i, j;
    int min_idx;
    char tmp;
    
    for(i = 0; i < strlen(arr); i++) {
        min_idx = i;
        for(j = i + 1; j < strlen(arr); j++){
            if(arr[min_idx] > arr[j])
                min_idx = j;
        }
        tmp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = tmp;
    }
    return arr;
}
void combination(int arr[], char alpha[], int index, int n, int r, int target) {
    if (r == 0)
        print_arr(arr, alpha, index);
    else if (target == n)
        return;
    else {
        arr[index] = target;
        combination(arr, alpha, index + 1, n, r - 1, target + 1);
        combination(arr, alpha, index, n, r, target + 1);
    }
}

void print_arr(int arr[], char alpha[], int length){
    int i;
    int vowel_num = 0, consonant_num = 0;
    for (i = 0; i < length; i++){
        if(alpha[arr[i]] == 'a' || alpha[arr[i]] == 'e' ||alpha[arr[i]] == 'i' ||alpha[arr[i]] == 'o' ||alpha[arr[i]] == 'u') {
            vowel_num ++;
        } else
            consonant_num++;
    }
    if(vowel_num >= 1 && consonant_num >=2) {
        for (i = 0; i < length; i++)
            printf("%c", alpha[arr[i]]);
        printf("\n");
    }
}
