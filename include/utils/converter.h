#ifndef FIFTEEN_PUZZLE_GAME_INCLUDE_UTILS_CONVERTER_H_
#define FIFTEEN_PUZZLE_GAME_INCLUDE_UTILS_CONVERTER_H_

namespace Utils {

using coordinate = std::pair<int, int>;

inline int Convert2DIndexTo1DIndex(int row, int column, int row_count) {
  return row*row_count + column;
}

inline coordinate Convert1DIndexTo2DIndex(int index1d, int rows, int columns) {
  return std::make_pair(index1d/rows, index1d%columns);
}
}

#endif //FIFTEEN_PUZZLE_GAME_INCLUDE_UTILS_CONVERTER_H_
