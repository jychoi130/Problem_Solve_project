/*전자컴퓨터공학부 소프트웨어공
180078 최지연
중복 제거하기*/

#include<iostream>
#include<set>
using namespace std;

int main() {
	int N;
	cin >> N; //몇 개의 변수를 받을지 설정
	set<int>s; //int형 set변수 선언

	for (int i = 0; i < N; i++) {
		int X;
		cin >> X; //N개의 개수 만큼 정수를 받는다
		
		if (s.count(X) > 0) { //만약 같은 값이 존재하면
			printf("Duplicated\n");//Duplicated 출력
		}
		else { //같은 값이 존재하지 않으면
			s.insert(X); //그 값을 set에 넣은 후
			printf("OK\n");//OK 출력
		}
	}
	return 0;
}