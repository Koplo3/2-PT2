#ifndef BALL_H
#define BALL_H
#include "point.hpp"
#include "player.hpp"

class Bomb : public Point{
    private:
        int color;
        int dy;
    public:
        Bomb();
        Bomb(int _x, int _y, int _size, int _color);

        int getRight() const;
        int getBottom() const;
        int getColor() const;
        int getSpeed() const;
        Player *getPlayer() const;

        void setColor(int value);
        void setSpeed(int value);
        void set(int _x, int _y, int _s, int _c);
        void set();
        void setPlayer(Player *value);

        void draw();
        void undraw() const;
        void move();
        int collision() const;
        void onCollide();
};

#endif