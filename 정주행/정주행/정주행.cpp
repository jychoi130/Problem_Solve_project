/*������ǻ�Ͱ��к� ����Ʈ�������
180078 ������*/

#include<iostream>
using namespace std;
bool cons(int data[], int n)
{
	int max = data[0]; //max�� �迭�� ù �� �Է�
	int min = data[0]; //min�� �迭 ù �� �Է�
	for (int i = 0; i < n; i++) 
	{
		if (max < data[i]) //���� max���� �迭 ���� ũ��
			max = data[i]; //max�� �迭 �� ����
		if (min > data[i]) //���� min���� �迭 ���� ������
			min = data[i]; //min�� �迭 �� ����
	}
	if (max - min == n - 1) //max-min���� ��ü ����-1����
		return true; 
	else return false;
}
int main()
{
	int n;
	int *data; 
	cin >> n;//���� �Է�
	data = new int[n]; //������ŭ �迭 ����
	for (int i = 0; i < n; i++) //������ŭ ���� �Է�
		cin >> data[i]; 
	bool result = cons(data, n); //���ӵ� ������ ���� �������� Ȯ��
	if (result)
		cout << "YES" << endl; //���̸� yes ���
	else cout << "NO" << endl; //�����̸� no ���

	delete[] data;//�迭 ����
	return 0;
}