#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr) {
  if (ptr == nullptr) {
    return 0;
  }
  return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
  if (raw == 0) {
    return nullptr;
  }
  return reinterpret_cast<Data *>(raw);
}
