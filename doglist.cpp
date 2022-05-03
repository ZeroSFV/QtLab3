#include "doglist.h"
#include <QDebug>

dogList::dogList(QObject* parent):QAbstractListModel(parent)
{
    breedList = { "Английский бульдог", "Немецкая овчарка", "Пудель", "Мопс", "Лабрадор-ретривер" };
}

dogList::~dogList()
{

}

int dogList::rowCount(const QModelIndex&) const
{
    return listOfDogs.size();
}

QVariant dogList::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= listOfDogs.size())
            return QVariant();
      {
        switch (role) {
                case name:
                    return QVariant(listOfDogs.at(index.row()).getDogName());
                case age:
                    return QVariant(listOfDogs.at(index.row()).getDogAge());
                case breed:
                    return QVariant(listOfDogs.at(index.row()).getDogBreed());
                case owner:
                    return QVariant(listOfDogs.at(index.row()).getDogOwner());

                default:
                    return QVariant();
            }
    }
}

QHash<int, QByteArray> dogList::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[name] = "nameOfDog";
    roles[age] = "ageOfDog";
    roles[breed] = "breedOfDog";
    roles[owner] = "ownerOfDog";
        return roles;
}

void dogList::add(const QString& nameDog, const int ageDog, const QString& breedDog, const QString& ownerDog){
    dog Dog;
    Dog.setDogName(nameDog);
    Dog.setDogAge(ageDog);
    Dog.setDogBreed(breedDog);
    Dog.setDogOwner(ownerDog);

    beginInsertRows(QModelIndex(),listOfDogs.size(),listOfDogs.size());
    listOfDogs.append(Dog);  //добавление в конец списка
    endInsertRows();
}

QAbstractListModel* dogList::getModel() {
    return this;
}

Q_INVOKABLE QStringList dogList::getBreedList() {
    return breedList;
}

Q_INVOKABLE int dogList::find(QString breed) {
    if (listOfDogs.size() > 0) {
        int count = 0;
        for (int index = 0; index < listOfDogs.size(); index++) {

            if (listOfDogs[index].getDogBreed() == breed) {
                count++;
            }
        }
        return count;
    }
    else return 0;
}

void dogList::del(const int index){

     if (index >= 0 && index < listOfDogs.size())
     {
    // сообщение модели о процессе удаления данных
         beginRemoveRows(QModelIndex(), index, index);
         listOfDogs.removeAt(index);
             endRemoveRows();
     }
     else qDebug() << "Error index";
}

void dogList::edit(const QString& nameDog, const int ageDog, const QString& breedDog, const QString& ownerDog, const int index) {
     if(index >= 0 && index < listOfDogs.size() )
     {
         auto& currentDog = listOfDogs[index];
         if (currentDog.getDogName().compare(nameDog)!=0 || currentDog.getDogAge() != ageDog || currentDog.getDogBreed().compare(breedDog)!=0 || currentDog.getDogOwner().compare(ownerDog)!=0)
         {
             currentDog.setDogName(nameDog);
             currentDog.setDogAge(ageDog);
             currentDog.setDogBreed(breedDog);
             currentDog.setDogOwner(ownerDog);

             auto modelIndex = createIndex(index, 0);
             emit dataChanged(modelIndex, modelIndex);
             qDebug() << listOfDogs[index].getDogAge();
         }
     }
     else qDebug() << "Error index";
}
