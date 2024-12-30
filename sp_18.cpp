#include <memory>
#include <vector>
#include <iostream>


using namespace std;

struct Member {};

struct Owner
{
	~Owner()
	{
		std::cout << "owner destructor\n";
	}
	Member mx;
};


using Ovec = std::vector<Owner>;


int main()
{
	shared_ptr<Ovec> svecptr(new Ovec); // use_count == 1
	svecptr->reserve(10);

	svecptr->emplace_back();
	svecptr->emplace_back();

	cout << "[1] svecptr.use_count() = " << svecptr.use_count() << "\n";

	shared_ptr<Owner> owner_ptr1(svecptr, &svecptr->at(0));
	cout << "[2] svecptr.use_count() = " << svecptr.use_count() << "\n";
	cout << "[3] owner_ptr1.use_count() = " << owner_ptr1.use_count() << "\n";
	shared_ptr<Owner> owner_ptr2(svecptr, &svecptr->at(1));
	cout << "[4] svecptr.use_count() = " << svecptr.use_count() << "\n";
	cout << "[5] optr1.use_count() = " << owner_ptr1.use_count() << "\n";
	cout << "[6] owner_ptr2.use_count() = " << owner_ptr2.use_count() << "\n";

	shared_ptr<Member> member_ptr(svecptr, &svecptr->at(1).mx);

	cout << "[7] svecptr.use_count() = " << svecptr.use_count() << "\n";
	cout << "[8] optr1.use_count() = " << owner_ptr1.use_count() << "\n";
	cout << "[9] owner_ptr2.use_count() = " << owner_ptr2.use_count() << "\n";
	cout << "[10] member_ptr.use_count() = " << member_ptr.use_count() << "\n";

	svecptr.reset();

	cout << "[11] svecptr.use_count() = " << svecptr.use_count() << "\n";
	cout << "[12] optr1.use_count() = " << owner_ptr1.use_count() << "\n";
	cout << "[13] owner_ptr2.use_count() = " << owner_ptr2.use_count() << "\n";
	cout << "[14] member_ptr.use_count() = " << member_ptr.use_count() << "\n";
	(void)getchar();
}
