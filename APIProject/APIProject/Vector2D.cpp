#include "Vector2D.h"
#include <random>


template <typename T>
Vector2D<T>::Vector2D():x(0), y(0){}

template<typename T>
Vector2D<T>::Vector2D(T p_x, T p_y): x(p_x), y(p_y){}

template <typename T>
T Vector2D<T>::GetX() noexcept
{
	return x;
}

template <typename T>
T Vector2D<T>::GetY() noexcept
{
	return y;
}

template <typename T>
void Vector2D<T>::Set(const T p_x, const T p_y) noexcept
{
	x = p_x;
	y = p_y;
}

template <typename T>
void Vector2D<T>::SetX(const T p_x) noexcept
{
	x = p_x;
}

template <typename T>
void Vector2D<T>::SetY(const T p_y) noexcept
{
	y = p_y;
}


template <typename T>
Vector2D<T> Vector2D<T>::operator+=(const Vector2D<T>& other) noexcept
{
	x += other.x;
	y += other.y;
	return *this;
}

template <typename T>
Vector2D<T> Vector2D<T>::operator-=(const Vector2D<T>& other) noexcept
{
	x -= other.x;
	y -= other.y;
	return *this;
}

template <typename T>
Vector2D<T> Vector2D<T>::operator*=(const T& value)  noexcept
{
	x *= value;
	y *= value;
	return *this;
}

template <typename T>
Vector2D<T> Vector2D<T>::operator*=(const Vector2D<T>& other)  noexcept
{
	x *= other.x;
	y *= other.y;
	return *this;
}



template <typename T>
Vector2D<T> Vector2D<T>::operator/=(const Vector2D<T>& other)  noexcept
{
	assert((other.x != 0 || other.y != 0) && "Division by 0 is not allowed");
	x /= other.x;
	y /= other.y;
	return Vector2D<T>(x, y);
}

template <typename T>
Vector2D<T> Vector2D<T>::operator/=(const T& value)  noexcept
{
	assert(value != 0 && "Division by 0 is not allowed");
	x /= value;
	y /= value;
	return *this;
}


template <typename T>
T Vector2D<T>::Magnitude() const noexcept
{
	return(static_cast<T>(sqrt((x * x) + (y * y))));
}

template <typename T>
Vector2D<T> Vector2D<T>::Normalize()   noexcept
{

	if (x == 0 && y == 0)
	{
		Set(0, 0);
		return *this;
	}

	if (x == 0)
	{
		Set(0, 1);
		return *this;
	}

	if (y == 0)
	{
		Set(1, 0);
		return *this;
	}

	Set(x / Magnitude(), y / Magnitude());
	return *this;
}

template <typename T>
T Vector2D<T>::Direction() const noexcept
{
	auto const radiance = (atan2(y, x));
	auto angle = static_cast<T> (radiance * ((circleDegree / 2) / std::_Pi));

	if (angle < 0)
	{
		angle += circleDegree;
	}

	return static_cast<T> (angle);
}

template <typename T>
T Vector2D<T>::SquareVector() const noexcept
{
	return ((x * x) + (y * y));
}


template class Vector2D<int>;
template class Vector2D<long>;
template class Vector2D<float>;
template class Vector2D<double>;
