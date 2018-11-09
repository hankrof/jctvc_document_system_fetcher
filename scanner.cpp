#include "scanner.h"
Scanner::Scanner(std::istream& input_stream)
	: _istream(input_stream)
{

}

Scanner::Scanner(std::string filename)
	: _istream(_file)
{
	open(filename);
}

Scanner::~Scanner()
{
	_file.close();
}

bool Scanner::open(std::string filename)
{
	bool result(true);
	try
	{
		if (_file.is_open())
			throw std::exception("Scanner is already opened to be associated with a file");
		_file.open(filename);
		if (!_file.is_open())
			throw std::exception("Could not open file!");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		result = false;
	}
	return result;
}

bool Scanner::is_open() const
{
	return _file.is_open();
}

void Scanner::close()
{
	_file.close();
}

TokenPtr Scanner::nextToken()
{
	if (!_bufferedOutput.empty())
		return nextTokenFromBufferedOutput();
	while (!_istream.eof() && _bufferedOutput.empty())
	{
		std::string s = nextStringByDelimeter();
		_bufferedOutput.resize(s.size());
		std::copy(s.begin(), s.end(), _bufferedOutput.begin());
	}
	return nextTokenFromBufferedOutput();
}

TokenPtr Scanner::nextTokenFromBufferedOutput()
{
	std::string output;
	TokenPtr p;
	if (!_bufferedOutput.empty())
	{
		for (size_t i = 0; i < _bufferedOutput.size(); i++)
		{
		}
		p = _tokenFactory.createToken(output[0], output);
	}
	return p;
}

std::string Scanner::nextStringByDelimeter(char delimeter)
{
	int c;
	std::string s;
	for (c = _istream.get(); c != delimeter && !_istream.eof(); c = _istream.get())
		if (c != '\n')
			s += c;
	while (!_istream.eof() && c == delimeter)
		c = _istream.get();
	if (!_istream.eof())
		_istream.unget();
	return s;
}

bool Scanner::isNumber(char c) const
{

}

bool Scanner::isWord(char c) const
{

}
