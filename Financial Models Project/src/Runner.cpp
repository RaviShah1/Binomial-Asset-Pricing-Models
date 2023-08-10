#include <iostream>
#include "BinomialOptionPricingModel.h"
using namespace std;

int main() {
	double optionPrice; // C0
	double S0 = 100.0; // Initial asset price
	double K = 100.0; // Strike price

	double r = 0.05;  // Risk-free rate

	double u = 1.1;   // Up factor

	int T = 1;   // Time to maturity
	int N = 1000;      // Number of time steps

	BinomialOptionPricingModel model(S0, K, T, r, N, u);
	optionPrice = model.binomialTree();
	cout << optionPrice;

	return 0;
}
