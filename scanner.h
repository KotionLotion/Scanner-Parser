#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>

using namespace std;

enum TokenType
{
    DIGIT,
    NUMBER,
    OPERATOR,
    UNKNOWN,
    END_OF_INPUT
};

struct Token
{
    TokenType type;
    string value;
    Token(TokenType typeOfToken, const string &valueOfToken);
};

vector<Token> tokenize(const string &input);

#endif