#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ifstream file("list.txt");
  string line;
  vector<int> left;
  vector<int> right;

  if (file.is_open()) {
    while (getline(file, line)) {
      // stringstream ss(line);
      // ss >> 

      string leftie = line.substr(0, line.find(' '));
      string rightie = line.substr(line.find(' ') + 1);

      int lefti = stoi(leftie);
      int righti = stoi(rightie);
      left.push_back(lefti);
      right.push_back(righti);
    }

    file.close();

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int solution = 0;
 for (size_t i = 0; i < left.size(); ++i) {
            solution += abs(left[i] - right[i]);
        }

    cout << solution << endl;

  }

  else {
    cout << "Impossible d'ouvrir la liste." << endl;
  }

  return 0;
}
