//
//  main.cpp
//  BOJ_11719
//
//  Created by 정구열 on 2018. 5. 31..
//  Copyright © 2018년 guyeol_jeong. All rights reserved.
//

/*
 * 문제 *
 * 입력 받은 대로 출력하는 프로그램을 작성하시오
 * 입력 *
 * 입력이 주어진다. 입력은 최대 100줄로 이루어져 있고, 알파벳 소문자, 대문자, 공백, 숫자로만 이루어져있다.
 * 각 줄은 100글자를 넘지 않으며, 빈 줄이 주어질 수도 있고, 각 줄의 앞 뒤에 공백이 있을 수도 있다.
 */

#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {
  // insert code here...
  string line;
  while(!cin.eof()){
    getline(cin, line);
    cout << line << endl;
  }
  
  return 0;
}
