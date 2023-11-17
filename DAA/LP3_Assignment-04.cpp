//============================================================================
// Name        : LP3_Assignment-04.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

void solve(int col, int n, vector<vector<string>> &ans, vector<string> &board, vector<int> &left, vector<int> &upperDiag, vector<int> &lowerDiag)
{
	if(col>=n)
	{
		ans.push_back(board);
		return;
	}
	for(int row=0;row<n;row++)
	{
		if(left[row]==0 && upperDiag[n-1+row-col]==0 && lowerDiag[row+col]==0)
		{
			board[row][col]='Q';
			left[row]=1;
			upperDiag[n-1+row-col]=1;
			lowerDiag[row+col]=1;
			solve(col+1,n,ans,board,left,upperDiag,lowerDiag);
			left[row]=0;
			upperDiag[n-1+row-col]=0;
			lowerDiag[row+col]=0;
			board[row][col]='.';
		}
	}
}


void show(int n, vector<string> &board)
{
	for(int i=0;i<n;i++)
	{
		cout<<board[i]<<endl;
	}
	cout<<endl;
}

int main(){
    int n;
    cout << "Enter the board size: ";
    while (!(cin >> n) || n < 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a positive integer: ";
    }

    vector<vector<string>> ans;
	vector<string> board(n);
	string s(n,'.');
	for(int i=0;i<n;i++)
	{
		board[i]=s;
	}
	vector<int> left(n,0);
	vector<int> upperDiag(2*n-1,0);
	vector<int> lowerDiag(2*n-1,0);
	show(n,board);
	cout<<"---------------"<<endl;
	solve(0,n,ans,board,left,upperDiag,lowerDiag);
	for(int i=0;i<ans.size();i++)
	{
		show(n,ans[i]);
		cout<<"---------------"<<endl;
	}
    return 0;
}



/*
Time Complexity: O(N!)
Auxiliary Space: O(N^2)
*/






// bool isSafe(int row, int col, vector<string> board, int n)
   // {
   //     int duprow=row;
   //     int dupcol=col;

   //     while(row>=0 && col>=0)
   //     {
   //         if(board[row][col]=='Q')
   //         return false;
   //         row--;
   //         col--;
   //     }
   //     row=duprow;
   //     col=dupcol;
   //      while(col>=0)
   //     {
   //         if(board[row][col]=='Q')
   //         return false;
   //         col--;
   //     }
   //     row=duprow;
   //     col=dupcol;
   //      while(row<n && col>=0)
   //     {
   //         if(board[row][col]=='Q')
   //         return false;
   //         row++;
   //         col--;
   //     }
   //     return true;
   // }

   // void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
   // {
   //     if(col==n)
   //     {
   //         ans.push_back(board);
   //         return;
   //     }
   //     for(int row=0;row<n;row++)
   //     {
   //         if(isSafe(row,col,board,n)==true)
   //         {
   //             board[row][col]='Q';
   //             solve(col+1,board,ans,n);
   //             board[row][col]='.';
   //         }
   //     }
   // }
