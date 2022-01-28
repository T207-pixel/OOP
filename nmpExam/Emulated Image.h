#pragma once
#include "Product.h"

class EmulatedImage : public  Product {
private:
	std::vector<int> extraArrOfProductsSecond;//extra products
public:
	EmulatedImage(int productId_c, std::string productName_c, bool correctness_c, std::vector<int> extraArrOfProductsSecond_c) :
		Product(productId_c, productName_c, correctness_c) {
		for (int i = 0; i < extraArrOfProductsSecond.size(); i++)
			extraArrOfProductsSecond[i] = extraArrOfProductsSecond_c[i];
	}

	virtual ~EmulatedImage() = default;

};

