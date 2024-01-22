#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
  AMateria *_materias[4];

public:
  MateriaSource();
  ~MateriaSource(){};

  MateriaSource(MateriaSource const &src);
  MateriaSource &operator=(const MateriaSource &rhs);

  void learnMateria(AMateria *);
  AMateria *createMateria(std::string const &type);
};

#endif
