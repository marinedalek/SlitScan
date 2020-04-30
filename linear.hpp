#pragma once
#include <type_traits>
#include <array>
#include <algorithm>
// linear.hpp
// Declares classes and functions for handling linear colour information

namespace marinedalek::slitscan {
	using s_size_t = int; // "This will begin to make things right..."

	// TODO: use concepts here when Intellisense supports them
	// Vector types

	template <typename T, s_size_t elems, typename Enable = void>
	class vector;

	template <typename T, s_size_t elems>
	class vector <T, elems, std::enable_if_t<std::is_arithmetic_v<T>>> {
	public:
		T& at(s_size_t i) { return m_data.at(std::size_t(i)); }
		auto begin() { return m_data.begin(); }
		auto end() { return m_data.end(); }
	private:
		std::array<T,elems> m_data {};
	};

	template <typename T, s_size_t elems>
	vector<T, elems>& operator +=
		(vector<T, elems>& lhs, vector<T, elems> const& rhs)
	{
		std::transform(lhs.begin(), lhs.end(), 
			rhs.begin(), lhs.begin(), std::plus<T>);
		return lhs;
	}

	template <typename T, s_size_t elems>
	vector<T, elems>& operator -=
		(vector<T, elems>& lhs, vector < T, elems> const& rhs)
	{
		std::transform(lhs.begin(), lhs.end(),
			rhs.begin(), lhs.begin(), std::minus<T>);
		return lhs;
	}

	// RGB types

	template <typename T, typename Enable = void>
	class linear_rgb;

	template <typename T>
	class linear_rgb <T, std::enable_if_t<std::is_floating_point_v<T>>> :
		public vector<T,3> {
	public:
		T& r = m_data[0];
		T& g = m_data[1];
		T& b = m_data[2];
	};

	template <typename T, typename Enable = void>
	class linear_rgba;

	template <typename T>
	class linear_rgba <T, std::enable_if_t<std::is_floating_point_v<T>>> :
		public vector<T, 4> {
	public:
		T& r = m_data[0];
		T& g = m_data[1];
		T& b = m_data[2];
		T& a = m_data[3];
	};

	
}
