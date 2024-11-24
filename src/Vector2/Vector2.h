
//--------------------------------------------------

#pragma once

//--------------------------------------------------

template <typename T>
class Vector2 {

  public:
    Vector2();
    Vector2(T both);
    Vector2(T x, T y);

    Vector2<T> operator+ (const Vector2<T>& other) const;
    Vector2<T> operator- (const Vector2<T>& other) const;
    Vector2<T> operator* (T scalar) const;
    Vector2<T> operator/ (T scalar) const;

    Vector2<T>& operator+= (const Vector2<T>& other);
    Vector2<T>& operator-= (const Vector2<T>& other);
    Vector2<T>& operator*= (T scalar);
    Vector2<T>& operator/= (T scalar);

  public:
    T x;
    T y;
};

//--------------------------------------------------

#include "Vector2.inl"

//--------------------------------------------------
