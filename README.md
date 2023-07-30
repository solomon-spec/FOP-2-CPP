# FOP-2-CPP
A wholesale management system built with C++ oop


# User Class

The `User` class represents a user in the marketplace system. It provides functionalities for managing user information and interactions within the marketplace. This class serves as the base class for both customers and administrators.

## Constructors

1. `User()`: Default constructor that initializes the `User` object with default values.

2. `User(const std::string& name, const std::string& fatherName, const std::string& userName, const std::string& password, const bool& isAdmin)`: Parameterized constructor to create a `User` object with provided user details.

## Member Variables

- `m_name`: A string that holds the name of the user.
- `m_fatherName`: A string that holds the father's name of the user.
- `m_userName`: A string that stores the username of the user.
- `m_password`: A string that stores the password of the user.
- `m_isAdmin`: A boolean flag indicating whether the user is an administrator or not.
- `m_cart`: A vector of `Product` objects representing the user's shopping cart.

## Public Member Functions

1. `std::string getName()`: Get the name of the user.

2. `std::string getFatherName()`: Get the father's name of the user.

3. `std::string getUserName()`: Get the username of the user.

4. `std::string getPassword()`: Get the password of the user.

5. `bool isAdminUser()`: Check if the user is an administrator.

6. `void setName(const std::string& name)`: Set the name of the user.

7. `void setFatherName(const std::string& fatherName)`: Set the father's name of the user.

8. `void setUserName(const std::string& userName)`: Set the username of the user.

9. `void setPassword(const std::string& password)`: Set the password of the user.

10. `void setAdmin(const bool& isAdminUser)`: Set whether the user is an administrator or not.

11. `int getFullDetails()`: Display the full details of the user, including name, father's name, username, password, and whether they are an administrator.

12. `virtual int displayMenu()`: Display the main menu for the user and return the selected choice.

13. `static User* login(std::vector<User*>& users)`: Static function to perform user login. It accepts a vector of pointers to `User` objects and returns a pointer to the logged-in user.

## Usage

1. Create a new `User` object for each user and set their details using the constructor and setter functions.

2. Use the `getName()`, `getUserName()`, and other getter functions to access user information.

3. To perform user login, call the static function `login(std::vector<User*>& users)` and pass the vector of user pointers. It will return the logged-in user's pointer or `nullptr` if the login fails.

4. Use `displayMenu()` to present the main menu for the user and handle their choice.

5. Manage the user's shopping cart using the `m_cart` vector and the associated `Product` objects.

   
## Admin Class

### Description
The `Admin` class is a derived class of the `User` class. It represents an admin user in the market place application. Admin users have additional privileges compared to regular customers.

### Public Members

#### Constructor
```cpp
Admin(const std::string& name, const std::string& fatherName, const std::string& userName,
	const std::string& password);
```
- Description: Constructs an admin object with the given details.
- Parameters:
  - `name` (const std::string&): The name of the admin.
  - `fatherName` (const std::string&): The father's name of the admin.
  - `userName` (const std::string&): The username of the admin.
  - `password` (const std::string&): The password of the admin.

#### Static Member Function
```cpp
static void registerAdmin(std::vector<User*>& users);
```
- Description: Registers a new admin and adds them to the vector of users.
- Parameters:
  - `users` (std::vector<User*>&): A reference to the vector of users where the new admin will be added.

#### Overridden Member Function
```cpp
int displayMenu() override;
```
- Description: Displays the admin menu and returns the choice selected by the admin.
- Returns: An integer representing the choice selected by the admin.

#### Member Functions
```cpp
int editProduct(std::vector<Product*>& products);
```
- Description: Allows the admin to choose and edit a product, which can also be used for restocking.
- Parameters:
  - `products` (std::vector<Product*>&): A reference to the vector of products from which the admin can choose the product to edit.
- Returns: An integer representing the next menu choice after editing the product.

```cpp
int deleteProduct(std::vector<Product*>& products);
```
- Description: Allows the admin to delete a product from the list of available products.
- Parameters:
  - `products` (std::vector<Product*>&): A reference to the vector of products from which the admin can choose the product to delete.
- Returns: An integer representing the next menu choice after deleting the product.

```cpp
int addProduct(std::vector<Product*>& products);
```
- Description: Allows the admin to add a new product to the list of available products.
- Parameters:
  - `products` (std::vector<Product*>&): A reference to the vector of products to which the new product will be added.
- Returns: An integer representing the next menu choice after adding the product.

### Usage Example
```cpp
// Create a new admin
Admin admin("John Doe", "Mr. Doe", "admin1", "password123");

// Register the new admin
Admin::registerAdmin(users);

// Display the admin menu and handle the selected option
int menuChoice = admin.displayMenu();
switch (menuChoice) {
    case 1:
        // Add a new product
        admin.addProduct(products);
        break;
    case 2:
        // Delete a product
        admin.deleteProduct(products);
        break;
    case 3:
        // Edit a product
        admin.editProduct(products);
        break;
    // ... other cases ...
}
```
