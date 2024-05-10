#include <cmath>
#include <iostream>
#include <vector>
#define M_PI 3.14 // 3.14159265358979323846
using namespace std;

// 基底類別 Shape
// Parent class Shape
class Shape {
  public:
    // 虛擬函式計算面積
    // Virtual function to calculate the area
    virtual float getArea() const = 0;
};

// 矩形類別 Rectangle，繼承自 Shape
// Rectangle class inherits from Shape
class Rectangle : public Shape {
  private:
    float width;
    float height;

  public:
    Rectangle(float w, float h) : width(w), height(h) {}

    /* 請填入計算矩形面積的程式碼 */
    /* please complete the code to calculate the area of rectangle */
    float getArea() const override { return width * height; }
};

// 圓形類別 Circle，繼承自 Shape
// Circle class inherits from Shape
class Circle : public Shape {
  private:
    float radius;

  public:
    Circle(float r) : radius(r) {}

    /* 請填入計算圓形面積的程式碼 */
    /* please complete the code to calculate the area of circle */
    float getArea() const override { return M_PI * radius * radius; }
};

int main() {
    int numShapes;
    cin >> numShapes;

    vector<Shape *> shapes;

    for (int i = 0; i < numShapes; i++) {
        char shapeType;
        cin >> shapeType;

        if (shapeType == 'R') {
            float x, y, width, height;
            cin >> x >> y >> width >> height;
            shapes.push_back(new Rectangle(width, height));
        } else if (shapeType == 'C') {
            float x, y, radius;
            cin >> x >> y >> radius;
            shapes.push_back(new Circle(radius));
        }
    }

    float totalArea = 0;
    for (const auto &shape : shapes) {
        float area = shape->getArea();
        totalArea += area;

        cout << "area of the figure: " << area << endl;
    }

    cout << "total area of all shapes: " << totalArea << endl;

    // 釋放記憶體
    // Release memory
    for (const auto &shape : shapes) {
        delete shape;
    }

    return 0;
}
