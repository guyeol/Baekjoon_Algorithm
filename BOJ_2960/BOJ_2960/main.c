//
//  main.c
//  BOJ_2960
//
//  Created by 정구열 on 2018. 1. 25..
//  Copyright © 2018년 NinTenJ_HYU. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, k;

int main(void) {
    
    int *set;
    int i, j, cnt = 0;
    int p, sol = 0;
    scanf("%d %d", &n, &k);
    
    set = (int*) malloc(sizeof(int)*(n+1));
    memset(set, 0, sizeof(int)*(n+1));
    set[0] = 1; set[1] = 1;
    
    for( i = 2; i <= n; i++){
        p = i;
        j = 1;
        if( set[i] == 0) {
            while(p <= n){
                if(set[p] == 0) {
                    set[p] = 1;
                    cnt ++;
                }
                if(cnt == k) {
                    sol = p;
                    break;
                }
                p = i * ++j;
            }
        }
        if( cnt == k)
            break;
    }
    printf("%d\n", sol);
    free(set);
    return 0;
}
