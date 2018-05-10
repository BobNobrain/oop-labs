#include <iostream>
using namespace std;

void mutatorRef(int& i) {
    i++;
}

void mutatorPtr(int* i) {
    (*i)++;
}

void mutatorNot(int i) {
    i++;
}

int main(int argc, char const *argv[])
{
    int i = 0;
    cout << "At start: " << i << endl;
    mutatorRef(i);
    cout << "After ref: " << i << endl;
    mutatorPtr(&i);
    cout << "After ptr: " << i << endl;
    mutatorNot(i);
    cout << "After not: " << i << endl;
    return 0;
}
