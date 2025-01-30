#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    int trim;

    cin >> word;
    while (word != "-1") {            // look at first input for end of data
        cin >> trim;
        cout << word.substr(trim, word.length()-1) << endl;
        cin >> word;
    }

    return 0;
}
