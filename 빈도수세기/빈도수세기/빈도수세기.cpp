/*전자컴퓨터공학부 소프트웨어공
180078 최지연
빈도수 세기*/

#include<iostream>
#include<map>
using namespace std;

int main()
{
	int n; //입력개수 설정하는 변수
	scanf("%d", &n); //개수 값 설정

	map<int, int>frequencyMap; //맵변수 사용,키 값은 숫자와 횟수이므로 int형 선언

	for (int i = 0; i < n; i++) { //입력 개수 만큼 반복
		int x;//int형 변수 선언
		scanf("%d", &x); //데이터 불러와서 x에 저장
		frequencyMap[x]++; //0으로 초기화 되어있는 것을 입력 횟수만큼 +1해준다.
		printf("%d %d\n", frequencyMap.size(), frequencyMap[x]);
		//키와 횟수 데이터 출력
	}
	return 0;
}