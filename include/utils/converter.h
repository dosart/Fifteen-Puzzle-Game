#ifndef FIFTEEN_PUZZLE_GAME_INCLUDE_UTILS_CONVERTER_H_
#define FIFTEEN_PUZZLE_GAME_INCLUDE_UTILS_CONVERTER_H_

namespace Utils {

using coordinate = std::pair<size_t, size_t>;

inline size_t Convert2DIndexTo1DIndex(size_t row, size_t column, size_t row_count) {
  return row*row_count + column;
}

inline coordinate Convert1DIndexTo2DIndex(size_t index1d, size_t rows, size_t columns) {
  return std::make_pair(index1d/rows, index1d%columns);
}
}

#endif //FIFTEEN_PUZZLE_GAME_INCLUDE_UTILS_CONVERTER_H_
