//
// Created by meanx on 05/12/2022.
//

#include <EngineCore/Utils/Constants.h>
#include <valarray>
#include "EngineCore/Maths/Vector2.h"

Vector2::Vector2(const Vector2 &vector2) {
    m_point[0] = vector2.x();
    m_point[1] = vector2.y();
}

Vector2::Vector2(double x, double y) {
    m_point[0] = x;
    m_point[1] = y;
}

Vector2 Vector2::operator-() const {
    return Vector2(-x(), -y());
}

bool Vector2::operator==(const Vector2 &vector2) const {
    Vector2 diff = *this - vector2;
    return diff.sqrAbs() < Constants::Epsilon;
}

bool Vector2::operator!=(const Vector2 &vector2) const {
    return !(*this == vector2);
}

Vector2 Vector2::operator+(const Vector2 &vec) const {
    return Vector2(x() + vec.x(), y() + vec.y());
}

Vector2 Vector2::operator-(const Vector2 &vec) const {
    return Vector2(x() - vec.x(), y() - vec.y());
}

Vector2 Vector2::operator*(double number) const {
    return Vector2(x() * number, y() * number);
}

double Vector2::dot(const Vector2 &vec) const {
    return x() * vec.x() + y() * vec.y();
}

Vector2 Vector2::operator/(double number) const {
    if (std::abs(number) > Constants::Epsilon) {
        return Vector2(x() / number, y() / number);
    } else {
        throw std::domain_error{"Vector2::operator /(double number): division by zero"};
    }
}

double Vector2::sqrAbs() const {
    return x() * x() + y() * y();
}

double Vector2::abs() const {
    return std::sqrt(sqrAbs());
}

const Vector2 Vector2::normalized() const {
    double vecAbs = abs();
    return vecAbs > Constants::Epsilon ? Vector2(*this) / abs() : Vector2(0, 0);
}
