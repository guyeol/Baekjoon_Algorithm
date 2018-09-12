/*
 * Baekjoon Online Judge problem # 1003
 * Algorithms using Dynamic Programming
 * fibonacci(3)을 호출하면 다음과 같은 일이 일어난다.
 * fibonacci(3)은 fibonacci(2)와 fibonacci(1) (첫 번째 호출)을 호출한다.
 * fibonacci(2)는 fibonacci(1) (두 번째 호출)과 fibonacci(0)을 호출한다.
 * 두 번째 호출한 fibonacci(1)은 1을 출력하고 1을 리턴한다.
 * fibonacci(0)은 0을 출력하고, 0을 리턴한다.
 * fibonacci(2)는 fibonacci(1)과 fibonacci(0)의 결과를 얻고, 1을 리턴한다.
 * 첫 번째 호출한 fibonacci(1)은 1을 출력하고, 1을 리턴한다.
 * fibonacci(3)은 fibonacci(2)와 fibonacci(1)의 결과를 얻고, 2를 리턴한다.
 * 1은 2번 출력되고, 0은 1번 출력된다. N이 주어졌을 때, fibonacci(N)을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.
 */

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
  int T, fib;
  int zero[40], one[40];
  zero[0] = 1; one[0] = 0;
  zero[1] = 0; one[1] = 1;
  
  cin >> T;
  for(int t = 1; t <= T; t++) {
    cin >> fib;
    if(fib == 0) cout << zero[0] << " "<< one[0] << endl;
    else if(fib == 1) cout << zero[1] << " " << one[1] << endl;
    else {
      for(int i = 2; i < fib; i++) {
        zero[i] = zero[i-1] + zero[i-2];
        one[i] = one[i-1] + one[i-2];
      }
      cout << zero[fib] << " " << one[fib] << endl;
    }
  }
  
  return 0;
}
