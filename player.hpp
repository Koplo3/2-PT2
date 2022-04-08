#ifndef PLAYER_H
#define PLAYER_H

class Player{
    private:
        int x, y, size;
        int dXY;
        int health;
        int point;
    public:
        Player();
        Player(int _x, int _y, int _s);

        int getX() const;
        int getY() const;
        int getSize() const;
        int getD() const;
        int getHealth() const;
        int getPoint() const;
        int getRight() const;
        int getBottom() const;

        void setX(int value);
        void setY(int value);
        void setSize(int value);
        void set(int _x, int _y, int _s);
        void setD(int value);
        void setHealth(int value);
        void setPoint(int value);
        void set(int _x, int _y, int _s, int _dxy, int _h);

        void draw();
        void undraw();
        void move();
        void reset();

        void displayScore();
};
#endif