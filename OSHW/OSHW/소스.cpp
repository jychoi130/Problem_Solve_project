#include<iostream>
using namespace std;
int main()
{
	int prime,check=1;
	cin >> prime;
	cout << "prime: 2";
	for (int i = 3; i < prime; i++)
	{
		for (int j = 2; j <i; j++)
		{
			check = 1;
			if (i%j == 0)
			{
				check = 0;
				break;
			}
		}
		if (check = 1)
			cout << " " << i;
	}
	cout << endl;
}