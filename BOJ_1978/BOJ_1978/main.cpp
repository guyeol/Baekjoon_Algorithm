//문제
//주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.
//
//입력
//첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.
//
//출력
//주어진 수들 중 소수의 개수를 출력한다.

#include <iostream>
bool isPrime(int n){
  if(n==1) return false;
  if(n==2) return true;
  else {
    for(int i=2;i<=(n/2)+1;i++){
      if((n%i)==0) return false;
    }
    return true;
  }
}
int main(int argc, const char * argv[]) {
  int n,cnt=0,a;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a);
    if(isPrime(a)) cnt++;
  }
  printf("%d",cnt);
  return 0;
}
