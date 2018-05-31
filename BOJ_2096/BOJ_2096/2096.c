//
//  BOJ_2096
//
//  Created by 정구열 on 2018. 1. 28..
//  Copyright © 2018년 NinTenJ_HYU. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) (a) > (b) ? (b) : (a)
#define MAX(a, b) (a) > (b) ? (a) : (b)

int main(void) {
    
    int N;
    int i;
    int set[3];
    int min_dp[2][3];
    int max_dp[2][3];
    
    for(i = 0; i < 2; i++){
        memset(min_dp[i], 0, sizeof(int) * 3);
        memset(max_dp[i], 0, sizeof(int) * 3);
    }
    scanf("%d", &N);
    scanf("%d %d %d", &set[0], &set[1], &set[2]);
    for(i = 0; i < 3; i++){
        min_dp[0][i] = set[i];
        max_dp[0][i] = set[i];
    }
    
    for(i = 1; i < N; i++) {
        scanf("%d %d %d", &set[0], &set[1], &set[2]);
        min_dp[i%2][0] = MIN(min_dp[(i+1)%2][0] + set[0], min_dp[(i+1)%2][1] + set[0]);
        min_dp[i%2][1] = MIN(MIN(min_dp[(i+1)%2][0] + set[1], min_dp[(i+1)%2][1] + set[1]), min_dp[(i+1)%2][2] + set[1]);
        min_dp[i%2][2] = MIN(min_dp[(i+1)%2][1] + set[2], min_dp[(i+1)%2][2] + set[2]);
        
        max_dp[i%2][0] = MAX(max_dp[(i+1)%2][0] + set[0], max_dp[(i+1)%2][1] + set[0]);
        max_dp[i%2][1] = MAX(MAX(max_dp[(i+1)%2][0] + set[1], max_dp[(i+1)%2][1] + set[1]), max_dp[(i+1)%2][2] + set[1]);
        max_dp[i%2][2] = MAX(max_dp[(i+1)%2][1] + set[2], max_dp[(i+1)%2][2] + set[2]);
    }
    
    printf("%d %d\n", MAX(MAX(max_dp[(N+1)%2][0], max_dp[(N+1)%2][1]), max_dp[(N+1)%2][2]) ,MIN(MIN(min_dp[(N+1)%2][0], min_dp[(N+1)%2][1]), min_dp[(N+1)%2][2]));
    return 0;
}
