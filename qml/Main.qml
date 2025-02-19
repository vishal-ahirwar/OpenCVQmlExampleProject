import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Effects

ApplicationWindow {
    visible: true
    width: 640 * 1.5
    height: 480 * 1.5
    flags: Qt.FramelessWindowHint
    
    Image {
        id: cameraImage
        anchors.centerIn: parent
        width: parent.width
        height: parent.height
        cache: false
        asynchronous: false
    }
    Connections {
        target: stream
        function onImageUpdated(img) {
            cameraImage.source = "image://cvprovider/image?" + Math.random();
        }
    }
    MultiEffect {
        source: btnClose.background
        anchors.fill: btnClose
        blurEnabled: true
        blurMax: 64
        blur: 1.0
        opacity:0.6
        autoPaddingEnabled:false
    }
    Button {
        id: btnClose
        text: "Close"
        width: parent.width * 0.15
        height: parent.height * 0.06
        background:Rectangle
        {
            id:btnBg
            anchors.fill:parent
            color:"white"
            radius:8
            opacity:0.3
        }
        anchors {
            horizontalCenter: parent.horizontalCenter
            bottom: parent.bottom
            margins: 15
        }
        onClicked: {
            Qt.quit();
        }
    }
}
