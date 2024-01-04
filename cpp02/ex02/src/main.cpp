#include "Fixed.hpp"

int main(void) {
  /* Fixed a; */
  /* Fixed const b(10); */
  /* Fixed const c(42.42f); */
  /* Fixed const d(b); */
  /* a = Fixed(1234.4321f); */
  /* std::cout << "a is " << a << std::endl; */
  /* std::cout << "b is " << b << std::endl; */
  /* std::cout << "c is " << c << std::endl; */
  /* std::cout << "d is " << d << std::endl; */
  /* std::cout << "a is " << a.toInt() << " as integer" << std::endl; */
  /* std::cout << "b is " << b.toInt() << " as integer" << std::endl; */
  /* std::cout << "c is " << c.toInt() << " as integer" << std::endl; */
  /* std::cout << "d is " << d.toInt() << " as integer" << std::endl; */

  std::cout << std::endl << "New Part: " << std::endl;
  std::cout << "--------------------------------" << std::endl;

  /* Fixed e; */
  /* Fixed const f(Fixed(5.05f) * Fixed(2)); */
  /* std::cout << e << std::endl; */
  /* std::cout << ++e << std::endl; */
  /* std::cout << e << std::endl; */
  /* std::cout << e++ << std::endl; */
  /* std::cout << e << std::endl; */
  /* std::cout << f << std::endl; */
  /* std::cout << Fixed::max(e, f) << std::endl; */

  Fixed c(5);
  Fixed d(2.5f);
  std::cout << "c = " << c << std::endl;
  std::cout << "d = " << d << std::endl;
  Fixed e = c;
  std::cout << "e = c gives e = " << e << std::endl;
  std::cout << c << " > " << d << " gives " << (c > d) << "(true)" << std::endl;
  std::cout << c << " < " << d << " gives " << (c < d) << "(false)"
            << std::endl;
  std::cout << c << " >= " << e << " gives " << (c >= e) << "(true)"
            << std::endl;
  std::cout << c << " <= " << d << " gives " << (c <= d) << "(false)"
            << std::endl;
  std::cout << c << " == " << e << " gives " << (c == e) << "(true)"
            << std::endl;
  std::cout << c << " != " << e << " gives " << (c != e) << "(false)"
            << std::endl;
  std::cout << c << " + " << d << " = " << (c + d) << std::endl;
  std::cout << c << " - " << d << " = " << (c - d) << std::endl;
  std::cout << c << " * " << e << " = " << (c * e) << std::endl;
  std::cout << c << " / " << d << " = " << (c / d) << std::endl;
  std::cout << "c: " << c << ". c++: " << c++ << ". c: " << c
            << ". ++c: " << ++c << "." << std::endl;
  std::cout << "e: " << e << ". e--: " << e-- << ". e: " << e
            << ". --e: " << --e << "." << std::endl;
  std::cout << "min (" << c << ", " << d << ") == " << Fixed::min(c, d)
            << std::endl;
  std::cout << "max (" << c << ", " << d << ") == " << Fixed::max(c, d)
            << std::endl;
  return 0;
}
