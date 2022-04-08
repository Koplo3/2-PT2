#include "point.hpp"

Point::Point(){
    x = 0;
    y = 0;
    size = 0;
}
Point::Point(int _x, int _y, int _size){
    x = _x;
    y = _y;
    size = _size;
}

int Point::getX() const{ return x; }
int Point::getY() const{ return y; }
int Point::getSize() const{ return size; }

void Point::setX(int value){ x = value; }
void Point::setY(int value){ y = value; }
void Point::setSize(int value){ size = value; }
void Point::set(int _x, int _y, int _s){
    x = _x;
    y = _y;
    size = _s;
}
void Point::setPlayer(Player *player){ p = player; }