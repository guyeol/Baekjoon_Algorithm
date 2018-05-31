/*
 * Baekjoon Online Judge problem number 1026
 * Created by 정구열 on 2018. 5. 30..
 */

/*
 * 옛날 옛적에 수학이 항상 큰 골칫거리였던 나라가 있었다. 이 나라의 국왕 김지민은 다음과 같은 문제를 내고 큰 상금을 걸었다.
 * 길이가 N인 정수 배열 A와 B가 있다. 다음과 같이 함수 S를 정의하자.
 * S = A[0]*B[0] + ... + A[N-1]*B[N-1]
 * S의 값을 가장 작게 만들기 위해 A의 수를 재배열하자. 단, B에 있는 수는 재배열하면 안된다.
 * S의 최솟값을 출력하는 프로그램을 작성하시오.
 */

#include <iostream>

int A[50], B[50];
int N, sol;

void quicksort(int [], int, int);
void quicksort_back(int [], int, int);

int main(int argc, const char * argv[]) {
  
  //N 입력받기
  std::cin >> N;
  
  //A 배열, B 배열 입력받기
  for(int i = 0; i < N; i++) std::cin >> A[i];
  for(int i = 0; i < N; i++) std::cin >> B[i];
  
  //A, B배열 정렬
  quicksort(A, 0, N - 1);
  quicksort_back(B, 0, N - 1);
  
  sol = 0;
  for(int i = 0; i < N; i++) sol += A[i]*B[i];
  std::cout << sol <<std::endl;
  
  return 0;
}

void quicksort(int arr[], int left, int right) {
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
  if (left < j) quicksort(arr, left, j);
  if (i < right) quicksort(arr, i, right);
}

void quicksort_back(int arr[], int left, int right) {
  int i = left, j = right;
  int pivot = arr[(left + right) / 2];
  int temp;
  do {
    while (arr[i] > pivot)
      i++;
    while (arr[j] < pivot)
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
  if (left < j) quicksort_back(arr, left, j);
  if (i < right) quicksort_back(arr, i, right);
}
