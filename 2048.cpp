#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
using namespace std;

int board[4][4];
int dirrow[] = {1, 0, -1, 0};
int dircol[] = {0, 1, 0, -1};
pair<int, int> generateposition()
{
    int occupied = 1, row, column;
    while (occupied)
    {
        row = rand() % 4;
        column = rand() % 4;
        if (board[row][column] == 0)
            occupied = 0;
    }
    return make_pair(row, column);
}
void rg(){
        pair<int, int> pos = generateposition();
    board[pos.first][pos.second] = 2;


}

void newgame()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i][j] = 0;
        }
    }
rg();
}
void printui()
{   system("cls");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
            {
                cout << "  .  ";
            }
            else
            {
                cout << "  "<<board[i][j]<<"  ";
            }
        }
        cout << "\n";
    }
    cout << "n=new game ,w=up ,s=down ,a=left,d=right\n";
}
bool canmove(int row,int column,int nextrow,int nextcolumn){
    if(nextrow<0||nextcolumn<0||nextrow>=4||nextcolumn>=4||board[row][column]!=board[nextrow][nextcolumn]&&board[nextrow][nextcolumn]!=0){
        return false;
    }
    else
    return true;
}
int move(int dir)
{
int startrow=0;
int startcolumn=0;
int row=1;
int column=1;
if(dir==0){
    startrow=3;
    row=-1;
}
if(dir==1){
    startcolumn=3;
    column=-1;
}
int movepossible=0;
for(int i=startrow;i>=0 && i<4;i+=row){
    for(int j=startcolumn;j>=0 && j<4;j+=column){
        int nexti=i+dirrow[dir];
        int nextj=j+dircol[dir ];
        if(canmove(i,j,nexti,nextj)){
            board[nexti][nextj]+=board[i][j];
               board[i][j]=0;
                movepossible=1;
        };
     


    }
}
if(movepossible==1){
    rg();
}
}

int main()
{

    srand(time(0));
    newgame();
    while (true)
    {   
        printui();
       char ch;
        cin >> ch;
        int direction = 0;
        if (ch == 'n')
        {
            newgame();
        }
        else
        {
            switch (ch)
            {

            case 'w':
                direction = 2;
                break;
            case 's':
                direction = 0;
                break;
            case 'a':
                direction = 3;
                break;
            case 'd':
                direction = 1;
                break;
            case 'q':
                cout << "Game over. Quitting...\n";
                return 0;
            }
            move(direction);
        }
    }
}