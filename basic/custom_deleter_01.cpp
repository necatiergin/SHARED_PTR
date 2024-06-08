//deleter constructor'a argüman olarak geçiliyor

#include <memory>
#include "person.h"


int main()
{
	{
		std::shared_ptr<Person> sptr{ new Person{"Gul", "Eryaman"}, [](Person* p) {
									std::cout << *p << " is being deleted\n";
									delete p;
									} };
	}

	std::cout << "main is still running\n";
	//....
}
