/*������ǻ�Ͱ��к� ����Ʈ�������
180078 ������*/
#include <iostream>

void main() {
	int a, b, temp, howto, min = 999, count;
	printf("ù��° �� �Է� : ");
	scanf_s("%d", &a);
	printf("�ι�° �� �Է� : ");
	scanf_s("%d", &b);
	howto = 0;

	while (howto != 128) { //128������ 2������ ����(2���� ������ ���� 0,1�� ���� 0000000-1111111�� ������ ���� ����, ���� ���� ������ ã��
		temp = a;
		count = 0;
		for (int i = 0; temp < b; i++) {
			if (howto & (1 << i)) {      //   *10+1�� ����
				temp = temp * 10 + 1;
			}
			else {                  //   *2�� ����
				temp *= 2;
			}
			count++;
		}
		if (min > count & temp == b) {// ������ ���� ���� ����� ������� ����
			min = count;
		}
		howto++;
	}
	if (min != 999) { 
		printf("%d�� ����", min + 1);
	}
	else {
		printf("-1");
	}
}