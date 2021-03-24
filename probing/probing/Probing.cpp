/*������ǻ�Ͱ��к� ����Ʈ�����
180078 ������*/
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
		int index = userId % length; //�� ó�� �õ� �� ��ȣ
		while (this->isEmpty(index) == true) //�̹� ���ȰŸ� �н�
			index = (index + 1) % length; //���� ��ȣ üũ
		return index;
	}
	bool isEmpty(int ticketIndex)
	{
		return this->used[ticketIndex]; //��뿩�� 
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
		tickets.push_back(ticketIndex); //���� �߰�
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