#include <iostream>
#include <vector>
using namespace std;

const int MAX_SEAT_NUMBER = 1000;//자리의 최대 개수
const int MAX_COLOR_NUMBER = 100; //색의 최대 개수

class Painting {
public:
	int left;
	int right;
	int color;

	Painting(){}
	
	Painting(int left, int right, int color)
	{
		this->left = left;
		this->right = right;
		this->color = color;
	}
};
void fillFrequencyTable(int data[], int n, int table[]) //색에 따른 자릿수 계산
{
	for (int i = 0; i < MAX_COLOR_NUMBER; i++) 
		table[i] = 0; //배열 0으로 초기화
	for (int i = 0; i < n; i++) //색에 따른 개수 구함
	{
		int color = data[i]; 
		table[color] += 1;
	}
}
void solve(int n, int m, const Painting* paintings)
{
	int* seats = new int[n];
	for (int i = 0; i < n; i++) //좌석 수 만큼의 배열 0으로 초기화
		seats[i] = 0;
	for (int i = 0; i < m; i++) //색칠할 방법의 수
	{
		const Painting &p = paintings[i];
		for (int j = p.left; j <= p.right; j++) //색칠할 첫 자리부터 마지막 자리까지
			seats[j] = p.color; //색 대입
	}

	int *table = new int[MAX_COLOR_NUMBER];
	fillFrequencyTable(seats, n, table); //색마다 자리 숫자 구하기 위한 함수

	int mincolor = seats[0]; //가장 작은 값
	int maxcolor = seats[0]; //가장 큰 값

	for (int color = 0; color < MAX_COLOR_NUMBER; color += 1)
	{
		if (table[color] == 0) //색이 0개인 경우 다음 색으로
			continue;

		if (table[mincolor] > table[color])
			mincolor = color; //값이 최소가 아닐 시 변경
		if (table[maxcolor] < table[color])
			maxcolor = color; //값이 더 최대가 아닐 시 변경
	}

	cout << maxcolor << endl << mincolor << endl; //답 출력
	delete[] seats; //배열 삭제
}
int main()
{
	int n, m;
	cin >> n >> m; //n좌석 수,m 색칠 방법 수

	Painting* paintings = new Painting[n];
	for (int i = 0; i < m; i++)
	{
		cin >> paintings[i].left >> paintings[i].right >> paintings[i].color;
		paintings[i].left -= 1; //좌석 번호 맞추기 위해서
		paintings[i].right -= 1; //좌석 번호 맞추기 위해
	}
	solve(n, m, paintings);
	return 0;
}
