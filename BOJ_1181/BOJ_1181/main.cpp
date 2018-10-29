//문제
//알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.
//
//길이가 짧은 것부터
//길이가 같으면 사전 순으로
//입력
//첫째 줄에 단어의 개수 N이 주어진다. (1≤N≤20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 주어지는 문자열의 길이는 50을 넘지 않는다.
//
//
//출력
//조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
bool comp(string a,string b){
  return a.length()<b.length();
}
bool comp2(string a,string b){
  return strcmp(a.c_str(), b.c_str())>=0?false:true;
}
int main(int argc, const char * argv[]) {
  int n;
  cin>>n;
  vector<string> vstr;
  while(n--){
    string str;
    cin>>str;
    vstr.push_back(str);
  }
  sort(vstr.begin(),vstr.end(),comp);
  int i=0;
  while(i!=vstr.size()){
    int l=(int)vstr[i].length();
    vector<string> temp;
    temp.push_back(vstr[i]);
    i++;
    while(vstr[i].length()==l)
      temp.push_back(vstr[i++]);
    sort(temp.begin(),temp.end(),comp2);
    cout<<temp[0]<<'\n';
    for(int j=1;j<temp.size();j++){
      if(temp[j]!=temp[j-1])
        cout<<temp[j]<<'\n';
    }
  }
  return 0;
}
