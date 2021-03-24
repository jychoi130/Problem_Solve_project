/*전자컴퓨터공학부 소프트웨어공학
180078 최지연*/
#include <iostream>

void main() {
	int a, b, temp, howto, min = 999, count;
	printf("첫번째 값 입력 : ");
	scanf_s("%d", &a);
	printf("두번째 값 입력 : ");
	scanf_s("%d", &b);
	howto = 0;

	while (howto != 128) { //128까지를 2진수로 생성(2가지 연산을 각각 0,1로 놓고 0000000-1111111의 연산을 전부 실행, 가장 빠른 연산을 찾음
		temp = a;
		count = 0;
		for (int i = 0; temp < b; i++) {
			if (howto & (1 << i)) {      //   *10+1을 해줌
				temp = temp * 10 + 1;
			}
			else {                  //   *2을 해줌
				temp *= 2;
			}
			count++;
		}
		if (min > count & temp == b) {// 연산이 가장 작은 방법의 연산수를 저장
			min = count;
		}
		howto++;
	}
	if (min != 999) { 
		printf("%d번 연산", min + 1);
	}
	else {
		printf("-1");
	}
}