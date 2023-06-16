#include <pybind11/pybind11.h>

class Rectangle {
public:
    Rectangle(int x, int y, int width, int height)
        : x_(x), y_(y), width_(width), height_(height) {}

    int area() { return width_ * height_; }
    int left() { return x_; }
    int top() { return y_; }
    int right() { return x_ + width_; }
    int bottom() { return y_ + height_; }
    int width() { return width_; }
    int height() { return height_; }
    void move(int dx, int dy) { x_ += dx; y_ += dy; }
    bool colliderect(Rectangle& other) {
        return x_ < other.right() && right() > other.left() &&
            y_ < other.bottom() && bottom() > other.top();
    }

private:
    int x_;
    int y_;
    int width_;
    int height_;
};

namespace py = pybind11;

PYBIND11_MODULE(rectangle, m) {
    py::class_<Rectangle>(m, "Rectangle")
        .def(py::init<int, int, int, int>())
        .def_property_readonly("x", &Rectangle::left)
        .def_property_readonly("y", &Rectangle::top)
        .def_property_readonly("left", &Rectangle::left)
        .def_property_readonly("top", &Rectangle::top)
        .def_property_readonly("right", &Rectangle::right)
        .def_property_readonly("bottom", &Rectangle::bottom)
        .def_property_readonly("width", &Rectangle::width)
        .def_property_readonly("height", &Rectangle::height)
        .def("area", &Rectangle::area)
        .def("move", &Rectangle::move)
        .def("colliderect", &Rectangle::colliderect);
}
