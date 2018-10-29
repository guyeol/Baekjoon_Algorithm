

#include<iostream>
using namespace std;
int main(){
  string a;
  int al[26];
  for(int i=0;i<26;i++)al[i]=-1;
  cin>>a;
  for(int i=0;i<a.length();i++){
    int asc=a[i];
    if(al[asc-97]==-1) al[asc-97]=i;
    else continue;
  }
  for(int i=0;i<26;i++) cout<<al[i]<<" ";
  return 0;
}
