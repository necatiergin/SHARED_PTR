#include <memory>
#include <string>

int main()
{
	using namespace std;

	auto ptr = new string{ "necati ergin" };

	shared_ptr<string> spx{ ptr };
	shared_ptr<string> spy{ ptr }; //ub
}
