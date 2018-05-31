//
//  main.cpp
//  BOJ_10699
//
//  Created by 정구열 on 2018. 5. 31..
//  Copyright © 2018년 guyeol_jeong. All rights reserved.
//

/*
 * 서울의 오늘 날짜를 출력하는 프로그램을 작성하시오.
 */

#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, const char * argv[]) {
  
  //시간 관련 구조체 tm 선언
  struct tm* datetime;
  
  // 현재 시간 가져오기
  time_t t = time(NULL);
  datetime = localtime(&t);
  
  cout << datetime->tm_year + 1900 << "-" << "0" << datetime -> tm_mon + 1 <<
    "-" << datetime -> tm_mday << endl;
  return 0;
}
