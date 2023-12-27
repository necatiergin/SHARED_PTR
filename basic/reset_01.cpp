#include <memory>
#include <iostream>

struct Nec {
	Nec()
	{
		std::cout << "Nec default ctor\n";
	}

	~Nec()
	{
		std::cout << "Nec destructor\n";
	}
};

int main()
{
	auto sp1 = std::make_shared<Nec>();
	std::cout << "sp1.use_count() = " << sp1.use_count() << '\n';
	auto sp2 = sp1;
	std::cout << "sp1.use_count() = " << sp1.use_count() << '\n';
	std::cout << "sp2.use_count() = " << sp2.use_count() << '\n';
	//sp1.reset(); //doesn't destroy the object
	sp1 = nullptr;
	std::cout << "sp2.use_count() = " << sp2.use_count() << '\n';
	(void)getchar();
}
