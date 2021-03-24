/*전자컴퓨터공학부 소프트웨어학과
180078 최지연*/
#include <iostream>
using namespace std;

bool checkprime(int p)//소수인지 확인하는 함수
{
	if (p == 1) { //만약 1을 입력한 경우 소수가 아닌다
		return false;
	}
	else if (p == 2) {//2를 입력한 경우 소수이다
		return true;
	}
	else {//다른 숫자를 입력한 경우
		for (int i = 2; i < p; i++)//2~입력한 숫자-1까지
		{
			if (p%i == 0)//나머지를 구해본다
				return false;//나머지가 없으면 나눠짐>>소수가 아니다
		}
		return true;//나머지 없으면 소수
	}
}
void Tcase(int index)//소수 확인할 숫자 입력받고 결과 출력함수
{
	int prime;//숫자 입력 받을 변수
	cin >> prime;//변수 대입
	bool result = checkprime(prime);//소수인지 확인하는 함수
	cout << "Case #" << index << endl; 
	if (result) //만약 결과가 참이다
		cout << "YES" << endl;//yes출력
	else//결과가 거짓이면
		cout << "NO" << endl;//no출력
}
int main()
{
	int num;
	cin >> num;//case 개수 입력

	for (int i = 1; i <= num; i++)//case개수만큼 숫자 입력받는 함수 돌림
	{
		Tcase(i);
	}

	return 0;
}