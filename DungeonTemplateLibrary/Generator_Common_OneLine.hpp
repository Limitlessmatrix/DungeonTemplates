﻿#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_GENERATOR_COMMON_ONE_LINE
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_GENERATOR_COMMON_ONE_LINE
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* Bug Check : already checked */

#include <cstddef>
#include "Utility_Matrix.hpp"

namespace dtl::generator::common::stl {

	template<typename Matrix_>
	constexpr void createOneLineUp(Matrix_& matrix_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t col{}; col < matrix_[0].size(); ++col)
			matrix_[0][col] = 1;
	}
	template<typename Matrix_>
	constexpr void createOneLineDown(Matrix_& matrix_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
			matrix_[matrix_.size() - 1][col] = 1;
	}
	template<typename Matrix_>
	constexpr void createOneLineLeft(Matrix_& matrix_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() == 0) continue;
			matrix_[row][0] = 1;
		}
	}
	template<typename Matrix_>
	constexpr void createOneLineRight(Matrix_& matrix_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() == 0) continue;
			matrix_[row][matrix_[row].size() - 1] = 1;
		}
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createOneLineUp(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t col{}; col < matrix_[0].size(); ++col)
			matrix_[0][col] = value_;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createOneLineDown(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
			matrix_[matrix_.size() - 1][col] = value_;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createOneLineLeft(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() == 0) continue;
			matrix_[row][0] = value_;
		}
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createOneLineRight(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() == 0) continue;
			matrix_[row][matrix_[row].size() - 1] = value_;
		}
	}
	//クラス版
	template<typename Matrix_Int_>
	class OneLineDown {
	public:
		//コンストラクタ
		constexpr OneLineDown() noexcept = default;
		template<typename Matrix_>
		constexpr explicit OneLineDown(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
			createOneLineDown(matrix_, value_);
		}
	};
	//クラス版
	template<typename Matrix_Int_>
	class OneLineUp {
	public:
		//コンストラクタ
		constexpr OneLineUp() noexcept = default;
		template<typename Matrix_>
		constexpr explicit OneLineUp(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
			createOneLineUp(matrix_, value_);
		}
	};
	//クラス版
	template<typename Matrix_Int_>
	class OneLineLeft {
	public:
		//コンストラクタ
		constexpr OneLineLeft() noexcept = default;
		template<typename Matrix_>
		constexpr explicit OneLineLeft(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
			createOneLineLeft(matrix_, value_);
		}
	};
	//クラス版
	template<typename Matrix_Int_>
	class OneLineRight {
	public:
		//コンストラクタ
		constexpr OneLineRight() noexcept = default;
		template<typename Matrix_>
		constexpr explicit OneLineRight(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
			createOneLineRight(matrix_, value_);
		}
	};

}

namespace dtl::generator::common::normal {

	template<typename Matrix_>
	constexpr void createOneLineUp(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ == 0) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[0][col] = 1;
	}
	template<typename Matrix_>
	constexpr void createOneLineDown(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ == 0) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[y_ - 1][col] = 1;
	}
	template<typename Matrix_>
	constexpr void createOneLineLeft(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row][0] = 1;
		}
	}
	template<typename Matrix_>
	constexpr void createOneLineRight(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row][x_ - 1] = 1;
		}
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createOneLineUp(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (y_ == 0) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[0][col] = value_;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createOneLineDown(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (y_ == 0) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[y_ - 1][col] = value_;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createOneLineLeft(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row][0] = value_;
		}
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createOneLineRight(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row][x_ - 1] = value_;
		}
	}
	//クラス版
	template<typename Matrix_Int_>
	class OneLineDown {
	public:
		//コンストラクタ
		constexpr OneLineDown() noexcept = default;
		template<typename Matrix_>
		constexpr explicit OneLineDown(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			createOneLineDown(matrix_, x_, y_, value_);
		}
	};
	//クラス版
	template<typename Matrix_Int_>
	class OneLineUp {
	public:
		//コンストラクタ
		constexpr OneLineUp() noexcept = default;
		template<typename Matrix_>
		constexpr explicit OneLineUp(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			createOneLineUp(matrix_, x_, y_, value_);
		}
	};
	//クラス版
	template<typename Matrix_Int_>
	class OneLineLeft {
	public:
		//コンストラクタ
		constexpr OneLineLeft() noexcept = default;
		template<typename Matrix_>
		constexpr explicit OneLineLeft(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			createOneLineLeft(matrix_, x_, y_, value_);
		}
	};
	//クラス版
	template<typename Matrix_Int_>
	class OneLineRight {
	public:
		//コンストラクタ
		constexpr OneLineRight() noexcept = default;
		template<typename Matrix_>
		constexpr explicit OneLineRight(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			createOneLineRight(matrix_, x_, y_, value_);
		}
	};

}

