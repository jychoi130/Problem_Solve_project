/*전자컴퓨터공학부 소프트웨어공
180078 최지연
깊이 우선 탐색*/

#include<iostream>
using namespace std;

int maps[10][10]; 
int visited[10] = {0};//초기화
int num;

void init() { //초기화
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			maps[i][j] = 0; //맵 배열을 0으로 초기화 해준다
}

void dfs(int v) { 
	cout << v << endl;
	visited[v] = 0; //한번 돌았기때문에 재 수행하지 않게 하기위해서
	for (int i = 0; i <= num; i++) { //num까지 반복 >>작은 값 부터 수행하도록 도와준다
		if (maps[v][i] && visited[i]) //둘다 1일때
			dfs(i);//재귀 함수
	}
}

int main() {
	int v1, v2; //간선 정보 입력받을 변수
	init();
	cin >> num; //간선 개수 
	for (int i = 0; i < num; i++) { //간선 개수만큼
		cin >> v1 >> v2; //간선이 잇는 노드 입력
		maps[v1][v2] = maps[v2][v1] = 1; //방향 없는 그래프>>간선 표시
		visited[v1] = visited[v2] = 1;//간선 있는 곳 1로 설정
	}
	dfs(1); //깊이 우선 탐색 1번 부터 시작
	return 0;
}