#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<vector<string>> lista = {{"11 ", "22 ", "32 "}};
  vector<string>::iterator it = find(lista[0].begin(), lista[0].end(), "11");

  return 0;
}
