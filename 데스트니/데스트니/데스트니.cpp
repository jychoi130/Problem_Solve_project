/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

class point2D
{
private:
	int x;
	int y;
public:
	point2D(int x = 0, int y = 0)
	{
		this->x = x; //��ǥ �ֱ�
		this->y = y; //��ǥ �ֱ�
	}
	int getSDistance(const point2D & target)const { //�Ÿ��� ���� ����
		int dx = abs(this->x - target.x); //���밪 
		int dy = abs(this->y - target.y); //���밪 
		return dx * dx + dy * dy; //�� ���ؼ� ��ȯ
	}
	double getDistance(const point2D & target)const { //�Ÿ� ����
		double sqd = (double)this->getSDistance(target);
		return sqrt(sqd);
	}
};

int main()
{
	int n;
	point2D *points; 

	cin >> n;
	points = new point2D[n]; //���� ������ŭ �迭 ����

	for (int i = 0; i < n; i++)//x,y��ǥ�� �Է¹���
	{
		int x, y;
		scanf("%d %d", &x, &y);
		points[i] = point2D(x, y);
	}

	int min_sqd = INT_MAX; //int���� �ִ밪
	int min_cnt = 0; 

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++) //�ߺ� ����� �ʿ� �����Ƿ�
		{
			int sqd = points[i].getSDistance(points[j]);
			if (sqd < min_sqd)//�Ÿ����� �� ������ 
			{
				min_sqd = sqd;//���� ������ ����
				min_cnt = 1;//���� 1��
			}
			else if (sqd == min_sqd)//�Ÿ��� ������
				min_cnt++; //���� ����
		}
	}
	double distance = sqrt(min_sqd);
	printf("%.1f\n", distance);
	cout << min_cnt << endl;
	
	delete[] points;
	return 0;
}