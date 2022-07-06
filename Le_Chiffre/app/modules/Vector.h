//#include "../Include.h"

struct Vector2
{
    float x, y;
};

struct Vector3
{
    float x, y, z;

    Vector3 operator+(Vector3 D)
    {
        return { x + D.x, y + D.y, z + D.z };
    }

    Vector3 operator-(Vector3 D)
    {
        return { x - D.x, y - D.y, z - D.z };
    }

    Vector3 operator*(float D)
    {
        return { x * D, y * D, z * D };
    }

    Vector3 operator/(float D)
    {
        return { x / D, y / D, z / D };
    }
};

struct Vector4
{
    float x, y, z, w;
};