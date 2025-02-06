import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480

    Image {
        id: cameraImage
        anchors.centerIn: parent
        width: parent.width
        height: parent.height
        cache:false
        asynchronous: false
    }
    Connections
    {
        target:stream
        function onImageUpdated(img)
        {
            cameraImage.source="image://cvprovider/image?"+Math.random()
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
            margins:15
        }
        onClicked:{
            Qt.quit()
        }
    }
}
