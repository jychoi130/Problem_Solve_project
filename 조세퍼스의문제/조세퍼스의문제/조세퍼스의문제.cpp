/*전자컴퓨터공학부 소프트웨어공
180078 최지연
조세퍼스의 문제*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Player { //플래이어 클래스 선언
public:
	int index;
	
	Player(int index) {
		this->index = index;
	}
};

vector<Player>getDeadPlayerList(int n, int m, const vector<Player>&players) {
	
	vector <Player> deadPlayers; //현재 제외된 플레이어 리스트

	queue<Player> que;//제외되지 않은 플레이어 리스트

	for (int i = 0; i < n; i++)
	{
		que.push(players[i]); //플레이어들을 넣는다
	}

	for (int i = 0; i < n; i++) {
		int jump = 1 + (m - 1) % que.size();//플레이어 아웃시킬 위치 찾기위한 변수
		for (int j = 0; j < jump - 1; j++) {
			Player p = que.front();
			que.pop();
			que.push(p);
		}//위치에 있는 플레이어가 나올때까지 앞의 플레이어들을 옮겨서 맨 앞으로 만든 후 제외시킨다
		Player dead = que.front();
		que.pop(); //제외되지않은 플레이어 리스트에서 꺼낸다

		deadPlayers.push_back(dead);//죽은 플레이어 리스트에 추가
	}
	return deadPlayers;
}

void process(int caseIndex) {
	int n, m;
	cin >> n >> m; //n명의 사람들의 번호,m 간격

	vector<Player> players;
	for (int i = 0; i < n; i++) {
		players.push_back(Player(i + 1));
	}//플레이어의 인덱스 설정해준다
	vector<Player> deadPlayers=getDeadPlayerList(n,m,players);//제외되는 플레이어 리스트
	
	for (int i = 0; i < n; i++)//죽은 플레이어 순서대로 출력
	{
		if (i > 0) {
			cout << " ";
		}
		Player p = deadPlayers[i];
		cout << p.index;
	}
	cout << endl;
}

int main() {
	int caseSize;//케이스 개수 받기위한 변수
	cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex); //케이스 개수만큼 프로세스 돌린다.
	}
}
