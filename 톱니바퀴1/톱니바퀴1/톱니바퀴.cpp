/*������ǻ�Ͱ��к� ����Ʈ�������
180078 ������*/
#include <iostream>
#include <Windows.h>
using namespace std;

void mix(int who, int LR, int data[4][8]) {      //��Ϲ��� ������ �Լ�

	int temp;
	if (LR == 1) { //�ð�������� ȸ��
		temp = data[who - 1][7];
		for (int i = 7; i > 0; i--) {
			data[who - 1][i] = data[who - 1][i - 1];
		}
		data[who - 1][0] = temp;
	}
	else { //�ݽð� �������� ȸ��
		temp = data[who - 1][0];
		for (int i = 0; i < 7; i++) {
			data[who - 1][i] = data[who - 1][i + 1];
		}
		data[who - 1][7] = temp;
	}
}

void main() {
	int a = 1; 
	int data[4][8];
	for (int i = 0; i < 4; i++) {
		cin >> a;
		for (int j = 7; j >= 0; j--) {
			data[i][j] = a % 10;
			a /= 10;
		}
	}

	int howmany; //������ ��
	int where, LR; //��𵹸����� ��� �������� ��������

	cin >> howmany;

	for (int i = 0; i < howmany; i++) {
		cin >> where >> LR;

		if (where == 1) { //ù ��° �����̴� ����
			if (data[0][2] != data[1][6] && data[1][2] != data[2][6] && data[2][2] != data[3][6]) {
				mix(1, LR, data);
				mix(2, LR * -1, data);
				mix(3, LR, data);
				mix(4, LR * -1, data);
			}
			else if (data[0][2] != data[1][6] && data[1][2] != data[2][6]) {
				mix(1, LR, data);
				mix(2, LR * -1, data);
				mix(3, LR, data);
			}
			else if (data[0][2] != data[1][6]) {
				mix(1, LR, data);
				mix(2, LR * -1, data);
			}
			else {
				mix(1, LR, data);
			}
		}
		else if (where == 2) { //�� ��° �����̴� ����
			if (data[0][2] != data[1][6] && data[1][2] != data[2][6] && data[2][2] != data[3][6]) {
				mix(1, LR * -1, data);
				mix(2, LR, data);
				mix(3, LR * -1, data);
				mix(4, LR, data);
			}
			else if (data[0][2] != data[1][6] && data[1][2] != data[2][6]) {
				mix(1, LR * -1, data);
				mix(2, LR, data);
				mix(3, LR * -1, data);
			}
			else if (data[1][2] != data[2][6] && data[2][2] != data[3][6]) {
				mix(3, LR * -1, data);
				mix(4, LR, data);
			}
			else if (data[1][2] != data[2][6]) {
				mix(2, LR, data);
				mix(3, LR * -1, data);
			}
			else if (data[0][2] != data[1][6]) {
				mix(1, LR * -1, data);
				mix(2, LR, data);
			}
			else {
				mix(2, LR, data);
			}
		}
		else if (where == 3) { //�� ��° �����̴� ����
			if (data[0][2] != data[1][6] && data[1][2] != data[2][6] && data[2][2] != data[3][6]) {
				mix(1, LR, data);
				mix(2, LR * -1, data);
				mix(3, LR, data);
				mix(4, LR * -1, data);
			}
			else if (data[0][2] != data[1][6] && data[1][2] != data[2][6]) {
				mix(1, LR, data);
				mix(2, LR * -1, data);
				mix(3, LR, data);
			}
			else if (data[1][2] != data[2][6] && data[2][2] != data[3][6]) {
				mix(2, LR * -1, data);
				mix(3, LR, data);
				mix(4, LR * -1, data);
			}
			else if (data[1][2] != data[2][6]) {
				mix(2, LR * -1, data);
				mix(3, LR, data);
			}
			else if (data[2][2] != data[3][6]) {
				mix(3, LR, data);
				mix(4, LR * -1, data);
			}
			else {
				mix(3, LR, data);
			}
		}
		else if (where == 4) { //�� ��° �����̴� ����
			if (data[0][2] != data[1][6] && data[1][2] != data[2][6] && data[2][2] != data[3][6]) {
				mix(1, LR * -1, data);
				mix(2, LR, data);
				mix(3, LR * -1, data);
				mix(4, LR, data);
			}
			else if (data[1][2] != data[2][6] && data[2][2] != data[3][6]) {
				mix(2, LR, data);
				mix(3, LR * -1, data);
				mix(4, LR, data);
			}
			else if (data[2][2] != data[3][6]) {
				mix(3, LR * -1, data);
				mix(4, LR, data);
			}
			else {
				mix(4, LR, data);
			}
		}
	}
	int sum = 0; //���� ���
	if (data[0][0] == 1) sum = sum + 1;
	if (data[1][0] == 1) sum = sum + 2;
	if (data[2][0] == 1) sum = sum + 4;
	if (data[3][0] == 1) sum = sum + 8;
	printf("%d", sum);

}