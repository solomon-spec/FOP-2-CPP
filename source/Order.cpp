#include "Order.h"
int Order::m_idGenerator = 1;	
std::vector<Order*> Order::orders = {};

Order::Order(std::string username, std::vector<Product*> products) {
	m_orderId = m_idGenerator++;
	std::string m_customerUsername;
	m_products = products;
 }

void Order::makeOrder(std::vector<Product>& products, std::string username) {
	//  products vector to product * vector
	std::vector<Product*> productsPtr;
	for (int i = 0; i < products.size(); i++) {
		productsPtr.push_back(&products[i]);
	}
	Order order(username, productsPtr);
	Order::orders.push_back(&order);
	products = {};


}
void Order::addProduct(Product& product) {
	m_products.push_back(&product);
}
void Order::displayOrder() {
	std::cout<< "Order ID: " << m_orderId << " ordered by: " << m_customerUsername <<
		" contains: " << std::endl;
	double total = 0;
	for (int i = 0; i < m_products.size(); i++) {
		std::cout << m_products[i]->getName() << " ---- " << m_products[i]->getPrice() << std::endl;
		total += m_products[i]->getPrice();
		}
	std::cout << "Total: " << total << std::endl;
}

std::vector<Product*> Order::getProducts() {
	return m_products;
}

std::string Order::orderToString() {
	return m_customerUsername;	
}