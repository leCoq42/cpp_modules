#include <gtest/gtest.h>
#include "../src/RPN.hpp"

class RPNTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

// Basic Operations Tests
TEST_F(RPNTest, BasicAddition) {
    EXPECT_NO_THROW({
        RPN rpn("2 3 +");
        EXPECT_EQ(rpn.getResult(), 5);
    });
}

TEST_F(RPNTest, BasicSubtraction) {
    EXPECT_NO_THROW({
        RPN rpn("5 3 -");
        EXPECT_EQ(rpn.getResult(), 2);
    });
}

TEST_F(RPNTest, BasicMultiplication) {
    EXPECT_NO_THROW({
        RPN rpn("4 2 *");
        EXPECT_EQ(rpn.getResult(), 8);
    });
}

TEST_F(RPNTest, BasicDivision) {
    EXPECT_NO_THROW({
        RPN rpn("6 2 /");
        EXPECT_EQ(rpn.getResult(), 3);
    });
}

// Complex Expression Tests
TEST_F(RPNTest, ComplexExpression) {
    EXPECT_NO_THROW({
        RPN rpn("3 4 + 5 * 2 -");
        EXPECT_EQ(rpn.getResult(), 33);
    });
}

TEST_F(RPNTest, MultiDigitNumbers) {
    EXPECT_NO_THROW({
        RPN rpn("12 3 *");
        EXPECT_EQ(rpn.getResult(), 36);
    });
}

// Error Cases Tests
TEST_F(RPNTest, EmptyInput) {
    EXPECT_THROW({
        RPN rpn("");
    }, std::invalid_argument);
}

TEST_F(RPNTest, DivisionByZero) {
    EXPECT_THROW({
        RPN rpn("5 0 /");
    }, std::invalid_argument);
}

TEST_F(RPNTest, InvalidCharacters) {
    EXPECT_THROW({
        RPN rpn("1 2 + a");
    }, std::invalid_argument);
}

TEST_F(RPNTest, InsufficientOperands) {
    EXPECT_THROW({
        RPN rpn("1 +");
    }, std::invalid_argument);
}

TEST_F(RPNTest, TooManyOperands) {
    EXPECT_THROW({
        RPN rpn("1 2 3 +");
    }, std::invalid_argument);
}

TEST_F(RPNTest, InvalidExpression) {
    EXPECT_THROW({
        RPN rpn("1 2 + +");
    }, std::invalid_argument);
}

// Edge Cases Tests
TEST_F(RPNTest, SingleNumber) {
    EXPECT_NO_THROW({
        RPN rpn("42");
        EXPECT_EQ(rpn.getResult(), 42);
    });
}

TEST_F(RPNTest, NegativeResults) {
    EXPECT_NO_THROW({
        RPN rpn("5 10 -");
        EXPECT_EQ(rpn.getResult(), -5);
    });
}

