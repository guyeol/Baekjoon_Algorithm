//
//  main.c
//  BOJ_11812
//
//  Created by 정구열 on 2018. 2. 4..
//  Copyright © 2018년 NinTenJ_HYU. All rights reserved.
//

#include <stdio.h>
#include <math.h>

void swap(long long *a, long long *b) {
    long long tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    long long N, xy[2];
    long long sol;
    int K, Q;
    scanf("%lld %d %d", &N, &K, &Q);
    for(int i = 0; i < Q; i++){
        scanf("%lld %lld", &xy[0], &xy[1]);
        xy[0]--; xy[1]--;
        sol = 0;
        // When k is 1, the distance between nodes is equal to the difference between two nodes.
        if (K == 1) {
            printf("%ld\n", labs(xy[0] - xy[1]));
            continue;
        }
        //If K is greater than 1, add the length until the parents of the two nodes are equal.
        //For convenience of calculation, the index of a large number of two nodes is set to zero.
        while (xy[0] != xy[1]) {
            if (xy[0] < xy[1])
                swap(&xy[0], &xy[1]);
            xy[0] = (xy[0] - 1) / K;
            sol++;
        }
        printf("%lld\n", sol);
    }
    return 0;
}
