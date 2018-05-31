//
//  main.c
//  Subset_Sum_Problem_1182
//
//  Created by 정구열 on 2018. 1. 21..
//  Copyright © 2018년 NinTenJ_HYU. All rights reserved.
//

#include <stdio.h>

int N, S, cnt=0;
int set[21];

void search(int n, int sum) {
    
    if(n == N + 1){
        if(sum == S){
            cnt ++;
        }
        return;
    }
    
    search(n + 1, sum + set[n]);
    search(n + 1, sum);
}

int main(void) {
    
    int i;
    scanf("%d %d", &N, &S);
    
    for(i = 1; i <= N; i++)
        scanf("%d", &set[i]);
    
    search(1, 0);
    
    if(S == 0)
        cnt-=1;
    
    printf("%d\n", cnt);
    
    return 0;
}
