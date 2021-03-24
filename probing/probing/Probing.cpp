/*전자컴퓨터공학부 소프트웨어공
180078 최지연*/
#include<iostream>
#include<vector>
using namespace std;

class TicketTable {
public:
	vector<bool>used;
	int length;
	TicketTable(int length)
	{
		this->length = length;
		this->used.assign(length, false);
	}
	int findEmptyIndexByUserId(int userId)
	{
		int index = userId % length; //맨 처음 시도 할 번호
		while (this->isEmpty(index) == true) //이미 사용된거면 패스
			index = (index + 1) % length; //다음 번호 체크
		return index;
	}
	bool isEmpty(int ticketIndex)
	{
		return this->used[ticketIndex]; //사용여부 
	}
	void setUsed(int index, bool status)
	{
		this->used[index] = status;
	}
};
vector<int>getTicketNumbers(int n, int m, const vector<int>&ids)
{
	vector<int> tickets;
	TicketTable table = TicketTable(n);
	for (int i = 0; i < m; i++)
	{
		int userId = ids[i];
		int ticketIndex = table.findEmptyIndexByUserId(userId);
		tickets.push_back(ticketIndex); //변수 추가
		table.setUsed(ticketIndex, true);
	}
	return tickets;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> ids(m);
	for (int i = 0; i < m; ++i)
		cin >> ids[i];
	vector<int> tickets = getTicketNumbers(n, m, ids);
	for (int i = 0; i < tickets.size(); ++i)
		cout << tickets[i] << endl;
}