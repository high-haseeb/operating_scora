#include <WiFi.h>  // For ESP32
#include <ESPAsyncWebServer.h>
#include <String>
#include <iostream>

const char *ssid = "ESP_AP";  // WiFi Name
const char *password = "12345678";  // WiFi Password

WiFiServer server(80);  // Start a web server on port 80


String htmlPage = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0-beta3/css/all.min.css">
    <style>
        body{
            margin: 0%;
        }
        html{
            scroll-behavior: smooth;
        }
        .a{
            display: flex;
            position: fixed;
            top: 0%;
            background-color: black;
            width: 100%;
            justify-content: space-around;
            align-items: center;
            font-weight: bolder;
            color: white;
            font-size: 20px;
            flex-wrap: wrap;
            border: white solid;
            border-width: 0px 0px 1px 0px ;
        }
        .a label{
            cursor: pointer;
            margin: 3px;
        }
        .b{
            display: flex;
            width: 100%;
            background-color: blue;
            justify-content: space-around;
            align-items: center;
            flex-wrap: wrap;
            flex-direction: row;
            border: white solid;
            border-width: 0px 0px 1px 0px ;

            
        }
        #img1{
            width: 300px;   
            margin-top: 40px;     
        }
        
        #h1{
            font-size: 40px;
            margin-top:40px;
        }
        
        .c{
            display: flex;
            width: 100%;
            background-color: #3373C4;
            justify-content: space-around;
            align-items: center;
            flex-wrap: wrap;
            flex-direction: column;
            border: white solid;
            border-width: 0px 0px 1px 0px ;
            color: white;
            
        }
        #c1, #e1,#f1{
            font-size: 30px;
            color: greenyellow;
            font-weight: bolder;
            margin-top: 10px;
            margin-bottom: 10px;

        }
        #c2,#e2,#e3,#f2{
            font-size: 20px;
            color: white;
            margin-right: 15px;
            margin-left: 15px;
            margin-bottom: 10px;


        }
        .e{
            display: flex;
            width: 100%;
            background-color: blue;
            justify-content: space-around;
            align-items: center;
            flex-wrap: wrap;
            flex-direction: column;
            border: white solid;
            border-width: 0px 0px 1px 0px ;
            color: white;
        }
        .e div,.f div{
            display: flex;
            justify-content: space-around;
            align-items: center;
            flex-wrap: wrap;
            flex-direction: row;
            
        }
        .e div label,.f div label{
            font-size: 20px;
            color: greenyellow;
            font-weight: bolder;
            margin: 10px;
        }
        .e div button,.f button{
            font-size: 20px;
            color: black;
            background-color: white;
            border-radius: 5px;
            margin: 10px;
            cursor: pointer;
            
        }
        .e div input[type="checkbox"]{
            accent-color: black;
            cursor: pointer;
        }
        .f div input[type="number"]{
            cursor: pointer;
            font-size: 20px;
            border-radius: 5px;
        }
        .f{
            display: flex;
            width: 100%;
            background-color: #3373C4;
            justify-content: space-around;
            align-items: center;
            flex-direction: column;
            border: white solid;
            border-width: 0px 0px 1px 0px ;
        }
        
        @media (max-width:850px)
        {
            .a label{font-size: 15px;}
            .b #h1{font-size: 24px;}
            .b #p{font-size: 18px;}
            .c #c1{font-size: 18px;}
            .e #e1{font-size: 18px;}
            .f #f1{font-size: 18px;}
            .c #c2{font-size: 15px;}
            .f #f2{font-size: 15px;}
            .e #e2{font-size: 15px;}
            .e #e3{font-size: 15px;}
            .e div label{font-size: 15px;}
            .f div label{font-size: 15px;}
            .f div input[type="number"]{font-size: 15px;}
            .e div button,.f button{font-size: 15px;}
            #img1{width: 200px;margin-top: 10px;}
        }
    </style>
</head>

