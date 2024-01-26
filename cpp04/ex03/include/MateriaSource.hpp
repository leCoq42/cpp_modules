#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#define MATERIA_SLOTS 4

class MateriaSource : public IMateriaSource {
private:
  AMateria *_materias[MATERIA_SLOTS];

public:
  MateriaSource();
  ~MateriaSource();

  MateriaSource(MateriaSource const &src);
  MateriaSource &operator=(const MateriaSource &rhs);

  void learnMateria(AMateria *);
  AMateria *createMateria(std::string const &type);

  void printMaterias();
};

#endif
