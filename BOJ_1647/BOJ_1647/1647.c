//
//  main.c
//  BOJ_1647
//
//  Created by 정구열 on 2018. 2. 21..
//  Copyright © 2018년 NinTenJ_HYU. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct edge {
    int src, dst, weight;
} EDGE;

EDGE edge[1000010];
int parent[100010];
int N, M;

void make_set(int x) {
    parent[x] = x;
}

int find_set(int x) {
    if(x != parent[x]) parent[x] = find_set(parent[x]);
    return parent[x];
}

int mst_kruskal(){
    int i, a, b, ans = 0, tmp = 0;
    for(i = 0; i < M; i++) {
        a = find_set(edge[i].src); b = find_set(edge[i].dst);
        if (a != b) {
            parent[a] = b;
            tmp = edge[i].weight;
            ans += edge[i].weight;
        }
    }
    return ans - tmp;
}

int compare(const void *a, const void *b) {
    EDGE *x, *y;
    x = (EDGE *)a;
    y = (EDGE *)b;
    if (x -> weight < y -> weight) return -1;
    if (x -> weight > y -> weight) return 1;
    return 0;
}

int main() {
    int i;
    scanf("%d %d", &N, &M);
    for(i = 0; i < M; i++) {
        make_set(i + 1);
        scanf("%d %d %d", &edge[i].src, &edge[i].dst, &edge[i].weight);
    }
    qsort(edge, M, sizeof(edge[1]), compare);
    printf("%d", mst_kruskal());
    return 0;
}
