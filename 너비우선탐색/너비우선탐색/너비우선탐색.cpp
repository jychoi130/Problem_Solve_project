/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������
���� �켱 Ž��*/
#include<iostream>
#include<queue> //�ʺ�켱Ž�� ť ����� ����
using namespace std;

int map[10][10] = { 0 }; //������� ǥ��
int visit[10] = { 0 }; //0���� �ʱ�ȭ
queue<int>q;//ť ����
int num, edge_num;//���, ������ ����

void bfs(int v) {
	cout << v << endl;
	q.push(v); //���� ���� �ִ´�
	while (!q.empty()) { //ť�� ��Ե� ������ ����
		int node = q.front(); //�� �� ���� ��忡 ����
		q.pop();//���� ���ؼ� ���ش�
		for (int i = 0; i < num; i++) { //���� ��ŭ �ݺ�
			if (map[node][i] == 1 & visit[i] == 0) {//�湮 ���ϰ� ����Ǿ�������
				visit[node] = 1;//�湮�� ǥ��
				cout << i << endl;//��� �� 
				q.push(i);//������ �Է�
			}
		}
	}
}

int main() {
	cin >> num >> edge_num;//���� ������ ���� �Է¹޴´�
	for (int i = 0; i < edge_num; i++) {//���� ������ŭ
		int v1, v2;//������ ��� ����
		cin >> v1 >> v2;//���� 
		map[v1][v2] = map[v2][v1] = 1;//�Ѵ� 1�� �ʱ�ȭ(������)
	}
	bfs(1);//1���� �ʺ�켱Ž�� ����
	return 0;
}