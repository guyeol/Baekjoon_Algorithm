//
//  main.c
//  BOJ_2580
//
//  Created by 정구열 on 2018. 2. 5..
//  Copyright © 2018년 NinTenJ_HYU. All rights reserved.
//

#include <stdio.h>
typedef enum {false, true} bool;

int sudoku[9][9];
bool find[9][9];

void sol(int, int);
void print(void);

int main(void) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            scanf("%d", &sudoku[i][j]);
            if(sudoku[i][j] == 0) find[i][j] = false;
            else find[i][j] = true;
        }
    }
    sol(0, 0);
    print();
    return 0;
}

void sol(){
}
void print(){
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++)
            printf("%d ", find[i][j]);
        printf("\n");
    }
}
