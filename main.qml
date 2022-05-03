import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick 6.0
import QtQuick.Window 6.0
import QtQuick.Controls 6.0// это версия библиотеки, содержащей Contol (аналоги виджетов) для версии Qt 5.6
import QtQuick.Layouts 6.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Каталог кинолога")
    property var combomodel : getBreedList()

    // объявляется системная палитра
    SystemPalette {
          id: palette;
          colorGroup: SystemPalette.Active
       }

    Rectangle{
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: btnAdd.top
        anchors.bottomMargin: 8
        border.color: "gray"
    ScrollView {
        anchors.fill: parent
        //flickableItem.interactive: true  // сохранять свойство "быть выделенным" при потере фокуса мыши

        ListView {
            id: dogList
            anchors.fill: parent
            model: dogModel // назначение модели, данные которой отображаются списком
            delegate: DelegateForDog{}
            clip: true //
            activeFocusOnTab: true  // реагирование на перемещение между элементами ввода с помощью Tab
            focus: true  // элемент может получить фокус
        }
    }
   }

    Button {
        id: btnAdd
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.rightMargin: 8
        anchors.right: btnEdit.left
        text: "Добавить"
        width: 100
        onClicked: {
            windowAdd.show()
        }
    }

    Button {
        id: btnEdit
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right: btnDel.left
        anchors.rightMargin: 8
        text: "Редактировать"
        width: 100

        onClicked: {
            var nameDog = dogList.currentItem.dogData.nameOfDog
            var ageDog = dogList.currentItem.dogData.ageOfDog
            var breedDog = dogList.currentItem.dogData.breedOfDog
            var ownerDog = dogList.currentItem.dogData.ownerOfDog

            windowEdit.execute(nameDog, ageDog, breedDog, ownerDog, dogList.currentIndex)
        }
    }

    ComboBox {
        id: comboBoxBreed
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.left: parent.left
        anchors.rightMargin: 8
        model: combomodel
        width: 160
    }

    Label {
        id: labelCount
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.left: comboBoxBreed.right
        anchors.rightMargin: 8
        anchors.leftMargin: 8
        width: 100
        text: find(comboBoxBreed.currentValue)
    }

    Button {
        id: btnDel
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 8
        text: "Удалить"
        width: 100
        enabled: dogList.currentIndex >= 0
        onClicked: {
            del(dogList.currentIndex)
        }
    }

    DialogForAdd {
        id: windowAdd
    }
    DialogForEdit{
        id: windowEdit
    }
}
