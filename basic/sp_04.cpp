#include "triple.h"
#include <memory>
#include <iostream>

int main()
{
	using namespace std;

	auto spx = make_shared<Triple>(1, 1, 1);
	auto spy = make_shared<Triple>(2, 2, 2);

	std::cout << "use count for spx : " << spx.use_count() << "\n";
	std::cout << "use count for spy : " << spy.use_count() << "\n";
	spx = spy;
	std::cout << "bir tusa basin "; std::getchar();

	std::cout << "use count for spx : " << spx.use_count() << "\n";
	std::cout << "use count for spy : " << spy.use_count() << "\n";
	std::cout << "bir tusa basin "; std::getchar();
}
