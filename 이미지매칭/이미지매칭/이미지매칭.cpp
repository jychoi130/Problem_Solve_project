/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������
�̹��� ��Ī*/
#pragma warning (disable:4996)
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int N, M, R, C; //�簢�� �������� ����
	int count = 0, p, q;//���� ���� �� ������Ű�� ���� ����
	int checkbreak = 0;

	scanf("%d %d", &N, &M); //ū �迭 A ����
	int** A = new int*[N];
	for (int i = 0; i < N; ++i)
		A[i] = new int[M];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &A[i][j]);

	scanf("%d %d", &R, &C); //���� �迭 B ����
	int** B = new int*[R];
	for (int i = 0; i < R; ++i)
		B[i] = new int[C];

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			scanf("%d", &B[i][j]);

	//���� ���簢���� ū ���簢������ ������ �� �ִ� �ִ�

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