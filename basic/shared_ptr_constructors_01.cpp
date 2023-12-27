#include <memory>
#include <string>

int main()
{
	using namespace std;

	shared_ptr<string> sp1; //default constructed - empty
	shared_ptr<string> sp2{ nullptr }; //empty
	shared_ptr<string> sp3{ new string {"ahmet ibrahim aksoy"} };
	auto sp4 = make_shared<string>("omer ayyildiz");
	auto up = make_unique<string>("oguzhan katli");
	shared_ptr<string> sp5{ move(up) };
	//...
}
