Baekjoon Online Judge
=====================
## Problem #2846 오르막길
### 사용한 알고리즘
* 배열
### 문제해결방안
* 아이디어 자체는 굉장히 쉽다. 푸는 방법은 여러가지가 있겠으나 내가 택한 방법은 오름 수 일때 (i번째 수가 i-1번째 수보다 큰 경우) 두 수의 차를 계속 더해가는 것이다. 더해가다가 오름 수 가 아닐 시, 이 전 오름수들의 차이와 비교해 그 중 최대 값으로 업데이트하면 된다.
  * 쉬운데 계속 틀렸습니다가 떴는데, 원인은 마지막 수를 검사할 때 였다. 마지막 수가 오름 수 이고, 그 수가 최대값인 경우인데, 마지막이다 보니 최대값을 업데이트 시키지 않고 반복문을 빠져나오는일이 발생하였다. 앞으로는 꼼꼼하게. 예외상황을 계속 생각해보며 반례를 찾아보는 연습을 해보자.