//deleter is passed to the constructor of the class

#include <memory>
#include "point.h"

int main()
{
	{
		std::shared_ptr<Point> sptr{ new Point{3, 6, 9}, [](Point* p) {
									std::cout << *p << " is being deleted\n";
									delete p;
									} };
	}

	std::cout << "main is still running\n";
	//...
}
