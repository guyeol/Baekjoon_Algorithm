/*
 * Baekjoon Online Judge Problem # 11048
 * Alogorithm using DYNAMIC PROGRAMMING
 *
 * 문제 *
 * 준규는 N×M 크기의 미로에 갇혀있다. 미로는 1×1크기의 방으로 나누어져 있고, 각 방에는 사탕이 놓여져 있다.
 * 미로의 가장 왼쪽 윗 방은 (1, 1)이고, 가장 오른쪽 아랫 방은 (N, M)이다.
 *
 * 준규는 현재 (1, 1)에 있고, (N, M)으로 이동하려고 한다. 준규가 (r, c)에 있으면,
 * (r+1, c), (r, c+1), (r+1, c+1)로 이동할 수 있고, 각 방을 방문할 때마다 방에 놓여져있는 사탕을 모두 가져갈 수 있다.
 * 또, 미로 밖으로 나갈 수는 없다.
 * 준규가 (N, M)으로 이동할 때, 가져올 수 있는 사탕 개수의 최대값을 구하시오.
 *
 * 입력 *
 * 첫째 줄에 미로의 크기 N, M이 주어진다. (1 ≤ N, M ≤ 1,000)
 *
 * 둘째 줄부터 N개 줄에는 총 M개의 숫자가 주어지며, r번째 줄의 c번째 수는 (r, c)에 놓여져 있는 사탕의 개수이다.
 * 사탕의 개수는 0보다 크거나 같고, 100보다 작거나 같다.
 *
 * 출력 *
 * 첫째 줄에 준규가 (N, M)으로 이동할 때, 가져올 수 있는 사탕 개수를 출력한다.
 */

#include <iostream>

#define MAX_N 1000
#define MAX_M 1000

int main(int argc, const char * argv[]) {
  int n, m;
  int maze[MAX_N][MAX_M];
  int dp[MAX_N][MAX_M] = {0};
  std::cin >> n >> m;
  
  //NxM 미로 입력받기
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++)
      std::cin >> maze[i][j];
  }
  //시작점 초기화
  dp[0][0] = maze[0][0];
  //DP를 이용하여 최대 사탕갯수 업데이트
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if((dp[i][j+1] < dp[i][j] + maze[i][j+1]) && (j + 1) != m)
        dp[i][j+1] = dp[i][j] + maze[i][j+1]; // (r, c+1)의 최댓값
      if(dp[i+1][j] < dp[i][j] + maze[i+1][j] && (i + 1) != n)
        dp[i+1][j] = dp[i][j] + maze[i+1][j]; // (r+1, c)의 최댓값
      if(dp[i+1][j+1] < dp[i][j] + maze[i+1][j+1] && (j + 1) != m && (i + 1) != n)
       dp[i+1][j+1] = dp[i][j] + maze[i+1][j+1]; // (r+1, c+1)의 최댓값
    }
  }
  std::cout << dp[n-1][m-1] << std::endl;
  return 0;
}
