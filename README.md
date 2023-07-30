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

