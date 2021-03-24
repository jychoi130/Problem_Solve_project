/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������*/
#include <iostream>
using namespace std;

const int MAX_TABLE_LENGTH = 10000; //0~9999���� ����� ���� ���� �� ����

void fillFrequencyTable(int data[], int n, int table[]) //������ �迭 �� üũ
{
	int frequent_number = 0; 
	for (int i = 0; i < MAX_TABLE_LENGTH; i++) //table �迭�� 0���� �ʱ�ȭ
		table[i] = 0;
	for (int i = 0; i < n; i++) //������ �迭�� ��ŭ for�� ����
	{
		frequent_number = data[i]; //�����Ͱ��� ������ ����
		table[frequent_number] += 1; //���� ���� table�� �ε����� ����Ͽ� +1���ش�.
		//�� 0-9999�� �ε����� ���� ���̺� �迭�� ���� �� ��ŭ +1�� ���༭ ������ ���ش�.
	}
}
int getFrequentNumber(int data[], int n)//���� ���� ���� �� ã��
{
	int frequent_number = 0;
	int table[MAX_TABLE_LENGTH]; 
	fillFrequencyTable(data, n, table); //� ���� ���Դ��� ���� üũ�ϴ� �Լ�
	for (int i = 0; i < MAX_TABLE_LENGTH; i++) //0~9999����
		if(table[i]>table[frequent_number]) //�� ���� ���� ���� �ε����� ������ ����
			frequent_number = i;
	return frequent_number;
}
int main()
{
	int n;
	cin >> n;

	int* data = new int[n]; //���� ������ŭ �迭 ����
	for (int i = 0; i < n; i++)
		cin >> data[i]; //�迭 �� �Է��� ��
	int answer = getFrequentNumber(data, n);
	printf("%04d", answer); //���� 4�ڸ��� ���
	delete[] data; //�迭 ����
	return 0;
}