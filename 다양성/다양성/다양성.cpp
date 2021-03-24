#include "pch.h"
#include <iostream>


void counting(int data[], int num)
{
	int count = 0;
	for (int i = 0; i < num; i++)
	{
		if (data[i] != data[i + 1]) //만약 i인덱스의 값과 다음 값이 같지않으면
			count++; //count값을 하나 올려준다.
	 }
	printf("\n%d개 입니다.\n", count);
}
int main()
{
	int num;
	int *data;

	printf("앨범의 갯수를 입력하세요: ");
	scanf("%d", &num);
	data = new int[num];

	printf("화보의 고유번호를 입력하세요: ");
	for(int i=0;i<num;i++) //앨범의 개수만큼 화보의 고유번호 입력
		scanf("%d", &data[i]);
	
	counting(data, num);

	delete[] data;
	return 0;
}
