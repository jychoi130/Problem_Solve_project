/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������
ž*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Tower {
public:
	int index;//��ġ
	int height;//����
	int targetTowerIndex;//������ ����

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
		int targetTowerIndex = 0;//�ʱ갪 0���� ����

		while (stk.empty() == false && stk.top().height < t.height) {
			stk.pop();//���� Ÿ�� ����
		}
		if (stk.size() > 0) {
			targetTowerIndex = stk.top().index;//���� Ÿ��
		}
		t.setTargetTowerIndex(targetTowerIndex);
		stk.push(t);
	}
}

int main()
{
	int n;
	cin >> n;//ž ����

	vector<Tower>towers;
	for (int i = 0; i < n; ++i)
	{
		int hi;
		cin >> hi;//����
		towers.push_back(Tower(i + 1, hi));
	}
	findTargetTowers(towers);//Ÿ�ٰ��

	for(int i = 0; i < n; i++){
		if (i > 0) {
			cout << " ";
		}
		Tower t = towers[i];
		int targetIndex = t.getTargetTowerIndex();
		cout << targetIndex;
	}
}