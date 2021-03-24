#include <iostream>
using namespace std;

bool isinside(long long x, long long y, long long r) //픽셀이 원에 포함되는지 확인
{
	long long sqd = x * x + y * y;  
	if (sqd < r*r) //값이 원의 크기보다 작으면
		return true;
	return false;
}
void testcase(int caseindex)
{
	long long r; //반지름 받을 변수
	scanf("%lld", &r); //반지름 입력
	long long sum = 0; //1사분면의 픽셀 개수 
	long long y = r; //반지름 길이 y축에 입력
	for (long x = 0; x <= r; x++)
	{
		long long height = 0;
		for (; y >= 0; y--) //y축을 위에서부터 확인
		{
			if (isinside(x, y, r)) { //isinside가 참이면 밑의 픽셀은 전부 포함된다.
				height = y + 1; 
				break;
			}
		}
		sum += height; //개수를 더해준다
	}
	cout << "#" << caseindex << endl;
	cout << sum * 4 << endl; //중심을 기준으로 분면이 4개 존재
}
int main()
{
	int casesize; //케이스 개수 받을 변수
	cin >> casesize;
	
	for (int caseindex = 1; caseindex <= casesize; caseindex++) //케이스 개수만큼
		testcase(caseindex); //테스트케이스함수 실행

	return 0;
}
