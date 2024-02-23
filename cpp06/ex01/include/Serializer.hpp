#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <cstdint>
#include <iostream>

struct Data {
  std::string title;
  std::string content;
};

class Serializer {
public:
  Serializer();
  virtual ~Serializer() = 0;
  Serializer(const Serializer &src);
  Serializer &operator=(const Serializer &rhs);

  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif
