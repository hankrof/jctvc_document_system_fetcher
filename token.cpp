#include "token.h"
Token::Token(const std::string &value)
	:  _value(value)
{

}

Token::~Token()
{

}

const std::string& Token::value() const
{
	return _value;
}

std::string& Token::value()
{
	return _value;
}

TokenUndefined::TokenUndefined()
	: Token("")
{

}

TokenWord::TokenWord(const std::string &value)
	: Token(value)
{

}

TokenNumber::TokenNumber(const std::string &value)
	: Token(value)
{

}

TokenLeftSquareBracket::TokenLeftSquareBracket()
	: Token("[")
{

}

TokenRightSquareBracket::TokenRightSquareBracket()
	: Token("]")
{

}

TokenLeftParenthese::TokenLeftParenthese()
	: Token("(")
{

}

TokenRightParenthese::TokenRightParenthese()
	: Token("(")
{

}

TokenColon::TokenColon()
	: Token(":")
{

}

TokenComma::TokenComma()
	: Token(",")
{

}

TokenDivision::TokenDivision()
	: Token("/")
{

}


TokenPlus::TokenPlus()
	: Token("+")
{

}


TokenMultiplication::TokenMultiplication()
	: Token("*")
{

}

TokenAssignment::TokenAssignment()
	: Token("=")
{

}

TokenDot::TokenDot()
	: Token(".")
{

}

TokenEOF::TokenEOF()
	: Token("")
{

}

TokenFactory::TokenFactory()
{
	initAsciiTokenTable();
}

TokenPtr TokenFactory::createToken(int c, const std::string &value) const
{
	if (_availableAsciiTokenTable[c])
		return _availableAsciiTokenTable[c];
	else if (!value.empty())
		return TokenPtr(new TokenWord(value);
	else
		return _availableAsciiTokenTable[256];
}

void TokenFactory::initAsciiTokenTable()
{
	_availableAsciiTokenTable['[']  = std::shared_ptr<Token>(new TokenLeftSquareBracket());
	_availableAsciiTokenTable[']']  = std::shared_ptr<Token>(new TokenRightSquareBracket());
	_availableAsciiTokenTable['(']  = std::shared_ptr<Token>(new TokenLeftParenthese());
	_availableAsciiTokenTable[')']  = std::shared_ptr<Token>(new TokenRightParenthese());
	_availableAsciiTokenTable[':']  = std::shared_ptr<Token>(new TokenColon());
	_availableAsciiTokenTable[',']  = std::shared_ptr<Token>(new TokenComma());
	_availableAsciiTokenTable['/']  = std::shared_ptr<Token>(new TokenDivision());
	_availableAsciiTokenTable['+']  = std::shared_ptr<Token>(new TokenPlus());
	_availableAsciiTokenTable['*']  = std::shared_ptr<Token>(new TokenMultiplication());
	_availableAsciiTokenTable['=']  = std::shared_ptr<Token>(new TokenAssignment());
	_availableAsciiTokenTable['.']  = std::shared_ptr<Token>(new TokenDot());
	_availableAsciiTokenTable[256]  = std::shared_ptr<Token>(new TokenUndefined());
}
