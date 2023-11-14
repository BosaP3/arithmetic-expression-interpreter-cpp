// *****testing*****

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

        // tratamento da avaliacao  *****testing*****
        double result = test(user_input);
        cout << "R: " << result << endl;
    }

    return 0;
}
