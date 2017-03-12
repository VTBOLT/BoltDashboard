import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    id: item
    signal toDebugSignal
    property alias needle: needle
    property alias text_test: text_test.text
    property alias qmlToDebug: qmlToDebug

    RowLayout {
        antialiasing: true
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        anchors.top: parent.top
    }

    Image {
        id: dial
        x: 0
        y: 0
        width: 1280
        height: 600
        antialiasing: true
        source: "../images/dashboard_background_with_gauge.png"

        Text {
            id: text_test
            x: 55
            y: 52
            width: 239
            height: 89
            color: "#FF0000"
            text: qsTr("Text")
            font.pixelSize: 45
        }
        Button {
            id: qmlToDebug
            text: "To Debug Screen"
            onClicked: item.toDebugSignal()
        }

        Image {
            id: needle
            x: 255
            y: 259
            width: 492
            height: 200
            fillMode: Image.PreserveAspectFit
            antialiasing: true
            z: 1
            source: "../images/dot_and_needle.png"
            //transform: Rotation{
            //    id: myRot
            //    origin.x: 350
            //    origin.y: 75
            //}
            //            SequentialAnimation{
            //                running: true
            //                loops: Animation.Infinite
            //                PropertyAction { target: myRot; property: "origin.x"; value: 380 }
            //                PropertyAction { target: myRot; property: "origin.y"; value:100 }
            //                NumberAnimation { target: myRot; property: "angle"; to: 180; duration: 2000}
            //                PropertyAction { target: myRot; property: "origin.x"; value: 380 }
            //                PropertyAction { target: myRot; property: "origin.y"; value: 100 }
            //                NumberAnimation { target: myRot; property: "angle"; to: 0; duration: 2000}
            //            }
        }

        Image {
            id: battery
            x: 0
            y: -28
            width: 1280
            height: 600
            antialiasing: true
            source: "../images/battery_outline.png"

            ProgressBar {
                id: progressBar
                x: 351
                y: 479
                width: 539
                height: 93
                indeterminate: false
                spacing: 0
                topPadding: 0
                antialiasing: true
                scale: 1
                to: 100
                value: 75
            }
        }
    }
}
