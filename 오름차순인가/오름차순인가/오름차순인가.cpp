#include "pch.h"
#include <iostream>
#include <cstdio>

using namespace std;

int check(int data[],int num)
{
	int look = data[0]; //look에 첫 값 저장
	int a;
	for (int i = 0; i < num; i++) 
	{
		if (look > data[i]) //만약 look의 값보다 data의 i인덱스값이 작을경우
		{
			a = 0; //a=0으로 설정
			break; //for문 나감
		}
		else
		{
			look = data[i]; //look값을 바꿔줌
			a = 1; //a=1으로 설정
		}
	}
	return a; //a값을 돌려줌
}

int main()
{
	int num,answer;
	int *data;
	
	scanf("%d", &num);
	data = new int[num]; //num크기의 배열을 생성

	for (int i = 0; i < num; i++) //배열에 값을 넣는다.
		scanf("%d", &data[i]);

	answer=check(data, num); //받은 값을 answer에 넣어줌.
	if (answer == 0) //answer값이 0이면
		printf("\nNO\n");
	else printf("\nYES\n"); //answer값이 0이 아니면

	delete[] data;

	return 0;
}