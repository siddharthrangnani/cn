#include<bits/stdc++.h>
using namespace std;

char exor(char a,char b)
{
if(a==b)
return '0';
else
return '1';
}

void crc(char data[], char key[])
{
int datal = strlen(data);
int keyl = strlen(key);

for(int i=0;i<keyl-1;i++)  
data[datal+i]='0';
data[datal+keyl-1]='\0';

int codel = datal+keyl-1;               
char temp[20],rem[20];

for(int i=0;i<keyl;i++)
rem[i]=data[i];
for(int j=keyl;j<=codel;j++)
{
    for(int i=0;i<keyl;i++)
    temp[i]=rem[i];                

    if(rem[0]=='0')                {
        for(int i=0;i<keyl-1;i++)
            rem[i]=temp[i+1];
    }
    else  {    
        for(int i=0;i<keyl-1;i++)
            rem[i]=exor(temp[i+1],key[i+1]);
            
    }
    if(j!=codel)
        rem[keyl-1]=data[j];        
    else
        rem[keyl-1]='\0';
}
    
for(int i=0;i<keyl-1;i++)
data[datal+i]=rem[i];               
data[codel]='\0';
cout<<"CRC="<<rem<<"\nDataword="<<data;

}

int main()
{
char key[20],data[20];

cout<<"Enter the data:";
cin>>data;
cout<<"Enter the key:";
cin>>key;

crc(data,key);                        // generate crc

return 0;
}