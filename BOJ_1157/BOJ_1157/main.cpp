//
//  main.cpp
//  BOJ_1157
//
//  Created by 정구열 on 2018. 10. 25..
//  Copyright © 2018년 guyeol_jeong. All rights reserved.
//

#include<iostream>
#include<string>
using namespace std;
int main(){
  string s;
  int alph[26]={0};
  int max=0,maxCnt=0;
  char mc='?';
  cin>>s;
  for(int i=0;i<s.length();i++){
    char c=s[i];
    int a=c;
    if(a>96) alph[a-97]++;
    else alph[a-65]++;
  }
  for(int i=0;i<26;i++){
    if(alph[i]>max) {
      max=alph[i];
      mc=i+65;
    }
  }
  for(int i=0;i<26;i++){
    if(alph[i]==max) maxCnt++;
  }
  
  (maxCnt==1)?cout<<mc:cout<<'?';
  return 0;
}
