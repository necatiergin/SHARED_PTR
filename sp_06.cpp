#include <memory>
#include "point.h"
#include <iostream>

int main()
{
	auto spx = std::make_shared<Point>(1, 1, 1);
	auto spy = std::make_shared<Point>(2, 2, 2);

	std::cout << "use count for spx : " << spx.use_count() << '\n';
	std::cout << "use count for spy : " << spy.use_count() << '\n';
	spx = spy;
	std::cout << "press any key"; std::getchar();

	std::cout << "use count for spx : " << spx.use_count() << '\n';
	std::cout << "use count for spy : " << spy.use_count() << '\n';
	std::cout << "press any key "; 
	std::getchar();
}
