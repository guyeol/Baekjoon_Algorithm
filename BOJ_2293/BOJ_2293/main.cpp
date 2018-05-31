
/*
 * Baekjoon Online Judge Problem # 2293
 * Algorithm using Dynamic Programming
 *
 * 문제 *
 * n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다.
 * 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다.
 * 그 경우의 수를 구하시오. (각각의 동전은 몇 개라도 사용할 수 있다.)
 *
 * 입력 *
 * 첫째줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000)
 * 다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 동전의 가치는 100,000보다 작거나 같은 자연수이다.
 */

#include <iostream>

int n, k;
int coin[100];
int dp[10001] = {0};

int main(int argc, const char * argv[]) {
  
  //n, k입력
  std::cin >> n >> k;
  
  //동전가치 입력받기
  for(int i = 0; i < n; i++) std::cin >> coin[i];
  
  dp[0] = 1;
  //점화식은 DP(n) = DP(n) + DP(n-coin)
  for(int i = 0; i < n; i++) {
    for(int j = coin[i]; j <= k; j++)
      dp[j] += dp[j - coin[i]];
  }
  std::cout << dp[k] << std::endl;
  return 0;
}
