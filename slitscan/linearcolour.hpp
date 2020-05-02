#pragma once

namespace marinedalek::slitscan
{
	template <typename T>
	struct linear_rgb {
		T r{};
		T g{};
		T b{};

		linear_rgb& operator+= (linear_rgb const& rhs)
		{
			r += rhs.r;
			g += rhs.g;
			b += rhs.b;
			return *this;
		}
		linear_rgb& operator-= (linear_rgb const& rhs)
		{
			r -= rhs.r;
			g -= rhs.g;
			b -= rhs.b;
			return *this;
		}
		linear_rgb& operator*= (linear_rgb const& rhs)
		{
			r *= rhs.r;
			g *= rhs.g;
			b *= rhs.b;
			return *this;
		}
		linear_rgb& operator*= (T const& rhs)
		{
			r *= rhs;
			g *= rhs;
			b *= rhs;
			return *this;
		}
		linear_rgb& operator/= (T const& rhs)
		{
			r /= rhs;
			g /= rhs;
			b /= rhs;
			return *this;
		}
	};

	template <typename T>
	linear_rgb<T> operator+ (linear_rgb<T> const& lhs, linear_rgb<T> const& rhs)
	{
		return linear_rgb<T> {lhs} += rhs;
	}
	template <typename T>
	linear_rgb<T> operator- (linear_rgb<T> const& lhs, linear_rgb<T> const& rhs)
	{
		return linear_rgb<T> {lhs} -= rhs;
	}
	template <typename T>
	linear_rgb<T> operator* (linear_rgb<T> const& lhs, linear_rgb<T> const& rhs)
	{
		return linear_rgb<T> {lhs} *= rhs;
	}
	template <typename T>
	linear_rgb<T> operator* (linear_rgb<T> const& lhs, T const& rhs)
	{
		return linear_rgb<T> {lhs} *= rhs;
	}
	template <typename T>
	linear_rgb<T> operator* (T const& lhs, linear_rgb<T> const& rhs)
	{
		return rhs * lhs;
	}
	template <typename T>
	linear_rgb<T> operator/ (linear_rgb<T> const& lhs, T const& rhs)
	{
		return linear_rgb<T> {rhs} /= rhs;
	}


}
