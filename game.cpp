#include<iostream>
#include<graphics.h>
#include<time.h>
#include<windows.h>
#include<unistd.h>
#include<dos.h>
using namespace std;

int endfunc(int e, int a); // declaraing function to check game is over or not

int main(){
	system("color 11"); //console screen font color
	string color;  // declaring variables
	int a;
	int n;
	cout<<"Choose any of these colors:\n \t1) BLUE \n \t2) GREEN \n \t3) YELLOW \n \t4) WHITE\n";
	cout<<"Enter Your Choice : ";   // taking choice of color from user
	getline(cin,color,'\n');        //string input function
	system("cls");                 //function for clrealing the console before execution of next instruction
	usleep(9999);
	cout<<"Your Color Choosen";     
    usleep(9999);
	system("cls");
	usleep(9999);
	cout<<"Choose the level of Difficulty at which you want to play :";          //taking user choice for hardess of level
	cout<<endl<<"\t1) EASY"<<endl<<"\t2) MEDIUM"<<endl<<"\t3) HARD"<<endl;
	cout<<"Enter Your Choice : ";  
	cin>>a;
	system("cls");
	usleep(999);
	cout<<"Your Level Choosen";
	if(a==1)  // speed condition according to choosen level
	{
		n=170;        //aurguments for delay funtion(used in following code)
		
	}
	if(a==2)
	{
		n=70;
		
	}
	if(a==3)
	{
		n=45;
		
	}

    //initializing variable
    int gd,gm;    //variables for graghics windows
	int rx=200,ry=200;   //variables for position of the food
	int x[200],y[200];       //arrays for the lenght of the snake
 
    for(int i = 0;i < 200 ; i++)    //loop of initialing length array
	{
        x[i]=0;
        y[i]=0;
    }
 
    int f=1;            // food
    int fd=1;
    int chk = 700;     //for checking
    	int d;         // variable for current direction 
    int dir=1;         // last past ditection
    int h= GetSystemMetrics(SM_CYSCREEN);     //to get Full 
   int w= GetSystemMetrics(SM_CXSCREEN);
   initwindow(w,h,"SNAKE GAME");
  
   settextstyle(4,0,5);        //changing font in output
   
   
  outtextxy(860,110," Snake Game  ");
    settextstyle(3,0,5);
  outtextxy(862,160," Instructions: ");         //Highlighting instructions on          
  outtextxy(858,220,"1)Don't Hit The Wall.");  
  outtextxy(858,280,"2)Don't collide with itself.");
  outtextxy(858,340,"3)Eat Bonus Food to make");
  outtextxy(858,380,"your speed slow.");
	 
	x[0]=200,y[0]=200;                
    d=1;                   //whenever game starts , snake moves in right diection
    int length =3;        //length of snake when game starts

while(true)               //infinite loop resposible for snake movement and running of game
{
    setfillstyle(3,1);    //defining area in console (with color and patteren) in which game will be played
    bar(0,0,640,480);
    
    setfillstyle(5,5); // Default border
    bar(0,0,640,10);
    bar(0,0,10,480);
    bar(0,480,640,470);
    bar(630,10,640,480);
    setfillstyle(1,11);
    if(color=="1"){         //if conditions will be executed according to user choice
    setfillstyle(1,1);
}
   else if(color=="2"){
	setfillstyle(1,2);
}
    else if(color=="3"){
    setfillstyle(1,14);
	}
	else if(color=="4"){
	setfillstyle(1,15);
	}
	else {
	setfillstyle(1,2); // Default color
	}
    
    
       // food taken?
   if(f%7!=0){
   
   if(x[0]==rx && y[0]==ry )   //x and y coordinates of the snake head become equal to food position 
   {
    length += 1;              //length of snake increases
    f=f+1;                    
 	if(a==1){                 //speed of snake increases according to hardness of levels
 		n=n-10;
	 }else if(a==2){
	 	n=n-3;
	 }else if(a==3){
	 	n=n-2;
	 }

	setfillstyle(1,0);//(style,color)     
    bar(rx,ry,rx+10,ry+10);                //making the food disapear        
     
    //make food
    do{
	rx = (1+rand()%630);     // to make the food appear randomly within the set range
	ry = (1+rand()%470);
    }while(getpixel(rx,ry)!=0 && rx > 10 && ry > 10);     

    rx=rx/20;               //for allignment of snake head and food
    rx=rx*10;
    ry=ry/20;
    ry=ry*10;
    
  setfillstyle(1,2); // Default     increasing length
	
	
     }
	 bar(rx,ry,rx+10,ry+10);  // food size
	 }
      
 //      food to slow the speed of snake
 if(f%7==0){
  if(x[0]==rx && y[0]==ry ){ 
  	 int n=60;
  	 n=n+15;               //speed increasing variable
    f=f+1;
    
   
    setfillstyle(1,4);//(style,color)     REd
   
    bar(rx,ry,rx-10,ry-10);
    
    //make food
    do{ // food at rendom position using random function
	rx = (rand()%630);
	ry = (rand()%470);
    }while(getpixel(rx,ry)!=0 && rx > 10 && ry > 10);

    rx=rx/20;
    rx=rx*10;
    ry=ry/20;
    ry=ry*10;
    
    setfillstyle(1,4);  // length of snake
     }
     setfillstyle(1,11);
      bar(rx,ry,rx+10,ry+10);
      if(color=="1"){
      	       setfillstyle(1,1);
	  }
      else if(color=="2"){
      	       setfillstyle(1,2);
	  }else if(color=="3"){
	  	       setfillstyle(1,14);
	  }
	  else if(color=="4"){
	  	       setfillstyle(1,15);
	  }
	 }
	
//      taking direction of snake as input and storing in d variable
   
    if(GetAsyncKeyState(VK_RIGHT)){d=1;}              
    else if(GetAsyncKeyState(VK_LEFT)){ d=2;}
    else if(GetAsyncKeyState(VK_UP)){ d=3;}
    else if(GetAsyncKeyState(VK_DOWN)) {d=4;}
    else{d=0;}
    switch(d){ 
    case 0:
      if(dir==1){x[0]=x[0]+10;}         //for the continuation of the key
      else if(dir==2){x[0]=x[0]-10;}    // as dir stores history(previously pressed key
      else if(dir==3){ y[0]=y[0]-10;}
      else if(dir==4) {y[0]=y[0]+10;}
      else{d=0;}
      break;
    case 1:
    	if(dir==1){
    		 	 x[0]=x[0]+10;       //defining the movement of head of the sanke accoring to pressed key(value of dir)
    		 break;
		}
          else{
          	 x[0]=x[0]+10;
          	 dir=1;
           break;
		  }
           
    case 2:
    	 	if(dir==2){
    		x[0]=x[0]-10;
    		break;
		}
          else{
          	x[0]=x[0]-10;
          	dir=2;
           break;
		  }
    case 3:
    	if(dir==3){
    	y[0]-=10;
    	break;
		}
          else{
          	 y[0]-=10;
          	 dir=3;
           break;
		  }
    case 4:
    		if(dir==4){
        	y[0]+=10;
    		 break;
		}
          else{
          	y[0]+=10;
          	 dir=4;
           break;
		  }
    }
    for(int i = 0; i < length;i++){ // increasing size of snake by eating food
        bar(x[i],y[i],x[i]+10,y[i]+10);
    }
    for(int i= 199; i >0;i--){  // moving snake body to the next index
        x[i] = x[i-1];
        y[i] = y[i -1];
    }
    if(x[0] >= 616 || x[0]<=0|| y[0]<=0 || y[0]>=456){   //If snake hits the boundary endfuction will be called
    endfunc(f,0);
    break;
    }

    for(int i = 2; i < length;i++){
        if(x[0] == x[i] && y[0] == y[i]){
            chk = i;         //chk variable includes every coordinate of snake body
            break;
            }
    }
    delay(n);
    if(x[0] == x[chk] && y[0] == y[chk]){   //if snake hits itself endfunction will be called
    settextstyle(4,0,6);
    
    char a[100],b[100];
    endfunc(f,1);
//    
    f=(f-2)*10;
    cleardevice();
    sprintf(a," Game Over \n Score : %d",f);
    outtextxy(350,300,a);
          usleep(999999);
    break;
    }

}
return 0;  //main function ends

}

