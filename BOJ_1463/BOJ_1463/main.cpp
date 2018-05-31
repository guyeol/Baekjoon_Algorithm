//
//  main.cpp
//  BOJ_1463
//
//  Created by 정구열 on 2018. 5. 31..
//  Copyright © 2018년 guyeol_jeong. All rights reserved.
//

/*
 * 문제 *
 * 정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
 * 1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
 * 2. X가 2로 나누어 떨어지면, 2로 나눈다.
 * 3. 1을 뺀다.
 * 정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다.
 * 연산을 사용하는 횟수의 최소값을 출력하시오.
 */

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
  int N, min;
  int *dp;
  cin >> N;
  dp = new int[N+1];
  dp[1] = 0; dp[2] = 1; dp[3] = 1;
  for(int i = 4; i <= N; i++){
    min = dp[i - 1];
    if((i % 3) == 0) {
      if(dp[i/3] < min)
        min = dp[i/3];
    }
    if((i % 2) == 0) {
      if(dp[i/2] < min)
        min = dp[i/2];
    }
    dp[i] = min + 1;
  }
  cout << dp[N] << endl;
  return 0;
}
