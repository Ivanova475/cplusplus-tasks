#include <iostream>

#include "password_storage.h"


int main()
{
    PasswordStorage ps;
    std::cout << "Input password: ";
    std::string user_input;
    std::getline(std::cin, user_input);
    if (Hash(user_input) == ps.GetPasswordHash())
    {
        if (Hash(user_input) != ps.GetPasswordHash())
        {
            std::cout << "It seems somebody tried to patch this program.\n";
            std::cout << "That patch doesn't work! Ha-ha-ha!" << std::endl;
            return 1;
        }
        std::cout << "Correct password." << std::endl;
    }
        else
    {
        std::cout << "Incorrect password. Try again." << std::endl;
    }

    return 0;
}
