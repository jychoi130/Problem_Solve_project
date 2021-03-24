/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������
���� �켱 Ž��*/

#include<iostream>
using namespace std;

int maps[10][10]; 
int visited[10] = {0};//�ʱ�ȭ
int num;

void init() { //�ʱ�ȭ
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			maps[i][j] = 0; //�� �迭�� 0���� �ʱ�ȭ ���ش�
}

void dfs(int v) { 
	cout << v << endl;
	visited[v] = 0; //�ѹ� ���ұ⶧���� �� �������� �ʰ� �ϱ����ؼ�
	for (int i = 0; i <= num; i++) { //num���� �ݺ� >>���� �� ���� �����ϵ��� �����ش�
		if (maps[v][i] && visited[i]) //�Ѵ� 1�϶�
			dfs(i);//��� �Լ�
	}
}

int main() {
	int v1, v2; //���� ���� �Է¹��� ����
	init();
	cin >> num; //���� ���� 
	for (int i = 0; i < num; i++) { //���� ������ŭ
		cin >> v1 >> v2; //������ �մ� ��� �Է�
		maps[v1][v2] = maps[v2][v1] = 1; //���� ���� �׷���>>���� ǥ��
		visited[v1] = visited[v2] = 1;//���� �ִ� �� 1�� ����
	}
	dfs(1); //���� �켱 Ž�� 1�� ���� ����
	return 0;
}