#pragma once
#include "Product.h"
#include <string>
#include <iostream>
#include <vector>

class App : public Product{
private:
	std::string exeFilename;//Way to the executable file
public:
	App(int productId_c, std::string productName_c, bool correctness_c, std::string exeFilename_c) :
		Product(productId_c, productName_c, correctness_c) , exeFilename(exeFilename_c) {}

	virtual ~App() = default;

	








	

	

};
