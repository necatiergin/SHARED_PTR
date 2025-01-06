#include <iostream>
#include <memory>
#include <string>

struct DelNec {
	void operator()(std::string* p)
	{
		std::cout << "DelErg " << *p << '\n';
		delete p;
	}
};

struct DelErg {
	void operator()(std::string* p)
	{
		std::cout << "DelErg " << *p << '\n';
		delete p;
	}
};

int main()
{
	using std::string, std::shared_ptr;

	shared_ptr<string> sp1(new string{ "necati" }, DelNec{});
	shared_ptr<string> sp2(new string{ "ergin" }, DelErg{});

	sp1 = sp2;
}
