//
//  main.c
//  BOJ_1761
//
//  Created by 정구열 on 2018. 2. 5..
//  Copyright © 2018년 NinTenJ_HYU. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 40001

typedef struct tree {
    int root;
    int parent[MAX];
    long long dist[MAX];
    int depth[MAX];
    int size;
}TREE;

TREE tree;
void set_dist(const int, const int );
void build(const int ,const int );
long long lca(int ,int );
int get_parent(const int );
int is_root(const int );

int main(void) {
    int N, M, a, b, dist;
    scanf("%d", &N);
    
    //memset(tree.parent, 0, sizeof(int) * (N + 1));
    tree.size = 0;
    for(int i = 1; i < N; i++) {
        scanf("%d %d %d", &a, &b, &dist);
        if(tree.size == 0) {
            tree.root = a;
            tree.parent[a] = -1;
            tree.parent[b] = a;
            tree.depth[a] = 0;
            tree.depth[b] = 1;
            tree.size += 2;
            tree.dist[a] = 0;
            set_dist(b, dist);
        } else {
            if(tree.parent[a] != 0) {
                build(a, b);
                set_dist(b, dist);
            }
            else {
                build(b, a);
                set_dist(a, dist);
            }
        }
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        printf("%lld\n", lca(a, b));
    }
    return 0;
}

void set_dist(const int a, const int distance) {
    tree.dist[a] = distance;
}

void build(const int a, const int b) {
    tree.parent[b] = a;
    tree.depth[b] = tree.depth[a] + 1;
    tree.size ++;
}

long long lca(int a, int b) {
    long long ans = 0;
    int depth_a = tree.depth[a];
    int depth_b = tree.depth[b];
    while(1) {
        if(depth_a == depth_b)
            break;
        if(depth_a < depth_b) {
            ans += tree.dist[b];
            b = get_parent(b);
            depth_b = tree.depth[b];
        } else {
            ans += tree.dist[a];
            a = get_parent(a);
            depth_a = tree.depth[a];
        }
    }
    while(tree.parent[a] != tree.parent[b] && a != b) {
        ans += tree.dist[a] + tree.dist[b];
        a = get_parent(a);
        b = get_parent(b);
    }
    if(is_root(a) | is_root(b))
        return ans;
    else
        return ans += tree.dist[a] + tree.dist[b];
}

int get_parent(const int a) {
    return tree.parent[a];
}

int is_root(const int a) {
    return tree.root == a ? 1 : 0;
}
