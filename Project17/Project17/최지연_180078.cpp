/* ������ǻ�Ͱ��к� ����Ʈ�����а�
180078 ������*/

#include <iostream>

using namespace std;

void winner(int people[], int num, int win) //�̱����� �ε��� ã��: ���������� �ִ� �迭,��� ��, �̱� ������
{
	for (int i = 0; i < num; i++) //�ε��� ã������ for��
		if (people[i] == win) //�迭�� ���� �̱� �������� ���� �����ϸ�
			cout << i << " ";
}
void check(int people[], int num)//���������� �̱� �� �Ǵ�
{
	int r = 0, s = 0, p = 0; //���� ���� �� ���� ���� �������� ����
	int win;
	for (int i = 0; i < num; i++) //���� ���� �� ���� ����
	{
		if (people[i] == 0) //������ s���� 1���� �ø�
			s++;
		else if (people[i] == 1) //������ r���� 1���� �ø�
			r++;
		else if (people[i] == 2) //���� p���� 1���� �ø�
			p++;
	}
	if (r > 0 && s > 0 && p > 0 || r == 0 && s == 0 || s == 0 && p == 0 || r == 0 && p == 0)
	{
		cout << endl << "���" << endl;
	}
	else if (s == 0) { // ������ ���� ���
		cout << "index : ";
		for (int i = 0; i < num; i++) {
			if (people[i] == 2) cout << i << "  ";
		}
	}
	else if (p == 0) { // ���� ���� ���
		cout << "index : ";
		for (int i = 0; i < num; i++) {
			if (people[i] == 1) cout << i << "  ";
		}
	}
	else if (r == 0) { // ������ ���� ���
		cout << "index : ";
		for (int i = 0; i < num; i++) {
			if (people[i] == 0) cout << i << "  ";
		}
	}
}

int main()
{
	int num; //��� ��
	int* people; //�Է°� ������ ��ȯ�ؼ� ������ �迭
	char a[20]; //���������� �� �Է¹��� �迭

	cin >> num;
	people = new int[num]; //��� ���� ���� ������ �迭 ����

	for (int i = 0; i < num; i++) //��� �� ���� for��
	{
		cin >> a;
		if (strcmp(a, "����") == 0) //�Է� ���� ������ ��� 
			people[i] = 0; //������ �迭�� 0�Է�
		else if (strcmp(a, "����") == 0)//�Է°��� ������ ���
			people[i] = 1; //������ �迭�� 1�Է�
		else if (strcmp(a, "��") == 0) //�Է°��� ���ϰ��
			people[i] = 2;//������ �迭�� 2�Է�
	}

	check(people, num); //�̱� ��� Ȯ���ϴ� �Լ� ����

	return 0;
}