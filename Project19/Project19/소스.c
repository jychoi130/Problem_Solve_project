#include<stdio.h> 

int main()
{
	int stack[8] = { NULL, };
	int topA = -1;
	int topB = 8;
	int x, y;
	while (1)
	{
		printf("���ÿ� ���� ���� ���� ���� ��ȣ(1,2)�� �Է��ϼ���: \n");
		scanf_s("%d %d", &x, &y);
		if (y == 1) //1�� ���ÿ� ���� ���� ���
		{
			topA++; //���� 1�� ž����Ʈ �̵�
			if (topA != topB) //���� 1�� ž�� ����2�� ž�� �������� ��
			{
				stack[topA] = x; //���� 1�� �� ����
			}
			if (topA == topB) //���� 1�� ž�� ����2�� ž�� ���� ��
			{
				printf("�����÷ο� �߻�!\n");
				if (topA == 0) //���� 1�� ������� ��
				{
					for (int i = 7; i > topB - 1; i--)
					{
						stack[i] = stack[i - 1]; //���� 2�� ù ���� ���� �� ����Ʈ
					}
					stack[topA] = x; //�� ������ �� ����
				}
				else //���� 1�� ������� ���� ��
				{
					for (int i = 0; i < topA; i++) //����1�� ù ���� ���� �� ����Ʈ 
					{
						stack[i] = stack[i + 1];
					}
					topA--;
					stack[topA] = x;
				}
			}
		}
		if (y == 2) //2�� ���ÿ� ���� ���� ���
		{
			topB--; //����2�� ž����Ʈ �̵�
			if (topA != topB) //���� 1�� ž�� ����2�� ž�� �������� ��
			{
				stack[topB] = x;
			}
			if (topA == topB) //���� 1�� ž�� ����2�� ž�� ���� ��
			{
				printf("�����÷ο� �߻�!\n");
				if (topB == 7) //���� 2�� ����� ��
				{
					for (int i = 0; i < topA; i++) //���� 1�� ù�� ���� �� ����Ʈ
					{
						stack[i] = stack[i + 1];
					}
					stack[topB] = x; //�� ������ �� ����
				}
				else //���� 2�� ������� ���� ��
				{
					for (int i = 7; i > topB; i--) //����2�� ù ���� ���� �� ����Ʈ 
					{
						stack[i] = stack[i - 1];
					}
					topB++;
					stack[topB] = x;
				}
			}
		}
		for (int i = 0; i < 8; i++) //���
		{
			if (stack[i] == NULL) //������� X�� ǥ��
				printf("X ");
			else printf("%d ", stack[i]);
		}
		printf("\n");
	}
}