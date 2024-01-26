#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() {
#ifdef DEBUG
  std::cout << "MateriaSource default constructor called." << std::endl;
#endif

  for (int i = 0; i < MATERIA_SLOTS; i++) {
    _materias[i] = nullptr;
  }
}

MateriaSource::~MateriaSource() {
#ifdef DEBUG
  std::cout << "MateriaSource destructor called." << std::endl;
#endif
  for (int i = 0; i < MATERIA_SLOTS; i++) {
    if (_materias[i] != nullptr)
      delete _materias[i];
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
    for (int i = 0; i < MATERIA_SLOTS; i++) {
      _materias[i] = rhs._materias[i];
    }
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
  if (m == nullptr) {
    std::cout << "MateriaSource: Cannot learn a null materia." << std::endl;
    return;
  }
  for (int i = 0; i < MATERIA_SLOTS; i++) {
    if (i == MATERIA_SLOTS - 1 && _materias[i] != nullptr) {
      std::cout << "MateriaSource: Cannot learn more materias." << std::endl;
      delete m;
      break;
    } else if (_materias[i] == nullptr) {
      _materias[i] = m;
      std::cout << "Learned Materia " << m->getType() << "." << std::endl;
      break;
    }
  }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  int i;

  for (i = 0; i < MATERIA_SLOTS; i++) {
    if (i == MATERIA_SLOTS - 1 && _materias[i] != nullptr)
      return (nullptr);
    if (_materias[i] != nullptr && _materias[i]->getType() == type)
      break;
  }
  return (_materias[i]->clone());
}

void MateriaSource::printMaterias() {
  for (int i = 0; i < MATERIA_SLOTS; i++) {
    if (_materias[i] != nullptr) {
      std::cout << "Materia " << i << ": " << _materias[i]->getType()
                << std::endl;
    }
  }
}
