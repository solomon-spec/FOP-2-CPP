#pragma once
#include<iostream>
#include<vector>
#include "Product.h"
class Order
{
private:
	// a static variable to generate unique id for each order
	static int m_idGenerator;

	// a unique id for each order
	std::string m_orderId; 

	// the username of the customer who made the order
	std::string m_customerUsername; 

	// a vector of pointers to the products in the order
	std::vector<Product*> m_products; 

public:
	// a static vector to store all orders
	static void makeOrder(std::vector<Product>&, std::string username);

	// get products
	std::vector<Product*> getProducts();
	// the constructor
	Order(std::string username, std::vector<Product*> products);

	// add product to an order
	void addProduct(Product&);

	// display the current order
	void displayOrder();

	// static vector to store all orders
	static std::vector<Order*> orders;

	//order to string
	std::string orderToString();
};

