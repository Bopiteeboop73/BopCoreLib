#pragma once

#include <ostream>

#include "config.h"

namespace bop {
    struct Vector2 {
        Vector2(Decimal pX, Decimal pY);

        Decimal X, Y;

        Vector2& operator+=(const Vector2 &pOther);
        Vector2& operator-=(const Vector2 &pOther);
        Vector2 operator-() const;
        Vector2& operator*=(Decimal pScale);
        Vector2& operator/=(Decimal pScale);

        friend std::ostream& operator<<(std::ostream& pOs, const Vector2& pV);

        [[nodiscard]] Decimal SqrMagnitude() const;
        [[nodiscard]] Decimal Magnitude() const;
        [[nodiscard]] Vector2 Normalised() const;
        [[nodiscard]] Vector2 GetNormal() const;

        [[nodiscard]] Decimal GetAngle(Vector2 pOther = {1, 0}) const;

    };

    Vector2 operator+(const Vector2 &pVec1, const Vector2 &pVec2);

    Vector2 operator-(const Vector2 &pVec1, const Vector2 &pVec2);


    Vector2 operator*(const Vector2 &pVec, Decimal pScale);
    Vector2 operator*(Decimal pScale, const Vector2 &pVec);

    Vector2 operator/(const Vector2 &pVec, Decimal pScale);

    bool operator==(const Vector2 &pVec1, const Vector2 &pVec2);
    bool operator!=(const Vector2 &pVec1, const Vector2 &pVec2);


    Decimal dot(Vector2 pVec1, Vector2 pVec2);
    Decimal cross(Vector2 pVec1, Vector2 pVec2);


}
