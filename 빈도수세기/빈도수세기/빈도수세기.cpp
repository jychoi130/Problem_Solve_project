/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������
�󵵼� ����*/

#include<iostream>
#include<map>
using namespace std;

int main()
{
	int n; //�Է°��� �����ϴ� ����
	scanf("%d", &n); //���� �� ����

	map<int, int>frequencyMap; //�ʺ��� ���,Ű ���� ���ڿ� Ƚ���̹Ƿ� int�� ����

	for (int i = 0; i < n; i++) { //�Է� ���� ��ŭ �ݺ�
		int x;//int�� ���� ����
		scanf("%d", &x); //������ �ҷ��ͼ� x�� ����
		frequencyMap[x]++; //0���� �ʱ�ȭ �Ǿ��ִ� ���� �Է� Ƚ����ŭ +1���ش�.
		printf("%d %d\n", frequencyMap.size(), frequencyMap[x]);
		//Ű�� Ƚ�� ������ ���
	}
	return 0;
}