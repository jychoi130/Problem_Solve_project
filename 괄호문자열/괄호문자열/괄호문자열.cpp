/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������
��ȣ���ڿ�*/

#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

class Parenthesis {
public:
	bool type;
	int index;

	Parenthesis(int index, bool type)//type>����/���� ����
	{
		this->index = index;
		this->type = type;
	}
	Parenthesis(int index, char c)
	{
		this->index = index;
		if (c == '(') {//���� ��ȣ
			this->type = true;
		}
		else {//���� ��ȣ
			this->type = false;
		}
	}
};
bool isValidParentheses(const vector<Parenthesis>&parentheses) { //������ȣ ������ ����, ������ȣ ������ ������ȣ �ϳ� ��
	stack<Parenthesis> st;
	for (int i = 0; i < parentheses.size(); i++)
	{
		Parenthesis p = parentheses[i];
		if (p.type == true) //������ȣ
		{
			st.push(p);//�� �ִ´�
		}
		else if (p.type == false)//������ȣ
		{
			if (st.size() > 0)
				st.pop();//������ȣ ������ ������� ��
			else return false;//������ȣ ���� ���°�� false
		}
	}
	if (st.size() > 0)//������ȣ���� ������ȣ ������ ����
		return false;
	return true;
}

void process(int caseIndex)
{
	string str;
	cin >> str;

	vector<Parenthesis>parentheses; //��� ��ġ ���� �����ϵ��� ���ͷ� ����
	for (int i = 0; i < str.length(); ++i) {
		parentheses.push_back(Parenthesis(i, str[i]));//tail�� ����
	}

	bool isValid = isValidParentheses(parentheses);

	if (isValid) //��ȣ ������ ����
	{
		cout << "YES" << endl; //yes ���
	}
	else {//���� �������� ���
		cout << "NO" << endl;//no ���
	}
}
	int main()
	{
		int caseSize; //���̽� Ƚ��
		cin >> caseSize;

		for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) //���̽� Ƚ����ŭ process����
		{
			process(caseIndex);
		}
	}
