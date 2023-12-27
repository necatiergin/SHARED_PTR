//deleter constructor'a argüman olarak geçiliyor

#include <memory>
#include "person.h"


int main()
{
	{
		std::shared_ptr<Person> sptr{ new Person{"Gul", "Eryaman"}, [](Person* p) {
									std::cout << *p << " kisisi delete ediliyor\n";
									delete p;
									} };
	}

	std::cout << "main devam ediyor\n";
}
