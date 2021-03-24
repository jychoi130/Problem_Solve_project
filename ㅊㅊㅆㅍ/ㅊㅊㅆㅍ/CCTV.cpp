/*180078 ������
CCTV*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

const int MAX = 8; //���� ���� ũ�� �ִ�
int n, m;
int a[MAX][MAX];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
vector<pair <pair<int, int>, int>> v;
int ans = 100;

void check(int x, int y, int dir, int flag, int num) // ���� ��ǥ���� ���� �������� ���ð����� ���� üũ
{
	if (flag == 1) // ���� ���� üũ
	{
		for (int i = 1; i < max(n, m); i++) // ���� �������� ���� �ƴ� ��� ���� Ȯ��
		{
			int nx = x + dx[dir] * i;
			int ny = y + dy[dir] * i;
			if (nx >= 0 && ny >= 0 && nx < n && ny < m)
			{
				if (a[nx][ny] == 6) break;
				if (a[nx][ny] == 0) a[nx][ny] = num; // 0�� ��� ���ڷ� ���� num���� �־ ����
			}
		}
	}
	else // ���� ���� ����
	{
		for (int i = 1; i < max(n, m); i++)
		{
			int nx = x + dx[dir] * i;
			int ny = y + dy[dir] * i;
			if (nx >= 0 && ny >= 0 && nx < n && ny < m)
			{
				if (a[nx][ny] == 6) break;
				if (a[nx][ny] == num) a[nx][ny] = 0; // num üũ ����
			}
		}
	}
}

void find(int index, int size)
{
	if (index == size) // ��� ����ī�޶� Ȯ�� ��
	{
		int cnt = 0;//���� ���� �ʴ� �κ� �� �������� ����
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)//��ü �迭����
			{
				if (a[i][j] == 0) //���õ��� ���� 0
					cnt++;// count���ֱ�
			}

		if (cnt < ans) ans = cnt; //cnt���� ans�߿� ans�� �� ������ cnt������ ans�� �ٲ��ش�
		return;
	}

	int x = v[index].first.first;
	int y = v[index].first.second;
	int type = v[index].second;
	int num = index + 7; // 1~6�� �����

	if (type == 1) // 1�� ��� �� ���� Ȯ��
	{
		for (int k = 0; k < 4; k++)
		{
			check(x, y, k, 1, num); // ���ñ��� üũ
			find(index + 1, size);
			check(x, y, k, 0, num); // üũ ����
		}
	}
	else if (type == 2) // 2�� ��� �� ���� Ȯ��
	{
		for (int k = 0; k < 2; k++)
		{
			check(x, y, k, 1, num); // ���� ���� üũ
			check(x, y, k + 2, 1, num); // ��ĭ �ǳ� �ٰ� �ݴ���� üũ
			find(index + 1, size);
			check(x, y, k, 0, num);// üũ ����
			check(x, y, k + 2, 0, num);// üũ ����
		}
	}
	else if (type == 3) // 3�� ��� ���� ���� Ȯ��
	{
		for (int k = 0; k < 4; k++)
		{
			check(x, y, k, 1, num); // ���� ���� üũ
			check(x, y, k + 1 > 3 ? 0 : k + 1, 1, num); // ���� ����� ������ �̷�� ���� Ȯ��
			find(index + 1, size);
			check(x, y, k, 0, num);// üũ ����
			check(x, y, k + 1 > 3 ? 0 : k + 1, 0, num);// üũ ����

		}
	}
	else if (type == 4) // 4�� ��� �� ���� Ȯ��
	{
		for (int k = 0; k < 4; k++)
		{
			for (int l = 0; l < 4; l++)
			{
				if (l == k) continue; // ���� ���� ���� ������ �� ���� Ȯ��
				check(x, y, l, 1, num);
			}
			find(index + 1, size);
			for (int l = 0; l < 4; l++)
			{
				if (l == k) continue;
				check(x, y, l, 0, num);// üũ ����
			}
		}
	}
	else if (type == 5) // 5�� ��� �� ���� Ȯ��
	{
		for (int k = 0; k < 4; k++)
			check(x, y, k, 1, num);

		find(index + 1, size);

		for (int k = 0; k < 4; k++)
			check(x, y, k, 0, num);// üũ ����
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m; //���� ���� ���� ����
	for (int i = 0; i < n; i++) //���η� ��ĭ
		for (int j = 0; j < m; j++) //���η� ��ĭ��
		{
			cin >> a[i][j];//�迭 �� �Է¹޴´�
			if (a[i][j] >= 1 && a[i][j] <= 5)
			{ 
				v.push_back(make_pair(make_pair(i, j), a[i][j])); //ī�޶� �� �ִ´�
			}
		}

	find(0, v.size()); 

	cout << endl<< ans << endl; //��� ���
}