// V 0.0.0 alpha
#include <iostream>
#include <fstream>
 
using namespace std;

int main(int argc, char *argv[]) {
	if (argc < 2) {
		cerr << "Error: " << "No input arguments!.";
		exit(1);
	}

	string prefix_out_file = "no_comment_";
	string cur_str;

	ifstream ifile(argv[1]);
	ofstream ofile((argc > 2 ? argv[2] : prefix_out_file + argv[1]));

	if (ifile.is_open() && ofile.is_open()) {
		while (getline(ifile, cur_str)) {
			cur_str.push_back('\n');
		
			for (int i = 0; i < cur_str.length(); ++i) {
				if (cur_str[i] == '/' && cur_str[i + 1] == '/')
					while (cur_str[i] != '\n') ++i;

				ofile.put(cur_str[i]);
			}
		}
	} else {
		cerr << "Can't open file(s).\n";
		exit(1);
	}

	return 0;
}

// B.M Samir