/* 전자컴퓨터공학부 소프트웨어학과
180078 최지연*/

#include "pch.h"
#include <iostream>
#include <time.h>
#include<string.h>
using namespace std;

void winner(int people[], int num, int win) //이긴사람의 인덱스 찾기: 가위바위보 있는 배열,사람 수, 이긴 선택지
{
	for (int i = 0; i < num; i++) //인덱스 찾기위한 for문
		if (people[i] == win) //배열의 값과 이긴 선택지의 값이 동일하면
			printf("%d ", i);//인덱스 출력
}
void check(int people[],int num)//가위바위보 이긴 쪽 판단
{
	int r = 0, s = 0,p=0; //가위 바위 보 각각 개수 세기위한 변수
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
	if (s > 0) //가위가 한개 이상
	{
		if (r > 0) //주먹 한개 이상
		{ 
			if (p > 0) //보 한개이상
				printf("\ndraw\n"); //각각 하나씩 있으므로 무승부
			else if (p == 0) //가위랑 주먹만 있는 경우
			{
				win = r; //이긴 사람 주먹
				winner(people, num, 1); //주먹인 인덱스 찾기
			}
		}
		if (r == 0) //주먹 없는 경우
		{
			if (p > 0) //가위랑 보만 있는 경우
			{
				win = s; //이긴 사람 가위
				winner(people, num, 0); //가위인 인덱스 찾기
			}
			else if (p == 0) //가위만 있는 경우
				printf("\ndraw\n");//무승부
		}
	}
	if (s == 0) //가위 없는 경우
	{
		if (r > 0)//주먹은 있는 경우
		{
			if (p > 0) //주먹 보 있는 경우
			{
				win = p; //이긴 사람은 보
				winner(people, num, 2); //보 낸 사람 인덱스 찾기
			}
			else if (p == 0) //주먹만 있는 경우
				printf("\ndraw\n"); //무승부
		}
		if (r == 0) //가위랑 주먹 없는 경우
		{
			if (p > 0) //보만 있는 경우
				printf("\ndraw\n"); //무승부
		}
	}
}


int main()
{
	clock_t start = clock(); //프로그램 실행 시간 확인
	int num; //사람 수
	int*people; //입력값 정수로 변환해서 저장할 배열
	char a[20]; //가위바위보 값 입력받을 배열

	scanf("%d", &num); //사람 수 입력
	people = new int[num]; //사람 수에 맞춰 정수형 배열 생성
	
	for (int i = 0; i < num; i++) //사람 수 맞춰 for문
	{
		scanf("%s", &a); //가위 바위 보 중 입력
		if(strcmp(a, "가위") ==0) //입력 값이 가위일 경우 
			people[i] = 0; //정수형 배열에 0입력
		else if (strcmp(a, "바위") == 0)//입력값이 바위일 경우
			people[i] = 1; //정수형 배열에 1입력
		else if (strcmp(a, "보") == 0) //입력값이 보일경우
			people[i] = 2;//정수형 배열에 2입력
	}
	
	check(people, num); //이긴 사람 확인하는 함수 돌림
	clock_t end = clock(); //시간 측정 끝
	printf("\nTime : %lf\n", (double)(end - start) / CLOCKS_PER_SEC); //시간 측정 계산
	return 0;
}
