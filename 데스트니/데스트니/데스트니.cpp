/*전자컴퓨터공학부 소프트웨어공
180078 최지연*/
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
		this->x = x; //좌표 넣기
		this->y = y; //좌표 넣기
	}
	int getSDistance(const point2D & target)const { //거리의 제곱 구함
		int dx = abs(this->x - target.x); //절대값 
		int dy = abs(this->y - target.y); //절대값 
		return dx * dx + dy * dy; //값 구해서 반환
	}
	double getDistance(const point2D & target)const { //거리 구함
		double sqd = (double)this->getSDistance(target);
		return sqrt(sqd);
	}
};

int main()
{
	int n;
	point2D *points; 

	cin >> n;
	points = new point2D[n]; //받은 개수만큼 배열 생성

	for (int i = 0; i < n; i++)//x,y좌표값 입력받음
	{
		int x, y;
		scanf("%d %d", &x, &y);
		points[i] = point2D(x, y);
	}

	int min_sqd = INT_MAX; //int형의 최대값
	int min_cnt = 0; 

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++) //중복 계산할 필요 없으므로
		{
			int sqd = points[i].getSDistance(points[j]);
			if (sqd < min_sqd)//거리값이 더 작으면 
			{
				min_sqd = sqd;//작은 값으로 변경
				min_cnt = 1;//개수 1개
			}
			else if (sqd == min_sqd)//거리가 같으면
				min_cnt++; //개수 증가
		}
	}
	double distance = sqrt(min_sqd);
	printf("%.1f\n", distance);
	cout << min_cnt << endl;
	
	delete[] points;
	return 0;
}