#pragma once
#include <vector>
#include "geometric.hpp"

namespace marinedalek::slitscan
{
	template <typename T = double>
	struct linear_rgb {
		explicit linear_rgb(T a_r, T a_g, T a_b) : r{ a_r }, g{ a_r }, b{ a_b }
		{}
		T r;
		T g;
		T b;

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

	using image_size = xy_pair<std::size_t, struct image_dims_tag>;

	class linear_image {
	public:
		linear_image(image_size size) : m_data( size.x * size.y, linear_rgb{0.0,0.0,0.0} )
		{};
	private:
		std::vector<linear_rgb<>> m_data;
	};

}
