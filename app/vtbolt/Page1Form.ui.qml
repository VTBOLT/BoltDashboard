import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {

    RowLayout {
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
        source: "images/dashboard_background_with_gauge.png"

        Image {
            id: needle
            x: 307
            y: 299
            width: 439
            height: 140
            z: 1
            source: "images/dot_and_needle.png"

        }

        Image {
            id: battery
            x: 0
            y: -28
            width: 1280
            height: 600
            source: "images/battery_outline.png"

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
