#pragma once
#include <type_traits>
#include <algorithm>

namespace marinedalek::slitscan::math {
	using s_size_t = int; // "This will begin to make things right..."

	// TODO: use concepts here when Intellisense supports them
	// Vector types

	template <typename T, s_size_t elems, typename Enable = void>
	struct vector;

	template <typename T, s_size_t elems>
	struct vector <T, elems, std::enable_if_t<std::is_arithmetic_v<T>>> {
		std::array<T, elems> data{};
	};

	template <typename T, s_size_t elems>
	vector<T, elems>& 
		operator +=	(vector<T, elems>& lhs, vector<T, elems> const& rhs)
	{
		std::transform(lhs.data.begin(), lhs.data.end(),
			rhs.data.begin(), lhs.data.begin(), std::plus<T>);
		return lhs;
	}

	template <typename T, s_size_t elems>
	vector<T, elems>& 
		operator -= (vector<T, elems>& lhs, vector < T, elems> const& rhs)
	{
		std::transform(lhs.data.begin(), lhs.data.end(),
			rhs.data.begin(), lhs.data.begin(), std::minus<T>);
		return lhs;
	}

	template <typename T, s_size_t elems, typename U>
	std::enable_if_t<std::is_arithmetic_v<U>, vector<T, elems>& >
		operator *= (vector<T, elems>& lhs, U rhs)
	{
		for (auto& element : lhs.data)
		{
			element *= rhs;
		}
		return lhs;
	}

	template <typename T, s_size_t elems, typename U>
	std::enable_if_t<std::is_arithmetic_v<U>, vector<T, elems>& >
		operator /= (vector<T, elems>& lhs, U rhs)
	{
		for (auto& element : lhs.data)
		{
			element /= rhs;
		}
		return lhs;
	}

	template <typename T, s_size_t elems>
	vector<T, elems>
		operator + (vector<T, elems> const& lhs, vector<T, elems> const& rhs)
	{
		auto vec = lhs;
		vec += rhs;
		return vec;
	}

	template <typename T, s_size_t elems>
	vector<T, elems>
		operator - (vector<T, elems> const& lhs, vector<T, elems> const& rhs)
	{
		auto vec = lhs;
		vec -= rhs;
		return vec;
	}

	template <typename T, s_size_t elems, typename U>
	std::enable_if_t<std::is_arithmetic_v<U>,vector<T, elems>>
		operator * (vector<T, elems> const& lhs, U rhs)
	{
		auto vec = lhs;
		vec *= rhs;
		return vec;
	}

	template <typename T, s_size_t elems, typename U>
	std::enable_if_t<std::is_arithmetic_v<U>,vector<T, elems>>
		operator / (vector<T, elems> const& lhs, U rhs)
	{
		auto vec = lhs;
		vec /= rhs;
		return vec;
	}
}
