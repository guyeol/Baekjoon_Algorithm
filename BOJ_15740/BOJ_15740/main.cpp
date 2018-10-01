//문제
//두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 A와 B (-10^10000 ≤ A, B ≤ 10^10000)가 주어진다.
//
//출력
//첫째 줄에 A+B를 출력한다.

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
  string A, B;
  vector<int> ans;
  cin >> A >> B;
  bool aIsNeg = false, bIsNeg = false;
  int aL = (int)A.length(), bL = (int)B.length();
  int c = 0;
  if(A[aL -1] == '-') aIsNeg = true;
  if(B[bL -1] == '-') bIsNeg = true;
  for(int i = 0; i < max(aL, bL); i++) {
    int a = A[aL - 1 - i] - '0';
    int b = B[bL - 1 - i] - '0';
    ans.push_back((a + b + c) % 10);
    //for(vector<int>::iterator it = ans.begin(); it!= ans.end(); it++) cout << *it;
    if(a + b >= 10) c = 1;
    else c = 0;
  }
  if(c == 1) ans.push_back(1);
  for(vector<int>::reverse_iterator rit = ans.rbegin(); rit!= ans.rend(); rit++) cout << *rit;
  return 0;
}
