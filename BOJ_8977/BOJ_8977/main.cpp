//문제
//The game "display" is gaining popularity in casinos around the world. The game is run on a big screen visible to all players. A single integer is displayed on the screen, which changes every minute.
//
//The players attempt to determine the sum of K consecutive numbers, starting from the B-th displayed number. More precisely, if Xn is the n-th number displayed (starting with X1), then players try to determine the sum XB + XB+1 + ... + XB+K−1.
//
//Mirko is thrilled with this game and often spends five or six hours calculating sums and growing in debt. Recently he realized that the numbers on screen follow a precise pattern; the same sequence of N integers repeats over and over.
//
//Help Mirko to find the sought sum, given the sequence of number repeating.
//
//입력
//The first line contains three integers N, K and B, 1 ≤ N ≤ 100, 1 ≤ K ≤ 100, 1 ≤ B ≤ 109.
//
//The second line contains N non-negative integers less than 100, separated by spaces. This is the sequence that keeps repeating on screen.
//
//출력
//Output the sum on a single line.
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
  long long n, k, b;
  cin >> n >> k >> b;
  long long total = 0, ans = 0;
  vector<long long> vi(n);
  vector<long long> par_sum(n);
  for (int i = 0; i < n; i++){
    cin >> vi[i];
    total += vi[i];
  }
  b %= n;
  ans = (k / n) * total;
  k %= n;
  b--;
  if (b == -1) b = n - 1;
  for (int i = 0; i < k; i++)
    ans += vi[(b + i) % n];
  cout << ans << endl;
}
