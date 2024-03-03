#include <iostream>
#include <cmath>

class SquareRootCalculator {
public:
	// function to calculate square root with Newton Raphson method
	// will run until the difference between the guesses is significantly small
    double calculateSquareRoot(double number) {
        double guess = 1.0;
        double prevGuess;

        do {
            prevGuess = guess;
            guess = 0.5 * (guess + number / guess);
        } while (std::fabs(guess - prevGuess) > 1e-6);

        return guess;
    }
};

int main() {
    SquareRootCalculator calculator;

	// random number from user
    double inputNumber;
    std::cout << "Enter a number: ";
    std::cin >> inputNumber;

	// ensuring only positive numbers are passed:
    if (inputNumber < 0) {
        std::cout << "Cannot calculate the square root of a negative number." << std::endl;
    } else {
        double squareRoot = calculator.calculateSquareRoot(inputNumber);
        std::cout << "Square Root using Newton-Raphson method is: " << squareRoot << std::endl;
    }

    return 0;
}

