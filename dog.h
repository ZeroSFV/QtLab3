#ifndef DOG_H
#define DOG_H

#include <QString>
class dog
{
private:
    QString dogName;
    int dogAge;
    QString dogBreed;
    QString dogOwner;

public:
    dog();
    QString getDogName() const;
    int getDogAge() const;
    QString getDogBreed() const;
    QString getDogOwner() const;
    void setDogName(const QString &Name);
    void setDogAge(const int age);
    void setDogBreed(const QString &Breed);
    void setDogOwner(const QString &Owner);
};

#endif // DOG_H
