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
    std::cout << "multiple ownership\n";
    {
        std::shared_ptr<Nec> sp1 = std::make_shared<Nec>(42);
        auto sp2 = sp1;
        auto sp3 = sp2;

        std::cout << "Nec::mx = " << sp1->get_x() << ", use_count() = "
            << sp1.use_count() << '\n';

        std::cout << "call sp1.reset()...\n";
        sp1.reset(new Nec{ 77});

        std::cout << "After reset():\n"
            << "sp1.use_count() = " << sp1.use_count()
            << ", sp1 @ " << sp1 << '\n'
            << "sp2.use_count() = " << sp2.use_count()
            << ", sp2 @ " << sp2 << '\n'
            << "sp3.use_count() = " << sp3.use_count()
            << ", sp3 @ " << sp3 << '\n'
            << "Leaving the scope...\n";
    }   
    std::cout << "main is still running\n";
}
