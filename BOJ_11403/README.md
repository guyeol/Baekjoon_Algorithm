Baekjoon Online Judge
=====================
## Problem #11403 경로찾기
### 사용한 알고리즘
* 플로이드-와샬 알고리즘
### 문제해결방안
* 이 문제는 주어진 그래프의 모든 경로를 찾는 문제이다.
  * 이 문제를 풀 수 있는 여러가지 그래프 알고리즘이 존재한다.
  * 예를 들면 그래프 알고리즘에 대표인 dfs와 bfs를 이용하는 방법
* 플로이드-와샬 알고리즘은 모든 정점에서 다른 정점간의 최소 거리를 구하는 알고리즘으로 3중 포문으로 구성되어 O(v^3)의 시간 복잡도를 갖는다.
  * 다른 알고리즘에 비해 시간이 오래걸릴 수 있으나, 모든 정점사이의 경로를 구할 수 있고 음수 가중치에 대해서도 해결할 수 있다.
  * 다이나믹 프로그래밍과 비슷하다. 반복문을 돌면서 지난 값과 비교하여 최소값을 계속 업데이트 시킨다.
  * 이 문제는 가중치가 전부 1이고, 최소값을 굳이 찾지 않아도 되기에 (정점사이의 연결성만 판단하면 됨) 좀 더 간단하다.
  * 플로이드-와샬 알고리즘은 연결되지 않는 정점의 값으로 무한대값을 넣는다. (이론상 무한대지 필요 이상의 값을 넣어주기만 하면 됨 여기선 어떤 경우에도 100을 넘지 않으므로 최댓값을 100으로 정했다.)