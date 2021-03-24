/*전자컴퓨터공학부 소프트웨어공
180078 최지연
히스토그램*/

#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>

using namespace std;

class Histogram { //히스토그램 클래스 생성
public:
	int height;//높이
	int leftX;//왼쪽변 x 좌표
	int rightX;//오른쪽변 x 좌표

	Histogram() {	}
	Histogram(int index, int height) {
		this->leftX = index;
		this->rightX = this->leftX + 1;
		this->height = height;
	}
};

long long getLargestRectangleArea(const vector<Histogram>&histograms) {
	long long answer = 0;//최대 직사각형 넓이
	//int로 선언시 overflow 발생
	stack<Histogram>stk;
	stk.push(Histogram(-1, 0));
	for (int i = 0; i < histograms.size() + 1; i++) //오름차순으로 확장
	{
		Histogram h;
		if (i < histograms.size()) {
			h = histograms[i];
		}
		else {
			h = Histogram(histograms.size(), 0); //가장 오른쪽에 높이 0까지 가상 히스토그램 생성
		}

		while (stk.size() > 1 && stk.top().height > h.height) {//확장 못하면 종료
			Histogram lh = stk.top();
			stk.pop();
			Histogram bh = stk.top();//삭제 전 탑 저장
			long long width = abs(h.leftX - bh.rightX); //차이로 가로길이 
			long long height = lh.height;//세로 길이 구함
			long long area = width * height; //면적구함

			answer = max(answer, area);//값 갱신
		}
		stk.push(h); //h 추가
	}
	return answer;
}

void process(int caseIndex) {
	int n;//그래프 개수
	cin >> n;

	vector<Histogram> histograms;
	for (int i = 0; i < n; i++) {
		int height;
		cin >> height;
		histograms.push_back(Histogram(i, height)); //인덱스와 높이 설정
	}
	long long answer = getLargestRectangleArea(histograms);//가장 큰 면적 반환
	cout << answer << endl;
}

int main() {
	int caseSize; //케이스 사이즈 입력받음
	cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) { //케이스 사이즈만큼 돌려본다
		process(caseIndex);
	}
}