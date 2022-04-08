#include "food.hpp"
#include "graphics.h"
#include "player.hpp"

Food::Food() : Point(){ fA = 1; }
Food::Food(int _x, int _y, int _s) : Point(_x, _y, _s){
    fA = 1;
}

int Food::getSize() const{ return size / 8; }
int Food::getLeft() const{ return x - size / 8; }
int Food::getTop() const{ return y - size / 8; }
int Food::getRight() const{ return x + size / 8; }
int Food::getBottom() const{ return y + size / 8; }
Player* Food::getPlayer() const{ return p; }

void Food::setSize(int value){ Point::setSize(value); }
void Food::setFoodActive(int value){ fA = value; }
void Food::set(int _x, int _y, int _s){
    Point::set(_x, _y, _s);
}
void Food::set(){
    set((rand() % (getmaxwidth() - 300 - 2 * size)) + size, (rand() % (getmaxheight() - 300 - 2 * size)) + size, size);
}
void Food::set(int _x, int _y, int _s, int _c){
    set(_x, _y, _s);
}

void Food::reset(){
    set((rand() % (getmaxwidth() - 300 - 2 * size)) + size, (rand() % (getmaxheight() - 300 - 2 * size)) + size, size);
    setFoodActive(1);
}

void Food::draw(){
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(x, y, getSize(), getSize());
}
void Food::undraw(){
    setcolor(EMPTY_FILL);
    setfillstyle(SOLID_FILL, EMPTY_FILL);
    fillellipse(x, y, getSize(), getSize());
}

void Food::move(){
    onCollide();
}

int Food::collision() const{
    bool b1 = p->getX() <= getLeft() && getLeft() <= p->getRight();
    bool b2 = p->getX() <= getRight() && getRight() <= p->getRight();
    bool b3 = p->getY() <= getTop() && getTop() <= p->getBottom();
    bool b4 = p->getY() <= getBottom() && getBottom() <= p->getBottom();

    if((b1 || b2) && (b3 || b4)){ return 1; }
    return 0;
}
void Food::onCollide(){
    if(collision() == 0 && fA == 1){
        draw();
    }
    else if(collision() == 1 && fA == 1){
        undraw();
        p->setPoint(p->getPoint() + 1);
        PlaySound("sfx_point.wav", NULL, SND_ASYNC);

        if(p->getHealth() < 5){
            p->setHealth(p->getHealth() + 1);
        }
        fA = 0;
        reset();
    }
}