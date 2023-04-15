#include <vector>
#include <Windows.h>

using namespace std;
class Shape {
public:
    virtual void draw(HDC hdc) = 0;
};

class Circle : public Shape {
private:
    int x, y, r;
public:
    Circle(int x, int y, int r) : x(x), y(y), r(r) {}
    void draw(HDC hdc) override {
        Ellipse(hdc, x - r, y - r, x + r, y + r);
    }
};

class Rectangle : public Shape {
private:
    int x1, y1, x2, y2;
public:
    Rectangle(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
    void draw(HDC hdc) override {
        ::Rectangle(hdc, x1, y1, x2, y2);
    }
};

vector<Shape*> shapes;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    HDC hdc;
    PAINTSTRUCT ps;
    switch (message) {
    case WM_CREATE: {
        shapes.push_back(new Circle(100, 100, 50));
        shapes.push_back(new Rectangle(200, 200, 300, 400));
        break;
    }
    case WM_PAINT: {
        hdc = BeginPaint(hWnd, &ps);
        for (auto shape : shapes) {
            shape->draw(hdc);
        }
        EndPaint(hWnd, &ps);
        break;
    }
    case WM_DESTROY: {
        for (auto shape : shapes) {
            delete shape;
        }
        PostQuitMessage(0);
        break;
    }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}