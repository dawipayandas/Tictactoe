#include<iostream>
using namespace std;

char sample[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};// array to store x or o as per user input
int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};// stores -1 for used space
int row;
int column;


int checkwin(int x)
{
if(x<9)// grid isnt full
{
if(sample[0][0]!=' ' && sample[0][0]==sample[0][1] && sample[0][1]==sample[0][2])// 1=2=3 and not empty
return 1;
else if(sample[0][0]!=' ' && sample[0][0]==sample[1][0] && sample[1][0]==sample[2][0])// 1=4=7 and not empty
return 1;
else if(sample[1][0]!=' ' && sample[1][0]==sample[1][1] && sample[1][1]==sample[1][2])// 4=5=6 and not empty
return 1;
else if(sample[0][1]!=' ' && sample[0][1]==sample[1][1] && sample[1][1]==sample[2][1])// 2=5=8 and not empty
return 1;
else if(sample[2][0]!=' ' && sample[2][0]==sample[2][1] && sample[2][1]==sample[2][2])// 7=8=9 and not empty
return 1;
else if(sample[0][2]!=' ' && sample[0][2]==sample[1][2] && sample[1][2]==sample[2][2])// 3=6=9 and not empty
return 1;
else if(sample[0][0]!=' ' && sample[0][0]==sample[1][1] && sample[1][1]==sample[2][2])// 1=5=9 and not empty
return 1;
else if(sample[0][2]!=' ' && sample[0][2]==sample[1][1] && sample[1][1]==sample[2][0])// 3=5=7 and not empty
return 1;
else
return 0;// game continues
}
else
return -1;//grid is full hence draw
}

void tictactoe(int count)
{
int input;
cout <<"Player "<< (count%2 + 1) <<" choice: ";
cin >> input;// input from user
for(int i=0;i<=2;i++){
for(int j=0;j<=2;j++){
if (input == arr[i][j]){
//stores row as column in thier respective variables
row=i;
column=j;
}
}
}
if(sample[row][column]!=' ')
arr[row][column]=-1;// condition to check in the user has input same input twice
if( arr[row][column]==-1){
cout <<" --Already entered, Please enter again-- \n";
tictactoe(count);// recursively calls tictactoe 
}
if(arr[row][column]!=-1 && count %2==0)
{
sample[row][column]='x';// puts x for first player
//Shows input in the grid
cout << "      |      |    \n";
cout << "  "<<sample[0][0]<<"   |  "<<sample[0][1]<<"   |  "<<sample[0][2]<<endl;
cout << " _____|______|_____ \n";
cout << "      |      |    \n";
cout << "  "<<sample[1][0]<<"   |  "<<sample[1][1]<<"   |  "<<sample[1][2]<<endl;
cout << " _____|______|_____ \n";
cout << "      |      |    \n";
cout << "  "<<sample[2][0]<<"   |  "<<sample[2][1]<<"   |  "<<sample[2][2]<<endl;
cout << "      |      |    \n";
count++;// increments count to check at last if the grid is full
int f=checkwin(count);// stores return variable of checkwin() as 1 if player won and -1 if grid is full; 0 to continue
if(f==-1){
cout<<"---Match DRAW---\n";
exit(0);
}
else if(f==1){
cout<<"Player 1 WINS!!!\n";
exit(0);
}
else
tictactoe(count);
}
if(arr[row][column]!=-1 && count %2==1)
{
/* Same for player 2 as player 1 */
sample[row][column]='o';
cout << "      |      |    \n";
cout << "  "<<sample[0][0]<<"   |  "<<sample[0][1]<<"   |  "<<sample[0][2]<<endl;
cout << " _____|______|_____ \n";
cout << "      |      |    \n";
cout << "  "<<sample[1][0]<<"   |  "<<sample[1][1]<<"   |  "<<sample[1][2]<<endl;
cout << " _____|______|_____ \n";
cout << "      |      |    \n";
cout << "  "<<sample[2][0]<<"   |  "<<sample[2][1]<<"   |  "<<sample[2][2]<<endl;
cout << "      |      |    \n";
count++;
int f=checkwin(count);
if(f==-1){
cout<<"---Match DRAW---\n";
exit(0);
}
else if(f==1){
cout<<"Player 2 WINS!!!\n";
exit(0);
}
else
tictactoe(count);
}

}


int main()
{
/* Shows grid as

      |      |    
  1   |  2   |  3
 _____|______|_____ 
      |      |    
  4   |  5   |  6
 _____|______|_____ 
      |      |    
  7   |  8   |  9
      |      |    

*/
cout << "      |      |    \n";
cout << "  "<<arr[0][0]<<"   |  "<<arr[0][1]<<"   |  "<<arr[0][2]<<endl;
cout << " _____|______|_____ \n";
cout << "      |      |    \n";
cout << "  "<<arr[1][0]<<"   |  "<<arr[1][1]<<"   |  "<<arr[1][2]<<endl;
cout << " _____|______|_____ \n";
cout << "      |      |    \n";
cout << "  "<<arr[2][0]<<"   |  "<<arr[2][1]<<"   |  "<<arr[2][2]<<endl;
cout << "      |      |    \n";

tictactoe(0);
return 0;
}
