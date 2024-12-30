#include <iostream>
#include <memory>

struct Deleter {
    void operator()(int* p)
    {
        std::cout << "Deleter operator()(int *) called for the address : " << p << '\n';
        delete[] p;
    }
};

int main()
{
    std::shared_ptr<int> sp(new int[10], Deleter());

    int* pd = new int[50];
    std::cout << "pd = " << pd << "\n";

    (*std::get_deleter<Deleter>(sp))(pd);
    //std::get_deleter<Deleter>(sp)->operator()(pd);
}
