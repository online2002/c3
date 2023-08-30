#include<bits/stdc++.h>
using namespace std;
int main(){
    //variables declaration...
    string direction,commands;
    char initial_direction,initial_facing;
    int cx,cy,cz,r=0,l=0;

    //taking inputs...
    cout<<"Enter Initial direction : ";
    cin>>initial_direction;
    cout<<"Enter Co-ordinates (x,y,z) : ";
    cin>>cx>>cy>>cz;
    cout<<"Enter command as String:";
    cin>>commands;

    //stablizing inputs...
    initial_facing=initial_direction;
    if(initial_direction=='n')direction="nesw";
    if(initial_direction=='e')direction="eswn";
    if(initial_direction=='s')direction="swne";
    if(initial_direction=='w')direction="wnes";


    //main logic...
    for(int i=0;i<commands.length();i++){
        //performing each operations...
        switch(commands[i]){
            case 'u':
                initial_facing = 'u';    
                break;
            case 'd':
                initial_facing = 'd';
                break;
            case 'r':
                r++;
                if(r>3)r=0;
                l--;
                if(l<0)l=3;
                initial_direction = direction[r]; 
                initial_facing = initial_direction;
                break;
            case 'l':
                l++;
                if(l>3)l=0;
                r--;
                if(r<0)r=3;
                initial_direction = direction[l];
                initial_facing = initial_direction; 
                break;
            case 'f':
                if(initial_facing == 'u'){
                    cz++;break;
                }
                if(initial_facing == 'd'){
                    cz--;break;
                }
                if(initial_direction == direction[0])cy++;
                if(initial_direction == direction[2])cy--;
                if(initial_direction == direction[1])cx++;
                if(initial_direction == direction[3])cx--;
                break;
            case 'b':
                if(initial_facing == 'u'){
                    cz--;break;
                }
                if(initial_facing == 'd'){
                    cz++;break;
                }
                if(initial_direction == direction[0])cy--;
                if(initial_direction == direction[2])cy++;
                if(initial_direction == direction[1])cx--;
                if(initial_direction == direction[3])cx++;
                break;
        }
        cout<<"\n"<<commands[i]<<" - ("<<cx<<", "<<cy<<", "<<cz<<") - "<<initial_facing;
    }
    cout<<"\nfinal co-ordinates : "<<"("<<cx<<", "<<cy<<", "<<cz<<")";
    cout<<"\nfinal direction : "<<initial_direction;
    return 0;
}