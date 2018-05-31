//
//  test.cpp
//  2800
//
//  Created by 정구열 on 2018. 1. 22..
//  Copyright © 2018년 NinTenJ_HYU. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stack>

#define FORC(it, C) for(__typeof((C).begin()) it = (C).begin(); it != (C).end(); ++it)

int main(void) {
    std::string given_exp;
    std::cin >> given_exp;
    int n = given_exp.size();
    std::vector< int > color(n, -1);
    std::stack< int > current;
    int num_of_brackets = 0;
    
    for (int i = 0; i < n; ++i) {
        if (given_exp[i] == '(') {
            color[i] = num_of_brackets++;
            current.push(color[i]);
        }
        if (given_exp[i] == ')') {
            color[i] = current.top();
            current.pop();
        }
    }
    
    std::set< std::string > solution;
    
    for (int i = 1; i < (1<<num_of_brackets); ++i) {
        std::string cur;
        for (int j = 0; j < n; ++j) {
            if ((given_exp[j] != '(' && given_exp[j] != ')') || !(i & (1 << color[j]))) {
                cur += given_exp[j];
            }
        }
        solution.insert(cur);
    }
    
    for (auto &rjesenje: solution) {
        std::cout << rjesenje << std::endl;
    }
    
    return 0;
}
