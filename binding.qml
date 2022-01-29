import QtQuick 2.12
import QtQuick.Controls 2.5 as Ctrls

Rectangle {
    id: window
    visible: true

    Column {
        spacing: 2
        width: parent.width

        Ctrls.Label {
            width: parent.width
            wrapMode: Label.Wrap
            height: implicitHeight
            horizontalAlignment: Qt.AlignHCenter
            text: "This is just a Label."
        }
    }
}
