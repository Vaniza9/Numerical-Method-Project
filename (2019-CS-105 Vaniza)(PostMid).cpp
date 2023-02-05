#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>
#include<stdlib.h>
#include<math.h>
#define EPSILON 0.001
#define   f(x)   x*x - 2*x + 1  
#define    h(x)    3*x - cos(x) -1 
using namespace std;
int factorial(int n){
   if(n == 1)
      return 1;
   return n * factorial(n-1);
}
float calU(float u, int n){
   if (n == 0)
      return 1;
   float result = u;
   for (int i = 1; i <= n / 2; i++)
      result = result*(u - i);
   for (int i = 1; i < n / 2; i++)
      result = result*(u + i);
   return result;
}

int main()
{
	char ch;

    printf("press 'A' for interpolation\n ");
    printf("press 'B' for integration\n");
    printf("press 'C' for Solution of ODE\n");
    scanf("%c",&ch);


   if(ch=='A')
  {
  	
  	int inputInter;
    abcde:
	printf("\nWelcome to the Solution for interpolation\n");
	printf("choose your problem\n");
	printf("0: Invalid Input\n1:sterling method\n2:Guass Backward\n3:Langrage\n4:Guass Forward\n5:Newton devident\n");
	scanf("%d",&inputInter);
	if(inputInter==1)
	{
			float x[100], fx[100], x1, yp=0, p;
	 int i,j,n;

	 /* Input Section */
	 cout<<"Enter number of data: ";
	 cin>>n;
	 cout<<"Enter data:"<< endl;
	 for(i=1;i<=n;i++)
	 {
		  cout<<"x["<< i<<"] = ";
		  cin>>x[i];
		  cout<<"fx["<< i<<"] = ";
		  cin>>fx[i];
	 }
	 cout<<"Enter interpolation point: ";
	 cin>>x1;
	
	
	float h, a, u, y1 = 0, N1 = 1, d = 1,
    N2 = 1, d2 = 1, temp1 = 1, temp2 = 1,
    k = 1, l = 1, delta[n][n];
   
    int  s;
    h = x[1] - x[0];
    s = floor(n / 2);
    a = x[s];
    u = (x1 - a) / h;
 
    // Preparing the forward difference
    // table
    for (i = 0; i < n - 1; ++i) {
        delta[i][0] = fx[i + 1] - fx[i];
    }
    for (i = 1; i < n - 1; ++i) {
        for (j = 0; j < n - i - 1; ++j) {
            delta[j][i] = delta[j + 1][i - 1]
                          - delta[j][i - 1];
        }
    }
 
    // Calculating f(x) using the Stirling
    // formula
    y1 = fx[s];
 
    for (i = 1; i <= n - 1; ++i) {
        if (i % 2 != 0) {
            if (k != 2) {
                temp1 *= (pow(u, k) -
                          pow((k - 1), 2));
            }
            else {
                temp1 *= (pow(u, 2) -
                          pow((k - 1), 2));
            }
            ++k;
            d *= i;
            s = floor((n - i) / 2);
            y1 += (temp1 / (2 * d)) *
                   (delta[s][i - 1] +
                   delta[s - 1][i - 1]);
        }
        else {
            temp2 *= (pow(u, 2) -
                      pow((l - 1), 2));
            ++l;
            d *= i;
            s = floor((n - i) / 2);
            y1 += (temp2 / (d)) *
                  (delta[s][i - 1]);
        }
    }
 
    cout << y1;
	}	
	
else if(inputInter==2)
 {
 		float x[100], fx[100], x1, yp=0, p;
			float f,s,d,h;
      int j,i,k,n;

	 /* Input Section */
	 cout<<"Enter number of data: ";
	 cin>>n;
	 cout<<"Enter data:"<< endl;
	 for(i=1;i<=n;i++)
	 {
		  cout<<"x["<< i<<"] = ";
		  cin>>x[i];
		  cout<<"fx["<< i<<"] = ";
		  cin>>fx[i];
	 }
	 cout<<"Enter interpolation point: ";
	 cin>>f;
      h=x[2]-x[1];
       
s=(f-x[n])/h;
d=fx[n];
p=1;
for(i=n,k=1;i>=1,k<n;i--,k++)
{
                 for(j=n;j>=1;j--)
                 {
                                 fx[j]=fx[j]-fx[j-1];
                                 }
                                 p=p*(s+k-1)/k;
                                 d=d+p*fx[n];
}
printf("for f=%f ,ans is=%f",f,d);
 }
 
 
 
	else if(inputInter==3)
	{
		float x[100], y[100], xp, yp=0, p;
	 int i,j,n;

	 /* Input Section */
	 cout<<"Enter number of data: ";
	 cin>>n;
	 cout<<"Enter data:"<< endl;
	 for(i=1;i<=n;i++)
	 {
		  cout<<"x["<< i<<"] = ";
		  cin>>x[i];
		  cout<<"y["<< i<<"] = ";
		  cin>>y[i];
	 }
	 cout<<"Enter interpolation point: ";
	 cin>>xp;

	 /* Implementing Lagrange Interpolation */
	 for(i=1;i<=n;i++)
	 {
		  p=1;
		  for(j=1;j<=n;j++)
		  {
			   if(i!=j)
			   {
			    	p = p* (xp - x[j])/(x[i] - x[j]);
			   }
		  }
		  yp = yp + p * y[i];
	 }
	 cout<< endl<<"Interpolated value at "<< xp<< " is "<< yp;
}




  else if(inputInter==4)
  {
  	int n;                         
int i,j;                       
float ax[10];                   
float ay[10];                   
float x;                       
float nr,dr;
float y=0;                      
float h;                        
float p;                        
float diff[20][20];             
float y1,y2,y3,y4;              
cout<<"GAUSS' FORWARD INTERPOLATION FORMULA !! ";

cout<<"\nEnter the no. of terms";
cin>>n;
//cin>>"\n\n Enter the value in the form of x";
   cout<<"\n Enter the value in the form of x";

for(i=0;i<n;i++)
   {
   cout<<"\n Enter the value of x "<<i+1;
   cin>>ax[i];
   }


cout<<"\n Enter the value in the form of y";

for(i=0;i<n;i++)
   {
   cout<<"\n Enter the value of y"<<i+1;
   cin>>ay[i];
   }


cout<<"\n\n Enter the value of x for ";
cout<<"\n which u want the value of y";
cin>>x;


h=ax[1]-ax[0];
for(i=0;i<n-1;i++)
   diff[i][1]=ay[i+1]-ay[i];

for(j=2;j<=4;j++)
   for(i=0;i<n-j;i++)
      diff[i][j]=diff[i+1][j-1]-diff[i][j-1];

i=0;
do
 {
 i++;
 }
while(ax[i]<x);

i--;
p=(x-ax[i])/h;
y1=p*diff[i][1];
y2=p*(p-1)*diff[i-1][2]/2;
y3=(p+1)*p*(p-1)*diff[i-2][3]/6;
y4=(p+1)*p*(p-1)*(p-2)*diff[i-3][4]/24;


y=ay[i]+y1+y2+y3+y4;


cout<<"\t\t"<<x<<"\t\t"<<y;

} 



    else if(inputInter==5)
    {
  	 double y[20][20],x[20],sum,fy,xr;
   /* ARRAY OF y[n][n] ELEMENTS FOR DIVIDED DIFFERENCE TABLE */
    int i,j,k,n,t,m;
    printf("\n     NEWTON'S DIVIDED DIFFERENCES INTERPOLATION METHOD");
    printf("\n\nEnter the number of entries (max 20) = ");
   /* ENTER THE NUMBER OF ENTRIES IN THE TABLE   */
    scanf("%d",&n);
    for(i = 0; i < n; i++)
        {
           /*  LOOP TO GET x AND y = f(x) IN THE TABLE   */
            printf("x%d = ",i);
            scanf("%lf",&x[i]);
            printf("           y%d = ",i);
            scanf("%lf",&y[i][0]);
        }
    printf("\nEnter the value of xr at which y = f(x) is to be"
           " calculated xr = ");
    scanf("%lf",&xr);
    k = n;
    for(j = 1; j < n; j++)
        {
           /*  LOOP TO CALCULATE DIVIDED DIFFERENCES IN THE TABLE  */
            k = k - 1;
            for(i = 0; i < k; i++)
                {
                    y[i][j] = (y[i+1][j-1] - y[i][j-1])/(x[i+j]-x[i]);
                }
        }
    sum = 0;
    for(t = 1; t < n; t++)
        {
           /* LOOP TO CALCULATE INTERPOLATED VALUE OF 'y'  */
            fy = 1;
            for(m = 0; m < t; m++)
                {
                    fy = fy * (xr - x[m]);
                }
            sum = sum + (fy * y[0][t]);
        }
    sum = sum + y[0][0];
    printf("\nThe interpolated value of y at xr = %lf"
           " is yr = %lf\n",xr,sum);
  }
   else
	{
		printf("invalid input\n");
		goto exit12;
	}
	goto abcde;
	exit12:
		printf("\n");
	

}



//integration
else if(ch=='B')
{
	int input;
	abcdef:
  	printf("\nWelcome to the Solution of Integration\n");
	printf("choose your problem\n");
	printf("0: Invalid Input\n1: Area of trapizium\n");
	scanf("%d",&input);
	if(input==1)
	{	
	
/* Define function here */
#define s(x) 1/(1+pow(x,2))
 float lower, upper, integration=0.0, stepSize, k;
 int i, subInterval;
/*Input */
 printf("Enter lower limit of integration: ");
 scanf("%f", &lower);
 printf("Enter upper limit of integration: ");
 scanf("%f", &upper);
 printf("Enter number of sub intervals: ");
 scanf("%d", &subInterval);

 /* Calculation */
 /* Finding step size */
 stepSize = (upper - lower)/subInterval;

 /* Finding Integration Value */
 integration = s(lower) + s(upper);
 for(i=1; i<= subInterval-1; i++)
 {
  k = lower + i*stepSize;
  integration = integration + 2 * s(k);
 }
 integration = integration * stepSize/2;
 printf("\nRequired value of integration is: %.3f", integration);

}
	else
	{
		printf("invalid input\n");
		goto exit122;
	}
	goto abcdef;
	exit122:
		printf("\n");
	
	}	

//ODE
else if(ch=='C')
{
	int input;
	abcdeff:
  	printf("Welcome to the Solution of ODE\n");
	printf("choose your problem\n");
	printf("0: Invalid Input\n1:Bessels Method \n2:Simpson1/3 Method \n3:Booles Method\n");
	scanf("%d",&input);
	if(input==1)
	{
		
	float x[100], y[20][20], xp, yp=0, p;
	 int i,j,n;
	cout<<"Enter number of data: ";
	 cin>>n;
	 cout<<"Enter data:"<< endl;
	 for(i=1;i<=n;i++)
	 {
		  cout<<"x["<< i<<"] = ";
		  cin>>x[i];
		  cout<<"y["<< i<<"] = ";
		  cin>>y[i][0];
	 }
	
   for (int i = 1; i < n; i++)
      for (int j = 0; j < n - i; j++)
         y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
   float value;
   cout<<"Enter interpolation point:";
   cin>>value;
   
   float sum = (y[2][0] + y[3][0]) / 2;
   int index;
   if (n % 2)
      index = n/2;
   else
      index = n/2 - 1;
   float u = (value - x[index]) / (x[1] - x[0]);
   for (int i = 1; i < n; i++) {
      if (i % 2)
         sum+= (((u-(0.5))*calU(u, i - 1)*y[index][i])/factorial(i));
      else
         sum+= ((calU(u, i)*(y[index][i]+y[-- index][i])/(factorial(i)*2)));
   }
   cout<<"Value at "<<value<<" found using Bessels's interpolation is "<<sum;
	}
	
	
	else if(input==2)
	{
		float lower, upper, integration=0.0, stepSize, k;
 int i, subInterval;

 /* Input */
 cout<<"Enter lower limit of integration: ";
 cin>>lower;
 cout<<"Enter upper limit of integration: ";
 cin>>upper;
 cout<<"Enter number of sub intervals: ";
 cin>>subInterval;

 /* Calculation */

 /* Finding step size */
 stepSize = (upper - lower)/subInterval;

 /* Finding Integration Value */
 integration = f(lower) + f(upper);

 for(i=1; i<= subInterval-1; i++)
 {
  k = lower + i*stepSize;

  if(i%2==0)
  {
    integration = integration + 2 * (f(k));
  }
  else
  {
    integration = integration + 4 * (f(k));
  }

 }

 integration = integration * stepSize/3;

 cout<< endl <<"Required value of integration is: "<< integration;
	}
	
	
	
		else if(input==3)
		{
			int n = 4;
    int h;
    float a,b;
    cout<<"enter the lower limit";
    cin>>a;
    cout<<"enter the upper limit";
    cin>>b;
    
    
    // Computing the step size
    h = ((b - a) / n);
    float sum = 0;
 
    // Substituing a = 0, b = 4 and h = 1
    float bl = ((7 * f(a) +
                32 * f(a + h) +
                12 * f(a + 2 * h) +
                32 * f(a + 3 * h) +
                 7 * f(a + 4 * h)) * 2 * h / 45);
 
    sum = sum + bl;
    cout<< sum;
		}
		else
	{
		printf("invalid input\n");
		goto exit1222;
	}
	goto abcdeff;
	exit1222:
		printf("\n");
	
	}	
}

