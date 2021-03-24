/*전자컴퓨터공학부 소프트웨어공학
180078 최지연*/

#include<iostream>
using namespace std;
bool cons(int data[], int n)
{
	int max = data[0]; //max에 배열의 첫 값 입력
	int min = data[0]; //min에 배열 첫 값 입력
	for (int i = 0; i < n; i++) 
	{
		if (max < data[i]) //만약 max보다 배열 값이 크면
			max = data[i]; //max에 배열 값 대입
		if (min > data[i]) //만약 min보다 배열 값이 작으면
			min = data[i]; //min에 배열 값 대입
	}
	if (max - min == n - 1) //max-min값이 전체 개수-1개면
		return true; 
	else return false;
}
int main()
{
	int n;
	int *data; 
	cin >> n;//개수 입력
	data = new int[n]; //개수만큼 배열 생성
	for (int i = 0; i < n; i++) //개수만큼 숫자 입력
		cin >> data[i]; 
	bool result = cons(data, n); //연속된 수열로 정렬 가능한지 확인
	if (result)
		cout << "YES" << endl; //참이면 yes 출력
	else cout << "NO" << endl; //거짓이면 no 출력

	delete[] data;//배열 삭제
	return 0;
}