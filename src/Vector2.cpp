#include <cmath>
#include <iosfwd>

#include "BopCoreLib/Vector2.h"

namespace bop {

    Vector2::Vector2(const Float pX, const Float pY): X(pX), Y(pY) {}

    Vector2 & Vector2::operator+=(const Vector2 &pOther) {
        X += pOther.X;
        Y += pOther.Y;

        return *this;
    }

    Vector2 & Vector2::operator-=(const Vector2 &pOther) {
        return *this += -pOther;
    }

    Vector2 Vector2::operator-() const {
        return {-X, -Y};
    }

    Vector2 & Vector2::operator*=(const Float pScale) {
        X *= pScale;
        Y *= pScale;

        return *this;
    }

    Vector2 & Vector2::operator/=(const Float pScale) {
        X /= pScale;
        Y /= pScale;

        return *this;
    }

    Float Vector2::SqrMagnitude() const {
        return X * X + Y * Y;
    }

    Float Vector2::Magnitude() const {
        return sqrt(SqrMagnitude());
    }

    std::ostream & operator<<(std::ostream &pOs, const Vector2 &pV) {
        return pOs << "[" << pV.X << ", " << pV.Y << "]";
    }



    Vector2 Vector2::Normalised() const {
        if (SqrMagnitude() == 0)
            return {0, 0};

        return *this / Magnitude();
    }

    Vector2 Vector2::GetNormal() const {
        return {-Y, X};
    }

    Float Vector2::GetAngle(const Vector2 pOther) const {
        return atan2(cross(*this, pOther), dot(*this, pOther));
    }

    Vector2 operator+(const Vector2 &pVec1, const Vector2 &pVec2) {
        return {pVec1.X + pVec2.X, pVec1.Y + pVec2.Y};
    }

    Vector2 operator-(const Vector2 &pVec1, const Vector2 &pVec2) {
        return pVec1 + -pVec2;
    }

    Vector2 operator*(const Vector2 &pVec, Float pScale) {
        return {pVec.X * pScale, pVec.Y * pScale};
    }

    Vector2 operator*(Float pScale, const Vector2 &pVec) {
        return pVec * pScale;
    }

    Vector2 operator/(const Vector2 &pVec, const Float pScale) {
        return {pVec.X / pScale, pVec.Y / pScale};
    }

    Vector2 operator/(const Float pScale, const Vector2 &pVec) {
        return pVec / pScale;
    }

    bool operator==(const Vector2 &pVec1, const Vector2 &pVec2) {
        constexpr Float EPS = 1e-5f;
        return std::fabs(pVec1.X - pVec2.X) < EPS &&
               std::fabs(pVec1.Y - pVec2.Y) < EPS;
    }

    bool operator!=(const Vector2 &pVec1, const Vector2 &pVec2) {
        return !(pVec1 == pVec2);
    }

    Float dot(Vector2 pVec1, Vector2 pVec2) {
        return pVec1.X * pVec2.X + pVec1.Y * pVec2.Y;
    }

    Float cross(Vector2 pVec1, Vector2 pVec2) {
        return pVec1.X * pVec2.Y - pVec2.X * pVec1.Y;
    }
}

