#include "bomb.hpp"
#include "point.hpp"
#include <graphics.h>

Bomb::Bomb() : Point(){;
    color = 0;
    dy = 2;
}
Bomb::Bomb(int _x = 0, int _y = 0, int _size = 0, int _color = 0) : Point(_x, _y, _size){
    color = _color;
    dy = 2;
}

int Bomb::getRight() const{ return x + size; }
int Bomb::getBottom() const{ return y + size; }
int Bomb::getColor() const{ return color; }
int Bomb::getSpeed() const{ return dy; }
Player* Bomb::getPlayer() const{ return p; }

void Bomb::setColor(int value){ color = value; }
void Bomb::setSpeed(int value){ dy = value; }
void Bomb::set(int _x, int _y, int _s, int _c){
    Point::set(_x, _y, _s);
    color = _c;
}
void Bomb::set(){
    set(0, 0, 0, 0);
}

void Bomb::draw(){
    setcolor(color);
    rectangle(x, y, getRight(), getBottom());
}
void Bomb::undraw() const{
    setcolor(BLACK);
    rectangle(x, y, getRight(), getBottom());
}
void Bomb::move(){
    undraw();
    y += dy;
    if(getBottom() >= getmaxheight()){
        y = getmaxheight() - size;
        dy = -dy;  
    }
    else if(y <= 0){
        y = 0;
        dy = -dy;
    }
    draw();
    onCollide();
}

int Bomb::collision() const{
    bool b1 = p->getX() <= x && x <= p->getRight();
    bool b2 = p->getX() <= getRight() && getRight() <= p->getRight();
    bool b3 = p->getY() <= y && y <= p->getBottom();
    bool b4 = p->getY() <= getBottom() && getBottom() <= p->getBottom();
    
    if((b1 || b2) && (b3 || b4)){ return 1; }
    return 0;
}

void Bomb::onCollide(){
    if(collision() == 1){
        PlaySound("sfx_hit.wav", NULL, SND_ASYNC);
        p->setHealth(p->getHealth() - 1);
        p->reset();
    }
}