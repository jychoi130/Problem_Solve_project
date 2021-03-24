/*전자컴퓨터공학부 소프트웨어공
180078 최지연
불안정 지역*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class City {
public:
	int index; //도시 인덱스
	int income; //도시 소득

	City(int index, int income) { //도시 생성자
		this->index = index;
		this->income = income;
	}
	bool operator<(const City&o)const {
		return this->income < o.income;
	}
	bool operator>(const City&o)const {
		return this->income > o.income;
	}//대소 관계 추가해야 무엇을 가지고 대소 관계를 비교할 것인가를 알 수 있다
};

int getMaximumRangeDifference(int n, int k, const vector<City>&cities) {
	int answer = 0;

	priority_queue<City, vector<City>, greater<City>> rangeMinimum;
	//소득 낮은 도시부터 팝하는 우선순위 큐
	priority_queue<City> rangeMaximum; //소득 높은 도시부터 팝하는 우선순위 큐

	for (int i = 0; i < k - 1; i++) {
		rangeMaximum.push(cities[i]);//큰 값이 탑
		rangeMinimum.push(cities[i]);//작은 값이 탑
	}
	for (int i = k - 1; i < n; i++) {
		rangeMaximum.push(cities[i]); 
		rangeMinimum.push(cities[i]);
		while (rangeMaximum.top().index < i - k + 1)rangeMaximum.pop();//범위에 없는 내용 삭제
		while (rangeMinimum.top().index < i - k + 1)rangeMinimum.pop(); //범위에 없는 내용 삭제
		answer = max(answer, rangeMaximum.top().income - rangeMinimum.top().income);//큰 값으로 업데이트
	}
	return answer; //답 반환해 줌
}

void process(int caseIndex) {
	int n, k;
	cin >> n >> k; //도시의 수,연속한 도시 수
	vector<City>cities;

	for (int i = 0; i < n; i += 1) {
		int income;
		cin >> income;
		cities.push_back(City(i, income)); //값 넣어준다
	}

	int answer = getMaximumRangeDifference(n, k, cities); //문제 풀이 진행

	cout << answer << endl; //답 출력
}

int main() {
	int caseSize; //케이스 개수 
	cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1)
		process(caseIndex); //케이스 개수만큼 프로세스 돌린다
}