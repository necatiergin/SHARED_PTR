#include <memory>
#include "point.h"
#include <iostream>

int main()
{
	using namespace std;

	auto sptr{ make_shared<Point>(3, 5, 8) };
	weak_ptr<Point> wp{ sptr };

	cout << "sptr.use_count() = " << sptr.use_count() << '\n';
	wp.reset();
	cout << "wp.use_count()   = " << wp.use_count() << '\n';
	cout << boolalpha;
	std::cout << "wp.expired() = " << wp.expired() << '\n';

	if (!wp.expired()) {
		shared_ptr<Point> sp(wp);
		cout << *sp << '\n';
	}
	else {
		cout << "resource already released\n";
	}
}
