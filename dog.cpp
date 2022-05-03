#include "dog.h"

dog::dog()
{

}

QString dog::getDogName() const
{
    return dogName;
}
int dog::getDogAge() const
{
    return dogAge;
}
QString dog::getDogBreed() const
{
    return dogBreed;
}
QString dog::getDogOwner() const
{
    return dogOwner;
}
void dog::setDogName(const QString &Name)
{
    dogName = Name;
}
void dog::setDogAge(const int age)
{
    dogAge = age;
}
void dog::setDogBreed(const QString &Breed)
{
    dogBreed = Breed;
}
void dog::setDogOwner(const QString &Owner)
{
    dogOwner = Owner;
}
