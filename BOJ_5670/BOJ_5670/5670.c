//
//  main.c
//  BOJ_5670
//
//  Created by 정구열 on 2018. 1. 31..
//  Copyright © 2018년 NinTenJ_HYU. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILD 26

typedef enum {false, true} bool;

typedef struct trie_node {
    bool end;
    int child_cnt;
    struct trie_node *children[MAX_CHILD];
} TRIENODE;

void insert(TRIENODE *, const char *);
TRIENODE *make_node(void);
int cal(TRIENODE *root, const char *);

TRIENODE *make_node() {
    int i;
    TRIENODE *node = (TRIENODE*) malloc(sizeof(TRIENODE));
    node -> end = false;
    node -> child_cnt = 0;
    for(i = 0; i < MAX_CHILD; i++)
        node -> children[i] = NULL;
    return node;
}
void insert(TRIENODE *parent, const char *key)
{
    int i;
    int idx;
    
    TRIENODE *new_node = parent;
    
    for (i = 0; i < strlen(key); i++)
    {
        idx = key[i] - 'a';
        if (new_node -> children[idx] == NULL) {
            new_node -> children[idx] = make_node();
            new_node -> child_cnt ++;
        }
        new_node = new_node->children[idx];
    }
    new_node -> end = true;
}

void destroy_tree(TRIENODE* node)
{
    int i;
    for(i = 0; i < MAX_CHILD; i++){
        if(node -> children[i] != NULL)
            destroy_tree(node -> children[i]);
    }
    free(node);
}

int cal(TRIENODE *node, const char *key) {
    int i, idx;
    int sum = 0;
    TRIENODE *tmp = node;
    for(i = 0; i < strlen(key); i++) {
        idx = key[i] - 'a';
        tmp = tmp -> children[idx];
        if(tmp -> end && i <= strlen(key) - 1)
            sum++;
        else if(tmp -> child_cnt > 1) {
            sum++;
        } else
            continue;
    }
    return sum;
}

int main(void) {
    double ans;
    int n, i;
    char word[100000][81];
    while(scanf("%d", &n) > 0) {
        ans = 0;
        TRIENODE *tree = make_node();
        for(i = 0; i < n; i++) {
            scanf("%s", word[i]);
            insert(tree, word[i]);
        }
        for(i = 0; i < n; i++)
            ans += cal(tree, word[i]);
        if(ans == 0)
            break;
        printf("%.2f\n", (double)(ans/n));
        destroy_tree(tree);
    }
    return 0;
}
