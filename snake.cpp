#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;
int width=30;
int height=16;
int x=5,y=5;
int score=0;
int fruitx=(rand()%29);
int fruity=(rand()%13);
int in;
int tailX[100];
int tailY[100];
int taillength=1;
bool gameover=false;
void setup(){
    gameover=false;
   
}
void draw(){
    system("cls");

    for(int i=0;i<=width;i++){
        cout<<"#";
    }cout<<endl;
    for(int i=0;i<height-2;i++){
        for(int j=0;j<width;j++){
            if(j==0 ){
                cout<<"#";
            }
            if(i==y && j==x){
                cout<<"O";
            }
            else if(i==fruity&&j==fruitx){
                cout<<"+";
            }
            else if (j==width-1)
            {
                cout<<"#"<<endl;
            }
           
            else{
                 bool print =false;
                 for(int k=0;k<taillength;k++){
                    if(tailX[k]==j && tailY[k]==i){
                        cout<<"o";
                        print=true;
                    }
                }
                if(!print){
                    cout<<" ";
                }
               
            }
            
        }
    }
     for(int i=0;i<=width;i++){
        cout<<"#";
    }cout<<endl;
    cout<<"Score:"<<score<<endl;
}
void input(){
    in = _getch();
    if(in == 0 || in == 224){
            in= _getch();
            if(in ==72){
                cout<<"Up arrow key"<<endl;
                y=y-1;
                cout<<x<<","<<y<<endl;
            }
            if(in ==80){
                y=y+1;
                cout<<"Down arrow key"<<endl;
                 cout<<x<<","<<y<<endl;
            }
            if(in ==75){
                x=x-1;
                cout<<"Left arrow key"<<endl;
                 cout<<x<<","<<y<<endl;
            }
            if(in ==77){
                x=x+1;
                cout<<"Right arrow key"<<endl;
                 cout<<x<<","<<y<<endl;
            }
    }

}

void logic(){
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
     tailX[0]=x;
    tailY[0]=y;

    for(int i=1;i<taillength;i++){
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;

    }
    if(x==fruitx && y==fruity){
        fruitx=(rand()%29);
        fruity=(rand()%13);
        taillength=taillength+1;
        score++;
    }
    
}
void GameStatus(){
    if(x==-1 or y==-1 or x==29 or y==14){
        gameover=true;
    }
}
int gameoverscreen(){
    while(!_kbhit()){
         system("cls");
 cout<<"Final score:"<<score<<endl;
    cout<<"Game Over"<<endl;
    cout<<"Press any key to close program.";

    }
   return 0;
   
}
int main() {
    setup();
    while (gameover==false){
        draw();
        input();
        logic();  
        GameStatus();
    }
    gameoverscreen();
    

    
   
} 