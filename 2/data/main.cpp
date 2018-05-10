#include <iostream>
using namespace std;

class Collection
{
protected:
    int* data;
    int len;
public:
    Collection(int n) {
        len = n;
        data = new int[n];
        for (int i = 0; i < len; ++i)
        {
            data[i] = 0;
        }
    }
    int get(int i) {
        if (i >= 0 && i < len) {
            return data[i];
        }
        return 0;
    }
    virtual void put(int elem) = 0;
    virtual int take() = 0;
    virtual void print() = 0;
    virtual ~Collection() {
        delete[] data;
    }
};

class Stack: public Collection
{
private:
    int end;
public:
    Stack(int n): Collection(n) {
        end = 0;
    }

    void put(int elem) {
        if (end < len) {
            data[end] = elem;
            ++end;
        }
        // else stack overflow
    }
    int take() {
        if (end > 0) {
            --end;
            return data[end];
        }
        // else stack empty
        return 0;
    }
    void print() override {
        cout << "Stack: ";
        for (int i = 0; i < end; ++i)
        {
            cout << data[i];
            if (i != end - 1) cout << ", ";
        }
        cout << endl;
    }

    ~Stack() {}
};

class Queue: public Collection
{
private:
    int start;
    int end;
    bool empty;
public:
    Queue(int n): Collection(n) {
        start = 0;
        end = 0;
        empty = true;
    }

    void put(int elem) {
        if (empty || end != start) {
            data[end] = elem;
            end = (end + 1) % len;
            empty = false;
        }
        // else queue is full
    }
    int take() {
        if (!empty) {
            int result = data[start];
            start = (start + 1) % len;
            empty = start == end;
            return result;
        }
        // else queue is empty
        return 0;
    }
    void print() override {
        cout << "Queue: ";
        for (int i = start; i != end; i = (i + 1) % len)
        {
            cout << data[i % len];
            if (i != (end == 0? len : end) - 1) cout << ", ";
        }
        cout << endl;
    }

    ~Queue() {}
};

#define N 4
int main(int argc, char const *argv[])
{
    Collection* cols[N] {
        new Stack(5),
        new Queue(5),
        new Stack(3),
        new Queue(3)
    };

    for (int i = 0; i < N; ++i)
    {
        Collection* c = cols[i];
        c->put(2);
        c->put(100);
        c->put(256);
        c->take();
        c->take();
        c->put(1024);

        cout << "Collection #" << i << ":" << endl;
        c->print();
        delete c;
        cols[i] = 0;
    }

    return 0;
}
