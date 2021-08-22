#include <gtest/gtest.h>
#include <assets.h>
#include <optional>

TEST(AssertTest, LoadFontWithException) {
  auto font = Game::LoadFont("Bad");
  ASSERT_EQ(font, std::nullopt);
}

TEST(AssertTest, LoadFontWithoutException) {
  auto font = Game::LoadFont("../../resources/calibri.ttf");
  ASSERT_EQ(font.has_value(), true);
}

