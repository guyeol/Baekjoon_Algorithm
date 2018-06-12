
/*
 * Baekjoon Online Judge Problem # 1520
 * Algorithm using DYNAMIC PROGRAMMING & DFS
 *
 * 문제 *
 * 여행을 떠난 세준이는 지도를 하나 구하였다. 이 지도는 아래 그림과 같이 직사각형 모양이며 여러 칸으로 나뉘어져 있다.
 * 한 칸은 한 지점을 나타내는데 각 칸에는 그 지점의 높이가 쓰여 있으며, 각 지점 사이의 이동은 지도에서 상하좌우 이웃한 곳끼리만 가능하다.
 * 현재 제일 왼쪽 위 칸이 나타내는 지점에 있는 세준이는 제일 오른쪽 아래 칸이 나타내는 지점으로 가려고 한다.
 * 그런데 가능한 힘을 적게 들이고 싶어 항상 높이가 더 낮은 지점으로만 이동하여 목표 지점까지 가고자 한다.
 * 위와 같은 지도에서는 다음과 같은 세 가지 경로가 가능하다.
 * 지도가 주어질 때 이와 같이 제일 왼쪽 위 지점에서 출발하여 제일 오른쪽 아래 지점까지
 * 항상 내리막길로만 이동하는 경로의 개수를 구하는 프로그램을 작성하시오.
 *
 * 입력 *
 * 첫째 줄에는 지도의 세로의 크기 M과 가로의 크기 N이 빈칸을 사이에 두고 주어진다.
 * 이어 다음 M개 줄에 걸쳐 한 줄에 N개씩 위에서부터 차례로 각 지점의 높이가 빈 칸을 사이에 두고 주어진다.
 * M과 N은 각각 500이하의 자연수이고, 각 지점의 높이는 10000이하의 자연수이다.
 *
 * 출력 *
 * 첫째 줄에 이동 가능한 경로의 수 H를 출력한다. 모든 입력에 대하여 H는 10억 이하의 음이 아닌 정수이다.
 */

#include <iostream>

#define MAX_M 10
#define MAX_N 10

void dfs(int x, int y) {
  
}

int main(int argc, const char * argv[]) {
  int M, N;
  int dp[MAX_M][MAX_N] = {0};
  int map[MAX_M][MAX_N];
  int visited[MAX_M][MAX_N];
  
  std::cin >> M >> N;
  
  //지도 초기화
  for(int i = 0; i < M; i++)
    for(int j = 0; j < N; j++)
      std::cin >> map[i][j];
  dp[0][0] = 1;
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++) {
      //(i, j)가 0이 아닐때만 카운트 가능
      if(dp[i][j]) {
        // 오른쪽으로 이동 가능한가
        if(map[i][j] > map[i][j+1] && (j + 1) < N)
          dp[i][j+1] ++;
        // 왼쪽으로 이동 가능한가
        if(map[i][j] > map[i][j-1] && (j - 1) > 0)
          dp[i][j-1] ++;
        // 밑으로 이동 가능한가
        if(map[i][j] > map[i+1][j] && (i + 1) < M)
          dp[i+1][j] ++;
        //위로 이동 가능한가
        if(map[i][j] > map[i-1][j] && (i - 1) > 0)
          dp[i-1][j] ++;
      }
    }
  }
  std::cout << dp[M-1][N-1] << std::endl;
  return 0;
}
