#include<bits/stdc++.h>
#define N 5

using namespace std;


void printBoard(bool board[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(board[i][j]==false)
				cout<<"0"<<" ";
			else
				cout<<"1"<<" ";
		}
		cout<<endl;
	}
}


void NQueens(bool board[N][N], int row, bool *cols, bool *rdiag, bool *ldiag){

    //Base
	if(row>=N){
		printBoard(board);
		cout<<endl;
		return;
	}



	for(int col=0;col<N;col++){
		//Now is the tricky part, if you draw a NXN grid and sum up the row and column
		//values you will see that the right diagonals are mapped using a single number
		//and the left diagonals are mapped , similarly the left diagonal can be found using
		//the relation row - col+ length of the board  
		if(cols[col]==false and rdiag[row+col]==false and ldiag[row-col+N-1]==false){
			board[row][col]=true;
			cols[col]=true;
			rdiag[row+col]=true;
			ldiag[row-col+N-1]=true;

			NQueens(board,row+1,cols,rdiag,ldiag);
			//The following lines trigger backtracking edits
			board[row][col]=false;
			cols[col]=false;
			rdiag[row+col]=false;
			ldiag[row-col+N-1]=false;
		}

	}
}




int main(){

	bool board[N][N]={ {0,0,0,0,0},
					  {0,0,0,0,0},
					  {0,0,0,0,0},
					  {0,0,0,0,0},
					  {0,0,0,0,0}};
	bool cols[N]={false};;
	bool ldiag[2*N-1]={false};
	bool rdiag[2*N-1]={false};
	NQueens(board,0,cols,rdiag,ldiag);

	return 0;
}