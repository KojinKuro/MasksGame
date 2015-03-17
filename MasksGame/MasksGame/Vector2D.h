//
//  Vector2D.h
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__Vector2D__
#define __MasksGame__Vector2D__

class Vector2D
{
public:
    Vector2D(int x, int y) : v_X(x) , v_Y(y) {}
    
    int getX() {return v_X;}
    int getY() {return v_Y;}
    
    void setX(int x) {v_X = x;}
    void setY(int y) {v_Y = y;}
    
    Vector2D operator+(Vector2D& v2)
    {
        return Vector2D(v_X + v2.v_X, v_Y + v2.v_Y);
    }
    friend Vector2D& operator+=(Vector2D& v1, Vector2D& v2)
    {
        v1.v_X += v2.v_X;
        v1.v_Y += v2.v_Y;
        return v1;
    }
    
    Vector2D operator-(Vector2D& v2)
    {
        return Vector2D(v_X - v2.v_X, v_Y - v2.v_Y);
    }
    friend Vector2D& operator-=(Vector2D& v1, Vector2D& v2)
    {
        v1.v_X -= v2.v_X;
        v1.v_Y -= v2.v_Y;
        return v1;
    }
    
    Vector2D operator*(float num)
    {
        return Vector2D(num * v_X, num * v_Y);
    }
    Vector2D& operator*=(float num)
    {
        v_X *= num;
        v_Y *= num;
        return *this;
    }
    
    Vector2D operator/(float num)
    {
        return Vector2D(v_X/num, v_Y/num);
    }
    Vector2D& operator/=(float num)
    {
        v_X /= num;
        v_Y /= num;
        return *this;
    }
private:
    int v_X;
    int v_Y;
};

#endif /* defined(__MasksGame__Vector2D__) */
