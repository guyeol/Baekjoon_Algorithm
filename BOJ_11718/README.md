Baekjoon Online Judge
=====================
## Problem #11718 그대로 출력하기
### 사용한 알고리즘
* 기본 입출력
* C++ 문법활용
	* std의 getline함수 활용
### 문제해결방안
* c++ 입출력 중 eof를 다루는 방법에 대해서 알아야 한다.
	* getline함수는 input stream 객체를 반환한다. (여기서는 cin) 하지만 eof를 만났을 때, eofbit flag가 업데이트 되어 더 이상 입력을 받지 않게 되는 점을 이용하여 구현한다.
