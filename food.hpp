#ifndef FOOD_H
#define FOOD_H
#include "point.hpp"
#include "player.hpp"

class Food : public Point{
    private:
        int fA; //food Activation
    public:
        Food();
        Food(int _x, int _y, int _s);

        int getSize() const;
        int getFoodActive() const;
        int getLeft() const;
        int getTop() const;
        int getRight() const;
        int getBottom() const;
        Player *getPlayer() const;

        void setSize(int value);
        void setFoodActive(int value);
        void set(int _x, int _y, int _s);
        void set();
        void set(int _x, int _y, int _s, int _c);

        void reset();

        void draw();
        void move();
        void undraw();
        int collision() const;
        void onCollide();
};

#endif