/* 
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.(http://sudoku.com.au/TheRules.aspx)

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated. 
*/

#include <iostream>
#include <vector>

using namespace std;

void showSudoku(vector<vector<char>>& board)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool isValidSudoku(vector<vector<char>>& board)
{
	int RowUsed[9][9] = {0}, ColUsed[9][9] = {0}, CellUsed[9][9] = {0}; // NOTE: 0-8	
	for (int r = 0; r < board.size(); r++) // row
	{
		for (int c = 0; c < board[r].size(); c++) // col
		{
			if (board[r][c] != '.') // has number
			{
				int k = (r/3)*3 + c/3; // map to cell number
				int num = board[r][c] - '0' - 1; // num index				
				if (RowUsed[r][num] == 0 && ColUsed[c][num] == 0 && CellUsed[k][num] == 0) // not used
				{				
					RowUsed[r][num] = ColUsed[c][num] = CellUsed[k][num] = 1;
				}
				else return false; // used before
			}
		}		
	}
	return true; // run to this point, no repeated element
}

bool isValidSudoku2(vector<vector<char> > &board)
{
    int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
    
    for(int i = 0; i < board.size(); ++ i)
        for(int j = 0; j < board[i].size(); ++ j)
            if(board[i][j] != '.')
            {
                int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                if(used1[i][num] || used2[j][num] || used3[k][num])
                    return false;
                used1[i][num] = used2[j][num] = used3[k][num] = 1;
            }
    
    return true;
}

int main()
{
	/*vector<vector<char>> sudoku = {	{'5','3','.','.','7','.','.','.','.'},
									{'6','.','.','1','9','5','.','.','.'},
									{'.','9','8','.','.','.','.','6','.'},
									{'8','.','.','.','6','.','.','.','3'},
									{'4','.','.','8','.','3','.','.','1'},
									{'7','.','.','.','2','.','.','.','6'},
									{'.','6','.','.','.','.','2','8','.'},
									{'.','.','.','4','1','9','.','.','5'},
									{'.','.','.','.','8','.','.','7','9'}};
	*/
	vector<vector<char>> sudoku = {	{'1','.','.','.','.','.','.','.','.'},
									{'.','.','.','.','.','.','.','.','1'},
									{'.','.','.','.','.','.','.','.','.'},
									{'.','.','.','.','.','.','.','.','.'},
									{'.','.','.','.','.','.','.','.','.'},
									{'.','.','.','.','.','.','.','.','.'},
									{'.','.','.','.','.','.','.','.','.'},
									{'.','.','.','.','.','.','.','.','.'},
									{'.','.','.','.','.','.','.','.','.'}};
	showSudoku(sudoku);
	if (isValidSudoku(sudoku))
		cout<<"YES, it is a valid sudoku"<<endl;
	else
		cout<<"NO, it isn't a valid sudoku"<<endl;
	
	return 0;
	
}
