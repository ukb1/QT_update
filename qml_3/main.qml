import QtQuick 2.15
import QtQuick.Window 2.15


Window {

    maximumHeight: 300
    maximumWidth:  600

    minimumHeight: maximumHeight
    minimumWidth:  maximumWidth
    visible: true
    title:   qsTr("joystick")

    property int value_x: 10
    property int value_y: 10
    property int left_control_y  : 50
    property int left_control_x  : 150
    property int right_control_y : 420
    property int right_control_x : 150
    property bool value : false


    Rectangle{
        id: udrl
        x: 50   //left_control_x
        y: 150  //left_control_y

        width: 132
        height: 112
        Image {
            id: upper
            x:  50
            y:  0
            source: "/Image/up.png"
            MouseArea{
                anchors.fill: parent
                onPressed:{ upper.opacity = 0.5 }
                onReleased: upper.opacity  = 1.0
            }
        }

        Image {
            id: down
            x: 50
            y: 80
            source: "/Image/down.png"
            MouseArea{
                anchors.fill: parent
                onPressed:  down.opacity  = 0.5
                onReleased: down.opacity  = 1.0
            }

        }
        Image {
            id: left
            x:  0
            y:  40
            source: "/Image/left.png"
            MouseArea{
                anchors.fill: parent
                onPressed:  left.opacity = 0.5
                onReleased: left.opacity = 1.0


            }
        }
        Image {
            id: right
            x:  100
            y:  40
            opacity: 1.0
            source: "/Image/right.png"
            MouseArea{
                anchors.fill: parent
                onPressed: right.opacity  = 0.5
                onReleased: right.opacity  = 1.0
            }
        }
    }


    Rectangle{
        id: xrtc
        x: 420 //right_control_x
        y: 150 // right_control_y

        width: 132
        height: 112
        Image {
            id: x_icon
            x:  50
            y:  80
            source: "/Image/x.png"
            MouseArea{
                anchors.fill: parent
                onPressed: x_icon.scale  = 1.3
                onReleased: x_icon.scale = 1.0
            }
        }
        Image {
            id: rec_icon
            x:  0
            y:  40
            source: "/Image/rectangle.png"
            MouseArea{
                anchors.fill: parent
                onPressed: rec_icon.scale  = 1.3
                onReleased: rec_icon.scale = 1.0
            }
        }
        Image {
            id: tri_icon
            x:50
            y:0
            source: "/Image/triangle.png"
            MouseArea{
                anchors.fill: parent
                onPressed:   tri_icon.scale = 1.3
                onReleased:  tri_icon.scale = 1.0
            }


        }
        Image {
            id: cir_icon
            x:100
            y:40
            opacity: 1.0
            source: "/Image/circle.png"
            MouseArea{
                anchors.fill: parent
                onPressed:    cir_icon.scale  = 1.3
                onReleased:   cir_icon.scale = 1.0
            }


        }
    }


    Image {
        id: rec
        x:  268
        y:  166
        opacity: 1.0
        source: "/Image/recycle.png"
        MouseArea{
            anchors.fill: rec
            onPressed:{
                rect.x    = value_x
                rect.y    = value_y
                rec.scale = 1.3

                if(value)
                {
                    rec.source =  "/Image/recycle.png"
                    value = false
                    udrl.x = 50
                    udrl.y = 150
                    xrtc.x = 420
                    xrtc.y = 150

                }
                else
                {
                    rec.source = "/Image/recycle2.png"
                    value = true
                    udrl.x = 420
                    udrl.y = 150
                    xrtc.x = 50
                    xrtc.y = 150
                }

            }
            onReleased: rec.scale = 1.0
        }

    }

    Rectangle {
        id: mainrec
        x:30 ; y:30
        width:  540
        height: 100
        color: "#D9D9D9"
        radius: 20
        clip: true
        Rectangle {
            id: rect
            x: value_x ; y: value_y
            width: 25
            height: 25
            color: "#59BDB7"
            radius: width*0.5

        }
        MouseArea {
               anchors.fill: parent
               onPositionChanged:
               {
                   rect.x = mouseX - rect.width / 2;
                   rect.y = mouseY - rect.height / 2
               }
           }
    }

//    Rectangle{
//        x:40; y:40
//        width: 400
//        height: 500
//        color: "Red"
//        Image{
//            x:10; y:10
//            width: 40
//            height: 40
//            source:"/Image/up.png"
//        }
//    }


}
