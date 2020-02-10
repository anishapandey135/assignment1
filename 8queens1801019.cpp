/*1.State space:                Here sate space is a 8x8 matrix where the position of a queen is represented by 1
2.State transition operator:    Adding a new queen which is denoted by 1 in the subsequent row.
3.intitial state:               A 8 x 8 null matrix.
4.Goal state:                   When all the rows are filled with a single queen at non attacking positions,
*/

#include<iostream>
#include<queue>

using namespace std;

bool solved=false;
int cost=0;
struct chessboard{
	int matrix[8][8];
	int queens;
};
queue<chessboard> q1;

void print(chessboard &temporaray){
	cout<<"temp"<<endl;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cout<<temporaray.matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}



bool validity(chessboard &temporaray){
	int q=temporaray.queens,p=0,i,i2;
	for(i=0;i<8;i++){
		if(temporaray.matrix[q-1][i]==1) 
			break;
	}
	for(int j=q-2;j>=0;j--){
		if(temporaray.matrix[j][i]==1){
			return false;
		}
	}
	i2=i-1;
	for(int j=q-2;j>=0;j--){
		if(j<0||i2<0) 
			break;
		if(temporaray.matrix[j][i2]==1) 
			return false;
		i2--;
	}
	i2=i+1;
	for(int j=q-2;j>=0;j--){
		if(j<0||i2>7) 
			break;
		if(temporaray.matrix[j][i2]==1) 
			return false;
		i2++;
	}
	return true;
}



void findstate(queue<chessboard> &q1){
	chessboard temporaray;
	bool oc=true;
	temporaray=q1.front();
	q1.pop();
	int q=temporaray.queens;
        if(temporaray.queens==8) {
    	print(temporaray);
    	cout<<"Got the solution\n"<<endl;
    	cout<<"Cost: "<<cost<<endl;
    	solved=true;
    	return;
	}
	for(int i=0;i<8;i++){
		temporaray.matrix[q][i]=1;
		temporaray.queens++;
		if(q==0||validity(temporaray)){
			print(temporaray);
			q1.push(temporaray);
			cost++;
		}
		temporaray.queens--;
		temporaray.matrix[q][i]=0;
	}
}


int main(){
	chessboard board1;
    for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			board1.matrix[i][j]=0;
		}
	}
	board1.queens=0;
	q1.push(board1);
    while(!q1.empty()&&solved==false){
    	findstate(q1);
}
return 0;
}
    	

