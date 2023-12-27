#include <iostream>
#include <memory>
#include "person.h"

void func(std::shared_ptr<Person> sptr)
{
	std::cout << "func cagrildi\n";
	std::cout << "sptr.use_count() = " << sptr.use_count() << '\n';
	std::cout << *sptr << "\n";
}

int main()
{
	auto sp = std::make_shared<Person>("Necati", "Ergin");
	std::cout << "func cagrisindan sonra sp.use_count() = " << sp.use_count() << '\n';
	func(sp);
	std::cout << "func cagrisindan sonra sp.use_count() = " << sp.use_count() << '\n';
}
