#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;
bool gameover;
int headx,heady,fruitx,fruity,score;
const int height =20;
const int width = 20;
enum eDirection{STOP=0,UP,DOWN,RIGHT,LEFT};
eDirection dir;
void setup(){
gameover=false;
headx=width/2;
heady=height/2;
fruitx=rand()%width;
fruity=rand()%height;
}
void draw(){
    system("cls");
for(int i=0; i<width;i++)
{
    cout<<'#';
}
cout<<endl;
for(int i=0; i<height;i++){
    for(int j=0;j<width;j++){
    if(j==0||j==width-1)
    {
        cout<<'#';
    }
    else if(i==heady&j==headx){
        cout<<'O';
    }
    else if(i==fruity&&j==fruitx){
        cout<<'F';
    }
    else{
    cout<<' ';}}
cout<<endl;}
for(int i=0; i<width;i++)
{
    cout<<'#';
}
cout<<endl;
cout<<"score:"<<score<<endl;
}
void input(){
    if(kbhit())
    {
        switch(getch()){
            case 'w':
                dir=UP;
                break;
            case 'd':
                dir=RIGHT;
                break;
            case 'a':
                dir=LEFT;
                break;
            case 's':
                dir=DOWN;
                break;
        default:
                break;
        }
    }

}
void logic(){
switch (dir)
{
case UP:
    heady--;
    break;
case DOWN:
    heady++;
    break;
case RIGHT:
    headx++;
    break;
case LEFT:
    headx--;
    break;    
default:
    break;
}
if(headx<0||headx>width||heady<0||heady>height)
 {
    gameover=true;
 }
 if(fruitx==headx&&fruity==heady)
 {
    score++;
fruitx=rand()%width;
fruity=rand()%height;
 }
}
int main()
{
    setup();
    while(!gameover){
        draw();
        input();
        logic();
        Sleep(50);
    }
}