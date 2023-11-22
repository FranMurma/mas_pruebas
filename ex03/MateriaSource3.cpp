
#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
    for (int i = 0; i < 4; i++)
        this->_learnedMaterias[i] = NULL;
    std::cout << "Default MateriaSource constructor called" << std::endl;
}

MateriaSource::~MateriaSource( void )
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_learnedMaterias[i])
            delete this->_learnedMaterias[i];
    }
    std::cout << "Default MateriaSource destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < 4; i++)
        this->_learnedMaterias[i] = other._learnedMaterias[i];
    std::cout << "Copy constructor MateriaSource called" << std::endl;
}

MateriaSource &MateriaSource::operator = (MateriaSource const &other)
{
    for (int i = 0; i < 4; i++)
        this->_learnedMaterias[i] = other._learnedMaterias[i];
    return (*this);
}
/*
AMateria *MateriaSource::getMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i] && this->_materias[i]->getType() == type)
            return (this->_materias[i]);
    }
    return (NULL);
}*/

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_learnedMaterias[i] == NULL)
        {
            this->_learnedMaterias[i] = m;
            return ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_learnedMaterias[i] && this->_learnedMaterias[i]->getType() == type)
            return (this->_learnedMaterias[i]->clone());
    }
    return (NULL);
}
