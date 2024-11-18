#include <iostream>
#include <string>

int cin_variable(std::string message)
{
    int variable = 0;
    std::cout << message;
    std::cin >> variable;
    return variable;
}