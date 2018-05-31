//
//  main.cpp
//  BOJ_2747
//
//  Created by 정구열 on 2018. 5. 31..
//  Copyright © 2018년 guyeol_jeong. All rights reserved.
//

/*
 * 피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다.
 * 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.
 * 이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n>=2)가 된다.
 * n=17일때 까지 피보나치 수를 써보면 다음과 같다.
 * 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
 * n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.
 */

#include <iostream>

int F[46], N;

int main(int argc, const char * argv[]) {
  F[0] = 0; F[1] = 1;
  
  //N입력 받기
  std::cin >> N;
  
  for(int i = 2; i <= N; i++) F[i] = F[i-1] + F[i-2];
  
  //답 출력
  std::cout << F[N] << std::endl;
  
  return 0;
}
