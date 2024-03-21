#include <vector>
#include <array>
#include <iostream>

struct vec2
{
	float x, y;

	vec2(float tx, float ty)
	{
		x = tx;
		y = ty;
	}
};

struct triangle
{
	std::array<vec2,3> points;
	
};

bool isColliding(const triangle& triangle1, const triangle& triangle2);
void changeTrianglePoint(int pointID, const vec2& newPoistion, triangle& traingle);

float triangleArea(const vec2& point1, const vec2& point2, const vec2& point3);