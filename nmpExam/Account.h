#pragma once
#include "Product.h"
#include <iostream>
#include <string>
#include <vector>

class Account {
private:
	std::string user;//user name
	std::string hashSum;//result of hash_sum
	int id;//identifier
	std::vector<Product*> arrOfProducts;
public:
	Account() = default;
	Account(std::string user_c, std::string hashSum_c, int id_c) : user(user_c), hashSum(hashSum_c), id(id_c), arrOfProducts() {}
	
	~Account() = default;

	std::string getUserName() const {
		return user;
	}

	void setUserName(std::string user_c) {
		user = user_c;
	}

	std::string getHashSum() const {
		return hashSum;
	}

	void setHashSum(std::string hashSum_c) {
		hashSum = hashSum_c;
	}

	int getId() const {
		return id;
	}

	void setId(int id_c) {
		id = id_c;
	}

	std::vector<Product*> getArrOfProducts() {
		return arrOfProducts;
	}

	void addProduct(Product *addingProd) {
		arrOfProducts.push_back(addingProd);
	}

	void deleteProduct(int productId) {

	}
	
	void printAccount() {
		for (int i = 0; i < arrOfProducts.size(); i++)
		arrOfProducts[i]->print();
	}
	
	
	
	
	
	
	
	
	
	
	
	//МЕТОДЫ
	//конструктор и деструктор
	//копирующий конструктор (можно добавить перемещающий но хз для чего)
	//геттеры сеттеры
	//ДОБАВЛЕНИЕ И УДАЛЕНИЕ В ВЕКТОР
	//вывод всех полей + с помощью перегруза <<
	//проверка целостности продукта (проверка как установлен флаг установки)
	//	
};
