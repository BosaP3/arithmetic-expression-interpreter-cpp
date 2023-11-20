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

bool isVariable(const std::string &var)
{
    return variables.find(var) != variables.end();
}

bool isOperator(const char &op)
{ // é Operador
    return op == '+' || op == '-' || op == '*' || op == '/';
}

void evaluation_Expression(const std::string &input)
{
    std::istringstream stream(input); //Cria um fluxo de string
    std::string token;
    while (stream >> token)
    {
        if (isOperator(token[0]))
        {
            // pushOperator(token[0]);
        }
        else if (isVariable(token))
        {
            double value = variables[token];
            // pushOperand(value);
        }
        else
        {
            try
            {
                double value = std::stod(token);
                // pushOperand(value);
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << "Erro: Valor invalido na expressao.\nOu\nErro: Variavel nao encontrada; \n"
                          << std::endl;
                // return NAN; **criar tratamento na main**
            }
        }
    }
    // evaluateFinal(); //tree
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
        evaluation_Expression(input); // Em caso de "input" função...
    }
}