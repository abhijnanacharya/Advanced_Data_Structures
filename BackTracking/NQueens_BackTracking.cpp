#include<bits/stdc++.h>
#define N 4
using namespace std;

void PrintBoard(int board[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<< board[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool isSafe(int board[N][N],int row, int col){
	for(int i=0;i<col;i++)
		if(board[row][i]==1) return false;

	for(int i=row, j=col; i>=0 and j>=0;i--,j--)
		if(board[i][j]) return false;

	for(int i=row, j=col; i<N and j>=0;i++,j--)
		if(board[i][j]) return false;

	return true;
}
bool Sol(int board[N][N], int col){
	//Base: ALL QUEENS have been placed successfully hence return true
	if(col>=N){
		return true;
	}


	for(int i=0;i<N;i++){
		if(isSafe(board,i,col)){
			board[i][col]=1;//Mark the postition of the QUEEN

			if(Sol(board,col+1))//Try to place the QUEEN in the next column 
				return true;//If Possible return true

			board[i][col]=0;//Else BackTrack and edit the last edits in the board
		}
	}
	return false;
}

int main(){

	int board[N][N]={ {0,0,0,0},
					  {0,0,0,0},
					  {0,0,0,0},
					  {0,0,0,0}};

	if(Sol(board,0)==false)
		{cout<<"Soln DNE"; return INT_MAX;}
	else{
			PrintBoard(board);
		}
	return 0;
}