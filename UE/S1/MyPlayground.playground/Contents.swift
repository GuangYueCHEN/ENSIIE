//: Playground - noun: a place where people can play

import UIKit

var str = "wtf" //定义变量  str.characters.count     str.characters : 每个字母   str.append( Character )
let MAX = 1000 //定义常量
let imTrue = true //布尔
var b:Int=1 + 2;//空格需要加分号 0b11 1_000_000 1.25e10
Int.max//看大小
//UInt Int8 Int16 位整型
print(str,terminator:"")
print(str)


print:for x in 0...9{ // ==  ..<10        _代替x循环9次
    x
    print("\(x) is ",terminator:"") ; print(x)

}


var a = -8.0
while a <= 0{//repeat {} while 条件     ／／break continue
  sin(a)
    a += 0.1
}
a+Double(b)//类型转化


if imTrue {
    print("i m true")
}
else if 4 + 3 == 7{
    print("3+4")
}



// switch
//功能强大
//case where






var colornum = 18// color
var batteryColor2:UIColor
batteryColor2 = UIColor.blue
batteryColor2

var batteryColor = colornum <= 20 ? UIColor.red : UIColor.green
batteryColor


//元组
var point = ( 5 , 2 )
let ( x , y ) = point
x
y
let ( z , _ )=point
z
let point2 = ( x : 3 , y : 2)
point2.x
point2.y
print( x , y , z ,separator: " -- " )



//数组
var someInts = [Int](repeating: 0, count: 3) // 都是0
var someInts2:[Int] = [10, 20, 30]
var someVar = someInts[0]
someInts.append(20)
someInts.append(30)
someInts += [40]
someInts.count
someInts.isEmpty
//for item in someInts{
  //  print(item)
//}

var al = "s"
switch al {  //可以判断各种数据结构
case "A","a":
    print("is a")
default:
    print("isn't a ") // () 代表空语句
}


//function --func
//guard --baowei
func buy2( money :Int , price : Int , capacity : Int , volume : Int){
    
    guard money >= price else {
        return
        
    }
   guard capacity >= volume else{
        return
    }
    
    print("ican buy it\n")
    print("ican buy it\n")
    print("ican buy it\n")
}

// string




