//
//  Easy_Stairs_Number
//
//  Created by 정구열 on 2018. 1. 23..
//  Copyright © 2018년 NinTenJ_HYU. All rights reserved.
//

#include <stdio.h>

unsigned int sol[101][10];
int N;

unsigned int make_sol() {
    int i;
    unsigned int sum = 0;
    for(i = 1; i < 10; i++){
        sum += sol[N][i];
        sum %= 1000000000;
    }
    return sum;
}

int main(void) {
    int i, j;
    
    scanf("%d", &N);
    
    //N이 1일때
    for(i = 0; i < 10; i++)
        sol[1][i] = 1;
    
    //N이 1보다 클 때
    if( N >= 2) {
        for(i = 2; i <= N; i++) {
            for(j = 0; j < 10; j++){
                if( j == 0)                 //0이면 그 전 수가 1일 때인 경우
                    sol[i][j] = sol[i-1][1] % 1000000000;
                else if( j == 9)            //9이면 그 전 수가 8일 때인 경우
                    sol[i][j] = sol[i-1][8] % 1000000000;
                else                        //0, 9가 아닐 땐 -1 과 +1 두 가지 경우
                    sol[i][j] = sol[i-1][j-1] % 1000000000 + sol[i-1][j+1] % 1000000000;
            }
        }
    }
    
    printf("%u\n", make_sol());
    
    return 0;
}
