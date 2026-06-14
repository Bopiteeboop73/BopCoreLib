#pragma once

#include <ostream>

namespace bop {
    struct Vector2 {
        Vector2(float pX, float pY);

        float X, Y;

        Vector2& operator+=(const Vector2 &pOther);
        Vector2& operator-=(const Vector2 &pOther);
        Vector2 operator-() const;
        Vector2& operator*=(float pScale);
        Vector2& operator/=(float pScale);

        friend std::ostream& operator<<(std::ostream& pOs, const Vector2& pV);

        [[nodiscard]] float SqrMagnitude() const;
        [[nodiscard]] float Magnitude() const;
        [[nodiscard]] Vector2 Normalised() const;
        [[nodiscard]] Vector2 GetNormal() const;

        [[nodiscard]] float GetAngle(Vector2 pOther = {1, 0}) const;

    };

    Vector2 operator+(const Vector2 &pVec1, const Vector2 &pVec2);

    Vector2 operator-(const Vector2 &pVec1, const Vector2 &pVec2);


    Vector2 operator*(const Vector2 &pVec, float pScale);
    Vector2 operator*(float pScale, const Vector2 &pVec);

    Vector2 operator/(const Vector2 &pVec, float pScale);
    Vector2 operator/(float pScale, const Vector2 &pVec);

    bool operator==(const Vector2 &pVec1, const Vector2 &pVec2);
    bool operator!=(const Vector2 &pVec1, const Vector2 &pVec2);


    float dot(Vector2 pVec1, Vector2 pVec2);
    float cross(Vector2 pVec1, Vector2 pVec2);


}
