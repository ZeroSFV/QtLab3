import QtQuick 2.0
import QtQuick 6.0
import QtQuick.Window 6.0
import QtQuick.Controls 6.0 // это версия библиотеки, содержащей Contol (аналоги виджетов) для версии Qt 5.6
import QtQuick.Layouts 6.0

Window {
    id: root
    modality: Qt.ApplicationModal  // окно объявляется модальным
    title: qsTr("Редактирование информации о собаке")
    minimumWidth: 400
    maximumWidth: 400
    minimumHeight: 200
    maximumHeight: 200

    property int currentIndex: -1
    property var combomodel : getBreedList()

    GridLayout {
        anchors { left: parent.left; top: parent.top; right: parent.right; bottom: buttonCancel.top; margins: 10 }
        columns: 2

        Label {
            Layout.alignment: Qt.AlignRight  // выравнивание по правой стороне
            text: qsTr("Имя собаки:")
        }
        TextField {
            id: textName
            Layout.fillWidth: true
            placeholderText: qsTr("Введите имя собаки")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Возраст собаки:")
        }
        SpinBox {
            id: textAge
            Layout.fillWidth: true
            value: 0
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Порода собаки:")
        }
        ComboBox {
            id: textBreed
            Layout.fillWidth: true
            model: combomodel
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Владелец собаки:")
        }
        TextField {
            id: textOwner
            Layout.fillWidth: true
            placeholderText: qsTr("Введите владельца собаки")
        }
    }
    Button {
        visible: { textName.length>0 && textAge.value>0 && textOwner.length>0 && root.currentIndex <0 }
        anchors { right: buttonCancel.left; verticalCenter: buttonCancel.verticalCenter; rightMargin: 10 }
        text: qsTr("Добавить в список")
        width: 100
        onClicked: {
            root.hide()
            add(textName.text, textAge.value, textBreed.currentValue, textOwner.text)
        }
    }
    Button {
        visible: { root.currentIndex>=0 }
        anchors { right: buttonCancel.left; verticalCenter: buttonCancel.verticalCenter; rightMargin: 10 }
        text: qsTr("Применить")
        width: 100
        onClicked: {
            root.hide()
            edit(textName.text, textAge.value, textBreed.currentValue, textOwner.text, root.currentIndex)
        }
    }
    Button {
        id: buttonCancel
        anchors { right: parent.right; bottom: parent.bottom; rightMargin: 10; bottomMargin: 10 }
        text: qsTr("Отменить")
        width: 100
        onClicked: {
             root.hide()
        }
    }

    function execute(name, age, breed, owner, index){
        textName.text = name
        textAge.value = age
        textOwner.text = owner
        textBreed.currentIndex = combomodel.indexOf(breed)
        root.currentIndex = index

        root.show()
    }
 }
