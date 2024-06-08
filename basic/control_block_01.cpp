//This code example is related to control block that shared_ptr objects use.

#include <iostream>
#include <memory>


void* operator new(size_t n)
{
	std::cout << "operator new called n : " << n << '\n';
	void* vp = std::malloc(n);
	if (!vp) {
		throw std::bad_alloc{};
	}
	std::cout << "address of allocated block : " << vp << '\n';
	return vp;
}

void operator delete(void* vp)
{
	if (vp)
		std::free(vp);
}

struct Data {
	char buffer[1024]{};
};


void f1()
{
	std::cout << "f1  called\n";
	auto p = new Data;
	std::shared_ptr<Data> sptr(p);
	std::cout << "\n\n";
}

void f2()
{
	std::cout << "f2 called\n";
	auto sptr = std::make_shared<Data>();
	std::cout << "\n\n";
}

int main()
{
	//f1();
	f2();
}
