#ifndef DOGLIST_H
#define DOGLIST_H

#include <QAbstractListModel>
#include <QVariant>
#include <QList>
#include <QModelIndex>
#include <QItemSelectionModel>
#include "dog.h"

class dogList : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(QAbstractListModel* dogModel READ getModel CONSTANT)  /* первый параметр - тип свойства (property)
                                                                     второй параметр - имя свойства, по которому будем обращаться к реальной модели в qml-файле
                                                                     третий параметр - метод С++ для получения значения свойства (получим саму модель)
                                                                     CONSTANT - qml получит свойство однократно, и в процессе работы это свойство изменяться не будет */
private:
    QList<dog> listOfDogs; // непосредственно данные
    QAbstractListModel *getModel();

public:
    dogList(QObject *parent = nullptr);
    ~dogList() override;

    // количество колонок
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QStringList breedList;

     // возвращение данных модели по указанному индексу и роли
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

    enum ResentRoles {
            name = Qt::DisplayRole,
            age = Qt::UserRole + 1,
            breed = Qt::UserRole + 2,
            owner = Qt::UserRole + 3
    };

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void add(const QString& nameDog, const int ageDog, const QString& breedDog, const QString& ownerDog);  // макрос указывает, что к методу можно обратиться из QML
    Q_INVOKABLE void del(const int index);
    Q_INVOKABLE void edit(const QString& nameDog, const int ageDog, const QString& breedDog, const QString& ownerDog, const int index);
    Q_INVOKABLE QStringList getBreedList();
    Q_INVOKABLE int find(QString breed);


};
#endif // DOGLIST_H
