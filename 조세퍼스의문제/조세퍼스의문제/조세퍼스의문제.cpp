/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������
�����۽��� ����*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Player { //�÷��̾� Ŭ���� ����
public:
	int index;
	
	Player(int index) {
		this->index = index;
	}
};

vector<Player>getDeadPlayerList(int n, int m, const vector<Player>&players) {
	
	vector <Player> deadPlayers; //���� ���ܵ� �÷��̾� ����Ʈ

	queue<Player> que;//���ܵ��� ���� �÷��̾� ����Ʈ

	for (int i = 0; i < n; i++)
	{
		que.push(players[i]); //�÷��̾���� �ִ´�
	}

	for (int i = 0; i < n; i++) {
		int jump = 1 + (m - 1) % que.size();//�÷��̾� �ƿ���ų ��ġ ã������ ����
		for (int j = 0; j < jump - 1; j++) {
			Player p = que.front();
			que.pop();
			que.push(p);
		}//��ġ�� �ִ� �÷��̾ ���ö����� ���� �÷��̾���� �Űܼ� �� ������ ���� �� ���ܽ�Ų��
		Player dead = que.front();
		que.pop(); //���ܵ������� �÷��̾� ����Ʈ���� ������

		deadPlayers.push_back(dead);//���� �÷��̾� ����Ʈ�� �߰�
	}
	return deadPlayers;
}

void process(int caseIndex) {
	int n, m;
	cin >> n >> m; //n���� ������� ��ȣ,m ����

	vector<Player> players;
	for (int i = 0; i < n; i++) {
		players.push_back(Player(i + 1));
	}//�÷��̾��� �ε��� �������ش�
	vector<Player> deadPlayers=getDeadPlayerList(n,m,players);//���ܵǴ� �÷��̾� ����Ʈ
	
	for (int i = 0; i < n; i++)//���� �÷��̾� ������� ���
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
	int caseSize;//���̽� ���� �ޱ����� ����
	cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex); //���̽� ������ŭ ���μ��� ������.
	}
}
