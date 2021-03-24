/*전자컴퓨터공학부 소프트웨어공
180078 최지연
깊이 우선 탐색*/
#include<iostream>
#include<queue> //너비우선탐색 큐 사용이 용이
using namespace std;

int map[10][10] = { 0 }; //인접행렬 표현
int visit[10] = { 0 }; //0으로 초기화
queue<int>q;//큐 선언
int num, edge_num;//노드, 엣지의 개수

void bfs(int v) {
	cout << v << endl;
	q.push(v); //받은 변수 넣는다
	while (!q.empty()) { //큐가 비게될 때까지 실행
		int node = q.front(); //맨 앞 정보 노드에 저장
		q.pop();//팝을 통해서 없앤다
		for (int i = 0; i < num; i++) { //개수 만큼 반복
			if (map[node][i] == 1 & visit[i] == 0) {//방문 안하고 연결되어있으면
				visit[node] = 1;//방문함 표시
				cout << i << endl;//출력 후 
				q.push(i);//데이터 입력
			}
		}
	}
}

int main() {
	cin >> num >> edge_num;//노드와 엣지의 개수 입력받는다
	for (int i = 0; i < edge_num; i++) {//엣지 개수만큼
		int v1, v2;//연결할 노드 변수
		cin >> v1 >> v2;//연결 
		map[v1][v2] = map[v2][v1] = 1;//둘다 1로 초기화(무방향)
	}
	bfs(1);//1부터 너비우선탐색 실행
	return 0;
}