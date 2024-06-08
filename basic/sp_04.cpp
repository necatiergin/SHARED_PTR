#include "point.h"
#include <memory>
#include <iostream>

int main()
{
	using namespace std;

	auto spx = make_shared<Point>(1, 1, 1);
	auto spy = make_shared<Point>(2, 2, 2);

	std::cout << "use count for spx : " << spx.use_count() << '\n';
	std::cout << "use count for spy : " << spy.use_count() << '\n';
	spx = spy;
	std::cout << "press any key"; std::getchar();

	std::cout << "use count for spx : " << spx.use_count() << '\n';
	std::cout << "use count for spy : " << spy.use_count() << '\n';
	std::cout << "press any key "; std::getchar();
}
