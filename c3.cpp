#include<bits/stdc++.h>
using namespace std;
int main(){
    string dir,com;
    char id,ifc;
    int cx,cy,cz,r=0,l=0;
    cout<<"Enter Initial Direction : ";
    cin>>id;
    ifc=id;
    if(id=='n')dir="nesw";
    if(id=='e')dir="eswn";
    if(id=='s')dir="swne";
    if(id=='w')dir="wnes";
    cout<<"Enter Co-ordinates (x,y,z) : ";
    cin>>cx>>cy>>cz;

    cout<<"Enter Command as String:";
    cin>>com;
    for(int i=0;i<com.length();i++){
        switch(com[i]){
            case 'u':
                ifc = 'u';    
                break;
            case 'd':
                ifc = 'd';
                break;
            case 'r':
                r++;
                if(r>3)r=0;
                l--;
                if(l<0)l=3;
                id = dir[r]; 
                ifc = id;
                break;
            case 'l':
                l++;
                if(l>3)l=0;
                r--;
                if(r<0)r=3;
                id = dir[l];
                ifc = id; 
                break;
            case 'f':
                if(ifc == 'u'){
                    cz++;break;
                }
                if(ifc == 'd'){
                    cz--;break;
                }
                if(id == dir[0])cy++;
                if(id == dir[2])cy--;
                if(id == dir[1])cx++;
                if(id == dir[3])cx--;
                break;
            case 'b':
                if(ifc == 'u'){
                    cz--;break;
                }
                if(ifc == 'd'){
                    cz++;break;
                }
                if(id == dir[0])cy--;
                if(id == dir[2])cy++;
                if(id == dir[1])cx--;
                if(id == dir[3])cx++;
                break;
        }
        cout<<"\n"<<com[i]<<" - ("<<cx<<", "<<cy<<", "<<cz<<") - "<<ifc;
    }
    cout<<"\nfinal co-ordinates : "<<"("<<cx<<", "<<cy<<", "<<cz<<")";
    cout<<"\nfinal direction : "<<id;
    return 0;
}