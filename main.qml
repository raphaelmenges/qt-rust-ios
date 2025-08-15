import QtQuick
import QtQuick.Controls
import QtQuick.Window

ApplicationWindow {
    visible: true
    width: 1280
    height: 720
    color: "#2c3e50"
    
    Column {
        anchors.centerIn: parent
        
        Text {
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: "Hello World from Qt!"
            color: "white"
        }
        
        Text {
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: helloFromMyCounter
            color: "white"
        }
        
        // Text {
        //     horizontalAlignment: Text.AlignHCenter
        //     verticalAlignment: Text.AlignVCenter
        //     text: helloFromMyBrige
        //     color: "white"
        // }
    }
}
