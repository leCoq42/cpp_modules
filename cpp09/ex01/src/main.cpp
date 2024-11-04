#include "RPN.hpp"
#include <iostream>

// int main(int argc, char **argv) {
//   if (argc != 2)
//     return 1;
//   try {
//     RPN rpn(argv[1]);
//   } catch (const std::exception &e) {
//     std::cerr << "Error: " << e.what() << std::endl;
// 	return EXIT_FAILURE;
//   }
// }

void runTest(const std::string& testName, const std::string& input, bool shouldThrow = false) {
    try {
        RPN rpnCalculator(input);
        if (shouldThrow) {
            std::cerr << "FAILED: " << testName << " - Expected exception but none was thrown.\n";
        } else {
            std::cout << "PASSED: " << testName << "\n";
        }
    } catch (const std::exception& e) {
        if (shouldThrow) {
            std::cout << "PASSED: " << testName << " - Caught expected exception: " << e.what() << "\n";
        } else {
            std::cerr << "FAILED: " << testName << " - Unexpected exception: " << e.what() << "\n";
        }
    }
}

int main() {
    // Basic valid tests
    runTest("Simple addition", "3 4 +");
    runTest("Simple subtraction", "1 5 -");
    runTest("Simple multiplication", "6 7 *");
    runTest("Simple division", "8 4 /");

    // Edge cases
    runTest("Single number should throw", "3", true);
    runTest("Division by zero should throw", "4 0 /", true);
    runTest("Empty input should throw", "", true);
    runTest("Insufficient operands should throw", "4 +", true);
    runTest("Invalid character input", "2 3 &", true);
    runTest("Invalid number input (multi-digit check)", "23", true);

    // Complex expression
    runTest("Complex expression", "5 1 2 + 4 * + 3 -");

	// Additional tests for the number size constraint
    runTest("Number larger than 9 should throw (10)", "10", true);
    runTest("Number larger than 9 should throw (15)", "15 3 +", true);
    runTest("Number exactly 9 should not throw", "9 1 +");

    return 0;
}
