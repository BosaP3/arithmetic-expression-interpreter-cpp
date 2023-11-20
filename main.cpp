#include <iostream>
#include <string>
#include "expression_evaluation.cpp"

using namespace std;

int main()
{
    string user_input;

    // Interface REPL (Read-Eval-Print-Loop) *****testing*****
    while (1)
    {
        cout << ">>> ";
        getline(cin, user_input);

        if (user_input == "exit")
            break;

        evaluation(user_input); // manda a entrada para avaliação
    }

    return 0;
}
