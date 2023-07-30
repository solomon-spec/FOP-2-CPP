#include <iostream>
#include "Utils.h"
#include "User.h"
#include "Admin.h"
#include "Customer.h"
#include "Data.h"

using namespace std;
std::vector<User*> users;
std::vector<Product*> products;
/*
1. main menu
2. user menu 
3. get full details
4. my cart
5. view all products
6. login as customer
7. login as admin
8. register as customer
9. register as admin
10. add product to cart
11. add product
12. remove product
13. update product
14. view all customers
15. view all orders


*/

void setInitialAppState(User* &user, int &menu, bool &isAdmin, bool &isLoggedIn) {
    user = nullptr;
    menu = 1;
    isLoggedIn = false;
    isAdmin = false;
}

int main()
{
    for (int i = 1; i <= 10; i++) {
        std::string name = "Customer " + std::to_string(i);
        std::string userName = "user" + std::to_string(i);
        std::string password = "pass" + std::to_string(i);
        User* customer = new Customer(name, "Father Name", userName, password);
        for (int j = 0; j < 5; j++) {
            Product product = Product("Product_" + std::to_string(j), "category_" + std::to_string(j), j * 10.1, j * 2);
            dynamic_cast<Customer*>(customer)->addToCart(product);
        }
        users.push_back(customer);
    }
    // create 10 products
    for (int i = 1; i<= 10; i++) {
		std::string name = "Product_" + std::to_string(i);
        std::string category = "category_" + std::to_string(i);
		double price = i * 10.1;
        int quantity = i * 2;
		Product* product = new Product(name,category, price, quantity);
		products.push_back(product);
	}
    users.push_back(new Admin("sol", "sol", "sol", "sol"));
    Data::writeUsers(users);
    User* user = nullptr; // this will hold the current user
    int menu = 1; // this will hold the current menu
    bool isLoggedIn = false; 
    bool isAdmin = false;

    while (true) {
        if(!isLoggedIn || menu == 1) {

            // reset the state of the program to the initial state
            setInitialAppState(user, menu, isAdmin, isLoggedIn);


			menu = Utils::mainMenu();
            switch (menu) {

            case 6:
                std::cout<<"loging you as customer"<<std::endl;
                user = User::login(users);
                if(user != nullptr) {
					isLoggedIn = true;
					isAdmin = false;
                    menu = 2;
				}
                break;

            case 7:
                std::cout<<"loging you as admin"<<std::endl;
                user = User::login(users);
                if (user != nullptr && !user->isAdminUser()) {
                    std::cout << "sorry you are not an admin";
                    system("pause");
                    user = nullptr;
                }
				else if (user != nullptr && user->isAdminUser()) {
					isLoggedIn = true;
					isAdmin = true;
					menu = 2;
				}
                break;

            case 8:
                std::cout<<"registering you as customer" << std::endl;
				Customer::registerCustomer(users);
                break;
            case 9:
                std::cout<<"registering you as admin" << std::endl;
                Admin::registerAdmin(users);
                break;
            }

            continue;
		}
        switch (menu) {
            case 2:
                menu = user->displayMenu();
                break;

            case 3:
                menu = user->getFullDetails();
                break;

            case 4:
                // cast the user pointer to a customer pointer
                if (dynamic_cast<Customer*>(user) != nullptr) {
				    menu = dynamic_cast<Customer*>(user)->myCart();
			    }
			    else {
				    cout << "You are not a customer" << endl;
				    menu = 2;
			    }
                break;
            case 5:
                Product::viewAllProduct(products);
                menu = 2;
                break;
            case 10:
                if (dynamic_cast<Customer*>(user) != nullptr) {
					Product* product = Product::getProduct(products);
                    if (product != nullptr) {
						dynamic_cast<Customer*>(user)->addToCart(*product);
                        menu = 4;
					}
                    menu = 2;
				}
				else {
					cout << "You are not a customer" << endl;
					menu = 2;
				}
				break;
            case 11:
                if (isAdmin) {
                    menu = dynamic_cast<Admin*>(user)->addProduct(products);
                }
				else {
					cout << "You are not an admin" << endl;
                    menu = 2;
				}
                break;
            case 12:
                if (isAdmin) {
                    menu = dynamic_cast<Admin*>(user)->deleteProduct(products);
                }
                else {
                    cout << "You are not an admin" << endl;
                    menu = 2;
                }
                break;
            case 13:
                if (isAdmin) {
					menu = dynamic_cast<Admin*>(user)->editProduct(products);
				}
				else {
					cout << "You are not an admin" << endl;
					menu = 2;
				}
				break;
			case 14:
                if (isAdmin) {
                	for(int i = 0; i < users.size(); i++) {
						if(dynamic_cast<Customer*>(users[i]) != nullptr) {
                            cout<<dynamic_cast<Customer*>(users[i])->getUserName()<<std::endl;
						}
					}
                    system("pause");
                    menu = 2;
                }
                else {
                    cout << "You are not an admin" << endl;
                    menu = 2;
                }
                break;
            case 15:
                if(isAdmin){
                    std::cout << "this is an order" << std::endl;
					for(int i = 0; i < Order::orders.size(); i++) {
						std::cout<<"this is an order"<<std::endl;
					}
				}
                break;
        }

    }

}


