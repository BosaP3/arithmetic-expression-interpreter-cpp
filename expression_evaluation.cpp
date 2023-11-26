#include <sstream>
#include <unordered_map>
#include <cmath>
#include <string>
#include <vector>
// #include "expression_tree.cpp"

struct valueOperator
{
    std::string op;
    double val;
};

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

bool isOperator(std::string str)
{
    return str == "+" || str == "-" || str == "*" || str == "/";
}

std::vector<valueOperator> expressionParts(const std::string &input)
{ // Divide a expressão em partes
    std::vector<valueOperator> Parts;
    std::string currentPart;

    // testar parenteses **
    for (char c : input) // separa os valores usando espaços delimitador
    {
        if (!std::isspace(c)) // Ignorar espaços em branco
        {
            currentPart += c;
        }
        else if (!currentPart.empty())
        {
            if (isNumber(currentPart))
            {
                valueOperator item;
                item.val = std::stod(currentPart);
                Parts.push_back(item);
            }
            else if (isOperator(currentPart))
            {
                valueOperator item;
                item.op = currentPart;
                Parts.push_back(item);
            }
            else if (variables.find(currentPart) != variables.end())
            {
                valueOperator item;
                item.val = variables[currentPart];
                Parts.push_back(item);
            }
            else
            {
                std::cerr << "Erro: Valor invalido na expressao.\nOu\nErro: Variavel nao encontrada; \n"
                          << std::endl;
            }
            currentPart.clear();
        }
    }
    if (!currentPart.empty()) // Ultima parte
    {
        if (isNumber(currentPart))
        {
            valueOperator item;
            item.val = std::stod(currentPart);
            Parts.push_back(item);
        }
        else if (isOperator(currentPart))
        {
            valueOperator item;
            item.op = currentPart;
            Parts.push_back(item);
        }
        else if (variables.find(currentPart) != variables.end())
        {
            valueOperator item;
            item.val = variables[currentPart];
            Parts.push_back(item);
        }
        else
        {
            std::cerr << "Erro: Valor invalido na expressao.\nOu\nErro: Variavel nao encontrada; \n"
                      << std::endl;
        }
        currentPart.clear();
    }
    return Parts; // Retorna um vector expressionParts
}

void evaluation_Variable(const std::string &input)
{
    size_t pos = input.find("=");
    std::string var = input.substr(0, pos);
    double value = std::stod(input.substr(pos + 1));
    variables[var] = value; // Guarda no map

    // Testar se o valor depois do sinal é uma expressao e resolver
}

void evaluation(const std::string &input)
{
    if (isNumber(input)) // Se for numero
        std::cout << input << std::endl;
    else if (input.find('=') != std::string::npos) // Se é variavel
        evaluation_Variable(input);
    else if (variables.find(input) != variables.end()) // Se for chave mapeada
        std::cout << variables[input] << std::endl;
    else // Teste de expressao
    {
        for (const auto &item : expressionParts(input))
        {
            if (!item.op.empty())
                std::cout << "Operador " << item.op << std::endl;
            else
                std::cout << "Valor " << item.val << std::endl;
        }
    }
}