namespace dtl::generator::common::array {

	template<typename Matrix_>
	constexpr void createOneLineUp(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ == 0) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[col] = 1;
	}
	template<typename Matrix_>
	constexpr void createOneLineDown(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ == 0) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[(y_ - 1)*x_ + col] = 1;
	}
	template<typename Matrix_>
	constexpr void createOneLineLeft(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row*x_] = 1;
		}
	}
	template<typename Matrix_>
	constexpr void createOneLineRight(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row*x_ + x_ - 1] = 1;
		}
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createOneLineUp(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (y_ == 0) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[col] = value_;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createOneLineDown(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (y_ == 0) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[(y_ - 1)*x_ + col] = value_;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createOneLineLeft(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row*x_] = value_;
		}
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createOneLineRight(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row*x_ + x_ - 1] = value_;
		}
	}
	//クラス版
	template<typename Matrix_Int_>
	class OneLineDown {
	public:
		//コンストラクタ
		constexpr OneLineDown() noexcept = default;
		template<typename Matrix_>
		constexpr explicit OneLineDown(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			createOneLineDown(matrix_, x_, y_, value_);
		}
	};
	//クラス版
	template<typename Matrix_Int_>
	class OneLineUp {
	public:
		//コンストラクタ
		constexpr OneLineUp() noexcept = default;
		template<typename Matrix_>
		constexpr explicit OneLineUp(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			createOneLineUp(matrix_, x_, y_, value_);
		}
	};
	//クラス版
	template<typename Matrix_Int_>
	class OneLineLeft {
	public:
		//コンストラクタ
		constexpr OneLineLeft() noexcept = default;
		template<typename Matrix_>
		constexpr explicit OneLineLeft(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			createOneLineLeft(matrix_, x_, y_, value_);
		}
	};
	//クラス版
	template<typename Matrix_Int_>
	class OneLineRight {
	public:
		//コンストラクタ
		constexpr OneLineRight() noexcept = default;
		template<typename Matrix_>
		constexpr explicit OneLineRight(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			createOneLineRight(matrix_, x_, y_, value_);
		}
	};

}

namespace dtl::generator::common::layer::stl {

