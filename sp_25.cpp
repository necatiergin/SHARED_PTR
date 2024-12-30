#include <memory>
#include <iostream>

struct B;

struct A {
	//std::shared_ptr<B> bptr;
	std::weak_ptr<B> bptr;
	~A() {
		std::cout << "A destructor\n";
	}
};

struct B {
	std::shared_ptr<A> aptr;
	~B() {
		std::cout << "B destructor\n";
	}
};

int main()
{
	std::shared_ptr<A> spa{ new A };
	std::shared_ptr<B> spb{ new B };
	spa->bptr = spb;
	std::cout << "spb.use_count() = " << spb.use_count() << "\n";
	spb->aptr = spa;
	std::cout << "spa.use_count() = " << spa.use_count() << "\n";
	//getchar();

}
