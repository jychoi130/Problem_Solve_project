/*전자컴퓨터공학부 소프트웨어공
180078 최지연
시장 추천하기*/

#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	int n; //후보자의 숫자 입력받을 변수 선언
	cin >> n;//후보자 수 입력

	map<string, int> frequencyMap; 
	//후보의 이름과 표수 저장하는 맵변수 선언
	int maxFrequency = 0;//최대 득표수

	for (int i = 0; i < n; i++) {//후보자 수 만큼 반복
		string st;//후보자 이름받을 변수
		cin >> st;//이름 입력
		frequencyMap[st]++; //이름에 따른 value값 증가시켜줌
		int k = frequencyMap[st];//k값에 value값 즉 득표수 입력넣음
		if (k > maxFrequency) {//만약 득표수가 최대 득표수보다 크면
			maxFrequency = k;//최대 득표수를 바꿔준다
		}
	}
	cout << maxFrequency << endl; //최대 득표수 출력

	map<string, int>::iterator it; //후보 출력하기 위한 iterator 변수 선언
	for (it = frequencyMap.begin(); it != frequencyMap.end(); it++)
	{
		if (it->second == maxFrequency) //최대 득표수와 동일하는 키 값을 가지면
			printf("%s ", it->first.c_str());//키 즉 후보이름을 출력한다.
	}
}