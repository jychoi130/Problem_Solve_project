/*전자컴퓨터공학부 소프트웨어공
180078 최지연
이미지 매칭*/
#pragma warning (disable:4996)
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int N, M, R, C; //사각형 생성위한 변수
	int count = 0, p, q;//개수 세고 식 만족시키기 위한 변수
	int checkbreak = 0;

	scanf("%d %d", &N, &M); //큰 배열 A 생성
	int** A = new int*[N];
	for (int i = 0; i < N; ++i)
		A[i] = new int[M];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &A[i][j]);

	scanf("%d %d", &R, &C); //작은 배열 B 생성
	int** B = new int*[R];
	for (int i = 0; i < R; ++i)
		B[i] = new int[C];

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			scanf("%d", &B[i][j]);

	//작은 직사각형이 큰 직사각형에서 움직일 수 있는 최대

	int temp;
	for (int i = 0; i < N - R + 1; i++) {
		for (int j = 0; j < M - C + 1; j++) {
			checkbreak = 0;
			for (int k = -1000; k < 1000; k++) {
				for (int l = 0; l < R; l++) {
					for (int n = 0; n < C; n++) {
						if (l == 0 && n == 0) {
							temp = B[l][n] - k * A[i][j];
						}
						else {
							if (temp == B[l][n] - k * A[i + l][j + n]) {
								checkbreak++;
							}
						}
					}
				}
			}
			if (checkbreak >= R * C) {
				count++;
			}
		}
	}
	cout << count;

}