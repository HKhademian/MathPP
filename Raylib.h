#pragma once

namespace Raylib
{
    extern "C"
    {
#include <raylib.h>
    }
}

namespace Raylib
{
    void DrawFPS(const Vector2 &pos)
    {
        return DrawFPS(pos.x, pos.y);
    }

    void DrawText(const char *text, const Vector2 &pos, int fontSize, Color color)
    {
        return DrawText(text, pos.x, pos.y, fontSize, color);
    }
}

namespace Raylib
{
    Vector2 operator+(const Vector2 &lhs, const Vector2 &rhs)
    {
        return Vector2{lhs.x + rhs.x, lhs.y + rhs.y};
    }

    Vector2 operator-(const Vector2 &lhs, const Vector2 &rhs)
    {
        return Vector2{lhs.x - rhs.x, lhs.y - rhs.y};
    }

    Vector2 operator*(const Vector2 &lhs, int v)
    {
        return Vector2{lhs.x * v, lhs.y * v};
    }

    Vector2 operator*(int v, const Vector2 &rhs)
    {
        return rhs * v;
    }

    Vector2 operator/(const Vector2 &lhs, int v)
    {
        return Vector2{lhs.x / v, lhs.y / v};
    }
}
