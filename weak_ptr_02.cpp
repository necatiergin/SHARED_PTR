#include <memory>
#include "person.h"
#include <iostream>



int main()
{
	using namespace std;
	
	auto spx = make_shared<Person>("Hakki", "Alagoz");

	cout << *spx << '\n';
	cout << "spx use count = " << spx.use_count() << '\n';
	weak_ptr<Person> wp(spx);
	cout << "spx use count = " << spx.use_count() << '\n';
	cout << "wp.use_count() = " << wp.use_count() << '\n';

	spx.reset();

	if (wp.expired()) {
		std::cout << "resource released\n";
	}
	else {  //not thread_safe
		cout << "resource not yet released\n";
		shared_ptr sx{ wp };
		cout << *sx << '\n';
	}
	(void)getchar();
}
