/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int get_area(int la, int ra, int ta, int ba, int lb, int rb, int tb, int bb)
{
	int l, r, t, b;
	l = max(la, lb);
	r = min(ra, rb);
	t = min(ta, tb);
	b = max(ba, bb);
	
	if(l<=r&&b<=t) //��ġ�� �κ� ���� ��
		return((r - l)*(t - b)); //���� ���ؼ� ����

	return 0;
}
void test_case()
{
	int ax, ay, bx, by;
	int px, py, qx, qy;
	cin >> ax >> ay >> bx >> by;
	cin >> px >> py >> qx >> qy;

	int la, ra, ba, ta; //1�� ���簢��
	la = min(ax, bx);
	ra = max(ax, bx);
	ta = max(ay, by);
	ba = min(ay, by);

	int lb, rb, bb, tb;//2�� ���簢��
	lb = min(px, qx);
	rb = max(px, qx);
	tb = max(py, qy);
	bb = min(py, qy);

	int answer = get_area(la, ra, ta, ba, lb, rb, tb, bb);
	//�������� ���� ���ϱ� ���ؼ� ���

	cout << answer << endl;

}
int main()
{
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++)
		test_case();
	
	return 0;
}
