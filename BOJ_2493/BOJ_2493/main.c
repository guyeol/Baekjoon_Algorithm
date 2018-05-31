//
//  main.c
//  BOJ_2493
//
//  Created by 정구열 on 2018. 3. 5..
//  Copyright © 2018년 NinTenJ_HYU. All rights reserved.
//

#include <stdio.h>

int T, a, b, c;
int rectangle(void);

int main(int argc, const char * argv[]) {
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d %d %d", &a, &b, &c);
        printf("#%d %d\n", i + 1, rectangle());
    }
    return 0;
}

int rectangle(){
    if( a == b) return c;
    if( b == c) return a;
    if( a == c) return b;
    else return -1;
}
