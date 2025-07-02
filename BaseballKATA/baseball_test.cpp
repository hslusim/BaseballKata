#include "gmock/gmock.h"
#include "baseball.cpp"

TEST(BaseballGame, ThrowExceptionInputLength) {
    Baseball game;
    EXPECT_THROW(game.guess(string("12")), length_error);
}