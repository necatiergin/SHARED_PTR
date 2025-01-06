#include <iostream>
#include <memory>

class Nec
{
public:
    Nec(int val = 0) noexcept : mx(val)
    {
        std::cout << "Nec::Nec(), mx = " << mx << " @ " << this << '\n';
    }

    ~Nec()
    {
        std::cout << "Nec::~Nec(), mx = " << mx << " @ " << this << '\n';
    }

    int get_x() const noexcept { return mx; }
private:
    int mx;
};

int main()
{
    std::cout << "unique ownership\n";
    {
        std::shared_ptr<Nec> sp = std::make_shared<Nec>(42);

        std::cout << "Nec::mx = " << sp->get_x() << ", use_count() = "
            << sp.use_count() << '\n';

        std::cout << "call sp.reset()...\n";
        sp.reset(); // Nec's destructor is called
        std::cout << "After reset(): use_count() = " << sp.use_count()
            << ", sp = " << sp << '\n';

        std::cout << std::boolalpha << "sp == nullptr: " << (sp == nullptr) << '\n';
    }

    std::cout << "main is still running\n";
}
