#ifndef POINT_H
#define POINT_H
#include "player.hpp"

class Point{
    protected:
        int x, y, size;
        Player *p;
    public:
        Point();
        Point(int _x, int _y, int _size);

        int getX() const;
        int getY() const;
        int getSize() const;

        void setX(int value);
        void setY(int value);
        void setSize(int value);
        void set(int _x, int _y, int _s);
        virtual void set() = 0;
        virtual void set(int _x, int _y, int _s, int _c) = 0;
        void setPlayer(Player *player);

        virtual void draw() = 0;
        virtual void move() = 0; //move() is basically all of function where it put all other function for the bomb / food to react at game
        virtual void onCollide() = 0;
};

#endif