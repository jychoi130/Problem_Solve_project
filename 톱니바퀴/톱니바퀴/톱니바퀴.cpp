/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������*/
#include<iostream>
using namespace std;

void Spin(int num,int w1[],int w2[],int w3[],int w4[])
{
	int spinDirection,spinWheel,forcheck[3];
	for (int i = 0; i < num; i++)
	{
		cout << "�� ��° ������ ��� �������� �����ǰ���?" << endl;
		cin >> spinWheel >> spinDirection;
		{
			if (w1[2] == w2[6])
				forcheck[0] = 0;
			else forcheck[0] = 1;
			if (w2[2] == w3[6])
				forcheck[1] = 0;
			else forcheck[1] = 1;
			if (w3[2] == w4[6])
				forcheck[2] = 0;
			else forcheck[2] = 1;
		}//���� ������ Ȯ��
//		checkforspin(w1, w2, w3, w4, spinWheel, spinDirection,forcheck);
	}
}
void forPut(int w1[], int w2[], int w3[], int w4[],int forput[])
{
	for (int i = 0; i < 8; i++)
		forput[i] = w1[i];
	for (int i = 0; i < 8; i++)
		forput[i + 8] = w2[i];
	for (int i = 0; i < 8; i++)
		forput[i + 16] = w3[i];
	for (int i = 0; i < 8; i++)
		forput[i + 24] = w4[i];
}
void checkforspin(int w1[],int w2[],int w3[],int w4[],int w,int dir,int c[])
{
	int tmp,forput[32];
	forPut(w1, w2, w3, w4, forput);
	if (w == 1)
	{
		if (dir == 1)
		{
			if (c[0] == 0) //�� ó������ ������ �ȳ���
			{
				for (int i =1; i < 8; i++)
					w1[i] = forput[i - 1];
				w1[0] = forput[7];

			}//ȸ�� ù ��°��
			else//ó�� ����
			{
				if (c[1] == 0) //ó���� ����,ù ���� ȸ��,�� ��° ������ �ݴ�� ȸ��
				{
					for (int i = 1; i < 8; i++)
						w1[i] = forput[i - 1];
					w1[0] = forput[7];
					for (int i = 0; i < 7; i++)
						w2[i] = forput[i + 9];
					w2[7] = forput[8];
				}
				else //�ι�°�� ���� 
				{
					if (c[2] == 0) //����°�� �Ȱ���,��, �� ��° ���� ȸ��
					{
						for (int i = 1; i < 8; i++)
							w1[i] = forput[i - 1];
						w1[0] = forput[7];
						for (int i = 0; i < 7; i++)
							w2[i] = forput[i + 9];
						w2[7] = forput[8];
						for (int i = 1; i < 8; i++)
							w3[i] = forput[i + 15];
						w3[0] = forput[23];
					}
					else//����°�� ���� //��ü ȸ��
					{
						for (int i = 1; i < 8; i++)
							w1[i] = forput[i - 1];
						w1[0] = forput[7];
						for (int i = 0; i < 7; i++)
							w2[i] = forput[i + 9];
						w2[7] = forput[8];
						for (int i = 1; i < 8; i++)
							w3[i] = forput[i + 15];
						w3[0] = forput[23];
						for (int i = 0; i < 7; i++)
							w4[i] = forput[i+25];
						w4[7] = forput[24];
					}
				}
			}
		}
		
		if (dir == -1)
		{
			if (c[0] == 0) //�� ó������ ������ �ȳ���
			{
				for (int i = 0; i < 7; i++)
					w1[i] = forput[i + 1];
				w1[7] = forput[0];

			}//ȸ�� ù ��°��
			else//ó�� ����
			{
				if (c[1] == 0) //ó���� ����,ù ���� ȸ��,�� ��° ������ �ݴ�� ȸ��
				{
					for (int i = 0; i < 7; i++)
						w1[i] = forput[i + 1];
					w1[7] = forput[0];
					for (int i = 1; i < 8; i++)
						w2[i] = forput[i + 7];
					w2[0] = forput[15];
				}
				else //�ι�°�� ���� 
				{
					if (c[2] == 0) //����°�� �Ȱ���,��, �� ��° ���� ȸ��
					{
						for (int i = 0; i < 7; i++)
							w1[i] = forput[i + 1];
						w1[7] = forput[0];
						for (int i = 1; i < 8; i++)
							w2[i] = forput[i + 7];
						w2[0] = forput[15];
						for (int i = 0; i < 7; i++)
							w3[i] = forput[i + 17];
						w3[7] = forput[16];
					}
					else//����°�� ���� //��ü ȸ��
					{
						for (int i = 0; i < 7; i++)
							w1[i] = forput[i + 1];
						w1[7] = forput[0];
						for (int i = 1; i < 8; i++)
							w2[i] = forput[i + 7];
						w2[0] = forput[15];
						for (int i = 0; i < 7; i++)
							w3[i] = forput[i + 17];
						w3[7] = forput[16];
						for (int i = 1; i < 8; i++)
							w4[i] = forput[i + 23];
						w4[0] = forput[31];
					}
				}
			}
		}
	}
	else if (w == 2) //�� ��° ���� ����
	{
		if (dir == 1)
		{

		}
		if (dir == -1)
		{

		}
	}
	else if (w == 3)
	{
		if (dir == 1)
		{

		}
		if (dir == -1)
		{

		}
	}
	else
	{
		if (dir == 1)
		{

		}
		if (dir == -1)
		{

		}
	}
	forPut(w1, w2, w3, w4, forput);
	for (int i = 0; i < 8; i++)
		cout << w1[i];
	cout << endl;
	for (int i = 0; i < 8; i++)
		cout << w2[i];
	cout << endl;
	for (int i = 0; i < 8; i++)
		cout << w3[i];
	cout << endl;
	for (int i = 0; i < 8; i++)
		cout << w4[i];
}


int main()
{
	int spinnum, wheel1[8], wheel2[8], wheel3[8], wheel4[8];
	{
		cout << "ù ��° ��Ϲ��� ����(0,1�߿� ����)" << endl;
		for (int i = 0; i < 8; i++)
			cin >> wheel1[i];
		cout << "�� ��° ��Ϲ��� ����(0,1�߿� ����)" << endl;
		for (int i = 0; i < 8; i++)
			cin >> wheel2[i];
		cout << "�� ��° ��Ϲ��� ����(0,1�߿� ����)" << endl;
		for (int i = 0; i < 8; i++)
			cin >> wheel3[i];
		cout << "�� ��° ��Ϲ��� ����(0,1�߿� ����)" << endl;
		for (int i = 0; i < 8; i++)
			cin >> wheel4[i];
	} //��������
	cin >> spinnum;//ȸ�� Ƚ�� ����
	Spin(spinnum,wheel1,wheel2,wheel3,wheel4);
	

	return 0;
}