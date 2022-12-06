//
// Created by meanx on 05/12/2022.
//

#ifndef SFML_PINGPONG_VECTOR2_H
#define SFML_PINGPONG_VECTOR2_H


#include <array>

class Vector2 {
    std::array<double, 2> m_point{};

public:
    Vector2() = default;

    Vector2(const Vector2 &vector2);

    explicit Vector2(double x, double y);

    Vector2 &operator=(const Vector2 &) = default;

    [[nodiscard]] double x() const { return m_point[0]; }

    [[nodiscard]] double y() const { return m_point[1]; }

    [[nodiscard]] Vector2 operator-() const;

    bool operator==(const Vector2 &vector2) const;

    bool operator!=(const Vector2 &vector2) const;

    [[nodiscard]] Vector2 operator+(const Vector2 &vec) const;

    [[nodiscard]] Vector2 operator-(const Vector2 &vec) const;

    [[nodiscard]] double dot(const Vector2 &vec) const;

    [[nodiscard]] Vector2 operator*(double number) const;

    [[nodiscard]] Vector2 operator/(double number) const;

    [[nodiscard]] double sqrAbs() const;

    [[nodiscard]] double abs() const;

    [[nodiscard]] const Vector2 normalized() const;
};


#endif //SFML_PINGPONG_VECTOR2_H
