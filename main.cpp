#include <graphics.h>
#include "bomb.hpp"
#include "food.hpp"
#include "player.hpp"

using namespace std;

int main(){
    
    initwindow(getmaxwidth(), getmaxheight(), "Group Project");
    int fC = 10;
    int s = 50;

    Player p(100, getmaxheight() / 2, s);
    p.draw();

    Bomb b[4];
    Food f[fC];
    Point *ptr[4 + fC];

    for(int i = 0; i < fC + 4; i++){
        if(i < 4){ ptr[i] = &b[i]; }
        else{ ptr[i] = &f[i-4]; }
    }

    for(int i = 0; i < fC + 4; i++){
        ptr[i]->setPlayer(&p);
        if(i < 4){
            ptr[i]->set((i + 1) * (getmaxwidth()-300 )/ 5, (rand() % 5) * getmaxheight() / 5, s, GREEN);
        }
        else{
            ptr[i]->set((rand() % ((getmaxwidth()-300) - 2 * s)) + s, (rand() % (getmaxheight() - 2 * s)) + s, s, WHITE);
        }
        ptr[i]->draw();
    }

    while(TRUE){
        p.draw();

        //move() is basically all of function where it put all other function for the bomb / food to react at game
        for(int i = 0; i < fC + 4; i ++){ ptr[i]->move(); }

        if(kbhit()) p.move();
        if(p.getHealth() == 0){ break; }

        p.displayScore();
    }

    readimagefile("Game Over.jpg", 0, 0, getmaxwidth(), getmaxheight());
    PlaySound("sfx_die.wav", NULL, SND_ASYNC);
    system("pause");

    return 0;
}