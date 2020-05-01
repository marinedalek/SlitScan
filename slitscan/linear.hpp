#pragma once
#include <type_traits>
#include <array>
#include <algorithm>
#include "math_vector.hpp"
// linear.hpp
// Declares classes and functions for handling linear colour information

namespace marinedalek::slitscan {

	// RGB types

	template <typename T, typename Enable = void>
	class linear_rgb;

	template <typename T>
	struct linear_rgb <T, std::enable_if_t<std::is_floating_point_v<T>>> :
		public math::vector<T,3> {
	public:
		T& r = m_data[0];
		T& g = m_data[1];
		T& b = m_data[2];
	};

	template <typename T, typename Enable = void>
	class linear_rgba;

	template <typename T>
	struct linear_rgba <T, std::enable_if_t<std::is_floating_point_v<T>>> :
		public math::vector<T, 4> {
	public:
		T& r = m_data[0];
		T& g = m_data[1];
		T& b = m_data[2];
		T& a = m_data[3];
	};

	
}
