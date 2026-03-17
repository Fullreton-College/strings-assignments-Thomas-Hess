#include <iostream>
#include <fstream>
#include <string>
#include <sstream> // to parse
using namespace std;

void parseCSV(const string& filename);

int main() {
   parseCSV("students.csv");
   return 0;
}

void parseCSV(const string& filename) {
   ifstream file(filename);
   string line, token;

   while (getline(file, line)) {
      stringstream ss(line);

      while (ss >> token) {
         int pos = token.find(':');
         cout << token.substr(0, pos) << ": "
              << token.substr(pos + 1) << endl;
      }
      // assuming the format is consistant

      cout << endl; // space between students
   }
}
