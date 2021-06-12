#include <iostream>
#include <string>

using namespace std;

class Term;
class Polynomial;

class Term {
public:
  friend class Polynomial;
  void set_term(string s);
  int get_pow();
  int get_coefficient();

private:
  int coefficient;
  int pow;
};

class Polynomial {
public:
  friend class Term;
  Polynomial(int s, Term t[]);
  int get_size();
  Term *myterm;

private:
  int P_size;
};

void Term::set_term(string s) {
  coefficient = stoi(s.substr(1, 1));
  pow = stoi(s.substr(4, 1));
  if (s[0] == '-') {
    coefficient = -coefficient;
  }
}

int Term::get_coefficient() { return coefficient; }
int Term::get_pow() { return pow; }

Polynomial::Polynomial(int s, Term t[]) {
  P_size = s;
  myterm = new Term[s];
  for (int i = 0; i < s; i++) {
    myterm[i].coefficient = t[i].coefficient;
    cout << i << " Term " << t[i].coefficient << endl;
    cout << i << " Polynomial " << myterm[i].coefficient << endl;
    myterm[i].pow = t[i].pow;
  }
}

int Polynomial::get_size() { return P_size; }

int main() {
  string x1;
  cin >> x1;
  int size_x1 = x1.size();

  Term term1[size_x1];

  for (int i = 0; i < size_x1; i += 5) {
    term1[i].set_term(x1.substr(i, 5));
  }

  Polynomial p1(size_x1 / 5, term1);
  for (int i = 0; i < size_x1; i += 5) {
    cout << term1[i].get_coefficient() << "x^";
    cout << term1[i].get_pow() << endl;
  }

  cout << "------------------" << endl;

  for (int i = 0; i < p1.get_size(); i++) {
    if (p1.myterm[i].get_coefficient() > 0)
      cout << "+";

    cout << p1.myterm[i].get_coefficient();
    cout << "x^";
    cout << p1.myterm[i].get_pow() << endl;
  }
  return 0;
}
