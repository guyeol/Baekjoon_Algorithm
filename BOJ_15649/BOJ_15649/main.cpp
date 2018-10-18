/*
 * Baekjoon Online Judge problem # 15649
 * Algorithm using Permutation
 * N과 M
 문제
 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
 
 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
 입력
 첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)
 
 출력
 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
 
 수열은 사전 순으로 증가하는 순서로 출력해야 한다.
 */
#include <iostream>

void swap(int *, int, int);
void print_arr(int *, int);

void perm(int *arr, int len, int n, int k) {
  if(len == k) {
    print_arr(arr, len);
    return;
  }
  for(int i = len; i < n; i++) {
    swap(arr, len, i);
    perm(arr, len + 1, n, k);
    swap(arr, len, i);
  }
}

void swap(int *arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
void print_arr(int *arr, int k) {
  for (int i = 0; i < k; i++) {
    if (i == k - 1)
      printf("%d\n", arr[i]);
    else
      printf("%d ", arr[i]);
  }
}
int main() {
  int N, M;
  int arr[8];
  scanf("%d %d", &N, &M);
  for(int i = 1; i <= N; i++) arr[i-1] = i;
  perm(arr, 0, N, M);
  return 0;
}
