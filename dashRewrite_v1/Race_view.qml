import QtQuick 2.4

// we could add functions here, but i think it's easier from
// within the c++ code to reference the ui.qml elements directly
// ... so we might not need this file

Race_viewForm {
    function qmlSlot(recvdRPM) {
        //console.log(recvdRPM)
        //text_test.text: qsTr(recvdRPM)
    }
}
