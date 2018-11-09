#include "jctvc_crawler.h"
#include "scanner.h"
#include <iostream>
#include <fstream>
#include <sstream>
int main(int argc, char **argv)
{
	std::stringstream ss("1234[] 7895");
	Scanner scn(ss);
	TokenPtr p = scn.nextToken();
	std::cin.get();
	return 0;
}