/*전자컴퓨터공학부 소프트웨어공학
180078 최지연*/

#include<iostream>

using namespace std;

void bubblesort(int data[],int n) //정렬
{
	int tmp;
	for(int j=0;j<n;j++) //숫자만큼 돌림
	for (int i = 0; i < n-1; i++)//0부터 n-1번까지 돌림
		if (data[i] > data[i + 1]) //만약 전의 숫자가 뒷 숫자보다 크면
		{
			tmp = data[i];
			data[i] = data[i + 1];
			data[i + 1] = tmp;
		}//순서바꿔줌
	
}
int main()
{
	int num;
	int *data;
	scanf("%d", &num);
	data = new int[num];

	for (int i = 0; i < num; i++)//배열에 숫자넣는다
		scanf("%d", &data[i]);
	bubblesort(data, num);//배열 정렬

	for (int i = 0; i < num; i++)
		printf("%d ", data[i]);//배열 출력
	delete[] data;
	return 0;
}