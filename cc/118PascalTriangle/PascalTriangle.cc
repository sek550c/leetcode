/* 
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

#include <iostream>
#include <vector>

using namespace std;

int getPascalTriangle(int r, int c) // recursion slow
{
	if (c == 0 || r == c) return 1; // no need r == 0, because r == 0 and r == c occur at the same time
	return getPascalTriangle(r-1, c-1)+getPascalTriangle(r-1, c);
}

void showPascalTriangle(vector<vector<int>> PT)
{
	for (int i = 0; i < PT.size(); i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			cout<<PT[i][j]<<" ";
		}
		cout<<endl;
	}
}

vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> res;
	// NOTE: need to init the 2-dim vector, otherwise cause Segmentation fault (core dumped)
	res.resize(numRows); // init row
	for(int i = 0; i < numRows; i++)
	{
		res[i].resize(i+1); // init col
	}
	
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			res[i][j] = getPascalTriangle(i, j);
		}
	}
	return res;
}

vector<vector<int>> generate2(int numRows)
{
	vector<vector<int>> res;
	// NOTE: need to init the 2-dim vector, otherwise cause Segmentation fault (core dumped)
	res.resize(numRows); // init row
	for(int i = 0; i < numRows; i++)
	{
		res[i].resize(i+1); // init col
	}
	// init end
	
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			if (j == 0 || i == j)
				res[i][j] = 1;
			else
				res[i][j] = res[i-1][j-1]+res[i-1][j]; // use previous info
		}
	}
	return res;
}

 vector<vector<int>> generate3(int numRows) 
 {
    vector<vector<int>> res(numRows);

    for (int i = 0; i < numRows; i++) 
    {
        res[i].resize(i + 1);
        res[i][0] = res[i][i] = 1; // first and last is 1

        for (int j = 1; j < i; j++) // middle part
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
    }
    
    return res;
}

int main()
{
	int row = 5;
	showPascalTriangle(generate2(row));
	return 0;
}
