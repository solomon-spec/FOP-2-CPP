#include "Data.h"

// define static vectors
std::vector<User*> Data::m_users = {};
std::vector<Product*> Data::m_products = {};
std::vector<Order*> Data::m_orders = {};

std::vector<User*> Data::readUsers() {
	// open the file
	std::ifstream file("users.txt");
	// if the file is not open, print an error message and return
	if (!file.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return {};
	}
	// while there is a line in the file read the users 
	std::string line;
	while (std::getline(file, line)) {

		// split the line into tokens
		std::vector<std::string> tokens = Utils::split(line, ',');

		// if the user is an admin
		if (tokens[0] == "admin") {

			// create a new admin
			Admin* admin = new Admin(tokens[1], tokens[2], tokens[3], tokens[4]);

			// add the admin to the vector
			m_users.push_back(admin);
		}

		// if the user is a customer
		else if (tokens[0] == "customer") {

			// create a new customer
			Customer* customer = new Customer(tokens[1], tokens[2], tokens[3], tokens[4]);

			// add the customer to the vector
			m_users.push_back(customer);
		}
		// if it is a product
		else if (tokens[0] == "product") {

			// get the customer last added to the vector
			Customer* customer = (Customer*)m_users[m_users.size() - 1];

			// create a new product
			Product product = Product(tokens[1], customer->getUserName(), std::stod(tokens[2]), std::stoi(tokens[3]));

			// add product to customer cart
			customer->addToCart(product);
		}
	}

	// close the file
	file.close();
	// return the vector
	return m_users;
}
// read products from file
std::vector<Product*> Data::readProducts(){

	// open the file
	std::fstream file("products.txt");

	// if the file is not open, print an error message and return
	if (!file.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return {};
	}

	// while there is a line in the file read the products
	std::string line;
	while (std::getline(file, line)) {

		// split the line into tokens
		std::vector<std::string> tokens = Utils::split(line, ',');

		// create a new product
		Product* product = new Product(tokens[0], tokens[1], std::stod(tokens[2]), std::stoi(tokens[3]));

		// add the product to the vector
		m_products.push_back(product);
	}
	file.close();
	return m_products;

}

// read orders from file
std::vector<Order*> Data::readOrders() {
	std::fstream file("orders.txt");
	if (!file.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return {};
	}
	std::string line;
	while (std::getline(file, line)) {
		std::vector<std::string> tokens = Utils::split(line, ',');
		if (tokens[0] == "order") {
			Data::m_orders.push_back(new Order(tokens[1], {}));
		}
		else if (tokens[0] == "product") {
			Product product = Product(tokens[1], tokens[2], std::stod(tokens[3]), std::stoi(tokens[4]));
			Data::m_orders[m_orders.size() - 1]->addProduct(product);
		}
	}
	file.close();
	return m_orders;

}

// write users to file
void Data::writeUsers(std::vector<User*>& users) {
	std::ofstream file("users.txt");
	if (!file.is_open()) {
		std::cout << "Error opening file" << std::endl;
		system("pause");
		return;
	}
	// clear the file
	file.clear();
	for (User* user : users) {
		file << user->userToString() << std::endl;
		if (dynamic_cast<Customer*>(user)) {
			Customer* customer = (Customer*)user;
			for (Product product : customer->getCart()) {
				file <<"product," + product.productToString() << std::endl;
			}
		}
	}
	file.close();
	std::cout<<"Users saved"<<std::endl;
	system("pause");
}


// write products to file
void Data::writeProducts(std::vector<Product*>& products) {
	std::ofstream file("products.txt");
	if (!file.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return;
	}
	// clear the file
	file.clear();
	for (Product* product : products) {
		file << product->productToString() << std::endl;
	}
	file.close();
}

// write orders to file
void Data::writeOrders(std::vector<Order*>& orders) {
	std::ofstream file("orders.txt");
	if (!file.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return;
	}
	// clear the file
	file.clear();
	for (Order* order : orders) {
		file << order->orderToString() << std::endl;
		for (Product* product : order->getProducts()) {
			file <<"product," + product->productToString() << std::endl;
		}
	}
	file.close();
}