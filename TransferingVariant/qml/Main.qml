import QtQuick
import QtQuick.Controls.Material
import TransferingVariant

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QVariantList and QVariantMap")

    function arrayObjectFunc(array, object) {
        console.log("---Printing array---")
        array.forEach(function(elem) {
            console.log("Array item: " + elem)
        })

        console.log("---Printing object---")
        for (var key in object) {
            console.log("Object[" + key + "]: " + object[key])
        }
    }

    Button {
        id: btn1Id
        text: "Pass data to Cpp"
        onClicked: {
            var arr = ['Africa', 'Asia', 'Europe', 'North America', 'South America', 'Oceania', 'Antartica']
            var obj = {
                firstName: 'John'
                , lastName: 'Snow'
                , location: 'Earth'
            }
            CppClass.passFromQmlToCpp(arr, obj)
        }
    }

    Button {
        id: btn2Id
        anchors.top: btn1Id.bottom
        text: "GetVariantListFromCpp"
        onClicked: {
            var data = CppClass.getVariantListFromCpp() // returns array
            data.forEach(function(elem) {
                console.log("Array ite: " + elem)
            })
        }
    }

    Button {
        id: btn3Id
        anchors.top : btn2Id.bottom
        text: "GetVariantMapFromCpp"
        onClicked: {
            var data = CppClass.getVariantMapFromCpp() // returns an object
            for (var key in data) {
                console.log("Object[" + key + "] : " + data[key])
            }
        }
    }

    Button {
        id: btn4Id
        anchors.top : btn3Id.bottom
        text: "Trigger JS call"
        onClicked: {
            CppClass.triggerJSCall()
        }
    }
}
