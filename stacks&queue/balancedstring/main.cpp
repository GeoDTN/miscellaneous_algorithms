#include <iostream>
#include <string>

using namespace std;
/*
A string S consisting of N characters is called properly nested if:

        S is empty;
        S has the form "(U)" where U is a properly nested string;
        S has the form "VW" where V and W are properly nested strings.
For example, string "(()(())())" is properly nested but string "())" isn't.

Write a function:

    int solution(std::string& S);

that, given a string S consisting of N characters, returns 1 if string S is properly nested and 0 otherwise.

For example, given S = "(()(())())", the function should return 1 and given S = "())", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [0..1,000,000];
        string S consists only of the characters "(" and/or ")".
 */
int solution(std::string& S);
int main()
{
  cout << "Hello World!" << endl;
  return 0;
}
int solution(std::string& S) {
  int counter1{};
  int counter2{};
  if (S.length() == 0) return 1;
  if (S[0] == ')') return 0;
  for (char c : S) {
    if (c == '(')
      ++counter1;
    else
      ++counter2;
  }
  if(counter1!=counter2) return 0;
  else return 1;
}
