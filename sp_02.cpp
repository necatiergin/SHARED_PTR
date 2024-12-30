#include <memory>
#include <string>
#include <iostream>

int main()
{
	using std::cout, std::string;

	std::shared_ptr<string> sptr{ new string{"necati"} };

	cout << "sizeof(string *) = " << sizeof(string*) << '\n';
	cout << "sizeof(sptr)     = " << sizeof(sptr) << '\n';
}
