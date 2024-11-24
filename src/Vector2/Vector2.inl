
//--------------------------------------------------

template <typename T>
Vector2<T>::Vector2():
    Vector2 (0, 0) {}

template <typename T>
Vector2<T>::Vector2(T both):
    Vector2 (both, both) {}

template <typename T>
Vector2<T>::Vector2(T x, T y): 
    x(x),
    y(y) {}

//--------------------------------------------------

template <typename T>
Vector2<T>& Vector2<T>::operator+= (const Vector2<T>& other) {
    x += other.x;
    y += other.y;
    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator-= (const Vector2<T>& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator*= (T scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator/= (T scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}

//--------------------------------------------------

template <typename T>
Vector2<T> Vector2<T>::operator+ (const Vector2<T>& other) const {
    Vector2<T> result = *this;
    result += other;
    return result;
}

template <typename T>
Vector2<T> Vector2<T>::operator- (const Vector2<T>& other) const {
    Vector2<T> result = *this;
    result -= other;
    return result;
}

template <typename T>
Vector2<T> Vector2<T>::operator* (T scalar) const {
    Vector2<T> result = *this;
    result *= scalar;
    return result;
}

template <typename T>
Vector2<T> Vector2<T>::operator/ (T scalar) const {
    Vector2<T> result = *this;
    result /= scalar;
    return result;
}

//--------------------------------------------------
