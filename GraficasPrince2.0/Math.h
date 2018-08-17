#pragma once

struct Vector4
{
	float x, y, z, w;
};

struct Vector3
{
	float x, y, z, w;
	Vector3() = default;
	Vector3(float vx, float vy = 0.0f, float vz = 0.0f)
		: x(vx),
		y(vy),
		z(vz)
	{}
};

struct Vertex
{
	Vector3 position;
	//Vector4 position;
	/*Vector4 color;
	Vector4 normal;
	float u = 0, v = 0;*/
};

class Math
{
public:
	Math();
	~Math();
};
