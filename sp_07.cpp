#include <memory>
#include <string>
#include <iostream>

int main()
{
	using std::cout;

	auto p = new std::string{ "necati ergin" };
	cout << "p          = " << p << '\n';
	std::shared_ptr<std::string> spx{ p };
	std::shared_ptr<std::string> spy;

	cout << "*spx       = " << *spx << '\n';
	cout << "spx        = " << spx << '\n';
	cout << "spx.get()  = " << spx.get() << '\n';

	cout << std::boolalpha;

	cout << "spx == spy = " << (spx == spy) << '\n';
	spy = spx;
	cout << "spx == spy = " << (spx == spy) << '\n';
}
