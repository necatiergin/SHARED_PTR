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
        std::shared_ptr<Nec> sptr = std::make_shared<Nec>(42);

        std::cout << "Nec::mx = " << sptr->get_x() << ", use_count() = "
            << sptr.use_count() << '\n';

        std::cout << "call sptr.reset()...\n";
        sptr.reset(new Nec{ 77});
        std::cout << "After reset(): use_count() = " << sptr.use_count()
            << ", sptr = " << sptr << "\nleaving the scope...\n";
    }   // Calls Nec's destructor.
    std::cout << "main is still running\n";
}
