#include "scanner.h"
#include <iostream>

int main()
{
    string input;
    cout << "Enter input: ";
    getline(cin, input);

    vector<Token> tokens = tokenize(input);

    for (size_t i = 0; i < tokens.size(); i++)
    {
        const Token &token = tokens[i];
        cout << "Token(Type: ";
        switch (token.type)
        {
        case DIGIT:
            cout << "DIGIT";
            break;
        case NUMBER:
            cout << "NUMBER";
            break;
        case OPERATOR:
            cout << "OPERATOR";
            break;
        case UNKNOWN:
            cout << "UNKNOWN";
            break;
        default:
            cout << "OTHER";
        }
        cout << ", Value: \"" << token.value << "\")\n";
    }

    return 0;
}