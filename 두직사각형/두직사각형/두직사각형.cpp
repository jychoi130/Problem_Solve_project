/*전자컴퓨터공학부 소프트웨어공
180078 최지연*/
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
	
	if(l<=r&&b<=t) //겹치는 부분 존재 시
		return((r - l)*(t - b)); //면적 구해서 리턴

	return 0;
}
void test_case()
{
	int ax, ay, bx, by;
	int px, py, qx, qy;
	cin >> ax >> ay >> bx >> by;
	cin >> px >> py >> qx >> qy;

	int la, ra, ba, ta; //1번 직사각형
	la = min(ax, bx);
	ra = max(ax, bx);
	ta = max(ay, by);
	ba = min(ay, by);

	int lb, rb, bb, tb;//2번 직사각형
	lb = min(px, qx);
	rb = max(px, qx);
	tb = max(py, qy);
	bb = min(py, qy);

	int answer = get_area(la, ra, ta, ba, lb, rb, tb, bb);
	//겹쳐지는 면적 구하기 위해서 사용

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
