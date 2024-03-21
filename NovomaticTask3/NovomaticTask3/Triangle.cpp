#include "Triangle.h"
#include <math.h>

// argorythm of point-traingle collision detection implementation
bool isColliding(const triangle& triangle1, const triangle& triangle2)
{
	float epsilon = pow(10, -14);
	const float triangleArea1 = triangleArea(triangle1.points[0], triangle1.points[1], triangle1.points[2]);
	const bool colision11 = epsilon > abs(triangleArea1 - (triangleArea(triangle2.points[0], triangle1.points[1], triangle1.points[2]) +
		triangleArea(triangle1.points[0], triangle2.points[0], triangle1.points[2]) +
		triangleArea(triangle1.points[0], triangle1.points[1], triangle2.points[0])));
	const bool colision12 = epsilon > abs(triangleArea1 - (triangleArea(triangle2.points[1], triangle1.points[1], triangle1.points[2]) +
		triangleArea(triangle1.points[0], triangle2.points[1], triangle1.points[2]) +
		triangleArea(triangle1.points[0], triangle1.points[1], triangle2.points[1])));
	const bool colision13 = epsilon > abs(triangleArea1 - (triangleArea(triangle2.points[2], triangle1.points[1], triangle1.points[2]) +
		triangleArea(triangle1.points[0], triangle2.points[2], triangle1.points[2])
		+ triangleArea(triangle1.points[0], triangle1.points[1], triangle2.points[2])));

	const float triangleArea2 = triangleArea(triangle2.points[0], triangle2.points[1], triangle2.points[2]);
	const bool colision21 = epsilon > abs(triangleArea2 - (triangleArea(triangle1.points[0], triangle2.points[1], triangle2.points[2]) +
		triangleArea(triangle2.points[0], triangle1.points[0], triangle2.points[2]) +
		triangleArea(triangle2.points[0], triangle2.points[1], triangle1.points[0])));
	const bool colision22 = epsilon > abs(triangleArea2 - (triangleArea(triangle1.points[1], triangle2.points[1], triangle2.points[2]) +
		triangleArea(triangle2.points[0], triangle1.points[1], triangle2.points[2]) +
		triangleArea(triangle2.points[0], triangle2.points[1], triangle1.points[1])));
	const bool colision23 = epsilon > abs(triangleArea2 - (triangleArea(triangle1.points[2], triangle2.points[1], triangle2.points[2]) +
		triangleArea(triangle2.points[0], triangle1.points[2], triangle2.points[2]) +
		triangleArea(triangle2.points[0], triangle2.points[1], triangle1.points[2])));


	return colision11 || colision12 || colision13 || colision21 || colision22 || colision23;
}

void changeTrianglePoint(int pointID, const vec2& newPoistion, triangle& traingle)
{
	traingle.points[pointID].x = newPoistion.x;
	traingle.points[pointID].y = newPoistion.y;

}
//area of traingle, p1 = a, p2 = b, p3 = c
float triangleArea(const vec2& p1, const vec2& p2, const vec2& p3)
{
	return abs((p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x) )/2;
}
