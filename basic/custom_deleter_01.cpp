//deleter is passed to the constructor of the class

#include <memory>
#include "point.h"

int main()
{
	using namespace std;

	{
		shared_ptr<Point> sptr{ new Point{3, 6, 9}, [](Point* p) {
									std::cout << *p << " is being deleted\n";
									delete p;
									} };
	}

	cout << "main is still running\n";
	//...
}
