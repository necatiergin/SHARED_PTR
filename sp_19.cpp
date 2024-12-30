#include <memory>
#include <string>

int main()
{
	auto ptr = new std::string{ "necati ergin" };

	std::shared_ptr<std::string> spx{ ptr };
	std::shared_ptr<std::string> spy{ ptr }; //ub
}
