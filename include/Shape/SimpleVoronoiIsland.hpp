﻿/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_SIMPLE_VORONOI_ISLAND_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_SIMPLE_VORONOI_ISLAND_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::SimpleVoronoiIsland-(形状クラス)/
#######################################################################################*/

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstdint>
#include <utility>
#include <Base/Struct.hpp>
#include <Macros/constexpr.hpp>
#include <Macros/nodiscard.hpp>
#include <Random/MersenneTwister32bit.hpp>
#include <Type/SizeT.hpp>
#include <Utility/VoronoiDiagram.hpp>

namespace dtl {
	inline namespace shape {

		//マップの外枠を指定した数値で埋め、偶数マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class SimpleVoronoiIsland {
		private:


			///// エイリアス /////

			using Index_Size = dtl::type::size;




			///// メンバ変数 /////

			dtl::utility::VoronoiDiagram<Matrix_Int_> voronoiDiagram{};
			double probability_value{ 0.5 };
			Matrix_Int_ land_value{};
			Matrix_Int_ sea_value{};

		public:


			///// 情報取得 /////

			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
				constexpr Index_Size getPointX() const noexcept {
				return this->voronoiDiagram.getPointX();
			}
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
				constexpr Index_Size getPointY() const noexcept {
				return this->voronoiDiagram.getPointY();
			}
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
				constexpr Index_Size getWidth() const noexcept {
				return this->voronoiDiagram.getWidth();
			}
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
				constexpr Index_Size getHeight() const noexcept {
				return this->voronoiDiagram.getHeight();
			}
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
				constexpr dtl::type::size getValue() const noexcept {
				return this->voronoiDiagram.getValue();
			}

			constexpr bool isIsland(const std::pair<std::int_fast32_t, std::int_fast32_t>& point_, const std::int_fast32_t sx_, const std::int_fast32_t sy_, const std::int_fast32_t w_, const std::int_fast32_t h_, const std::int_fast32_t numerator_, const std::int_fast32_t denominator_) const noexcept {
				//return true;
				return (point_.first > ((w_ - sx_) * numerator_ / denominator_ + sx_) && point_.first < ((w_ - sx_) * (denominator_ - numerator_) / denominator_ + sx_)) && (point_.second > ((h_ - sy_) * numerator_ / denominator_ + sy_) && point_.second < ((h_ - sy_) * (denominator_ - numerator_) / denominator_ + sy_));
			}


			///// 生成呼び出し /////

			//STL
			template<typename Matrix_>
			constexpr bool draw(Matrix_&& matrix_) const noexcept {
				return this->voronoiDiagram.draw(matrix_,
					[this](const std::pair<std::int_fast32_t, std::int_fast32_t> & point_, Matrix_Int_ & color_, const std::int_fast32_t sx_, const std::int_fast32_t sy_, const std::int_fast32_t w_, const std::int_fast32_t h_) {
						if ((this->isIsland(point_, sx_, sy_, w_, h_, 2, 5) || this->isIsland(point_, sx_, sy_, w_, h_, 1, 5)) && dtl::random::mt32bit.probability(this->probability_value)) color_ = this->land_value;
						else color_ = this->sea_value;
					});
			}

			//LayerSTL
			template<typename Matrix_>
			constexpr bool draw(Matrix_&& matrix_, const Index_Size layer_) const noexcept {
				return this->voronoiDiagram.draw(matrix_, layer_,
					[this](const std::pair<std::int_fast32_t, std::int_fast32_t>& point_, Matrix_Int_ & color_, const std::int_fast32_t sx_, const std::int_fast32_t sy_, const std::int_fast32_t w_, const std::int_fast32_t h_) {
						if ((this->isIsland(point_, sx_, sy_, w_, h_, 2, 5) || this->isIsland(point_, sx_, sy_, w_, h_, 1, 5)) && dtl::random::mt32bit.probability(this->probability_value)) color_ = this->land_value;
						else color_ = this->sea_value;
					});
			}

			//Normal
			template<typename Matrix_>
			constexpr bool draw(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->voronoiDiagram.draw(matrix_, max_x_, max_y_,
					[this](const std::pair<std::int_fast32_t, std::int_fast32_t>& point_, Matrix_Int_ & color_, const std::int_fast32_t sx_, const std::int_fast32_t sy_, const std::int_fast32_t w_, const std::int_fast32_t h_) {
						if ((this->isIsland(point_, sx_, sy_, w_, h_, 2, 5) || this->isIsland(point_, sx_, sy_, w_, h_, 1, 5)) && dtl::random::mt32bit.probability(this->probability_value)) color_ = this->land_value;
						else color_ = this->sea_value;
					});
			}

			//LayerNormal
			template<typename Matrix_>
			constexpr bool draw(Matrix_&& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->voronoiDiagram.draw(matrix_, layer_, max_x_, max_y_,
					[this](const std::pair<std::int_fast32_t, std::int_fast32_t>& point_, Matrix_Int_ & color_, const std::int_fast32_t sx_, const std::int_fast32_t sy_, const std::int_fast32_t w_, const std::int_fast32_t h_) {
						if ((this->isIsland(point_, sx_, sy_, w_, h_, 2, 5) || this->isIsland(point_, sx_, sy_, w_, h_, 1, 5)) && dtl::random::mt32bit.probability(this->probability_value)) color_ = this->land_value;
						else color_ = this->sea_value;
					});
			}

			//Array
			template<typename Matrix_>
			constexpr bool drawArray(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->voronoiDiagram.drawArray(matrix_, max_x_, max_y_,
					[this](const std::pair<std::int_fast32_t, std::int_fast32_t>& point_, Matrix_Int_ & color_, const std::int_fast32_t sx_, const std::int_fast32_t sy_, const std::int_fast32_t w_, const std::int_fast32_t h_) {
						if ((this->isIsland(point_, sx_, sy_, w_, h_, 2, 5) || this->isIsland(point_, sx_, sy_, w_, h_, 1, 5)) && dtl::random::mt32bit.probability(this->probability_value)) color_ = this->land_value;
						else color_ = this->sea_value;
					});
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& create(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->draw(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& createArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& createOperator(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawOperator(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& createOperatorArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}


			///// 消去 /////

			//始点座標Xを初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SimpleVoronoiIsland& clearPointX() noexcept {
				this->voronoiDiagram.clearPointX();
				return *this;
			}
			//始点座標Yを初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SimpleVoronoiIsland& clearPointY() noexcept {
				this->voronoiDiagram.clearPointY();
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SimpleVoronoiIsland& clearWidth() noexcept {
				this->voronoiDiagram.clearWidth();
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SimpleVoronoiIsland& clearHeight() noexcept {
				this->voronoiDiagram.clearHeight();
				return *this;
			}
			//塗り値を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SimpleVoronoiIsland& clearValue() noexcept {
				this->voronoiDiagram.clearValue();
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SimpleVoronoiIsland& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SimpleVoronoiIsland& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SimpleVoronoiIsland& clear() noexcept {
				this->clearRange();
				this->clearValue();
				return *this;
			}


			///// 代入 /////

			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SimpleVoronoiIsland& setPointX(const Index_Size end_x_) noexcept {
				this->voronoiDiagram.setPointX(end_x_);
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SimpleVoronoiIsland& setPointY(const Index_Size end_y_) noexcept {
				this->voronoiDiagram.setPointY(end_y_);
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SimpleVoronoiIsland& setWidth(const Index_Size width_) noexcept {
				this->voronoiDiagram.setWidth(width_);
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SimpleVoronoiIsland& setHeight(const Index_Size height_) noexcept {
				this->voronoiDiagram.setHeight(height_);
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SimpleVoronoiIsland& setValue(const dtl::type::size voronoi_num_) noexcept {
				this->voronoiDiagram.setValue(voronoi_num_);
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SimpleVoronoiIsland& setRange(const dtl::base::MatrixRange& matrix_range_) noexcept {
				this->voronoiDiagram.setRange(matrix_range_);
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SimpleVoronoiIsland& setPoint(const Index_Size point_) noexcept {
				this->setPointX(point_);
				this->setPointY(point_);
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SimpleVoronoiIsland& setPoint(const Index_Size end_x_, const Index_Size end_y_) noexcept {
				this->setPointX(end_x_);
				this->setPointY(end_y_);
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SimpleVoronoiIsland& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size length_) noexcept {
				this->setPointX(end_x_);
				this->setPointY(end_y_);
				this->setWidth(length_);
				this->setHeight(length_);
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SimpleVoronoiIsland& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->setPointX(end_x_);
				this->setPointY(end_y_);
				this->setWidth(width_);
				this->setHeight(height_);
				return *this;
			}


			///// コンストラクタ /////

			constexpr SimpleVoronoiIsland() noexcept = default;
			constexpr explicit SimpleVoronoiIsland(const dtl::type::size voronoi_num_) noexcept
				:voronoiDiagram(voronoi_num_) {}
			constexpr explicit SimpleVoronoiIsland(const dtl::type::size voronoi_num_, const double probability_value_) noexcept
				:voronoiDiagram(voronoi_num_), probability_value(probability_value_) {}
			constexpr explicit SimpleVoronoiIsland(const dtl::type::size voronoi_num_, const double probability_value_, const Matrix_Int_& land_value_) noexcept
				:voronoiDiagram(voronoi_num_), probability_value(probability_value_), land_value(land_value_) {}
			constexpr explicit SimpleVoronoiIsland(const dtl::type::size voronoi_num_, const double probability_value_, const Matrix_Int_& land_value_, const Matrix_Int_& sea_value_) noexcept
				:voronoiDiagram(voronoi_num_), probability_value(probability_value_), land_value(land_value_), sea_value(sea_value_) {}

			constexpr explicit SimpleVoronoiIsland(const dtl::base::MatrixRange& matrix_range_) noexcept
				:voronoiDiagram(matrix_range_) {}
			constexpr explicit SimpleVoronoiIsland(const dtl::base::MatrixRange& matrix_range_, const dtl::type::size voronoi_num_) noexcept
				:voronoiDiagram(matrix_range_, voronoi_num_) {}
			constexpr explicit SimpleVoronoiIsland(const dtl::base::MatrixRange& matrix_range_, const dtl::type::size voronoi_num_, const double probability_value_) noexcept
				:voronoiDiagram(matrix_range_, voronoi_num_), probability_value(probability_value_) {}
			constexpr explicit SimpleVoronoiIsland(const dtl::base::MatrixRange& matrix_range_, const dtl::type::size voronoi_num_, const double probability_value_, const Matrix_Int_& land_value_) noexcept
				:voronoiDiagram(matrix_range_, voronoi_num_), probability_value(probability_value_), land_value(land_value_) {}
			constexpr explicit SimpleVoronoiIsland(const dtl::base::MatrixRange& matrix_range_, const dtl::type::size voronoi_num_, const double probability_value_, const Matrix_Int_& land_value_, const Matrix_Int_& sea_value_) noexcept
				:voronoiDiagram(matrix_range_, voronoi_num_), probability_value(probability_value_), land_value(land_value_), sea_value(sea_value_) {}
		};
	}
}

#endif //Included Dungeon Template Library