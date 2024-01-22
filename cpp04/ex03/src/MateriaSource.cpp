#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() {
#ifdef DEBUG
  std::cout << "MateriaSource default constructor called." << std::endl;
#endif

  for (int i = 0; i < 4; i++) {
    _materias[i] = nullptr;
  }
}

MateriaSource::MateriaSource(const MateriaSource &src) {
#ifdef DEBUG
  std::cout << "MateriaSource copy constructor called." << std::endl;
#endif

  *this = src;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
#ifdef DEBUG
  std::cout << "MateriaSource assignment operator called." << std::endl;
#endif

  if (this != &rhs) {
    for (int i = 0; i < 4; i++) {
      _materias[i] = rhs._materias[i];
    }
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
  if (m == nullptr) {
    return;
  }
  for (int i = 0; i < 4; i++) {
    if (_materias[i] == nullptr) {
      _materias[i] = m;
      break;
    }
  }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  int i;

  for (i = 0; i < 4; i++) {
    if (_materias[i] != nullptr && _materias[i]->getType() == type)
      break;
  }
  if (i == 4)
    return (nullptr);
  return (_materias[i]->clone());
}
