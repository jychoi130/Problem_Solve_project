/*전자컴퓨터공학부 소프트웨어공
180078 최지연*/
#include <iostream>
using namespace std;

const int MAX_TABLE_LENGTH = 10000; //0~9999개의 경우의 수가 나올 수 있음

void fillFrequencyTable(int data[], int n, int table[]) //데이터 배열 값 체크
{
	int frequent_number = 0; 
	for (int i = 0; i < MAX_TABLE_LENGTH; i++) //table 배열값 0으로 초기화
		table[i] = 0;
	for (int i = 0; i < n; i++) //데이터 배열값 만큼 for문 돌림
	{
		frequent_number = data[i]; //데이터값을 변수에 받음
		table[frequent_number] += 1; //받은 값을 table의 인덱스로 사용하여 +1해준다.
		//즉 0-9999의 인덱스를 가진 테이블 배열에 나온 수 만큼 +1을 해줘서 개수를 세준다.
	}
}
int getFrequentNumber(int data[], int n)//가장 많이 나온 수 찾기
{
	int frequent_number = 0;
	int table[MAX_TABLE_LENGTH]; 
	fillFrequencyTable(data, n, table); //어떤 수가 나왔는지 개수 체크하는 함수
	for (int i = 0; i < MAX_TABLE_LENGTH; i++) //0~9999까지
		if(table[i]>table[frequent_number]) //더 많이 나온 값의 인덱스를 변수에 넣음
			frequent_number = i;
	return frequent_number;
}
int main()
{
	int n;
	cin >> n;

	int* data = new int[n]; //받은 개수만큼 배열 생성
	for (int i = 0; i < n; i++)
		cin >> data[i]; //배열 값 입력해 줌
	int answer = getFrequentNumber(data, n);
	printf("%04d", answer); //숫자 4자리로 출력
	delete[] data; //배열 삭제
	return 0;
}