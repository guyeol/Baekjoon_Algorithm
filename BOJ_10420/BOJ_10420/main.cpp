//문제
//세계적으로 유명한 커플 상근이와 나예는 2016년 4월 3일이 사귀기 시작한지 200일이 되는 날이었다. 상근이는 그 날이 200일인줄 몰라서 나예한테 혼났다. 이런 일이 다시는 없도록 하기 위해서 기념하려고 하는 날 수가 양의 정수로 주어지면 기념일 날짜를 출력하는 프로그램을 작성하여 다시는 혼나는 일이 없도록 하려 한다. 이 커플의 사귀기 시작한 날짜는 2015년 9월 17일이다. 하지만, 알 수 없는 이유에 의해서 문제를 풀 때는 사귀기 시작한 날짜를 2014년 4월 2일로 처리해야 한다.
//
//2월이 28일까지 있는 년을 평년이라 하고, 29일까지 있는 년을 윤년이라 한다. 윤년은 연도가 4의 배수이면서, 100의 배수가 아닐 때 또는 400의 배수일 때이다. 예를들어 1900년은 4의 배수이지만 100의 배수이기 때문에 윤년이 아니다. 하지만 2000년은 400의 배수이기 때문에 윤년이다.
//
//입력
//첫째 줄에 기념하려는 날이 양의 정수 N (1 ≤ N ≤ 10,000)으로 주어진다.
//
//출력
//첫째 줄에 기념일의 날짜를 YYYY-MM-DD 의 형식으로 출력한다.

#include <iostream>
using namespace std;

class anniversary {
private:
  int year;
  int month;
  int day;
public:
  string getAnniversary(int foretime) {
    year = 2014; month = 1; day = 1;
    int daysFromNewYear = 31 + 28 + 31 + 2 + foretime;
    while(true){
      int curDaysInYear = getDaysOfYear(year);
      int curDaysInMonth = getNumOfDaysInMonth(year, month);
      if(daysFromNewYear >= curDaysInYear) {
        daysFromNewYear -= curDaysInYear;
        year += 1;
      }
      else if (daysFromNewYear >= curDaysInMonth) {
        daysFromNewYear -= curDaysInMonth;
        if(month == 12)
          month = 1;
        else
          month += 1;
      } else {
        day = daysFromNewYear - 1;
        break;
      }
    }
    return toString();
  };
  
  bool isLeapYear(int _year) {
    if((_year % 4) == 0 && (_year % 100) != 0) return true;
    if((_year % 400) == 0) return true;
    else return false;
  }
  
  int getDaysOfYear(int _year) {
    if(isLeapYear(_year)) return 366;
    else return 365;
  }
  
  int getNumOfDaysInMonth(int _year, int _month) {
    if(_month == 1 || _month == 3 || _month == 5 || _month == 7
       || _month == 8 || _month == 10 || _month == 12) return 31;
    else if(_month == 2) {
      if(isLeapYear(_year)) return 29;
      else return 28;
    } else return 30;
  }
  string toString() {
    string date;
    date += to_string(year);
    if (month < 10) date += "-0" + to_string(month);
    else date += "-" + to_string(month);
    if (day < 10) date += "-0" + to_string(day);
    else date += "-" + to_string(day);
    return date;
  }
};

int main(int argc, const char * argv[]) {
  int days;
  anniversary a;
  cin >> days;
  cout << a.getAnniversary(days) << endl;
  return 0;
}
