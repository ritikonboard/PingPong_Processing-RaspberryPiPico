import processing.serial.*;
Serial port;
String value;
boolean clicked = false;
int s1,s2;
String player_1_name,player_2_name;
int ball_x, ball_y, radius, speedX, speedY;
int player_1_Y_pos,player_2_Y_pos;
int paddle_Height, paddle_Width;
int paddleXL, paddleXR;

int scoreL=0; 
int scoreR=0; 
int winScore=5; 

color colorL=color(100,0,255);
color colorR=color(100,40,10);

void setup(){
  fullScreen();
  port = new Serial(this, "COM6", 9600);
  port.bufferUntil('\n');
  textSize(30);
  textAlign(CENTER,CENTER);
  rectMode(CENTER);
  paddleXL=20;
  paddleXR=width-20;
  
  paddle_Height=170;
  paddle_Width=20;
  
  ball_x=width/2; 
  ball_y=height/2; 
  
  radius=50; 
  speedX=6;
  speedY=8;

}

void draw(){
 background(0,200,200);
  port.write(scoreL);
  port.write(scoreR);
  movingBAll();
  bounceBack();
  movingPaddle();
  paddleCONCT();
  score();
  gameOver();
}

void movingBAll(){
 fill(255,0,0);
 circle(ball_x,ball_y,radius);
 ball_x=ball_x+speedX;
 ball_y=ball_y+speedY;
 }
 
 
void bounceBack(){
 if(ball_x > width-radius/3){
 reStart();
 speedX = -speedX;
 scoreL=scoreL+1;}
 else if(ball_x<0+radius/3){
 scoreR=scoreR+1;
 reStart();
 }
 else if(ball_y>height-radius/3){
 speedY=-speedY;
 }
 else if(ball_y<0+radius/3){
 speedY=-speedY;
 }
 } 
 
void movingPaddle(){
 fill(colorL);
 rect(paddleXL,player_1_Y_pos,paddle_Width,paddle_Height);
 fill(colorR);
 rect(paddleXR,player_2_Y_pos,paddle_Width,paddle_Height);  
}


void paddleCONCT(){
if(ball_x-radius/2<paddleXL+paddle_Width/2 && ball_y-radius/2 < player_1_Y_pos+paddle_Height/2 && ball_y+radius/2 > player_1_Y_pos-paddle_Height/2){
 if(speedX < 0){
 speedX=speedX-2;
 speedX = -speedX;} 
}
 if(ball_x+radius/2 > paddleXR - paddle_Width/2 && ball_y+radius/2 > player_2_Y_pos - paddle_Height/2 && ball_y-radius/2 < player_2_Y_pos + paddle_Height/2){
 if(speedX > 0){
   speedX=speedX+2;
   speedX=-speedX;}
}
}

 void score(){
 fill(0);
 text(player_1_name,120,25);
 text(player_2_name,width-120,25);
 text("Coded  : with love ",width-180,height-30);
 fill(250,0,0);
 text(scoreL,120,50);
 text(scoreR,width-120,50);
 text("PING PONG GAME",width/2,height/2+50);
 text(" Team 20 : RoboKnights",width/2+26,height/2+80);
 }
 
 void gameOver(){
 if(scoreL == winScore){
 gameOverPage(player_1_name);
 }
 if(scoreR == winScore){
 gameOverPage(player_2_name);
 }
 }
 
 void gameOverPage(String msg){
 speedX=0;
 speedY=0;
 text("GAME OVER",width/2,height/3-40);
 text("CLICK TO RESTART",width/2,height/3-80);
 text(msg+"  WINS!!!",width/2,height/3);
 
 if(mousePressed){
 scoreR=0;
 scoreL=0;
 speedX=6;
 speedY=8;
 }
 }
 
 void reStart(){
 ball_x=width/2;
 ball_y=height/2;
 radius=50;
 speedX=6;
 speedY=8;
 }
 
 void serialEvent( Serial port) 
{
  value = port.readStringUntil('\n');
  
  if (value != null)
  {
    String[] values = split(value, ",");
    player_1_name = values[0];
    player_2_name = values[1];
    player_1_Y_pos = int(values[2]);
    player_2_Y_pos = int(values[3]);
    s1 = int(values[4]) ;
    s2 = int(values[5]) ;
  }
}
 
