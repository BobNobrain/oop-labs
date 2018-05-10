#include <iostream>

namespace basic {
    int plus(int a, int b) {
        return a + b;
    }
}

namespace bitwise {
    int plus(int a, int b) {
        return a ^ b;
    }
}

int main(int argc, char const *argv[])
{
    int four = basic::plus(2, 2);
    int zero = bitwise::plus(2, 2);
    std::cout << "2 + 2 = " << four << std::endl;
    std::cout << "2 ^ 2 = " << zero << std::endl;
    return 0;
}
