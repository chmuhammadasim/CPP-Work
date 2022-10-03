#include<iostream>
#include "extraF.h"
using namespace std;
void zero(int arr[]){
	for(int i=0;i<10;i++)
	arr[i]=0;
}
main()
{
	int arr[10],n,loc,z=0,u=0,s,a,b,temp;
	char choice,choice2;
	zero(arr);
    dbmsintro();
    do
	{
		mainmenu:
    	dbmsmenu();
		cin>>choice;
		switch(choice)
		{
			case '1':
				number();
				cin>>n;
				up:
				case1();
				cin>>choice2;
				switch(choice2)
				{
					case '1':
							if(arr[0]==0){
								arr[0]=n;
							}
							else{
								for(int i=8;i>=0;i--)
								{
									if(arr[i]!=0)
									arr[i+1]=arr[i];	
								}
								arr[0]=n;
							}
						break;
					case '2':
						loca();
						cin>>loc;
						if(arr[loc]==0)
						{
							arr[loc]=n;
						}
						else
						{
							for(int i=loc;i<=9;i++)
							{
								if(arr[i]==0)
									{
										z=i;
										break;
									}
							}
							for(int i=loc;i<z;i++)
								{
									arr[i+1]=arr[i];
								}
								arr[loc]=n;
						}
						break;
					case '3':
							if(arr[9]==0){
								arr[9]=n;
							}
							else{
								for(int i=9;i>=0;i--)
								{
									if(arr[i]==0)
									{
										z=i;
										break;
									}
								}
								for(int i=z;i<9;i++)
								{
									arr[i]=arr[i+1];
								}
								arr[9]=n;
							}
						break;
					case '4':
						goto mainmenu;
						break;
					default:
						goto up;
						break;
				}
				break;
			case '2':
				cout<<"\n\n\n"<<"List : ";
				for(int i=0;i<10;i++)
				{
					cout<<arr[i]<<" ";
				}
				cout<<"\n\n\n";
				system("pause");
				break;
			case '3':
				up1:
				case2();
				cin>>choice2;
				switch(choice2)
				{
					case '1':
						number();
						cin>>n;
						for(int i=0;i<=9;i++)
						{
							if(arr[i]==n)
							{
								cout<<"Your Required number ( "<<n<<" )  is on index :"<<i<<endl;
							}
						}
						cout<<"\n\n\n";
						system("pause");
						break;
					case '2':
						index();
						cin>>n;
						cout<<"ON Required Index ( "<<n<<" ) the number is :"<<arr[n];
						cout<<"\n\n\n";
						system("pause");
						break;
					case '3':
						goto mainmenu;
						break;
					default:
						goto up1;
				}
				break;
			case '4':
				up2:
				case3();
				cin>>choice2;
				switch(choice2)
				{
					case '1':
						number();
						cin>>n;
						updatenumber();
						cin>>u;
						for(int i=0;i<=9;i++)
						{
							if(arr[i]==n)
							{
								arr[i]=u;
							}
						}
						break;
					case '2':
						index();
						cin>>n;
						updatenumber();
						cin>>u;
						arr[n]=u;
						break;
					case '3':
						goto mainmenu;
						break;
					default:
							goto up2;
						break;
				}
				break;
			case '5':
				up3:
				case4();
				cin>>choice2;
				switch(choice2)
				{
					case '1':
						number();
						cin>>n;
						for(int i=0;i<=9;i++)
						{
							if(arr[i]==n)
							{
								z=i;
								for(int i=z;i<9;i++)
								{
									arr[i]=arr[i+1];
								}
							}
						}
						break;
					case '2':
						loca();
						cin>>loc;
						for(int i=loc;i<9;i++)
							{
								arr[i]=arr[i+1];
							}
						break;
					case '3':
						break;
					default:
							goto up3;
						break;
				}
				break;
			case '6':
				up4:
				case6();
				cin>>choice2;
				switch(choice2)
				{
					case '1':
						number();
						cin>>a;
						copyto();
						cin>>b;
						for(int i=0;i<=9;i++)
						{
							if(arr[i]==a)
							{
								z=i;
								break;
							}
						}
						for(int i=0;i<=9;i++)
						{
							if(arr[i]==b)
							{
								arr[i]=arr[z];
							}
						}
						break;
					case '2':
						loca();
						cin>>a;
						copyto();
						cin>>b;
						arr[b]=arr[b];
						break;
					case '3':
							goto mainmenu;
						break;
					default:
						goto up4;					
				}
				break;
			case '7':
				up5:
				case5();
				cin>>choice2;
				switch(choice2)
				{
					case '1': 
						number();
						cin>>n;
						swapto();
						cin>>s;
						for(int i=0;i<=9;i++)
						{
							if(n==arr[i])
							{
								a=i;
							}
							if(s==arr[i])
							{
								b=i;
							}
						}
						temp=arr[a];
						arr[a]=arr[b];
						arr[b]=temp;
						break;
					case '2':
						loca();
						cin>>n;
						swapto();
						cin>>s;
						temp=arr[n];
						arr[n]=arr[s];
						arr[s]=temp;
						break;
					case '3':
							goto mainmenu;
						break;
					default:
						goto up5;
				}
				break;
			case '8':
				break;
			default:
				break;
		}	
	}while(choice!='8');
}
