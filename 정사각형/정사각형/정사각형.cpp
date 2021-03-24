/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������
���簢��*/

#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;

class Point2D {
public:
	int x;
	int y;
	int index;

	Point2D(int index, int x, int y) { //�ε��� �Է� �޾��� ���
		this->index = index; //�ε��� ���� �Է� ���� ������ ����
		this->x = x; //x�� �Է� ���� ������ ����
		this->y = y;//y�� �Է� ���� ������ ����
	}
	Point2D(int x, int y) { //�ε��� �Է� �ȹ޾��� ���
		this->index = 1;//�ε��� ���� 1�� ����
		this->x = x;//x�� �Է� ���� ������ ����
		this->y = y;//y�� �Է� ���� ������ ����
	}
	long long getSquaredDistanceTo(Point2D target) { //�� ��ǥ�� ���� �Ÿ� ��� >>���簢���� ����
		long long dx = abs(this->x - target.x);//�� ���� �� ����
		long long dy = abs(this->y - target.y);//�� ���� �� ����
		return dx * dx + dy * dy;//���簢���� ����
	}
	bool operator<(const Point2D& other)const { //� ������ �񱳿����� ������ ������ ����
		if (this->x != other.x) { //x��ǥ�� �ٸ��� x��ǥ ����
			return this->x < other.x;
		}
		return this->y < other.y; //x��ǥ ���Ͻ� y��ǥ�� ����
	}
};

long long getMaximumSquareArea(int n, const vector <Point2D>& points) {
	long long answer = 0;//����

	set<Point2D>pSet; //set���� Ŭ�� ������ �����
	for (int i = 0; i < n; i++) {
		pSet.insert(points[i]);//������ �������ش�
	}

	for (int i = 0; i < n; i++) {//�� �� ����ش�
		Point2D pa = points[i];
		for (int j = 0; j < n; j++) {
			Point2D pb = points[j];
			if (i == j)continue;//���� �� ���ش�

			long long area = pa.getSquaredDistanceTo(pb); //���� ���
			if (area < answer)//���� ������ continue
				continue;

			int dx = pb.x - pa.x;
			int dy = pb.y - pa.y;
			//���簢�� Ȯ�� ����
			Point2D pd(pa.x - dy, pa.y + dx);
			Point2D pc(pb.x - dy, pb.y + dx);

			if (pSet.count(pc) > 0 && pSet.count(pd) > 0)//�� ������ ���� ������Ʈ
				answer = max(answer,area);

		}
	}
	return answer;
}

void process(int caseIndex) {
	int n;
	cin >> n;//Ŭ���� ���� �ޱ�

	vector<Point2D>points;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y; //x,y���� �Է¹޴´�
		points.push_back(Point2D(i, x, y));//Ŭ���� ��� ������
	}
	double answer = getMaximumSquareArea(n, points);//���� ���ϴ� �Լ�

	cout << fixed << setprecision(2) << answer << endl;//��°¥������ ���
}

int main() {
	int caseSize; //���̽� ���� �޴� ����
	cin >> caseSize;//���̽� ���� ����

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++) {
		process(caseIndex); //���̽� ������ŭ process����
	}
}