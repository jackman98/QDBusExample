import QtQuick 2.10
import QtQuick.Controls 2.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Rectangle")

    Rectangle {
        anchors.fill: parent
        color: controller.color
        opacity: controller.opacity
    }
}