<body>
    <div class="a">
        <label >About</label>
        <label >Kinematics</label>
        <label >Operation</label>
        <label >Specifications</label>
    </div>
    <div id="About">
        <div class="b">
            <h1 id="h1" style="color: greenyellow;font-weight: bolder;">
                SCORA ER-14 ROBOT
            <p id="p" style="color: white;">4-DOF Robotic Arm for Kinematics and Control</p>
            </h1>
            <img id="img1" src="scora.png"  alt="">
        </div>

        <div class="c">
            <label id="c1">Overview</label>
            <label id="c2">
                The SCORA ER-14 is a 4-degree-of-freedom (DOF) robotic arm designed for educational
                and industrial applications, particularly in kinematics, automation, and control system studies.
                It features a robust mechanical structure with precise joint articulation, enabling users to 
                perform forward and inverse kinematics calculations for motion planning. The robot is commonly
                used in research labs and training institutes to teach robotics concepts, programming, and 
                real-world automation techniques. Its compact design and compatibility with various control systems
                make it a versatile tool for learning and experimentation in robotic manipulation.
            </label>
        </div>
    </div>
    <div id="Kinematics">

    </div>
    <div id="Operation">
        <div class="e">
            <label id="e1">Operation</label>
            <label id="e3">Precision control at your fingertips – Operate the SCORA robot with ease! </label>
            <label id="e2"> Trigger a 10-degree rotation for individual robot joints.</label>
            <div>
                <label>Joint 1:</label>
                <button onclick="sendCommand('/M1_ON')">Start</button>               
                <label ><input type="checkbox" >Clockwise</label>
            </div>
            <div>
                <label>Joint 2:</label>
                <button onclick="sendCommand('/M2_ON')">Start</button>               
                <label ><input type="checkbox" >Clockwise</label>

            </div>
            <div>
                <label>Joint 3:</label>
                <button onclick="sendCommand('/M3_ON')">Start</button>               
                <label ><input type="checkbox" >Downward</label>


            </div>
            <div>
                <label>Joint 4:</label>
                <button onclick="sendCommand('/M4_ON')">Start</button>               
                <label ><input type="checkbox" >Clockwise</label>

            </div>
                
        </div>
        <div class="f">
            <label  id="f1"> Forward Kinematics</label>
            <label id="f2">Provide joint angles as input and change the position of the end effector.</label>
            <div>
                <label>Joint 1:</label>
                <input  type="number" placeholder="Angle(deg)">                
            </div>
            <div>
                <label>Joint 2:</label>
                <input  type="number" placeholder="Angle(deg)">                
            </div>
            <div>
                <label>Joint 3:</label>
                <input  type="number" placeholder="Translation(cm)">                
            </div>
            <div>
                <label>Joint 4:</label>
                <input  type="number" placeholder="Angle(deg)">                
              
            </div>
            <button id="submit">Submit</button>
        </div>
    </div>
    <div id="Specification">

    </div>

    <script>
        document.addEventListener("DOMContentLoaded",()=>
    {
        let ids=["#About","#Kinematics","#Operation","#Specification"]
        let icons=document.querySelectorAll(".a label")
        let checks=document.querySelectorAll(".e div input")
        
        for(let i=0;i<checks.length;i++)
        {
            checks[i].addEventListener("change",()=>
            {
                if(checks[i].checked)
                {
                    document.body.style.backgroundColor="white"           
                }
                else
                {
                    document.body.style.backgroundColor="white"           
                }
            })
        }
        
        icons[0].style.color="greenyellow"
        
        for(let i=0;i<icons.length;i++)
        {
            icons[i].addEventListener("click",()=>
            {
                for(let j=0;j<icons.length;j++)
                {
                    icons[j].style.color="white"
                }
                icons[i].style.color="greenyellow"
                window.location.hash=ids[i]
            })
        }
        
        let joint_angles=document.querySelectorAll(".f div input")
        let submit=document.getElementById("submit")
        
        submit.addEventListener("click",()=>
        {
            let angles=[]
            for(let i=0;i<joint_angles.length;i++)
            {
                angles.push(joint_angles[i].value)
            }
        
        fetch(`/forward_kinematics?j1=${angles[0]}&j2=${angles[1]}&j3=${angles[2]}&j4=${angles[3]}`)
        .then(response=>response.json())
        .catch(error=>console.error("Error:",error))
        })
    }
    )
    
    function sendCommand(cmd) {
            fetch(cmd)
            .then(response => console.log("Command sent: " + cmd))
            .catch(error => console.error("Error:", error));
        }
    </script>
</body>
</html>

)rawliteral";
#define M1_ENCODER_A 34  
#define M1_ENCODER_B 35  
#define M3_ENCODER_A 32
#define M3_ENCODER_B 33
#define M4_ENCODER_A 0
#define M4_ENCODER_B 15 
#define CPR 1024      // Counts Per Revolution (adjust based on encoder model)

