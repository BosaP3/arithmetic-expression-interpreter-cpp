//*****test****
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <cmath>
#include <string>

std::unordered_map<std::string, double> variables;

bool isNumber(const std::string &s)
{
    std::istringstream iss(s);
    double value;
    return iss >> value >> std::ws && iss.eof();
}

void evaluation_Variable(const std::string &input)
{
    size_t pos = input.find("="); // encontra o sinal
    std::string var = input.substr(0, pos);
    double value = std::stod(input.substr(pos + 1));
    variables[var] = value; // guarda no map

    // testar se o valor depois do sinal é uma expressao e resolver
}

void evaluation(const std::string &input)
{
    if (isNumber(input)) // teste se for somente um numero
        std::cout << input << std::endl;
    else if (input.find('=') != std::string::npos) // teste se é variavel
        evaluation_Variable(input);
    else if (variables.find(input) != variables.end()) // teste de chave mapeada
        std::cout << variables[input] << std::endl;
    else // teste de expressao
    {
        // return evaluation_Expression(input); // Em caso de "input" função...
    }
}