#include <iostream>
#include <vector>
#include <cmath>
#include "BinomialOptionPricingModel.h"
using namespace std;

BinomialOptionPricingModel::BinomialOptionPricingModel(double S0, double K, int T, double r, int N, double u) {
	this->S0 = S0;
	this->K = K;
	this->T = T;
	this->r = r;
	this->N = N;
	this->u = u;
	d = 1 / u;
}

int BinomialOptionPricingModel::binomialTree() {
	double dt = T / N;
	double q = (exp(r * dt) - d) / (u - d);
	double disc = exp(-r * dt);

	vector<double> S(N + 1, 0);
	S[0] = S0 * pow(d, N);

	for(int j = 1; j <= N; j++) {
		S[j] = S[j - 1] * u / d;
	}

	vector<double> C(N + 1, 0);
	for(int j = 1; j <= N; j++) {
		C[j] = max(S[j] - K, 0.0);
	}

	for (int i = N; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			C[j] = disc * (q * C[j + 1] + (1 - q) * C[j]);
		}
	}

	return C[0];
}


