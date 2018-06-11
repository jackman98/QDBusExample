import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import Qt.labs.platform 1.0

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Rectangle Controller")
    ColumnLayout {
        anchors.centerIn: parent

        Label {
            text: "Opacity"
            horizontalAlignment: Qt.AlignHCenter
            Layout.fillWidth: true
        }

        Slider {
            id: slider
            Layout.fillWidth: true
            onValueChanged: {
                controller.opacity = slider.value
            }
            Component.onCompleted: {
                slider.value = controller.opacity
            }
        }

        Button {
            text: qsTr("Choose color")
            Layout.fillWidth: true
            onClicked: {
                colorDialog.open()
            }
        }
    }
    ColorDialog {
        id: colorDialog
        modality: Qt.ApplicationModal
        onAccepted: {
            controller.color = colorDialog.color
        }
        Component.onCompleted: {
            colorDialog.color = controller.color
        }
    }

}
