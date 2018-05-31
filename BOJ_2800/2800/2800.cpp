//
//  2800.c
//
//  Created by 정구열 on 2018. 1. 22..
//  Copyright © 2018년 NinTenJ_HYU. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char equa[201];
char sol_set[200][200];
char bracket_stack[10];
int *bracket_idx_set;
int top_idx, bracket_num;
int cur;
int comparisonFunctionString(const void *a, const void *b);
    
int main() {
    
    int i, j;
    scanf("%s", equa);
    top_idx = -1;
    bracket_num = 0;
    unsigned long len = strlen(equa);
    bracket_idx_set = (int*) malloc(sizeof(int)*len);
    memset(bracket_idx_set, -1, sizeof(bracket_idx_set)*len);
    
    for(i = 0; i < len; i++) {
        if(equa[i] == '(') {
            bracket_idx_set[i] = bracket_num++;
            bracket_stack[++top_idx] = bracket_idx_set[i]; //왼쪽 괄호가 나오면 스택에 인덱스번호를 push함
        }
        if(equa[i] == ')') {
            bracket_idx_set[i] = bracket_stack[top_idx];    //오른쪽 괄호가 나오면 스택에서 pop해서 bracket이 위치하는 idx에 넣음
            top_idx--;
        }
    }
    
    int num_of_cases = pow(2, bracket_num) - 1; // 괄호쌍을 제거하는 모든 경우의 수는 2^n-1개 (최대는 2^10-1 1023)
    
    for(i = 1 ; i <= num_of_cases; i ++) {         //모든 경우의 수에 대해
        cur = 0;
        for (j = 0; j < len; j++) {
            if( equa[j] != '(' && equa[j] != ')' ){     //숫자나 연산자인 경우
                sol_set[i-1][cur] = equa[j];
                cur++;
            } else if(!(i & (1 << bracket_idx_set[j]))) {
                sol_set[i-1][cur] = equa[j];
                cur++;
            }
        }
    }
    
    qsort((void *)sol_set, num_of_cases, sizeof(sol_set[0]), comparisonFunctionString);
    
    for(i = 0; i < num_of_cases; i++)
        printf("%s\n", sol_set[i]);
    
    free(bracket_idx_set);
    return 0;
}

int comparisonFunctionString(const void *a, const void *b) {
    return( strcmp( (char *)a, (char *)b) );
}
