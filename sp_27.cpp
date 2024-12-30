#include <memory>
#include "point.h"
#include <iostream>

int main()
{
	auto sptr{ std::make_shared<Point>(3, 5, 8) };
	std::weak_ptr<Point> wp{ sptr };

	std::cout << "sptr.use_count() = " << sptr.use_count() << '\n';
	wp.reset();
	std::cout << "wp.use_count()   = " << wp.use_count() << '\n';
	std::cout << std::boolalpha;
	std::cout << "wp.expired() = " << wp.expired() << '\n';

	if (!wp.expired()) {
		std::shared_ptr<Point> sp(wp);
		std::cout << *sp << '\n';
	}
	else {
		std::cout << "resource already released\n";
	}
}
