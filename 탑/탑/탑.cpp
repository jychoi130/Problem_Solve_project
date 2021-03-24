/*전자컴퓨터공학부 소프트웨어공
180078 최지연
탑*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Tower {
public:
	int index;//위치
	int height;//높이
	int targetTowerIndex;//레이저 수신

	Tower(int index, int height)
	{
		this->index = index;
		this->height = height;
		this->targetTowerIndex = 0;
	}
	void setTargetTowerIndex(int targetTowerIndex) {
		this->targetTowerIndex = targetTowerIndex;
	}
	int getTargetTowerIndex()
	{
		return this->targetTowerIndex;
	}
};

void findTargetTowers(vector<Tower>& towers)
{
	stack<Tower> stk;
	for (int i = 0; i < towers.size(); i++) {
		Tower& t = towers[i];
		int targetTowerIndex = 0;//초깃값 0으로 설정

		while (stk.empty() == false && stk.top().height < t.height) {
			stk.pop();//낮은 타워 제거
		}
		if (stk.size() > 0) {
			targetTowerIndex = stk.top().index;//높은 타워
		}
		t.setTargetTowerIndex(targetTowerIndex);
		stk.push(t);
	}
}

int main()
{
	int n;
	cin >> n;//탑 개수

	vector<Tower>towers;
	for (int i = 0; i < n; ++i)
	{
		int hi;
		cin >> hi;//높이
		towers.push_back(Tower(i + 1, hi));
	}
	findTargetTowers(towers);//타겟계산

	for(int i = 0; i < n; i++){
		if (i > 0) {
			cout << " ";
		}
		Tower t = towers[i];
		int targetIndex = t.getTargetTowerIndex();
		cout << targetIndex;
	}
}