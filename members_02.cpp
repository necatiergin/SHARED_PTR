#include <memory>
#include <string>
#include <iostream>

int main()
{
	using std::cout, std::string, std::shared_ptr;

	cout << std::boolalpha;
	shared_ptr<string> p1;

	cout << "p1 is : " << (p1 ? "not empty" : "empty") << '\n';
	p1.reset(new string{ "necati" });
	cout << "p1 is : " << (p1 ? "not empty" : "empty") << '\n';
	cout << "*p1   : " << *p1 << '\n';
	p1.reset();
	cout << "p1 is : " << (p1 ? "not empty" : "empty") << '\n';

	shared_ptr<string> p2{ nullptr };
	cout << "p2 is : " << (p2 ? "not empty" : "empty") << '\n';
	p2 =std:: make_shared<string>("ergin");
	cout << "p2 is : " << (p2 ? "not empty" : "empty") << '\n';
	p2 = nullptr;
	cout << "p2 is : " << (p2 ? "not empty" : "empty") << '\n';
}
