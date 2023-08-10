#ifndef BINOMIALOPTIONPRICINGMODEL_H_
#define BINOMIALOPTIONPRICINGMODEL_H_

class BinomialOptionPricingModel {
public:
	double S0, K, r, u, d;
	int T, N;
	BinomialOptionPricingModel(double S0, double K, int T, double r, int N, double u);
	int binomialTree();
};

#endif /* BINOMIALOPTIONPRICINGMODEL_H_ */
