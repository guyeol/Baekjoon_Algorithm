/*
 * Baekjoon Online Judge problem # 2750
 * Algorithm using Quick Sort Algorithm
 *
 * 문제 *
 * N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
 * 입력 *
 * 첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 절대값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.
 * 출력 *
 * 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
 */

#include <iostream>
int arr[1000], N;

void quickSort(int left, int right) {
  int i = left, j = right;
  int pivot = arr[(left + right) / 2];
  int temp;
  do {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i<= j) {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
  } while (i<= j);
  /* recursion */
  if (left < j)
    quickSort(left, j);
  
  if (i < right)
    quickSort(i, right);
}
int main(int argc, const char * argv[]) {
  std::cin >> N;
  for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
  quickSort(0, N-1);
  for(int i = 0; i < N; i++) printf("%d\n", arr[i]);
  return 0;
}
