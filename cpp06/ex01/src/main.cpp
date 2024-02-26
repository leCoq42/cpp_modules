#include "Serializer.hpp"

int main(void) {
  Data data = {"Hello", "World"};
  Data *data_ptr = &data;
  /* Serializer serializer; */
  /* (void)serializer; */

  std::cout << "Input data: \n Title: " << data.title
            << "\n Content: " << data.content << std::endl;
  std::cout << std::endl;

  uintptr_t serialized = Serializer::serialize(&data);
  std::cout << "Serialized data: " << serialized << std::endl;
  std::cout << std::endl;

  Data *deserialized = Serializer::deserialize(serialized);
  std::cout << "Deserialized data: \n Title: " << deserialized->title
            << "\n Content: " << deserialized->content << std::endl;
  std::cout << std::endl;

  if (deserialized == data_ptr) {
    std::cout << "Deserialized data is the same as the original data"
              << std::endl;
  } else
    std::cout << "Deserialized data is not the same as the original data"
              << std::endl;

  return 0;
}
