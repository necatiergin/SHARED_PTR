#include <memory>
#include <string>
#include <iostream>

struct Nec {
	Nec() { std::cout << "constructor\n"; }
	~Nec() { std::cout << "destructor\n"; }
};

int main()
{
	using namespace std;

	shared_ptr<void> sp1{ new Nec };
	shared_ptr<void> sp2{ new string};
	shared_ptr<void> sp3{ new int};
}
