#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

using namespace std;

/*bool myfunction (int i,int j) { return (i<j); }

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int main () {
  int myints[] = {32,71,12,45,26,80,53,33};
  vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

  // using default comparison (operator <):
  sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33

  // using function as comp
  sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

  // using object as comp
  sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

  // print out content:
  cout << "myvector contains:";
  for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';

  return 0;
} */
int eucl (int x, int y) { // x > y
    if (x % y == 0) {
        return y;
    }
    else {
        int temp = x % y;
        return eucl(y, temp);
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    int minab = a, maxab = b;
    if (b < a) {
        minab = b;
        maxab = a;
    }
    cout << eucl(maxab, minab) << endl;
    return 0;
}
