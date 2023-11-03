// ...

#include <iostream>
#include <string>

using namespace std;

int main(){
    string user_input;
    
    // Interface REPL (Read-Eval-Print-Loop) *****testing*****
    while(1){ 
        cout << ">>> ";
        getline(cin, user_input);

        if(user_input == "exit") break;

        // tratamento da avaliacao  

        
    }

    return 0;
}
