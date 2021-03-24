#include<stdio.h> 

int main()
{
	int stack[8] = { NULL, };
	int topA = -1;
	int topB = 8;
	int x, y;
	while (1)
	{
		printf("스택에 넣을 값과 넣을 스택 번호(1,2)를 입력하세요: \n");
		scanf_s("%d %d", &x, &y);
		if (y == 1) //1번 스택에 값을 넣을 경우
		{
			topA++; //스택 1의 탑포인트 이동
			if (topA != topB) //스택 1의 탑과 스택2의 탑이 같지않을 때
			{
				stack[topA] = x; //스택 1에 값 넣음
			}
			if (topA == topB) //스택 1의 탑과 스택2의 탑이 같을 때
			{
				printf("오버플로우 발생!\n");
				if (topA == 0) //스택 1이 비어있을 때
				{
					for (int i = 7; i > topB - 1; i--)
					{
						stack[i] = stack[i - 1]; //스택 2의 첫 값을 없앤 후 시프트
					}
					stack[topA] = x; //빈 공간에 값 삽입
				}
				else //스택 1이 비어있지 않을 때
				{
					for (int i = 0; i < topA; i++) //스택1의 첫 값을 없앤 후 시프트 
					{
						stack[i] = stack[i + 1];
					}
					topA--;
					stack[topA] = x;
				}
			}
		}
		if (y == 2) //2번 스택에 값을 넣을 경우
		{
			topB--; //스택2의 탑포인트 이동
			if (topA != topB) //스택 1의 탑과 스택2의 탑이 같지않을 때
			{
				stack[topB] = x;
			}
			if (topA == topB) //스택 1의 탑과 스택2의 탑이 같을 때
			{
				printf("오버플로우 발생!\n");
				if (topB == 7) //스택 2가 비었을 때
				{
					for (int i = 0; i < topA; i++) //스택 1의 첫값 없앤 후 시프트
					{
						stack[i] = stack[i + 1];
					}
					stack[topB] = x; //빈 공간에 값 삽입
				}
				else //스택 2이 비어있지 않을 때
				{
					for (int i = 7; i > topB; i--) //스택2의 첫 값을 없앤 후 시프트 
					{
						stack[i] = stack[i - 1];
					}
					topB++;
					stack[topB] = x;
				}
			}
		}
		for (int i = 0; i < 8; i++) //출력
		{
			if (stack[i] == NULL) //빈공간은 X로 표시
				printf("X ");
			else printf("%d ", stack[i]);
		}
		printf("\n");
	}
}