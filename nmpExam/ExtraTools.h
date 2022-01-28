#pragma once
#include "App.h"
#include <iostream>
#include <string>
#include <vector>

class ExtraTools : public Product {
private:
	std::vector<int> extraArrOfProducts;//extra products
public:
	ExtraTools(int productId_c, std::string productName_c, bool correctness_c, std::vector<int> extraArrOfProducts_c) :
		Product(productId_c, productName_c, correctness_c) {
			for (int i = 0; i < extraArrOfProducts.size(); i++)
				extraArrOfProducts[i] = extraArrOfProducts_c[i];
	}

	virtual ~ExtraTools() = default;

	
};
