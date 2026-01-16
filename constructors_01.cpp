#include <memory>
#include <string>

int main()
{
	using std::shared_ptr, std::string;

	shared_ptr<string> sp1; //default constructed - empty
	shared_ptr<string> sp2{ nullptr }; //empty
	shared_ptr<string> sp3{ new string {"ahmet ibrahim aksoy"} };
	auto sp4 = std::make_shared<string>("omer ayyildiz");
	auto up = std::make_unique<string>("oguzhan katli");
	shared_ptr<string> sp5{ std::move(up) };
	//...
}
