class Point {
public:
    int x;
    int y;
    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
    ~Point() {}
};

int len2(Point* p) {
    return (p->x) * (p->x) + (p->y) * (p->y);
}

int main(int argc, char const *argv[]) {
    Point* ptrs[100];
    for (int i = 0; i < 100; ++i)
    {
        ptrs[i] = new Point(10, 10);
        len2(ptrs[i]);
    }
    for (int i = 0; i < 100; ++i)
    {
        delete ptrs[i];
    }
    return 0;
}
