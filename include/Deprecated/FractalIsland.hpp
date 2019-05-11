﻿/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_FRACTAL_ISLAND_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_FRACTAL_ISLAND_HPP

/* Character Code : UTF-8 (BOM) */
/* [2019/03/08] Android NDK Compile (Clang 5.0) : already checked */

#include <cstdint>
#include <array>
#include <memory>
#include <new>
#include <Random/MersenneTwister32bit.hpp>
#include <Macros/nodiscard.hpp>
#include <Macros/constexpr.hpp>
#include <Type/SizeT.hpp>

//Dungeon Template Library Namespace
namespace dtl {
	inline namespace generator {
		namespace terrain {
			namespace stl {

				enum {
					biome_ocean,//海洋
					biome_plains,//平原
					biome_desert,//砂漠
					biome_extreme_hills,//山岳
					biome_forest,//森林
					biome_taiga,//タイガ
					biome_swampland,//湿地
					biome_river,//河川
					biome_hell,//地獄
					biome_sky,//空
					biome_frozen_ocean,//凍った海
					biome_frozen_river,//凍った川
					biome_ice_flats,//雪原
					biome_ice_mountains,//雪山
					biome_mushroom_island,//茸島
					biome_mushroom_island_shore,//茸島海岸
					biome_beaches,//砂浜
					biome_desert_hills,//砂漠の丘陵
					biome_forest_hills,//森林の丘陵
					biome_taiga_hills,//タイガ丘陵
					biome_smaller_extreme_hills,//高い丘
					biome_jungle,//ジャングル
					biome_jungle_hills2C4205,//ジャングルの丘陵
					biome_jungle_edge,//ジャングルの端
					biome_deep_ocean,//深海
					biome_stone_beach,//岩礁
					biome_cold_beach,//冷たい砂浜
					biome_birch_forest,//白樺の森
					biome_birch_forest_hills,//白樺の森の丘陵
					biome_roofed_forest,//覆われた森
					biome_taiga_cold,//冷たいタイガ
					biome_taiga_cold_hills,//冷たいタイガの丘陵
					biome_redwood_taiga,//メガタイガ
					biome_redwood_taiga_hills,//メガタイガ丘陵
					biome_extreme_hills_with_trees,//山岳
					biome_savanna,//サバンナ
					biome_savanna_rock,//サバンナの台地
					biome_mesa,//メサ
					biome_mesa_rock,//メサ台地森林
					biome_mesa_clear_rock,//メサ台地森林
					biome_size
				};

				std::array<std::uint_fast32_t, biome_size> biome_color{
					{
						0x29289f,
						0x65a338,
						0xdfcb8c,
						0x606060,
						0x56621,
						0x0b6659,
						0x07f9b2,
						0x0000ff,
						0xff0000,
						0x8080ff,
						0x9090a0,
						0xa0a0ff,
						0xffffff,
						0xa0a0a0,
						0xff00ff,
						0xa000ff,
						0xfade55,
						0xd25f12,
						0x22551c,
						0x163933,
						0x72789a,
						0x537b09,
						0xffffff,
						0x628b17,
						0x191882,//深海
						0xa2a284,
						0xfaf0c0,
						0x307444,
						0x1f5f32,
						0x40511a,
						0x31554a,
						0x243f36,
						0x596651,
						0x545f3e,
						0x507050,
						0xbdb25f,
						0xa79d64,
						0xd94515,
						0xb09765,
						0xca8c65
					}
				};

				template<typename Matrix_Int_>
				constexpr bool isLandBiome(const Matrix_Int_ value_) noexcept {
					return (value_ == biome_plains || value_ == biome_forest);
				}
				template<typename Matrix_Int_>
				constexpr bool isForestBiome(const Matrix_Int_ value_, const Matrix_Int_ value2_, const Matrix_Int_ value3_, const Matrix_Int_ value4_) noexcept {
					return (((value_ == biome_forest) ? 1 : 0) + ((value2_ == biome_forest) ? 1 : 0) + ((value3_ == biome_forest) ? 1 : 0) + ((value4_ == biome_forest) ? 1 : 0)) >= 2;
				}

				template<typename Matrix_>
				DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
					void createLand(Matrix_ & matrix_) noexcept {

					using dtl::random::mersenne_twister_32bit;

					for (dtl::type::size row{ 1 }; row < matrix_.size() - 1; ++row)
						for (dtl::type::size col{ 1 }; col < matrix_[row].size() - 1; ++col)
							if (matrix_[row][col] == biome_plains && mersenne_twister_32bit.probability()) matrix_[row][col] = biome_forest;

					for (dtl::type::size i{}; i < 5; ++i)
						for (dtl::type::size row{ 1 }; row < matrix_.size() - 1; ++row)
							for (dtl::type::size col{ 1 }; col < matrix_[row].size() - 1; ++col) {
								if (!isLandBiome(matrix_[row][col])) continue;
								else if (!isLandBiome(matrix_[row][col - 1]) || !isLandBiome(matrix_[row][col + 1]) || !isLandBiome(matrix_[row - 1][col]) || !isLandBiome(matrix_[row + 1][col])) matrix_[row][col] = biome_plains;
								else if (matrix_[row][col - 1] && matrix_[row][col + 1] && matrix_[row - 1][col] && matrix_[row + 1][col]) matrix_[row][col] = matrix_[row][col + 1];
								else if (isForestBiome(matrix_[row][col - 1], matrix_[row][col + 1], matrix_[row - 1][col], matrix_[row + 1][col])) matrix_[row][col] = biome_forest;
								else switch (mersenne_twister_32bit(4))
								{
								case 0:matrix_[row][col] = matrix_[row][col - 1]; break;
								case 1:matrix_[row][col] = matrix_[row][col + 1]; break;
								case 2:matrix_[row][col] = matrix_[row - 1][col]; break;
								case 3:matrix_[row][col] = matrix_[row + 1][col]; break;
								}
							}
				}

				template<typename Matrix_Int_>
				constexpr bool isOceanBiome(const Matrix_Int_ value_) noexcept {
					return (value_ == biome_ocean || value_ == biome_deep_ocean);
				}
				template<typename Matrix_Int_>
				constexpr bool isDeepOceanBiome(const Matrix_Int_ value_, const Matrix_Int_ value2_, const Matrix_Int_ value3_, const Matrix_Int_ value4_) noexcept {
					return (((value_ == biome_deep_ocean) ? 1 : 0) + ((value2_ == biome_deep_ocean) ? 1 : 0) + ((value3_ == biome_deep_ocean) ? 1 : 0) + ((value4_ == biome_deep_ocean) ? 1 : 0)) >= 3;
				}


				template<typename Matrix_>
				DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
					void createDeepOcean(Matrix_ & matrix_) noexcept {

					using dtl::random::mersenne_twister_32bit;

					for (dtl::type::size row{ 1 }; row < matrix_.size() - 1; ++row)
						for (dtl::type::size col{ 1 }; col < matrix_[row].size() - 1; ++col)
							if (matrix_[row][col] == biome_ocean && mersenne_twister_32bit.probability()) matrix_[row][col] = biome_deep_ocean;

					for (dtl::type::size i{}; i < 2; ++i)
						for (dtl::type::size row{ 1 }; row < matrix_.size() - 1; ++row)
							for (dtl::type::size col{ 1 }; col < matrix_[row].size() - 1; ++col) {
								if (!isOceanBiome(matrix_[row][col])) continue;
								else if (!isOceanBiome(matrix_[row][col - 1]) || !isOceanBiome(matrix_[row][col + 1]) || !isOceanBiome(matrix_[row - 1][col]) || !isOceanBiome(matrix_[row + 1][col])) matrix_[row][col] = biome_ocean;
								else if (matrix_[row][col - 1] && matrix_[row][col + 1] && matrix_[row - 1][col] && matrix_[row + 1][col]) matrix_[row][col] = matrix_[row][col + 1];
								else if (isDeepOceanBiome(matrix_[row][col - 1], matrix_[row][col + 1], matrix_[row - 1][col], matrix_[row + 1][col])) matrix_[row][col] = biome_deep_ocean;
								else switch (mersenne_twister_32bit(4))
								{
								case 0:matrix_[row][col] = matrix_[row][col - 1]; break;
								case 1:matrix_[row][col] = matrix_[row][col + 1]; break;
								case 2:matrix_[row][col] = matrix_[row - 1][col]; break;
								case 3:matrix_[row][col] = matrix_[row + 1][col]; break;
								}
							}
				}



				//Diamond Square (Average)
				//ダイヤモンド・スクエア法(平均値)
				template<typename Matrix_Int_, typename Matrix_>
				DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
					void createDiamondSquareAverage_Map(const dtl::type::size x_, const dtl::type::size y_, dtl::type::size size_, const Matrix_Int_ t1_, const Matrix_Int_ t2_, const Matrix_Int_ t3_, const Matrix_Int_ t4_, Matrix_ & matrix_, const Matrix_Int_ max_value_) noexcept {

					using dtl::random::mersenne_twister_32bit;

					//再起の終了処理
					if (size_ == static_cast<dtl::type::size>(0)) return;

					const Matrix_Int_ vertex_rand{ static_cast<Matrix_Int_>(mersenne_twister_32bit(static_cast<std::int_fast32_t>(size_))) };
					//頂点の高さを決める
					const Matrix_Int_ vertex_height{ static_cast<Matrix_Int_>((t1_ / 4 + t2_ / 4 + t3_ / 4 + t4_ / 4)) };
					matrix_[y_][x_] = ((vertex_height > max_value_ - vertex_rand) ? max_value_ : (vertex_height + vertex_rand));
					//四角形の2点同士の中点の高さを決定
					const Matrix_Int_ s1{ static_cast<Matrix_Int_>((t1_ / 2 + t2_ / 2)) };
					const Matrix_Int_ s2{ static_cast<Matrix_Int_>((t1_ / 2 + t3_ / 2)) };
					const Matrix_Int_ s3{ static_cast<Matrix_Int_>((t2_ / 2 + t4_ / 2)) };
					const Matrix_Int_ s4{ static_cast<Matrix_Int_>((t3_ / 2 + t4_ / 2)) };
					//4つの地点の座標を決める
					matrix_[y_ + size_][x_] = s3;
					matrix_[y_ - size_][x_] = s2;
					matrix_[y_][x_ + size_] = s4;
					matrix_[y_][x_ - size_] = s1;

					//分割サイズを半分にする
					size_ /= static_cast<dtl::type::size>(2);
					//4つに分割
					createDiamondSquareAverage_Map(x_ - size_, y_ - size_, size_, t1_, s1, s2, matrix_[y_][x_], matrix_, max_value_);
					createDiamondSquareAverage_Map(x_ - size_, y_ + size_, size_, s1, t2_, matrix_[y_][x_], s3, matrix_, max_value_);
					createDiamondSquareAverage_Map(x_ + size_, y_ - size_, size_, s2, matrix_[y_][x_], t3_, s4, matrix_, max_value_);
					createDiamondSquareAverage_Map(x_ + size_, y_ + size_, size_, matrix_[y_][x_], s3, s4, t4_, matrix_, max_value_);
				}

				DUNGEON_TEMPLATE_LIBRARY_NODISCARD
				DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
					dtl::type::size getDiamondSquareMatrixSize(const dtl::type::size matrix_size) noexcept {
					dtl::type::size map_size{ 2 };
					while (true) {
						if ((map_size + 1) > matrix_size) return (map_size >>= 1);
						map_size <<= 1;
					}
					return 0;
				}

			} //namespace
		}
	}
}

#endif //Included Dungeon Template Library