#include <gtest/gtest.h>
#include "utils/converter.h"

TEST(UtilsTests, Convert2DIndex) {
  ASSERT_EQ(Utils::Convert2DIndexTo1DIndex(1, 2, 4), 6);
  ASSERT_EQ(Utils::Convert2DIndexTo1DIndex(0, 0, 4), 0);
  ASSERT_EQ(Utils::Convert2DIndexTo1DIndex(3, 3, 4), 15);
}

TEST(UtilsTests, Convert1DIndex) {
  auto[row0, column0] = Utils::Convert1DIndexTo2DIndex(6, 4, 4);
  auto[row1, column1] = Utils::Convert1DIndexTo2DIndex(0, 4, 4);
  auto[row2, column2] = Utils::Convert1DIndexTo2DIndex(15, 4, 4);

  ASSERT_EQ(row0, 1);
  ASSERT_EQ(column0, 2);

  ASSERT_EQ(row1, 0);
  ASSERT_EQ(column1, 0);

  ASSERT_EQ(row2, 3);
  ASSERT_EQ(column2, 3);
}