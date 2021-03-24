/*180078 ������*/
#include<iostream>
using namespace std;

const int MAX_ROW = 9;
const int MAX_COL = 9;

class SudokuBoard {
public:
	int getRowByIndex(int index)
	{
		return(index - 1) / 9 + 1;
	}//��ȣ ������ ���� row ���
	int getColByIndex(int index)
	{
		return(index - 1) % 9 + 1;
	}//��ȣ ������ ���� column ���
	int getGroupByIndex(int index)
	{
		int r = getRowByIndex(index);
		int c = getColByIndex(index);
		return getGroupByPosition(r, c);
	}//��ü ĭ�� 9�׷����� ����
	int getGroupByPosition(int row, int column)
	{
		int left = ((row - 1) / 3) * 3 + 1;
		int offset = ((column - 1) / 3);
		return left + offset;
	}//ĭ�� ��ġ�� �׷� ��ȣ ���
	int getIndexByPosition(int row, int column)
	{
		return (row - 1) * 9 + (column - 1) % 9 + 1;
	}
};
void process(int caseIndex)
{
	int index;
	cin >> index;
	SudokuBoard board = SudokuBoard();
	int row = board.getRowByIndex(index);
	int col = board.getColByIndex(index);
	int group = board.getGroupByIndex(index);
	cout << "Case # " << caseIndex << ":" << endl;
	cout << row << " " << col << " " << group << endl;
}
int main()
{
	int caseSize;
	cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex)
		process(caseIndex);
}