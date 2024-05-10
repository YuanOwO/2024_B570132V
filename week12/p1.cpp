#include <cmath>
#include <initializer_list>
#include <iomanip>
#include <iostream>
using namespace std;

class Complex {
  private:
    double m_real;
    double m_imag;

  public:
    double getReal() const { return m_real; }
    double getImag() const { return m_imag; }

    Complex(void) {}
    Complex(double real, double imag) {
        m_real = real;
        m_imag = imag;
    }
    virtual ~Complex(void) {}
    void setValue(double real, double imag) {
        m_real = real;
        m_imag = imag;
    }

    Complex &operator=(const Complex &rhs) {
        m_real = rhs.m_real;
        m_imag = rhs.m_imag;
        return *this;
    }
    Complex &operator=(const initializer_list<double> &rhs) {
        m_real = *rhs.begin();
        m_imag = *(rhs.begin() + 1);
        return *this;
    }

    Complex operator+(const Complex &rhs) const {
        Complex temp = {m_real + rhs.m_real, m_imag + rhs.m_imag};
        return temp;
    }
    Complex operator-(const Complex &rhs) const {
        Complex temp = {m_real - rhs.m_real, m_imag - rhs.m_imag};
        return temp;
    }
    Complex operator*(const Complex &rhs) const {
        Complex temp = {m_real * rhs.m_real - m_imag * rhs.m_imag,
                        m_real * rhs.m_imag + m_imag * rhs.m_real};
        return temp;
    }
    Complex operator/(const Complex &rhs) const {
        double bottom = rhs.m_real * rhs.m_real + rhs.m_imag * rhs.m_imag;
        Complex temp = {(m_real * rhs.m_real + m_imag * rhs.m_imag) / bottom,
                        (m_imag * rhs.m_real - m_real * rhs.m_imag) / bottom};
        return temp;
    }
};

ostream &operator<<(ostream &os, const Complex &rhs) {
    os << "(" << setprecision(5) << rhs.getReal() << showpos << setprecision(5)
       << rhs.getImag() << noshowpos << "i)";
    return os;
}

double abs(const Complex &num) {
    return sqrt(num.getReal() * num.getReal() + num.getImag() * num.getImag());
}

bool operator==(const Complex &lhs, const Complex &rhs) {
    Complex temp = lhs - rhs;
    return abs(temp) <= 1e-7;
}

int main() {
    double input_1, input_2, input_3, input_4, input_5, input_6;
    Complex a, b;
    cin >> input_1 >> input_2 >> input_3 >> input_4;
    cin >> input_5 >> input_6;

    a = {input_1, input_2};
    b = {input_3, input_4};

    cout << "add: " << endl;
    cout << a << "+" << b << "=" << a + b << endl;

    cout << "subtract: " << endl;
    cout << a << "-" << b << "=" << a - b << endl;

    cout << "multiply: " << endl;
    cout << a << "*" << b << "=" << a * b << endl;

    cout << "divide: " << endl;
    cout << a << "/" << b << "=" << a / b << endl;

    //////////////////////////////////////////////

    a = {3.055, 3.055};
    input_5 = input_5 / 2.0 + 1.51;
    input_6 = input_6 / 2.0 + 1.51;
    b = {input_5, input_6};

    cout << "equal: " << endl;
    cout << a << (a == b ? "==" : "!=") << b << endl;

    cout << "magnitude: " << endl;
    cout << b << "=" << setprecision(5) << abs(b) << endl;
    return 0;
}
