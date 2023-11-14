#include <iostream>
#include <string>
#include <unordered_map>
#include "expression_evaluation.cpp"

using namespace std;

int main()
{
    string user_input;
    unordered_map<string, double> variables;

    // Interface REPL (Read-Eval-Print-Loop) *****testing*****
    while (1)
    {
        cout << ">>> ";
        getline(cin, user_input);

        if (user_input == "exit")
            break;

        if (isNumber(user_input)) // teste numero
        {
            cout << user_input << endl;
        }
        else
        {
            size_t pos = user_input.find("=");
            if (pos != string::npos) // testa variavel
            {
                string var = user_input.substr(0, pos);
                double value = stod(user_input.substr(pos + 1));
                variables[var] = value;
            }
            else if (variables.find(user_input) != variables.end()) // testa variavel existente
            {
                cout << variables[user_input] << endl;
            }
            else
            {
                cout << "Variavel nao definida: " << user_input << endl;
            }
        }
        // expressao
    }

    return 0;
}
