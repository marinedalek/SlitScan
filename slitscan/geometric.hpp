#pragma once
namespace marinedalek::slitscan {
	template <typename T, typename Tag>
	struct xy_pair {
		explicit xy_pair(T p_x, T p_y) : x{ p_x }, y{ p_y } {}
		T x;
		T y;
	};
	
	template <typename T>
	using point_2d = xy_pair<T, struct point_2d_tag>;
	template <typename T>
	using vector_2d = xy_pair<T, struct vector_2d_tag>;
	template <typename T>
	using size_2d = xy_pair<T, struct size_2d_tag>;
	template <typename T>
	using scale_2d = xy_pair<T, struct scale_2d_tag>;

	template <typename T>
	point_2d<T>& operator+=(point_2d<T>& lhs, vector_2d<T> rhs)
	{
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		return lhs;
	}
	template <typename T>
	point_2d<T>& operator-=(point_2d<T>& lhs, vector_2d<T> rhs)
	{
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		return lhs;
	}
	template <typename T>
	vector_2d<T>& operator+=(vector_2d<T>& lhs, vector_2d<T> rhs)
	{
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		return lhs;
	}
	template <typename T>
	vector_2d<T>& operator-=(vector_2d<T>& lhs, vector_2d<T> rhs)
	{
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		return lhs;
	}
	template <typename T, typename U>
	vector_2d<T>& operator*=(vector_2d<T>& lhs, U rhs)
	{
		lhs.x *= rhs;
		lhs.y *= rhs;
		return lhs;
	}
	template <typename T, typename U>
	vector_2d<T>& operator/=(vector_2d<T>& lhs, U rhs)
	{
		lhs.x /= rhs;
		lhs.y /= rhs;
		return lhs;
	}
	template <typename T>
	vector_2d<T>& operator*=(vector_2d<T>& lhs, scale_2d<T> rhs)
	{
		lhs.x *= rhs.x;
		lhs.y *= rhs.y;
		return lhs;
	}
	template <typename T>
	vector_2d<T>& operator/=(vector_2d<T>& lhs, scale_2d<T> rhs)
	{
		lhs.x /= rhs.x;
		lhs.y /= rhs.y;
		return lhs;
	}
	template <typename T, typename U>
	size_2d<T>& operator*=(size_2d<T>& lhs, U rhs)
	{
		lhs.x *= rhs;
		lhs.y *= rhs;
		return lhs;
	}
	template <typename T, typename U>
	size_2d<T>& operator/=(size_2d<T>& lhs, U rhs) 
	{
		lhs.x /= rhs;
		lhs.y /= rhs;
		return lhs;
	}
	template <typename T>
	size_2d<T>& operator*=(size_2d<T>& lhs, scale_2d<T> rhs)
	{
		lhs.x *= rhs.x;
		lhs.y *= rhs.y;
		return lhs;
	}
	template <typename T>
	size_2d<T>& operator/=(size_2d<T>& lhs, scale_2d<T> rhs)
	{
		lhs.x /= rhs.x;
		lhs.y /= rhs.y;
		return lhs;
	}
	template <typename T, typename U>
	scale_2d<T>& operator*=(scale_2d<T>& lhs, U rhs)
	{
		lhs.x *= rhs;
		lhs.y *= rhs;
		return lhs;
	}
	template <typename T, typename U>
	scale_2d<T>& operator/=(scale_2d<T>& lhs, U rhs)
	{
		lhs.x /= rhs;
		lhs.y /= rhs;
		return lhs;
	}
	template <typename T>
	scale_2d<T>& operator*=(scale_2d<T>& lhs, scale_2d<T> rhs)
	{
		lhs.x *= rhs.x;
		lhs.y *= rhs.y;
		return lhs;
	}
	template <typename T>
	scale_2d<T>& operator/=(scale_2d<T>& lhs, scale_2d<T> rhs)
	{
		lhs.x /= rhs.x;
		lhs.y /= rhs.y;
		return lhs;
	}

}


