/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������
�ߺ� �����ϱ�*/

#include<iostream>
#include<set>
using namespace std;

int main() {
	int N;
	cin >> N; //�� ���� ������ ������ ����
	set<int>s; //int�� set���� ����

	for (int i = 0; i < N; i++) {
		int X;
		cin >> X; //N���� ���� ��ŭ ������ �޴´�
		
		if (s.count(X) > 0) { //���� ���� ���� �����ϸ�
			printf("Duplicated\n");//Duplicated ���
		}
		else { //���� ���� �������� ������
			s.insert(X); //�� ���� set�� ���� ��
			printf("OK\n");//OK ���
		}
	}
	return 0;
}