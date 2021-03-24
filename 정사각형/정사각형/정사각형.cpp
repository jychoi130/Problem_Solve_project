/*전자컴퓨터공학부 소프트웨어공
180078 최지연
정사각형*/

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

	Point2D(int index, int x, int y) { //인덱스 입력 받았을 경우
		this->index = index; //인덱스 값을 입력 받은 값으로 설정
		this->x = x; //x를 입력 받은 값으로 설정
		this->y = y;//y를 입력 받은 값으로 설정
	}
	Point2D(int x, int y) { //인덱스 입력 안받았을 경우
		this->index = 1;//인덱스 값을 1로 설정
		this->x = x;//x를 입력 받은 값으로 설정
		this->y = y;//y를 입력 받은 값으로 설정
	}
	long long getSquaredDistanceTo(Point2D target) { //두 좌표의 제곱 거리 계산 >>정사각형의 면적
		long long dx = abs(this->x - target.x);//차 구한 후 절댓값
		long long dy = abs(this->y - target.y);//차 구한 후 절댓값
		return dx * dx + dy * dy;//정사각형의 면적
	}
	bool operator<(const Point2D& other)const { //어떤 값으로 비교연산을 실행할 것인지 설정
		if (this->x != other.x) { //x좌표가 다르면 x좌표 기준
			return this->x < other.x;
		}
		return this->y < other.y; //x좌표 동일시 y좌표를 기준
	}
};

long long getMaximumSquareArea(int n, const vector <Point2D>& points) {
	long long answer = 0;//면적

	set<Point2D>pSet; //set변수 클라스 형으로 사용함
	for (int i = 0; i < n; i++) {
		pSet.insert(points[i]);//변수에 삽입해준다
	}

	for (int i = 0; i < n; i++) {//두 점 잡아준다
		Point2D pa = points[i];
		for (int j = 0; j < n; j++) {
			Point2D pb = points[j];
			if (i == j)continue;//같은 점 빼준다

			long long area = pa.getSquaredDistanceTo(pb); //면적 계산
			if (area < answer)//면적 작으면 continue
				continue;

			int dx = pb.x - pa.x;
			int dy = pb.y - pa.y;
			//정사각형 확인 위해
			Point2D pd(pa.x - dy, pa.y + dx);
			Point2D pc(pb.x - dy, pb.y + dx);

			if (pSet.count(pc) > 0 && pSet.count(pd) > 0)//값 있으면 면적 업데이트
				answer = max(answer,area);

		}
	}
	return answer;
}

void process(int caseIndex) {
	int n;
	cin >> n;//클래스 개수 받기

	vector<Point2D>points;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y; //x,y값을 입력받는다
		points.push_back(Point2D(i, x, y));//클래스 계속 삽입함
	}
	double answer = getMaximumSquareArea(n, points);//면적 구하는 함수

	cout << fixed << setprecision(2) << answer << endl;//둘째짜리까지 출력
}

int main() {
	int caseSize; //케이스 개수 받는 변수
	cin >> caseSize;//케이스 개수 설정

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++) {
		process(caseIndex); //케이스 개수만큼 process진행
	}
}