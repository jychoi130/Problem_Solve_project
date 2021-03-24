/*전자컴퓨터공학부 소프트웨어공
180078 최지연
괄호문자열*/

#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

class Parenthesis {
public:
	bool type;
	int index;

	Parenthesis(int index, bool type)//type>열림/닫힘 구분
	{
		this->index = index;
		this->type = type;
	}
	Parenthesis(int index, char c)
	{
		this->index = index;
		if (c == '(') {//열린 괄호
			this->type = true;
		}
		else {//닫힌 괄호
			this->type = false;
		}
	}
};
bool isValidParentheses(const vector<Parenthesis>&parentheses) { //열린괄호 들어오면 저장, 닫힌괄호 들어오면 열린괄호 하나 뺌
	stack<Parenthesis> st;
	for (int i = 0; i < parentheses.size(); i++)
	{
		Parenthesis p = parentheses[i];
		if (p.type == true) //열린괄호
		{
			st.push(p);//값 넣는다
		}
		else if (p.type == false)//닫힌괄호
		{
			if (st.size() > 0)
				st.pop();//열린괄호 갯수가 남은경우 팝
			else return false;//열린괄호 갯수 없는경우 false
		}
	}
	if (st.size() > 0)//닫힌괄호보다 열린괄호 갯수가 많음
		return false;
	return true;
}

void process(int caseIndex)
{
	string str;
	cin >> str;

	vector<Parenthesis>parentheses; //모든 위치 접근 가능하도록 벡터로 선언
	for (int i = 0; i < str.length(); ++i) {
		parentheses.push_back(Parenthesis(i, str[i]));//tail에 저장
	}

	bool isValid = isValidParentheses(parentheses);

	if (isValid) //괄호 갯수가 동일
	{
		cout << "YES" << endl; //yes 출력
	}
	else {//동일 하지않은 경우
		cout << "NO" << endl;//no 출력
	}
}
	int main()
	{
		int caseSize; //케이스 횟수
		cin >> caseSize;

		for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) //케이스 횟수만큼 process돌림
		{
			process(caseIndex);
		}
	}
