/*������ǻ�Ͱ��к� ����Ʈ�������
180078 ������*/

#include<iostream>

using namespace std;

void bubblesort(int data[],int n) //����
{
	int tmp;
	for(int j=0;j<n;j++) //���ڸ�ŭ ����
	for (int i = 0; i < n-1; i++)//0���� n-1������ ����
		if (data[i] > data[i + 1]) //���� ���� ���ڰ� �� ���ں��� ũ��
		{
			tmp = data[i];
			data[i] = data[i + 1];
			data[i + 1] = tmp;
		}//�����ٲ���
	
}
int main()
{
	int num;
	int *data;
	scanf("%d", &num);
	data = new int[num];

	for (int i = 0; i < num; i++)//�迭�� ���ڳִ´�
		scanf("%d", &data[i]);
	bubblesort(data, num);//�迭 ����

	for (int i = 0; i < num; i++)
		printf("%d ", data[i]);//�迭 ���
	delete[] data;
	return 0;
}