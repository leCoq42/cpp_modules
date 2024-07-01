#include "Serializer.hpp"


Serializer::~Serializer() {
  std::cout << "Serializer destructor called." << std::endl;
}

Serializer::Serializer(const Serializer &src) {
  std::cout << "Serializer copy constructor called." << std::endl;
  *this = src;
}

Serializer &Serializer::operator=(const Serializer &rhs) {
  std::cout << "Serializer assignment operator overload called." << std::endl;
  if (this != &rhs)
    *this = rhs;
  return *this;
}

uintptr_t Serializer::serialize(Data *ptr) {
  if (ptr == nullptr) {
    throw std::invalid_argument("Cannot serialize a nullptr.");
  }
  return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
  if (raw == 0) {
    throw std::invalid_argument("Cannot deserialize 0.");
  }
  return reinterpret_cast<Data *>(raw);
}
