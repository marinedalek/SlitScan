#pragma once

namespace marinedalek::slitscan
{
	template <typename T>
	struct linear_rgb {
		T r{};
		T g{};
		T b{};

		linear_rgb& operator+= (linear_rgb rhs)
		{
			r += rhs.r;
			g += rhs.g;
			b += rhs.b;
			return *this;
		}
		linear_rgb& operator-= (linear_rgb rhs)
		{
			r -= rhs.r;
			g -= rhs.g;
			b -= rhs.b;
			return *this;
		}
		linear_rgb& operator*= (linear_rgb rhs)
		{
			r *= rhs.r;
			g *= rhs.g;
			b *= rhs.b;
			return *this;
		}
		linear_rgb& operator*= (T rhs)
		{
			r *= rhs;
			g *= rhs;
			b *= rhs;
			return *this;
		}
		linear_rgb& operator/= (T rhs)
		{
			r /= rhs;
			g /= rhs;
			b /= rhs;
			return *this;
		}
	};

	template <typename T>
	linear_rgb<T> operator+ (linear_rgb<T> lhs, linear_rgb<T> rhs)
	{
		return linear_rgb<T> {lhs} += rhs;
	}
	template <typename T>
	linear_rgb<T> operator- (linear_rgb<T> lhs, linear_rgb<T> rhs)
	{
		return linear_rgb<T> {lhs} -= rhs;
	}
	template <typename T>
	linear_rgb<T> operator* (linear_rgb<T> lhs, linear_rgb<T> rhs)
	{
		return linear_rgb<T> {lhs} *= rhs;
	}
	template <typename T>
	linear_rgb<T> operator* (linear_rgb<T> lhs, T rhs)
	{
		return linear_rgb<T> {lhs} *= rhs;
	}
	template <typename T>
	linear_rgb<T> operator* (T lhs, linear_rgb<T> rhs)
	{
		return rhs * lhs;
	}
	template <typename T>
	linear_rgb<T> operator/ (linear_rgb<T> lhs, T rhs)
	{
		return linear_rgb<T> {rhs} /= rhs;
	}

}
