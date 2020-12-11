#include <iostream>
#include <fstream>
#include <string>
#include <regex>
 
using namespace std;

int main(int argc, char *argv[]) {
	if (argc < 2) {
		cerr << "Error: No input arguments.";
		exit(1);
	}

	string crline;
	const string prefix_out_file = "no_comments_";

	ifstream ifile(argv[1]);
	ofstream ofile((argc > 2 ? argv[2] : prefix_out_file + argv[1]));

	//regex regular("[^\"]{1}((\\/\\*[^\\*\\/]*\\*\\/)|(//.*))");
	regex regular("(\\/\\*[^\\*\\/]*\\*\\/)|(//.*)");

	if (ifile && ofile) {
		while (getline(ifile, crline)) 
			ofile << regex_replace(crline.c_str(), regular, "") << '\n';
	} else {
		cerr << "Can't open file(s).\n";
		exit(1);
	}

	ofile.close();
	ifile.close();

	return 0;
}

// Hi!
