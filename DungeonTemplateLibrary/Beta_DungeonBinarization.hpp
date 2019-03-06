﻿#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_BINARIZATION
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_BINARIZATION
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>

//Dungeon Template Library Namespace

namespace dtl::utility::stl {

	template<typename Matrix_, typename STL2_>
	constexpr void binarizationBool(Matrix_& matrix_, STL2_& stl2_) noexcept {
		if (matrix_.size() != stl2_.size()) return;
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (matrix_[row].size() != stl2_[row].size()) continue;
				if (matrix_[row][col]) stl2_[row][col] = true;
				else stl2_[row][col] = false;
			}
	}

	template<typename Matrix_, typename STL2_, typename Matrix_Int_>
	constexpr void binarizationBool(Matrix_& matrix_, STL2_& stl2_, const Matrix_Int_ value_) noexcept {
		if (matrix_.size() != stl2_.size()) return;
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (matrix_[row].size() != stl2_[row].size()) continue;
				if (matrix_[row][col] >= value_) stl2_[row][col] = true;
				else stl2_[row][col] = false;
			}
	}

} //namespace

#endif //Included Dungeon Template Library