	template<typename Matrix_>
	constexpr void createOneLineUp(Matrix_& matrix_, const std::size_t layer_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t col{}; col < matrix_[0].size(); ++col)
			matrix_[0][col][layer_] = 1;
	}
	template<typename Matrix_>
	constexpr void createOneLineDown(Matrix_& matrix_, const std::size_t layer_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
			matrix_[matrix_.size() - 1][col][layer_] = 1;
	}
	template<typename Matrix_>
	constexpr void createOneLineLeft(Matrix_& matrix_, const std::size_t layer_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() == 0) continue;
			matrix_[row][0][layer_] = 1;
		}
	}
	template<typename Matrix_>
	constexpr void createOneLineRight(Matrix_& matrix_, const std::size_t layer_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() == 0) continue;
			matrix_[row][matrix_[row].size() - 1][layer_] = 1;
		}
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createOneLineUp(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t col{}; col < matrix_[0].size(); ++col)
			matrix_[0][col][layer_] = value_;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createOneLineDown(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
			matrix_[matrix_.size() - 1][col][layer_] = value_;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createOneLineLeft(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() == 0) continue;
			matrix_[row][0][layer_] = value_;
		}
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createOneLineRight(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() == 0) continue;
			matrix_[row][matrix_[row].size() - 1][layer_] = value_;
		}
	}
	//クラス版
	template<typename Matrix_Int_>
	class OneLineDown {
	public:
		//コンストラクタ
		constexpr OneLineDown() noexcept = default;
		template<typename Matrix_>
		constexpr explicit OneLineDown(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, layer_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
			createOneLineDown(matrix_, layer_, value_);
		}
	};
	//クラス版
	template<typename Matrix_Int_>
	class OneLineUp {
	public:
		//コンストラクタ
		constexpr OneLineUp() noexcept = default;
		template<typename Matrix_>
		constexpr explicit OneLineUp(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, layer_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
			createOneLineUp(matrix_, layer_, value_);
		}
	};
	//クラス版
	template<typename Matrix_Int_>
	class OneLineLeft {
	public:
		//コンストラクタ
		constexpr OneLineLeft() noexcept = default;
		template<typename Matrix_>
		constexpr explicit OneLineLeft(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, layer_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
			createOneLineLeft(matrix_, layer_, value_);
		}
	};
	//クラス版
	template<typename Matrix_Int_>
	class OneLineRight {
	public:
		//コンストラクタ
		constexpr OneLineRight() noexcept = default;
		template<typename Matrix_>
		constexpr explicit OneLineRight(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, layer_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
			createOneLineRight(matrix_, layer_, value_);
		}
	};


}

namespace dtl::generator::common::layer::normal {

	template<typename Matrix_>
	constexpr void createOneLineUp(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ == 0) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[0][col][layer_] = 1;
	}
	template<typename Matrix_>
	constexpr void createOneLineDown(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ == 0) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[y_ - 1][col][layer_] = 1;
	}
	template<typename Matrix_>
	constexpr void createOneLineLeft(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row][0][layer_] = 1;
		}
	}
	template<typename Matrix_>
	constexpr void createOneLineRight(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row][x_ - 1][layer_] = 1;
		}
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createOneLineUp(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (y_ == 0) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[0][col][layer_] = value_;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createOneLineDown(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (y_ == 0) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[y_ - 1][col][layer_] = value_;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createOneLineLeft(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row][0][layer_] = value_;
		}
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createOneLineRight(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row][x_ - 1][layer_] = value_;
		}
	}
	//クラス版
	template<typename Matrix_Int_>
	class OneLineDown {
	public:
		//コンストラクタ
		constexpr OneLineDown() noexcept = default;
		template<typename Matrix_>
		constexpr explicit OneLineDown(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, layer_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			createOneLineDown(matrix_, layer_, x_, y_, value_);
		}
	};
	//クラス版
	template<typename Matrix_Int_>
	class OneLineUp {
	public:
		//コンストラクタ
		constexpr OneLineUp() noexcept = default;
		template<typename Matrix_>
		constexpr explicit OneLineUp(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, layer_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			createOneLineUp(matrix_, layer_, x_, y_, value_);
		}
	};
	//クラス版
	template<typename Matrix_Int_>
	class OneLineLeft {
	public:
		//コンストラクタ
		constexpr OneLineLeft() noexcept = default;
		template<typename Matrix_>
		constexpr explicit OneLineLeft(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, layer_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			createOneLineLeft(matrix_, layer_, x_, y_, value_);
		}
	};
	//クラス版
	template<typename Matrix_Int_>
	class OneLineRight {
	public:
		//コンストラクタ
		constexpr OneLineRight() noexcept = default;
		template<typename Matrix_>
		constexpr explicit OneLineRight(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, layer_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			createOneLineRight(matrix_, layer_, x_, y_, value_);
		}
	};

}

#endif //Included Dungeon Template Library