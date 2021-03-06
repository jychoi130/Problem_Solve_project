#include "pch.h"
#include <iostream>
#include <cstdio>

using namespace std;

void check(int doheight[], int domonth[], int num, int month)
{
	int tall = -1; //tall을 기본 값 -1로 초기화 시킨다.
	for (int i = 0; i < num; i++)
	{
		if (domonth[i] == month) //만약 설정한 달과 도토리의 달이 같으면
		{
			if (tall < doheight[i]) //tall값에 저장된 값과 도토리의 크기를 비교
				tall = doheight[i]; //큰 값을 tall에 넣는다.
		}
	}
	printf("\n이번 달 가장 큰 도토리는 : %d 이다.\n", tall);
}

int main()
{
	int num, month;
	int *doheight; 
	int *domonth;
	printf("도토리 개수를 입력하세요: ");
	scanf("%d", &num); //입력할 도토리의 개수를 설정한다.
	doheight = new int[num]; //도토리들의 키를 입력받는 배열 생성
	domonth = new int[num]; //도토리들의 생월을 입력받는 배열 생성

	printf("도토리 크기를 입력하세요: "); 
	for (int i = 0; i < num; i++) //0번 도토리부터 num번 도토리까지 키를 입력받는다.
		scanf("%d", &doheight[i]); 
	printf("도토리 생월을 입력하세요: "); //0번 도토리부터 num번 도토리까지 생월을 입력받는다.
	for (int j = 0; j < num; j++)
		scanf("%d", &domonth[j]);

	scanf("%d", &month); //현재 달을 설정한다.
	check(doheight, domonth, num, month); 

	delete[] doheight; //배열 삭제
	delete[] domonth; //배열 삭제
	return 0;
}