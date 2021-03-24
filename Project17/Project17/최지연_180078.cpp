/* 전자컴퓨터공학부 소프트웨어학과
180078 최지연*/

#include <iostream>

using namespace std;

void winner(int people[], int num, int win) //이긴사람의 인덱스 찾기: 가위바위보 있는 배열,사람 수, 이긴 선택지
{
	for (int i = 0; i < num; i++) //인덱스 찾기위한 for문
		if (people[i] == win) //배열의 값과 이긴 선택지의 값이 동일하면
			cout << i << " ";
}
void check(int people[], int num)//가위바위보 이긴 쪽 판단
{
	int r = 0, s = 0, p = 0; //가위 바위 보 각각 개수 세기위한 변수
	int win;
	for (int i = 0; i < num; i++) //가위 바위 보 숫자 세기
	{
		if (people[i] == 0) //가위면 s변수 1개씩 올림
			s++;
		else if (people[i] == 1) //바위면 r변수 1개씩 올림
			r++;
		else if (people[i] == 2) //보면 p변수 1개씩 올림
			p++;
	}
	if (r > 0 && s > 0 && p > 0 || r == 0 && s == 0 || s == 0 && p == 0 || r == 0 && p == 0)
	{
		cout << endl << "비김" << endl;
	}
	else if (s == 0) { // 가위가 없을 경우
		cout << "index : ";
		for (int i = 0; i < num; i++) {
			if (people[i] == 2) cout << i << "  ";
		}
	}
	else if (p == 0) { // 보가 없을 경우
		cout << "index : ";
		for (int i = 0; i < num; i++) {
			if (people[i] == 1) cout << i << "  ";
		}
	}
	else if (r == 0) { // 바위가 없을 경우
		cout << "index : ";
		for (int i = 0; i < num; i++) {
			if (people[i] == 0) cout << i << "  ";
		}
	}
}

int main()
{
	int num; //사람 수
	int* people; //입력값 정수로 변환해서 저장할 배열
	char a[20]; //가위바위보 값 입력받을 배열

	cin >> num;
	people = new int[num]; //사람 수에 맞춰 정수형 배열 생성

	for (int i = 0; i < num; i++) //사람 수 맞춰 for문
	{
		cin >> a;
		if (strcmp(a, "가위") == 0) //입력 값이 가위일 경우 
			people[i] = 0; //정수형 배열에 0입력
		else if (strcmp(a, "바위") == 0)//입력값이 바위일 경우
			people[i] = 1; //정수형 배열에 1입력
		else if (strcmp(a, "보") == 0) //입력값이 보일경우
			people[i] = 2;//정수형 배열에 2입력
	}

	check(people, num); //이긴 사람 확인하는 함수 돌림

	return 0;
}