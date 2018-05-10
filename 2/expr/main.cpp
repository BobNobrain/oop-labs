#include <iostream>
using namespace std;

class Expr
{
public:
    Expr() {}
    virtual int eval() = 0;
    virtual ~Expr() {}
};

class Num: public Expr
{
public:
    int n;
    Num(int n) {
        this->n = n;
    }

    int eval() override {
        return this->n;
    }

    ~Num() {}
};

class Add: public Expr
{
public:
    Expr* e1;
    Expr* e2;
    Add(Expr* left, Expr* right) {
        e1 = left;
        e2 = right;
    }

    int eval() override {
        return this->e1->eval() + this->e2->eval();
    }

    ~Add() {}
};

class Substract: public Expr
{
public:
    Expr* e1;
    Expr* e2;
    Substract(Expr* left, Expr* right) {
        e1 = left;
        e2 = right;
    }

    int eval() override {
        return this->e1->eval() - this->e2->eval();
    }

    ~Substract() {}
};

int main(int argc, char const *argv[])
{
    Expr* two = new Num(2);
    Expr* five = new Num(5);
    Expr* sub = new Add(two, two);
    Expr* root = new Substract(five, sub);
    cout << "5 - (2 + 2) = " << root->eval() << endl;
    delete two;
    delete five;
    delete sub;
    delete root;
    return 0;
}
