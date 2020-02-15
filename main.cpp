#include "Subforwardlist.h"
#include "Subvector.h"
#include <iostream>
int main() {
    Subforwardlist a;
    a.push_back(1);
    a.push_back(2);
    a.show();
    std::cout << std::endl;
    Subvector s;
    s.push_back(0);
    s.show();
    return 0;
}
