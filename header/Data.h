#pragma once
#include <iostream>
#include<fstream>
#include <vector>
#include <string>
#include "User.h"
#include "Admin.h"
#include "Customer.h"
#include "Order.h"
#include "Product.h"
#include "Utils.h"

// a class to store all data in file and read and write to file
class Data
{
private:
	// a vector of pointers to all users
	static std::vector<User*> m_users;

	// a vector of pointers to all products
	static std::vector<Product*> m_products;

	// a vector of pointers to all orders
	static std::vector<Order*> m_orders;
	
public:
	// a static function to read all users from file
	static std::vector<User*> readUsers();

	// a static function to read all products from file
	static std::vector<Product*> readProducts();

	// a static function to read all orders from file
	static std::vector<Order*> readOrders();

	// a static function to write all users to file
	static void writeUsers(std::vector<User*>&);

	// a static function to write all products to file
	static void writeProducts(std::vector<Product*>&);

	// a static function to write all orders to file
	static void writeOrders(std::vector<Order*>&);


};

