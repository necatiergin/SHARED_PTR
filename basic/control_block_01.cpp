//Bu ornek shared ptr nesnelerinin kullandigi kontrol bloguyla ilgili

#include <iostream>
#include <memory>


void* operator new(size_t n)
{
	std::cout << "operator new called n : " << n << "\n";
	void* vp = std::malloc(n);
	if (!vp) {
		throw std::bad_alloc{};
	}
	std::cout << "address of allocated block : " << vp << "\n";
	return vp;
}

//operator delete kodda gosterilmiyor

struct Data {
	char buffer[1024]{};
};


void f1()
{
	std::cout << "f1 cagrildi\n";
	auto p = new Data;
	std::shared_ptr<Data> sptr(p);
	std::cout << "\n\n";
}

void f2()
{
	std::cout << "f2 cagrildi\n";
	auto sptr = std::make_shared<Data>();
	std::cout << "\n\n";
}

int main()
{
	//f1();
	f2();
}
