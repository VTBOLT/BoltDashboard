import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    id: item
    signal toDebugSignal
    property alias needle: needle
    property alias myRot: myRot.angle
    //property alias qmlToDebug: qmlToDebug

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
        fillMode: Image.PreserveAspectFit
        antialiasing: true
        source: "../dash_images_real/dash_background_with_meter.png"

        Image {
            id: needle
            x: 371
            y: 300
            width: 526
            height: 143
            fillMode: Image.PreserveAspectFit
            antialiasing: true
            z: 1
            source: "../dash_images_real/needle_w_green_dot.png"

            transform: Rotation{
                id: myRot
                origin.x: 263
                origin.y: 71.5
                angle: 0
            }
            function setRotation (angle) {
                text_test: text = angle
            }
            MouseArea{
                width: needle.width
                height: needle.height
                onClicked: item.toDebugSignal()
                //onClicked: console.log("Mouse Area Clicked!")
            }
        }

        /*Button {
            id: qmlToDebug
            text: "To Debug Screen"
            onClicked: item.toDebugSignal()
        }*/

        Image {
            id: battery
            x: 0
            y: -28
            width: 1280
            height: 600
            fillMode: Image.PreserveAspectFit
            antialiasing: true
            source: "../dash_images_real/battery_sized_to_fit_screen.png"

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
