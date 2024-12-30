#include <iostream>
#include <memory>
#include "person.h"

void func(std::shared_ptr<Person> sptr)
{
	std::cout << "func called\n";
	std::cout << "inside func sptr.use_count() = " << sptr.use_count() << '\n';
	std::cout << *sptr << "\n";
}

int main()
{
	auto sp = std::make_shared<Person>("Necati", "Ergin");
	std::cout << "before calling func sp.use_count() = " << sp.use_count() << '\n';
	func(sp);
	std::cout << "after calling func sp.use_count() = " << sp.use_count() << '\n';
}
