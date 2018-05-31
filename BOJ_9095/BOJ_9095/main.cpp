//
//  main.cpp
//  BOJ_9095
//
//  Created by 정구열 on 2018. 5. 31..
//  Copyright © 2018년 guyeol_jeong. All rights reserved.
//

/*
 * Baekjoon Online Judge problem # 9095
 * Algorithm using Dynamic Programming
 */

/*
 * * * 문제 설명 * * *
 * 정수 4를 1, 2, 3의 조합으로 나타내는 방법은 총 7가지가 있다.
 * 1+1+1+1
 * 1+1+2
 * 1+2+1
 * 2+1+1
 * 2+2
 * 1+3
 * 3+1
 * 정수 n이 주어졌을 때, n을 1,2,3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
 */

#include <iostream>

int T, n;
int dp[12] = {0};

void sol() {
  for(int i = 4; i <= 11; i++) dp[i] += dp[i-1] + dp[i-2] + dp[i-3];
}

int main(int argc, const char * argv[]) {
  
  dp[1] = 1; dp[2] = 2; dp[3] = 4;
  //Test Case 입력
  std::cin >> T;
  sol();
  
  for(int i = 0; i < T; i++) {
    std::cin >> n;
    std::cout << dp[n] << std::endl;
  }
  
  return 0;
}
