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
    cout << "n=new game,q=Quitting,w=up ,s=down ,a=left,d=right\n";
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
int movepossible=0,canmovepossible=0;
do{
movepossible=0;
for(int i=startrow;i>=0 && i<4;i+=row){
    for(int j=startcolumn;j>=0 && j<4;j+=column){
        int nexti=i+dirrow[dir];
        int nextj=j+dircol[dir ];
        if(board[i][j]&&canmove(i,j,nexti,nextj)){
            board[nexti][nextj]+=board[i][j];
               board[i][j]=0;
                movepossible=canmovepossible=1;
        };
     


    }
}}while(movepossible);
if(canmovepossible ==1){
    rg();
}
}
bool isGameOver()
{
   
    for (int dir = 0; dir < 4; ++dir)
    {
        int startrow = (dir == 2) ? 3 : 0;
        int startcolumn = (dir == 3) ? 3 : 0;
        int row = (dir == 0 || dir == 2) ? -1 : 1;
        int column = (dir == 1 || dir == 3) ? -1 : 1;

        for (int i = startrow; i >= 0 && i < 4; i += row)
        {
            for (int j = startcolumn; j >= 0 && j < 4; j += column)
            {
                int nexti = i + dirrow[dir];
                int nextj = j + dircol[dir];

                if (canmove(i, j, nexti, nextj))
                {
                    return false; 
                }
            }
        }
    }

    return true; 
}

int main()
{

    srand(time(0));
    newgame();
    while (true)
    {   
        printui();
       char ch;
        ch=_getch();
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
                cout << "sssQuitting...\n";
                return 0;
            }
            move(direction);
        if (isGameOver())
        {
            printui();
            cout << "You LOOSE !!!. You DUMBASS!!!!\n";
            return 0;
        }
        }
    }
}