#include "scanner.h"
#include <cctype>

Token::Token(TokenType typeOfToken, const string &valueOfToken)
{
    type = typeOfToken;
    value = valueOfToken;
}

Token getNextToken(const string &input, size_t &pos)
{
    while (pos < input.length() && isspace(input[pos]))
    {
        pos++;
    }
    if (pos >= input.length())
    {
        return Token(END_OF_INPUT, "");
    }

    // Handle numbers (including negative numbers)
    if ((input[pos] == '-' && pos + 1 < input.length() && isdigit(input[pos + 1])) || isdigit(input[pos]))
    {
        bool isNegativeNumber = (input[pos] == '-');
        if (isNegativeNumber)
        {
            if (pos > 0 && (input[pos - 1] == '(' || input[pos - 1] == '=' ||
                            input[pos - 1] == '+' || input[pos - 1] == '-' ||
                            input[pos - 1] == '*' || input[pos - 1] == '/'))
            {
                string number;
                number += input[pos++];
                while (pos < input.length() && isdigit(input[pos]))
                {
                    number += input[pos++];
                }
                return Token(NUMBER, number);
            }
        }

        string number;
        if (isNegativeNumber)
        {
            number += input[pos++];
        }
        while (pos < input.length() && isdigit(input[pos]))
        {
            number += input[pos++];
        }
        return number.length() > 1 || isNegativeNumber ? Token(NUMBER, number) : Token(DIGIT, number);
    }

    // Handle operators
    if (input[pos] == '+' || input[pos] == '-' || input[pos] == '*' || input[pos] == '/' || input[pos] == '(' || input[pos] == ')')
    {
        string op;
        op += input[pos++];
        return Token(OPERATOR, op);
    }

    // Handle unknown tokens
    string unknown;
    while (pos < input.length() && !isspace(input[pos]) &&
           input[pos] != '+' && input[pos] != '-' &&
           input[pos] != '*' && input[pos] != '/' &&
           input[pos] != '(' && input[pos] != ')')
    {
        unknown += input[pos++];
    }
    return Token(UNKNOWN, unknown);
}

vector<Token> tokenize(const string &input)
{
    vector<Token> tokens;
    size_t position = 0;

    while (true)
    {
        Token token = getNextToken(input, position);
        if (token.type == END_OF_INPUT)
        {
            break;
        }
        tokens.push_back(token);
    }

    return tokens;
}