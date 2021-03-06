#include "stdafx.h"
#include <iostream>
#include <args.hxx>

using namespace args;
using namespace std;

int main(int argc, char **argv)
{
	ArgumentParser parser("This is a test program.", "This goes after the options.");
	HelpFlag help(parser, "help", "Display this help menu", { 'h', "help" });
	CompletionFlag completion(parser, { "complete" });
	
	try
	{
		parser.ParseCLI(argc, argv);
	}
	catch (const Completion& e)
	{
		cout << e.what();
	}
	catch (const Help&)
	{
		cout << parser;
	}
	catch (const ParseError& e)
	{
		cerr << e.what() << endl;
		cerr << parser;
		return 1;
	}

	return 0;
}

