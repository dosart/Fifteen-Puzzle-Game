#include <gtest/gtest.h>
#include "utils/converter.h"

TEST(Convert2DIndex, SimpleTest)
{
  ASSERT_EQ(Utils::Convert2DIndexTo1DIndex(1,2,4), 6);
  ASSERT_EQ(Utils::Convert2DIndexTo1DIndex(0,0,4), 0);
  ASSERT_EQ(Utils::Convert2DIndexTo1DIndex(3,3,4), 15);
}