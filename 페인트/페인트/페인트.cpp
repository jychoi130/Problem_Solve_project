/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������*/
#include <iostream>
#include <vector>
using namespace std;

const int MAX_SEAT_NUMBER = 1000;//�ڸ��� �ִ� ����
const int MAX_COLOR_NUMBER = 100; //���� �ִ� ����

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
void fillFrequencyTable(int data[], int n, int table[]) //���� ���� �ڸ��� ���
{
	for (int i = 0; i < MAX_COLOR_NUMBER; i++) 
		table[i] = 0; //�迭 0���� �ʱ�ȭ
	for (int i = 0; i < n; i++) //���� ���� ���� ����
	{
		int color = data[i]; 
		table[color] += 1;
	}
}
void solve(int n, int m, const Painting* paintings)
{
	int* seats = new int[n];
	for (int i = 0; i < n; i++) //�¼� �� ��ŭ�� �迭 0���� �ʱ�ȭ
		seats[i] = 0;
	for (int i = 0; i < m; i++) //��ĥ�� ����� ��
	{
		const Painting &p = paintings[i];
		for (int j = p.left; j <= p.right; j++) //��ĥ�� ù �ڸ����� ������ �ڸ�����
			seats[j] = p.color; //�� ����
	}

	int *table = new int[MAX_COLOR_NUMBER];
	fillFrequencyTable(seats, n, table); //������ �ڸ� ���� ���ϱ� ���� �Լ�

	int mincolor = seats[0]; //���� ���� ��
	int maxcolor = seats[0]; //���� ū ��

	for (int color = 0; color < MAX_COLOR_NUMBER; color += 1)
	{
		if (table[color] == 0) //���� 0���� ��� ���� ������
			continue;

		if (table[mincolor] > table[color])
			mincolor = color; //���� �ּҰ� �ƴ� �� ����
		if (table[maxcolor] < table[color])
			maxcolor = color; //���� �� �ִ밡 �ƴ� �� ����
	}

	cout << maxcolor << endl << mincolor << endl; //�� ���
	delete[] seats; //�迭 ����
}
int main()
{
	int n, m;
	cin >> n >> m; //n�¼� ��,m ��ĥ ��� ��

	Painting* paintings = new Painting[n];
	for (int i = 0; i < m; i++)
	{
		cin >> paintings[i].left >> paintings[i].right >> paintings[i].color;
		paintings[i].left -= 1; //�¼� ��ȣ ���߱� ���ؼ�
		paintings[i].right -= 1; //�¼� ��ȣ ���߱� ����
	}
	solve(n, m, paintings);
	return 0;
}