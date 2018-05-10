class Point {
public:
    int x;
    int y;
    Point() { x = 0; y = 0; }
    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
    ~Point() {}
};

int len2(Point& p) {
    return (p.x) * (p.x) + (p.y) * (p.y);
}

int main(int argc, char const *argv[]) {
    Point ps[100];
    for (int i = 0; i < 100; ++i)
    {
        ps[i] = Point(10, 10);
        len2(ps[i]);
    }
    return 0;
}
