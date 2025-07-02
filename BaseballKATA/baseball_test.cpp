#include "gmock/gmock.h"
#include "baseball.cpp"

using namespace testing;

class BaseballFixture : public Test {
public:
    Baseball game{ "123" };
    void assertInvalidInput(string guessNumber) {
        //game.guess() 수행 후, Exception이 발생해야 PASS이다.
        try {
            game.guess(guessNumber);
            FAIL();
        }
        catch (exception e) {
            // PASS
        }
    }
};

TEST_F(BaseballFixture, ThrowExceptionInputInvalidCase) {
    assertInvalidInput("12");
    assertInvalidInput("12s");
    assertInvalidInput("121");
}

TEST_F(BaseballFixture, ReturnSolvedResult) {
    GuessResult result = game.guess("123");

    EXPECT_TRUE(result.solved);
    EXPECT_EQ(3, result.strikes);
    EXPECT_EQ(0, result.balls);
}

