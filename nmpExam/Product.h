#pragma once
#include <string>
#include <vector>
#include <iostream>

class Product {
private:
	int productId;//identificator
	std::string productName;//name of product
	std::vector<std::string> listOfFilenames;//list which contains (file names)
	bool correctness;//flag which shows correctness of instolation
public:
	Product(int productId_c, std::string productName_c, bool correctness_c) : productId(productId_c), productName(productName_c), listOfFilenames(), correctness(correctness_c) {}

	virtual ~Product() = default;

	virtual void print() {
		std::cout << "Product identificator: " << productId << std::endl;
		std::cout << "Name of product: " << productName << std::endl;
		std::cout << "This is flag which shows correctness of instolation: " << correctness << std::endl;
		for (int i = 0; i < listOfFilenames.size(); i++) {
			std::cout << "Number of filename in list [" << i << "]:" << listOfFilenames[i] << std::endl;
		}
	}

	virtual int getId() const {
		return productId;
	}
};
