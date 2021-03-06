/*180078 최지연
CCTV*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

const int MAX = 8; //가로 세로 크기 최댓값
int n, m;
int a[MAX][MAX];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
vector<pair <pair<int, int>, int>> v;
int ans = 100;

void check(int x, int y, int dir, int flag, int num) // 현재 좌표에서 현재 방향으로 감시가능한 구역 체크
{
	if (flag == 1) // 감시 구역 체크
	{
		for (int i = 1; i < max(n, m); i++) // 현재 방향으로 벽이 아닌 모든 구역 확인
		{
			int nx = x + dx[dir] * i;
			int ny = y + dy[dir] * i;
			if (nx >= 0 && ny >= 0 && nx < n && ny < m)
			{
				if (a[nx][ny] == 6) break;
				if (a[nx][ny] == 0) a[nx][ny] = num; // 0인 경우 인자로 받은 num으로 넣어서 구분
			}
		}
	}
	else // 감시 구역 해제
	{
		for (int i = 1; i < max(n, m); i++)
		{
			int nx = x + dx[dir] * i;
			int ny = y + dy[dir] * i;
			if (nx >= 0 && ny >= 0 && nx < n && ny < m)
			{
				if (a[nx][ny] == 6) break;
				if (a[nx][ny] == num) a[nx][ny] = 0; // num 체크 해제
			}
		}
	}
}

void find(int index, int size)
{
	if (index == size) // 모든 감시카메라 확인 후
	{
		int cnt = 0;//감시 되지 않는 부분 수 세기위한 변수
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)//전체 배열에서
			{
				if (a[i][j] == 0) //감시되지 않은 0
					cnt++;// count해주기
			}

		if (cnt < ans) ans = cnt; //cnt값과 ans중에 ans가 더 작을시 cnt값으로 ans를 바꿔준다
		return;
	}

	int x = v[index].first.first;
	int y = v[index].first.second;
	int type = v[index].second;
	int num = index + 7; // 1~6은 사용중

	if (type == 1) // 1번 경우 네 방향 확인
	{
		for (int k = 0; k < 4; k++)
		{
			check(x, y, k, 1, num); // 감시구역 체크
			find(index + 1, size);
			check(x, y, k, 0, num); // 체크 해제
		}
	}
	else if (type == 2) // 2번 경우 양 방향 확인
	{
		for (int k = 0; k < 2; k++)
		{
			check(x, y, k, 1, num); // 현재 방향 체크
			check(x, y, k + 2, 1, num); // 한칸 건너 뛰고 반대방향 체크
			find(index + 1, size);
			check(x, y, k, 0, num);// 체크 해제
			check(x, y, k + 2, 0, num);// 체크 해제
		}
	}
	else if (type == 3) // 3번 경우 직각 방향 확인
	{
		for (int k = 0; k < 4; k++)
		{
			check(x, y, k, 1, num); // 현재 방향 체크
			check(x, y, k + 1 > 3 ? 0 : k + 1, 1, num); // 현재 방향과 직각을 이루는 방향 확인
			find(index + 1, size);
			check(x, y, k, 0, num);// 체크 해제
			check(x, y, k + 1 > 3 ? 0 : k + 1, 0, num);// 체크 해제

		}
	}
	else if (type == 4) // 4번 경우 세 방향 확인
	{
		for (int k = 0; k < 4; k++)
		{
			for (int l = 0; l < 4; l++)
			{
				if (l == k) continue; // 현재 방향 빼고 나머지 세 방향 확인
				check(x, y, l, 1, num);
			}
			find(index + 1, size);
			for (int l = 0; l < 4; l++)
			{
				if (l == k) continue;
				check(x, y, l, 0, num);// 체크 해제
			}
		}
	}
	else if (type == 5) // 5번 경우 전 방향 확인
	{
		for (int k = 0; k < 4; k++)
			check(x, y, k, 1, num);

		find(index + 1, size);

		for (int k = 0; k < 4; k++)
			check(x, y, k, 0, num);// 체크 해제
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m; //세로 가로 길이 설정
	for (int i = 0; i < n; i++) //세로로 한칸
		for (int j = 0; j < m; j++) //가로로 한칸씩
		{
			cin >> a[i][j];//배열 값 입력받는다
			if (a[i][j] >= 1 && a[i][j] <= 5)
			{ 
				v.push_back(make_pair(make_pair(i, j), a[i][j])); //카메라 값 넣는다
			}
		}

	find(0, v.size()); 

	cout << endl<< ans << endl; //결과 출력
}