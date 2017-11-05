#ifndef COMPLEX_H
#define COMPLEX_H

#define __USE_MINGW_ANSI_STDIO 0

#include <cmath>
#include <limits>
#include <string>
//#include <utility>

class Complex {
public:

  const double PI = 3.1415926535897;

  Complex() {};
  Complex(const double & r, const double & i) : _real(r), _imag(i) {};
  Complex(const Complex & c) : _real(c._real), _imag(c._imag) {};
  Complex(Complex && c) : _real(c._real), _imag(c._imag) {};
  ~Complex() {};

  void fromPhasor(const double & mag, const double & angleR) {
    _real = mag * cos(angleR);
    _imag = mag * sin(angleR);
  };

  Complex & operator= (const Complex & c) {
    _real = c._real; _imag = c._imag;
    return *this;
  };

  Complex & operator= (Complex && c) {
    _real = c._real; _imag = c._imag;
    return *this;
  };

  bool operator== (const Complex & c) {
    return (c._real == _real && c._imag == _imag);
  };

  bool operator!= (const Complex & c) {
    return ! (*this == c);
  };

  bool operator >= (const Complex & c) {
    return mag() >= c.mag();
  };

  bool operator < (const Complex & c) {
    return !(*this >= c);
  };

  bool operator <= (const Complex & c) {
    return mag() <= c.mag();
  };

  bool operator > (const Complex & c) {
    return !(*this <= c);
  };

  Complex && operator+ (const Complex & c) {
    Complex newC(_real + c._real, _imag + c._imag);
    return std::move(newC);
  }

  Complex && operator- (const Complex & c) {
    Complex newC(_real - c._real, _imag - c._imag);
    return std::move(newC);
  }

  Complex && operator* (const Complex & c) {
    double r = (_real * c._real) - (_imag * c._imag);
    double i = (_real * c._imag) + (_imag * c._real);
    return std::move(Complex(r, i));
  }

  Complex && operator/ (const Complex & c) {
    if (c.mag() != 0) {
      double newMag = mag() / mag();
      double newAngle = angleRad() - c.angleRad();
      Complex newC;
      newC.fromPhasor(newMag, newAngle);
      return std::move(newC);
    } else {
      return std::move(Complex(std::numeric_limits<double>::infinity(),
                               std::numeric_limits<double>::infinity()));
    }
  }

  const double & real() const { return _real; };
  const double & imag() const { return _imag; };
  double mag() const { return sqrt(_real*_real + _imag*_imag);};
  double angleRad() const { return _imag != 0 ? atan(_imag / _real) : 0;};
  double angleDeg() const { return angleRad() / static_cast<double> (2L * PI);};

  std::string toString () {
    std::string s;
    s.append("(Complex: ");
    s.append(std::to_string(_real));
    if (_imag < 0) {
      s.append( " - i");
      s.append(std::to_string(-_imag));
    } else {
      s.append(" + i");
      s.append(std::to_string(_imag));
    }
    s.append(")");
    return s;
  };

  std::string toStringPhasorRad() {
    std::string s;
    s.append("(Mag: ");
    s.append(std::to_string(mag()));
    s.append( ", Ang (R): ");
    s.append(std::to_string(angleRad()));
    s.append(")");
    return s;
  };

  std::string toStringPhasorDeg() {
    std::string s;
    s.append("(Mag: ");
    s.append(std::to_string(mag()));
    s.append( ", Ang (D): ");
    s.append(std::to_string(angleDeg()));
    s.append(")");
    return s;
  }

private:
  double _real = 0;
  double _imag = 0;

};


#endif // COMPLEX_H
