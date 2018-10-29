//이와 같이 나열된 분수들을 1/1 -> 1/2 -> 2/1 -> 3/1 -> 2/2 -> … 과 같은 지그재그 순서로 차례대로 1번, 2번, 3번, 4번, 5번, … 분수라고 하자.
//
//X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 X(1 ≤ X ≤ 10,000,000)가 주어진다.
//
//출력
//첫째 줄에 분수를 출력한다.

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
  int n;
  int i=1;
  cin>>n;
  while(true){
    if(n<=0){
      break;
    } else
      n-=i++;
  }
  i-=1;
  n*=-1;
  if(i%2==0){
    int a=i;
    int b=1;
    for(int k=1;k<=n;k++){
      a-=1;
      b+=1;
    }
    cout<<a<<"/"<<b<<'\n';
  } else {
    int a=1;
    int b=i;
    for(int k=1;k<=n;k++){
      a+=1;
      b-=1;
    }
    cout<<a<<"/"<<b<<'\n';
  }
  return 0;
}
