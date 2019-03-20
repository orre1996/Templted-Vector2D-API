#pragma once
#include <cassert>

template <typename T>
class Vector2D 
{
public:

	Vector2D();
	Vector2D(T p_x, T p_y);

	T GetX()  noexcept;
	T GetY()  noexcept;

	void Set(const T p_x, const T p_y) noexcept;
	void SetX(const T p_x) noexcept;
	void SetY(const T p_y) noexcept;

	Vector2D<T> operator+= (const Vector2D<T> &other)  noexcept;
	Vector2D<T> operator-= (const Vector2D<T> &other)  noexcept;
	Vector2D<T> operator*= (const T &value)  noexcept;
	Vector2D<T> operator*= (const Vector2D<T> &other)  noexcept;
	Vector2D<T> operator/= (const Vector2D<T> &other)  noexcept;
	Vector2D<T> operator/= (const T &value)  noexcept;
	
	T Magnitude() const noexcept;
	Vector2D<T> Normalize() noexcept;
	T Direction() const noexcept;
	T SquareVector() const noexcept;
	
private:
	T x;
	T y;
	int circleDegree = 360;
	
};

template <typename T>
Vector2D<T> operator+(Vector2D<T>& left, Vector2D<T>& right) noexcept
{
	return Vector2D<T>(left.GetX() + right.GetX(), left.GetY() + right.GetY());
}

template <typename T>
Vector2D<T> operator-(Vector2D<T>& left, Vector2D<T>& right) noexcept
{
	return Vector2D<T>(left.GetX() - right.GetX(), left.GetY() - right.GetY());
}

template <typename T>
Vector2D<T> operator*(Vector2D<T>& left, Vector2D<T>& right) noexcept
{
	return Vector2D<T>(left.GetX() * right.GetY(), left.GetX() * right.GetY());
}

template <typename T>
Vector2D<T> operator*(Vector2D<T>& left, const T& value) noexcept
{
	return Vector2D<T>(left.GetX() * value, left.GetY() * value);
}

template <typename T>
Vector2D<T> operator/(Vector2D<T>& left, Vector2D<T>& right)  noexcept
{
	assert((right.GetX() != 0 || right.GetY() != 0) && "Division by 0 is not allowed");
	return Vector2D<T>(left.GetX() / right.GetX(), left.GetY() / right.GetY());
}

template <typename T>
Vector2D<T> operator/(Vector2D<T>& left, const T& value)  noexcept
{
	assert(value != 0 && "Division by 0 is not allowed");
	return Vector2D<T>(left.GetX() / value, left.GetY() / value);
}

template <typename T>
bool operator>(Vector2D<T>& left, const Vector2D<T>& right) noexcept
{
	return(left.SquareVector() > right.SquareVector());
}

template <typename T>
bool operator>=(Vector2D<T>& left, const Vector2D<T>& right) noexcept
{
	return(left.SquareVector() >= right.SquareVector());
}

template <typename T>
bool operator<(Vector2D<T>& left, const Vector2D<T>& right) noexcept
{
	return(left.SquareVector() < right.SquareVector());
}

template <typename T>
bool operator<=(Vector2D<T>& left, const Vector2D<T>& right) noexcept
{
	return(left.SquareVector() <= right.SquareVector());
}

template <typename T>
bool operator==(Vector2D<T>& left, const Vector2D<T>& right) noexcept
{
	return(left.SquareVector() == right.SquareVector());
}

template <typename T>
bool operator!=(Vector2D<T>& left, const Vector2D<T>& right) noexcept
{
	return(left.SquareVector() != right.SquareVector());
}

template <typename T>
static float Distance(Vector2D<T>& left, Vector2D<T>& right) {

	Vector2D<T> a = left - right;

	return static_cast<float>(a.Magnitude());
}

template <typename T>
static float DotProduct(Vector2D<T>& left, Vector2D<T>& right) noexcept
{
	return static_cast<float>((left.GetX() * right.GetX()) + (left.GetY() * right.GetY()));
}
