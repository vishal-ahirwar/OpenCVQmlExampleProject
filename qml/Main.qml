import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480

    Image {
        id: cameraImage
        source: "image://cvprovider/image"
        anchors.centerIn: parent
        width: parent.width
        height: parent.height
        cache:false
        asynchronous: false
    }
    Connections
    {
        target:stream
        function onReload()
        {
            cameraImage.source=""
            cameraImage.source="image://cvprovider/image"
        }
    }

    Button
    {
        text:"Close"
        width:parent.width*0.15
        height:parent.height*0.06
        anchors
        {
            horizontalCenter:parent.horizontalCenter
            bottom:parent.bottom
        }
        onClicked:{
            Qt.quit()
        }
    }
}
