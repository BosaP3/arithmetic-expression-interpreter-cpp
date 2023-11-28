#include <stack>
#include <sstream>

// Estrutura para representar um nó da árvore de expressão
struct Node
{
    std::string value;
    Node *left;
    Node *right;

    Node(std::string v) : value(v), left(nullptr), right(nullptr) {}
};

// Verifica se um operador tem uma prioridade maior que outro
int getPriority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0; // else
}

// Constrói a árvore de expressão a partir de uma expressão "inorder/infixa"
Node *buildExpression(const std::string &expression)
{
    std::stack<Node *> stackNodes;
    std::stack<char> operators;

    std::stringstream ss(expression);
    std::string element;

    while (ss >> element)
    {
        if (isdigit(element[0]))
        {
            stackNodes.push(new Node(element));
        }
        else if (element == "(")
        {
            operators.push('(');
        }
        else if (element == ")")
        {
            while (!operators.empty() && operators.top() != '(')
            {
                Node *right = stackNodes.top();
                stackNodes.pop();

                Node *left = stackNodes.top();
                stackNodes.pop();

                Node *operador = new Node(std::string(1, operators.top()));
                operador->left = left;
                operador->right = right;

                stackNodes.push(operador);
                operators.pop();
            }
            operators.pop(); // Remover o '('
        }
        else
        {
            while (!operators.empty() && getPriority(operators.top()) >= getPriority(element[0]))
            {
                Node *right = stackNodes.top();
                stackNodes.pop();

                Node *left = stackNodes.top();
                stackNodes.pop();

                Node *operador = new Node(std::string(1, operators.top()));
                operador->left = left;
                operador->right = right;

                stackNodes.push(operador);
                operators.pop();
            }
            operators.push(element[0]);
        }
    }

    while (!operators.empty())
    {
        Node *right = stackNodes.top();
        stackNodes.pop();

        Node *left = stackNodes.top();
        stackNodes.pop();

        Node *operador = new Node(std::string(1, operators.top()));
        operador->left = left;
        operador->right = right;

        stackNodes.push(operador);
        operators.pop();
    }

    return stackNodes.top();
}

// recebe um Node e calcula o resultado da expressão
double calculateResult(Node *raiz)
{
    if (!raiz)
    {
        return 0.0;
    }

    if (isdigit(raiz->value[0]))
    {
        return stof(raiz->value);
    }

    double left = calculateResult(raiz->left);
    double right = calculateResult(raiz->right);

    if (raiz->value == "+")
    {
        return left + right;
    }
    else if (raiz->value == "-")
    {
        return left - right;
    }
    else if (raiz->value == "*")
    {
        return left * right;
    }
    else if (raiz->value == "/")
    {
        if (right != 0)
        {
            return left / right;
        }
        else
        {
            std::cerr << "Erro: Divisao por zero." << std::endl;
            return 0;
        }
    }

    std::cerr << "Erro: Operador invalido." << std::endl;
    return 0;
}

void TreeIn(Node *root)
{
  if (!root)
    return;

  TreeIn(root->left);
  std::cout << root->value << ' ';
  TreeIn(root->right);
}