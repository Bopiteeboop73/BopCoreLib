#pragma once

#include <ostream>

#include "config.h"

namespace bop {
    struct Vector2 {
        Vector2(Float pX, Float pY);

        Float X, Y;

        Vector2& operator+=(const Vector2 &pOther);
        Vector2& operator-=(const Vector2 &pOther);
        Vector2 operator-() const;
        Vector2& operator*=(Float pScale);
        Vector2& operator/=(Float pScale);

        friend std::ostream& operator<<(std::ostream& pOs, const Vector2& pV);

        [[nodiscard]] Float SqrMagnitude() const;
        [[nodiscard]] Float Magnitude() const;
        [[nodiscard]] Vector2 Normalised() const;
        [[nodiscard]] Vector2 GetNormal() const;

        [[nodiscard]] Float GetAngle(Vector2 pOther = {1, 0}) const;

    };

    Vector2 operator+(const Vector2 &pVec1, const Vector2 &pVec2);

    Vector2 operator-(const Vector2 &pVec1, const Vector2 &pVec2);


    Vector2 operator*(const Vector2 &pVec, Float pScale);
    Vector2 operator*(Float pScale, const Vector2 &pVec);

    Vector2 operator/(const Vector2 &pVec, Float pScale);
    Vector2 operator/(Float pScale, const Vector2 &pVec);

    bool operator==(const Vector2 &pVec1, const Vector2 &pVec2);
    bool operator!=(const Vector2 &pVec1, const Vector2 &pVec2);


    Float dot(Vector2 pVec1, Vector2 pVec2);
    Float cross(Vector2 pVec1, Vector2 pVec2);


}
