#include <memory>
#include <string>
#include <iostream>

int main()
{
	using namespace std;

	auto p = new string{ "necati ergin" };
	cout << "p          = " << p << '\n';
	shared_ptr<string> spx{p};
	shared_ptr<string> spy;

	cout << "*spx       = " << *spx << '\n';
	cout << "spx        = " << spx << '\n';
	cout << "spx.get()  = " << spx.get() << '\n';

	cout << boolalpha;

	cout << "spx == spy = " << (spx == spy) << '\n';
	spy = spx;
	cout << "spx == spy = " << (spx == spy) << '\n';
}
