//
//  BOJ_5052
//
//  Created by 정구열 on 2018. 1. 29..
//  Copyright © 2018년 NinTenJ_HYU. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false, true} bool;

typedef struct trie_node {
    bool end;
    int child_cnt;
    struct trie_node *children[10];
} TRIENODE;

void insert(TRIENODE *, const char *);
TRIENODE *make_node(void);
bool terminate = false;

TRIENODE *make_node() {
    int i;
    TRIENODE *node = (TRIENODE*) malloc(sizeof(TRIENODE));
    node -> end = false;
    node -> child_cnt = 0;
    for(i = 0; i < 10; i++)
        node -> children[i] = NULL;
    return node;
}
bool is_leaf(TRIENODE *node) {
    if(node -> child_cnt == 0)
        return true;
    else
        return false;
}
void insert(TRIENODE *parent, const char *key)
{
    int i;
    int idx;
    
    TRIENODE *new_node = parent;
    
    for (i = 0; i < strlen(key); i++)
    {
        idx = key[i] - '0';
        if (new_node -> children[idx] == NULL) {
            new_node -> children[idx] = make_node();
            new_node -> child_cnt ++;
        }
        else if(new_node -> children[idx] -> end) {
            terminate = true;
            return;
        }
        new_node = new_node->children[idx];
    }
    if(!is_leaf(new_node)) {
        terminate = true;
        return;
    }
    new_node -> end = true;
}

void destroy_tree(TRIENODE* node)
{
    int i;
    for(i = 0; i < 10; i++){
        if(node -> children[i] != NULL)
            destroy_tree(node->children[i]);
    }
    free(node);
}

int main(void) {
    int t, n;
    int i, j;
    char phone_num[11];
    scanf("%d", &t);
    for(i = 0; i < t; i++) {
        scanf("%d", &n);
        TRIENODE *tree = make_node();
        for(j = 0; j < n; j++) {
            scanf("%s", phone_num);
            if(!terminate)
                insert(tree, phone_num);
        }
        if(terminate)
            printf("NO\n");
        else
            printf("YES\n");
        terminate = false;
        destroy_tree(tree);
    }
    return 0;
}