volatile int M1_encoderCount = 0;
int lastStateA1;
volatile int M3_encoderCount = 0;
int lastStateA3;
volatile int M4_encoderCount = 0;
int lastStateA4;

void IRAM_ATTR readEncoder1() {
    int stateA1 = digitalRead(M1_ENCODER_A);
    int stateB1 = digitalRead(M1_ENCODER_B);

    if (stateA1 != lastStateA1) {
        if (stateB1 != stateA1) {
            M1_encoderCount++;
        } else {
            M1_encoderCount--;
        }
    }
    lastStateA1 = stateA1;
}
void IRAM_ATTR readEncoder3() {
    int stateA3 = digitalRead(M3_ENCODER_A);
    int stateB3 = digitalRead(M3_ENCODER_B);

    if (stateA3 != lastStateA3) {
        if (stateB3 != stateA3) {
            M3_encoderCount++;
        } else {
            M3_encoderCount--;
        }
    }
    lastStateA3 = stateA3;
}
void IRAM_ATTR readEncoder4() {
    int stateA4 = digitalRead(M4_ENCODER_A);
    int stateB4 = digitalRead(M4_ENCODER_B);

    if (stateA4 != lastStateA4) {
        if (stateB4 != stateA4) {
            M4_encoderCount++;
        } else {
            M4_encoderCount--;
        }
    }
    lastStateA4 = stateA4;
}
void setup() {
    Serial.begin(9600);
    WiFi.softAP(ssid, password);  // Create ESP's own WiFi network
    server.begin();  // Start web server
    //Motor1
    #define M1_REN 25
    #define M1_LEN 27
    #define M1_RPWM 26
    #define M1_LPWM 14
    //Motor2
    #define M2_REN 16
    #define M2_LEN 4
    #define M2_RPWM 17
    #define M2_LPWM 5
     //Motor3
    #define M3_REN 18
    #define M3_LEN 21
    #define M3_RPWM 19
    #define M3_LPWM 22
     //Motor4
    #define M4_REN 12
    #define M4_LEN 2
    #define M4_RPWM 13
    #define M4_LPWM 23
    //Encoder1
    pinMode(M1_ENCODER_A, INPUT_PULLUP);
    pinMode(M1_ENCODER_B, INPUT_PULLUP);
    lastStateA1 = digitalRead(M1_ENCODER_A);
    attachInterrupt(digitalPinToInterrupt(M1_ENCODER_A), readEncoder1, CHANGE);
    //Encoder3
    pinMode(M3_ENCODER_A, INPUT_PULLUP);
    pinMode(M3_ENCODER_B, INPUT_PULLUP);
    lastStateA3 = digitalRead(M3_ENCODER_A);
    attachInterrupt(digitalPinToInterrupt(M3_ENCODER_A), readEncoder3, CHANGE);
    //Encoder4
    pinMode(M4_ENCODER_A, INPUT_PULLUP);
    pinMode(M4_ENCODER_B, INPUT_PULLUP);
    lastStateA4 = digitalRead(M4_ENCODER_A);
    attachInterrupt(digitalPinToInterrupt(M4_ENCODER_A), readEncoder4, CHANGE);

    int array[16]={13,23,2,12,22,19,18,21,5,17,4,16,14,25,26,27};
    for(int i=0;i<16;i++)
    {
        pinMode(array[i],OUTPUT);
        digitalWrite(array[i],LOW);
    }
}

