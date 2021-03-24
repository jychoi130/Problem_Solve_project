/*전자컴퓨터공학부 소프트웨어공학
180078 최지연*/
#include <iostream>
using namespace std;

int main()
{
	int a, b, count = 1;
	cin >> a >> b;

	while (a < b) {//a<b보다 작을 때
		if (b % 10 == 1) {//b의 맨 뒷자리 수 확인해서 1이면 
			b = (b - 1) / 10; //1떼는 연산 실행
			count++; //연산횟수 증가
		}
		else if (b % 2 == 0) { //만약 2로 나눠지면
			b /= 2; //2로 나누는 연산 실행
			count++; //연산 횟수 증가
		}
	}
	if (a == b) { //둘이 같아지면
		printf("%d", count); //연산횟수 출력
	}
	else { //연산이 안될경우 -1출력
		printf("-1");
	}
}