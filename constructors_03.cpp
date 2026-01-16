#include <memory>
#include <string>
#include <iostream>

struct Nec {
	Nec() { std::cout << "constructor\n"; }
	~Nec() { std::cout << "destructor\n"; }
};

int main()
{
	std::shared_ptr<void> sp1{ new Nec };
	std::shared_ptr<void> sp2{ new std::string };
	std::shared_ptr<void> sp3{ new int };
}
