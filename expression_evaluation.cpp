#include <unordered_map>
#include <string>
#include <sstream>
#include "expression_tree.cpp"

std::unordered_map<std::string, std::string> variables;

// Verifica se a entrada pode ser convertida para um double
bool isNumber(const std::string &s)
{
    std::stringstream iss(s);
    double value;
    iss >> value;
    return iss.eof();
}

// Verifica se a entrada já foi mapeada
bool isVariable(const std::string &var)
{
    return variables.find(var) != variables.end();
}

// Verifica se a entrada é um operador valido
bool isOperator(std::string str)
{
    return str == "+" || str == "-" || str == "*" || str == "/";
}

// Recebe e percorre uma String para analisar e/ou adaptar os parametros corretos de uma Expressõe Aritmética
std::string validExpression(const std::string &input)
{
    std::string correct;

    // Dividir a expressão pelos espaços
    std::stringstream ss(input);
    std::string element;

    // Contador de parênteses abertos
    int ParenthesesCount = 0;

    while (ss >> element)
    {
        if (!element.empty())
        {
            if (isNumber(element) || isOperator(element))
            { // Operando / Operador
                correct += element + " ";
            }
            else if (isVariable(element))
            {                                        //  Variavel
                correct += variables[element] + " "; // Passa o valor da variável
            }
            else if (element == "(")
            { // Parenteses
                ParenthesesCount++;
                correct += element + " ";
            }
            else if (element == ")")
            {
                if (ParenthesesCount > 0)
                {
                    ParenthesesCount--;
                    correct += element + " ";
                }
            }
            else
            {
                return "ERRO1";
            }
        }
    }
    // Verificação de parênteses desalinhados
    if (ParenthesesCount != 0)
    {
        return "ERRO2";
    }

    return correct;
}

// Recebe e guarda uma variavel no unordered_map
void evaluation_Variable(const std::string &input)
{
    size_t pos = input.find("=");
    std::string var = input.substr(0, pos);
    std::string value = input.substr(pos + 1);

    // remove as ocorrencias dos "caracteres"
    var.erase(var.find_last_not_of(" \t\n\r\f\v") + 1);
    value.erase(0, value.find_first_not_of(" \t\n\r\f\v"));

    if (value.find_first_of("+-*/()") != std::string::npos)
    {
        std::string test = validExpression(value);
        if (test == "ERRO1")
            std::cout << "Erro: Valor invalido encontrado." << std::endl;
        else if (test == "ERRO2")
            std::cout << "ERRO: Parenteses desbalanceados." << std::endl;
        else
        {
            Node *raiz = buildExpression(test);
            double result = calculateResult(raiz);
            variables[var] = std::to_string(result);
        }
    }
    else
    {
        variables[var] = value;
    }
}

// Coordena a avaliação da entrada
void evaluation(const std::string &input)
{
    if (input.find('=') != std::string::npos) // Variavel
        evaluation_Variable(input);
    else if (variables.find(input) != variables.end()) // Chave mapeada
        std::cout << variables[input] << std::endl;
    else // Expressao
    {
        std::string test = validExpression(input);
        if (test == "ERRO1")
            std::cout << "Erro: Valor invalido encontrado." << std::endl;
        else if (test == "ERRO2")
            std::cout << "ERRO: Parenteses desbalanceados." << std::endl;
        else
        {
            Node *raiz = buildExpression(test);
            std::cout << calculateResult(raiz) << std::endl;
        }
    }
}
