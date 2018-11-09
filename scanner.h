#ifndef HM_RESULT_SCANNER_H
#define HM_RESULT_SCANNER_H
#include "token.h"
#include <iostream>
#include <fstream>
#include <deque>
class Scanner
{
public:
	Scanner(std::istream& input_stream);
	Scanner(std::string filename);
	Scanner(const Scanner &scn) = delete;
	Scanner& operator=(const Scanner &scn) = delete;
	~Scanner();
	bool open(std::string filename);
	bool is_open() const;
	void close();
	TokenPtr nextToken();
	std::string nextStringByDelimeter(char delimeter = ' ');
private:
	bool isNumber() const;
	bool isWord() const;
	std::string getNumber();
	TokenPtr nextTokenFromBufferedOutput();
	std::istream& _istream;
	std::ifstream _file;
	TokenFactory _tokenFactory;
	std::deque<char> _bufferedOutput;
};
#endif