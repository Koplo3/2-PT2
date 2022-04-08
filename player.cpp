#include "player.hpp"
#include <graphics.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

Player::Player(){
    x = 0;
    y = 0;
    size = 0;
    dXY = 0;
    health = 0;
    point = 0;
}
Player::Player(int _x, int _y, int _s){
    x = _x;
    y = _y;
    size = _s;
    dXY = 10;
    health = 3;
    point = 0;
}

int Player::getX() const{ return x; }
int Player::getY() const{ return y; }
int Player::getSize() const{ return size; }
int Player::getD() const{ return dXY; }
int Player::getHealth() const{ return health; }
int Player::getPoint() const{ return point; }
int Player::getRight() const{ return x + size; }
int Player::getBottom() const{ return y + size; }

void Player::setX(int value){ x = value; }
void Player::setY(int value){ y = value; }
void Player::setSize(int value){ size = value; }
void Player::set(int _x, int _y, int _s){
    x = _x;
    y = _y;
    size = _s;
}
void Player::setD(int value){ dXY = value; }
void Player::setHealth(int value){ health = value; }
void Player::setPoint(int value){ 
    point = value;
    if(point < 0){ point = 0; }
}
void Player::set(int _x, int _y, int _s, int _dxy, int _h){
    set(_x, _y, _s);
    dXY = _dxy;
    health = _h;
}

void Player::draw(){
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    rectangle(x, y, getRight(), getBottom());
    
}
void Player::undraw(){
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    bar(x, y, getRight() + 1, getBottom() + 1);
}
void Player::move(){
    undraw();
    
    char c = getch();
    switch(c) {
    case KEY_UP:
        y-=dXY;
        break;
    case KEY_DOWN:
        y+=dXY;
        break;
    case KEY_LEFT:
        x-=dXY;
        break;
    case KEY_RIGHT:
        x+=dXY;
        break;
    default:
        break;
    }

    if(x < 0){ x = 0; }
    else if(x + size > getmaxwidth()){ x = getmaxwidth() - size; }
    if(y < 0){ y = 0; }
    else if(y + size > getmaxheight()){ y = getmaxheight() - size; }

    draw();
}

void Player::reset(){
    undraw();
    set(50, getmaxheight() / 2, size);
    draw();
}

void Player::displayScore(){
    bar((getmaxwidth()-299),0, getmaxwidth(),getmaxheight());
    settextstyle(10, HORIZ_DIR, 5);
    outtextxy((getmaxwidth()-250), 100 ,"SCORE");
    outtextxy((getmaxwidth()-250), 250 ,"LIFE");

    string skor=to_string(point);
    char *cstr = new char[skor.length() + 1];
    strcpy(cstr, skor.c_str());

    
    string life = to_string(health);
    char *lifeP = new char[life.length() + 1];
    strcpy(lifeP, life.c_str());
        
    outtextxy((getmaxwidth()-250), 150 , cstr);
    outtextxy((getmaxwidth()-250), 300 ,lifeP);
        
    delete [] cstr;
    delete [] lifeP;
}