void loop() {
    WiFiClient client = server.available();  // Check for new connections
    if (!client) return;

    // Wait until the client sends a request
    while (!client.available()) delay(1);

    String request = client.readStringUntil('\r');  // Read the request
    client.flush();

    // Check if browser requested LED ON or OFF
    if (request.indexOf("/M1_ON") != -1) {
        digitalWrite(M1_REN,HIGH);
        digitalWrite(M1_LEN,HIGH);
        float angle1 = (M1_encoderCount *360) / (160*1024);  

        while(angle1<10.0)
        {
            angle1 = (M1_encoderCount *360) / (160*1024);
            Serial.println(angle1);
            analogWrite(M1_LPWM,150);//AntiClockWsie
            delay(500);
        }
        digitalWrite(M1_REN,LOW);
        digitalWrite(M1_LEN,LOW);
        analogWrite(M1_LPWM,0);
        client.println("HTTP/1.1 204 No Content"); // No response body
    } 
    if (request.indexOf("/M2_ON") != -1) {
        digitalWrite(M2_REN,HIGH);
        digitalWrite(M2_LEN,HIGH);
        for(float i=0;i<255;i+=.5)
        {
            analogWrite(M2_RPWM,i);//ClockWise
            delay(30);
            Serial.println(i);
        }
        

        client.println("HTTP/1.1 204 No Content"); // No response body
    }
    if (request.indexOf("/M3_ON") != -1) {
        digitalWrite(M3_REN,HIGH);
        digitalWrite(M3_LEN,HIGH);
        float trans1= (M3_encoderCount *360) / (160*1024*4.91);

        while(trans1<7.0)
        {
            trans1 = (M3_encoderCount *360) / (160*1024*4.91);
            Serial.println(trans1);
            analogWrite(M3_RPWM,150);
            delay(500);
        }
        digitalWrite(M3_REN,LOW);
        digitalWrite(M3_LEN,LOW);
        analogWrite(M3_RPWM,0);//Down

        client.println("HTTP/1.1 204 No Content"); // No response body
    } 
    if (request.indexOf("/M4_ON") != -1) {
        digitalWrite(M4_REN,HIGH);
        digitalWrite(M4_LEN,HIGH);
        float angle4 = 3.6*(M1_encoderCount *360) / (160*1024);  

        while(angle4<90.0)
        {
            angle4 = 3.6*(M1_encoderCount *360) / (160*1024);
            Serial.println(angle4);
            analogWrite(M1_LPWM,150);//ClockWsie
            delay(200);
        }
        digitalWrite(M4_REN,LOW);
        digitalWrite(M4_LEN,LOW);
        analogWrite(M4_LPWM,0);
        client.println("HTTP/1.1 204 No Content"); // No response body
    } 
    if (request.indexOf("/forward_kinematics") != -1) {
        String name_=request.substring(20,request.length());
        int e[4];
        int a[4];
        int ee=0;
        int aa=0;
        for(int i=0;i<name_.length();i++)
        {
            if(name_[i]=='=')
            {
                e[ee]=i;
                ee+=1;
            }
            if(name_[i]=='&')
            {
                a[aa]=i;
                aa+=1;    
            }
        }
        
        int j1=(name_.substring(e[0]+1,a[0])).toInt();
        int j2=(name_.substring(e[1]+1,a[1])).toInt();
        int j3=(name_.substring(e[2]+1,a[2])).toInt();
        int j4=(name_.substring(e[3]+1,a[3])).toInt();
        
        float angle1 = (M1_encoderCount *360) / (160*1024);  
        float trans1= (M3_encoderCount *360) / (160*1024*4.91);
        Serial.println(angle1);
        Serial.println(trans1);
        while(angle1<j1 || trans1<j3)
        {
            angle1 = (M1_encoderCount *360) / (160*1024);
            trans1= (M3_encoderCount *360) / (160*1024*4.91);
            Serial.println(angle1);
            Serial.println(trans1);

            
            if(digitalRead(M2_LEN)!=HIGH){digitalWrite(M2_LEN,HIGH);}
            if(digitalRead(M2_REN)!=HIGH){digitalWrite(M2_REN,HIGH);}
            if(digitalRead(M3_LEN)!=HIGH){digitalWrite(M3_LEN,HIGH);}
            if(digitalRead(M3_REN)!=HIGH){digitalWrite(M3_REN,HIGH);}
            if(angle1<j1){analogWrite(M2_LPWM,170);}
            if(trans1<j3){analogWrite(M3_RPWM,170);}
            delay(100);
            Serial.println("running");
        }
            digitalWrite(M1_REN,LOW);
            digitalWrite(M1_LEN,LOW);
            
            digitalWrite(M3_REN,LOW);
            digitalWrite(M3_LEN,LOW);
           
            analogWrite(M1_LPWM,0);
            analogWrite(M3_RPWM,0);
            delay(1000);

        
    
        client.println("HTTP/1.1 204 No Content"); // No response body
    }
   
    else {
        // Serve the HTML page when root URL is requested
        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println("Connection: close");
        client.println();
        client.println(htmlPage);
    }

    client.stop();
}
