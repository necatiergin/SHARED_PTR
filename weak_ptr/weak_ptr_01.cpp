#include <memory>
#include <iostream>
#include "point.h"

int main()
{
	using namespace std;
	cout << boolalpha;

	auto sptr = make_shared<Point>(4, 7, 9);
	weak_ptr<Point> wp{ sptr };

	cout << "sptr.use_count() = " << sptr.use_count() << '\n';
	//sptr.reset();
	//cout << "wp.use_count() = " << wp.use_count() << '\n';
	//cout << "wp.expired() = " << wp.expired() << "\n";

	//if (shared_ptr<Date> sp = wp.lock()) {
	if (auto sp = wp.lock()) {
		cout << "resource not released yet: " << *sp << '\n';
	}
	else {
		cout << "resource already released\n";
	}

}
