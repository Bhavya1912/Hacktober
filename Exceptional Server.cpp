//his challenge, you are required to handle error messages while working with small computational server that performs complex calculations.
//It has a function that takes  large numbers as its input and returns a numeric result. Unfortunately, there are various exceptions that may occur during execution.

//Complete the code in your editor so that it prints appropriate error messages, should anything go wrong. The expected behavior is defined as follows:

//If the compute function runs fine with the given arguments, then print the result of the function call.
//If it fails to allocate the memory that it needs, print Not enough memory.
//If any other standard C++ exception occurs, print Exception: S where  is the exception's error message.
//If any non-standard exception occurs, print Other Exception.

#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/* Define the exception here */
struct BadLengthException : exception 
{
  string s;
  BadLengthException (int n) : s(to_string(n)) {}
  const char *what() const noexcept override 
  {
    return s.c_str();
  }
};


bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}
