#include <iostream>
#include <string>
#include "Vector"

int cin_variable(std::string message)
{
    int variable = 0;
    std::cout << message;
    std::cin >> variable;
    return variable;
}

void printMessage(int message)
{
    std::cout << message << std::endl;
}

void printMessage(std::string message)
{
    std::cout << message << std::endl;
}