int endfunc(int e,int a){  //defining end function
    setfillstyle(1,5);
    e=(e-2)*10;           //calculating score according to food eaten
    
    bar(0,0,640,470); //covers game screen
    system("cls");    //clearing the screen
    if(a == 0){       //snake hit the boundary
    	cout<<endl<<endl<<endl;
		cout<<"\t\t\tYou died outside the boundary!!!";
char a[100],b[100];
    cleardevice();
    sprintf(a," Game Over Score : %d",e);
    outtextxy(450,300,a);
          usleep(999999);
    }
    else if(a== 1){              //If snake hits itself
    	    cout<<endl<<endl<<endl;
			cout<<"\t\t\tYou died into yourself!!!\n";
    }
		cout<<"Your score is :\n"<<e;
		
	// For Message Showing
	system("color 11");
	if(e<150){                                                      //Displaying respose according to score of user
		cout<<endl<<endl<<"\t\t\t Try better next time"<<endl;
    cout << "       a$$$$$$$$$$a" << endl;
    cout << "     a$$$$$$$$$$$$$$a" << endl;
    cout << "   a$$$$$$$$$$$$$$$$$$a" << endl;
    cout << "  a$$$$$$$$$$$$$$$$$$$$a" << endl;
    cout << " a$$$$$   $$$$$$   $$$$$a" << endl;
    cout << "a$$$$$     $$$$     $$$$$a" << endl;
    cout << "a$$$$$$$ $$$$$$$$$$$$$$$$a" << endl;
    cout << "a$$$$$$$ $$$$$$$$$$$$$$$$a" << endl;
    cout << "a$$$$$$$$$$$$$$$$$$$$$$$$a" << endl;
    cout << " a$$$$$$          $$$$$$a" << endl;
    cout << "  a$$$$  $$$$$$$$  $$$$a" << endl;
    cout << "   a$$ $$$$$$$$$$$$ $$a" << endl;
    cout << "     a$$$$$$$$$$$$$$a" << endl;
    cout << "       a$$$$$$$$$$a" << endl;
	}
	else if(e>150 && e<1000){
	cout<<endl<<endl<<"\t\t\t Good\n";
	cout << "       a$$$$$$$$$$a" << endl;
    cout << "     a$$$$$$$$$$$$$$a" << endl;
    cout << "   a$$$$$$$$$$$$$$$$$$a" << endl;
    cout << "  a$$$$$$$$$$$$$$$$$$$$a" << endl;
    cout << " a$$$$$   $$$$$$   $$$$$a" << endl;
    cout << "a$$$$$     $$$$     $$$$$a" << endl;
    cout << "a$$$$$$$$$$$$$$$$$$$$$$$$a" << endl;
    cout << "a$$$$$$$$$$$$$$$$$$$$$$$$a" << endl;
    cout << "a$$$$  $$$$$$$$$$$$  $$$$a" << endl;
    cout << " a$$$$              $$$$a" << endl;
    cout << "  a$$$$$$$$$$$$$$$$$$$$a" << endl;
    cout << "   a$$$$$$$$$$$$$$$$$$a" << endl;
    cout << "     a$$$$$$$$$$$$$$a" << endl;
    cout << "       a$$$$$$$$$$a" << endl;
	
	}
	else if(e>1000 && e<1500){
	  cout<<endl<<endl<<"\t\t\t Excellent";	
	}
	else if(e>1500){
	   cout<<endl<<endl<<"\t\t\t Perfect";
	cout << "       a$$$$$$$$$$a" << endl;
    cout << "     a$$$$$$$$$$$$$$a" << endl;
    cout << "   a$$$$$$$$$$$$$$$$$$a" << endl;
    cout << "  a$$$$$$$$$$$$$$$$$$$$a" << endl;
    cout << " a$$$$$   $$$$$$   $$$$$a" << endl;
    cout << "a$$$$$     $$$$     $$$$$a" << endl;
    cout << "a$$$$$$$$$$$$$$$$$$$$$$$$a" << endl;
    cout << "a$$$$$$$$$$$$$$$$$$$$$$$$a" << endl;
    cout << "a$$$$$$$           $$$$$$a" << endl;
    cout << "a$$$$$               $$$$a" << endl;
    cout << " a$$$$$$           $$$$$a" << endl;
    cout << "  a$$$$$$$$$$$$$$$$$$$a" << endl;
    cout << "   a$$$$$$$$$$$$$$$$$a" << endl;
    cout << "     a$$$$$$$$$$$$$$a" << endl;
    cout << "       a$$$$$$$$$$a" << endl;	
	}
   
}
