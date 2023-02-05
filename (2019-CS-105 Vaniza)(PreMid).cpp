#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>
#include<stdlib.h>
#include<math.h>
#define EPSILON 0.001
#define   f(x)   x*x - 2*x + 1  //bisection
#define    h(x)    3*x - cos(x) -1 /* newton ripshon*/
#define   g(x)   3 + sin(x)  
#define    j(x)    x*x*x - 2*x - 5 //secant method
#define   k(x)   x*log10(x) - 1.2  //regular falsi

#define f1(x,y,z)  (17-y+2*z)/20//gacobi,seidal method
#define f2(x,y,z)  (-18-3*x+z)/20
#define f3(x,y,z)  (25-2*x+3*y)/20
#define   fn(x)   cos(x)-3*x+1//picard method
#define   gn(x)   (1+cos(x))/3
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
	printf("press 'A' for Solution of System of Non-Linear Equations\n ");
    printf("press 'B' for Solution of System of Linear Equations\n ");
    printf("press 'C' for interpolation\n ");
    printf("press 'D' for integration\n");
    printf("press 'E' for ODE\n");
    scanf("%c",&ch);
    /*Nonlinear************/
    if(ch=='A')
    {
	
    int input;
    abc:
	printf("Welcome to the Solution of System of Non-Linear Equations\n");
	printf("choose your problem\n");
	printf("0: Invalid Input\n1: Bisection method\n2: Newton Rapshon method \n3: Secant method\n4: Regular falsi method\n");
	scanf("%d",&input);
		
		
	
	if(input==1)
	{
	
		float x0, x1, x2, f0, f1, f2, e;
	 int step = 1;                                                                                                                                                                                                                                    
	 //clrscr();
	 /* Inputs */
	 upq:
	 printf("\nEnter two initial guesses:\n");
	 scanf("%f%f", &x0, &x1);
	 printf("Enter tolerable error:\n");
	 scanf("%f", &e);
	 /* Calculating Functional Value */
	 f0 = f(x0);
	 f1 = f(x1);
	 /* Checking whether given guesses brackets the root or not. */
	 if( f0 * f1 > 0.0)
	 {
		  printf("Incorrect Initial Guesses.\n");
		  goto upq;
	 }
   /* Implementing Bisection Method */
	 printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
	 do
	 {
		  x2 = (x0 + x1)/2;
		  f2 = f(x2);
		
		  printf("%d\t\t%f\t%f\t%f\t%f\n",step, x0, x1, x2, f2);
		
		  if( f0 * f2 < 0)
		  {
			   x1 = x2;  
			   f1 = f2;
		  }
		  else
		  {
			   x0 = x2;
			   f0 = f2;
		  }
		  step = step + 1;
	 }while(fabs(f2)>e);
	 printf("\nRoot is: %f\n", x2);
	 getch();
	}
	//newton  Ripshon method is oepn method
	else if(input==2)
	{
      
			 float x0, x1, f0, f1, g0, e;
	 int step = 1, N;
	 //clrscr();
     /* Inputs */
	 printf("\nEnter initial guess:\n");
	 scanf("%f", &x0);
	 printf("Enter tolerable error:\n");
	 scanf("%f", &e);
	 printf("Enter maximum iteration:\n");
	 scanf("%d", &N);
	 /* Implementing Newton Raphson Method */
	 printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
	 do
	 {
		  g0 = g(x0);
		  f0 = h(x0);
		  if(g0 == 0.0)
		  {
			   printf("Mathematical Error.");
			   exit(0);
		  }

		
		  x1 = x0 - f0/g0;

		
		  printf("%d\t\t%f\t%f\t%f\t%f\n",step,x0,f0,x1,f1);
		  x0 = x1;
		  
		  step = step+1;
		
		  if(step > N)
		  {
			   printf("Not Convergent.");
			   exit(0);
		  }
		  
		  f1 = h(x1);
		  
	 }while(fabs(f1)>e);
	
	 printf("\nRoot is: %f\n", x1);
	 getch();
	}
	//secant method
	else if(input==3)
	{
	
  

		 float x0, x1, x2, f0, f1, f2, e;
	 int step = 1, N;
	 printf("\nEnter initial guesses:\n");
	 scanf("%f%f", &x0, &x1);
	 printf("Enter tolerable error:\n");
	 scanf("%f", &e);
	 printf("Enter maximum iteration:\n");
	 scanf("%d", &N);
	
	
	 printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
	 do
	 {
		  f0 = j(x0);
		  f1 = j(x1);
		  if(f0 == f1)
		  {
			   printf("Mathematical Error.");
			   exit(0);
		  }
		  
		  x2 = x1 - (x1 - x0) * f1/(f1-f0);
		  f2 = j(x2);
		  
		  printf("%d\t\t%f\t%f\t%f\t%f\n",step,x0,x1,x2, f2);
		  
		  x0 = x1;
		  f0 = f1;
		  x1 = x2;
		  f1 = f2;
		  
		  step = step + 1;
		  
		  if(step > N)
		  {
			   printf("Not Convergent.");
			   exit(0);
		  }
	 }while(fabs(f2)>e);
	
	 printf("\nRoot is: %f\n", x2);
	 getch();
	}
	
	//regullar falsi
	else if(input==4)
	{
	
		float x0, x1, x2, f0, f1, f2, e;
	 int step = 1;
	
	 up:
	 printf("\nEnter two initial guesses:\n");
	 scanf("%f%f", &x0, &x1);
	 printf("Enter tolerable error:\n");
	 scanf("%f", &e);
	 /* Calculating Functional Values */
	 f0 = k(x0);
	 f1 = k(x1);
	 /* Checking whether given guesses brackets the root or not. */
	 if( f0*f1 > 0.0)
	 {
		  printf("Incorrect Initial Guesses.\n");
		  goto up;
	 }
	
	 printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
	 do
	 {
		  x2 = x0 - (x0-x1) * f0/(f0-f1);
		  f2 = k(x2);
		  printf("%d\t\t%f\t%f\t%f\t%f\n",step, x0, x1, x2, f2);
		
		  if(f0*f2 < 0)
		  {
			   x1 = x2;
			   f1 = f2;
		  }
		  else
		  {
			   x0 = x2;
			   f0 = f2;
		  }
		  step = step + 1;
	
	 }while(fabs(f2)>e);

	 printf("\nRoot is: %f\n", x2);
	 getch();
	}
	
	else
	{
		printf("invalid input\n");
		goto exit;
	}
	goto abc;
	exit:
		printf("\n");
}











//linear equation
   else if(ch=='B')
   {
   	 int inputL;
    abcd:
	printf("Welcome to the Solution of System of Linear Equations\n");
	printf("choose your problem\n");
	printf("0: Invalid Input\n1: Jaccobi method\n2: Guass Seidal method\n");
	scanf("%d",&inputL);		
	
	if(inputL==1)
	{


 float x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
 int count=1;
 //clrscr();
 printf("Enter tolerable error:\n");
 scanf("%f", &e);

 printf("\nCount\tx\ty\tz\n");
 do
 {
  /* Calculation */
  x1 = f1(x0,y0,z0);
  y1 = f2(x0,y0,z0);
  z1 = f3(x0,y0,z0);
  printf("%d\t%0.4f\t%0.4f\t%0.4f\n",count, x1,y1,z1);

  /* Error */
  e1 = fabs(x0-x1);
  e2 = fabs(y0-y1);
  e3 = fabs(z0-z1);

  count++;

  /* Set value for next iteration */
  x0 = x1;
  y0 = y1;
  z0 = z1;
 }while(e1>e && e2>e && e3>e);

 printf("\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n",x1,y1,z1);

   	
}
 else if(inputL==2)
 {

float x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
 int count=1;
 //clrscr();
 printf("Enter tolerable error:\n");
 scanf("%f", &e);

 printf("\nCount\tx\ty\tz\n");
 do
 {
  /* Calculation */
  x1 = f1(x0,y0,z0);
  y1 = f2(x1,y0,z0);
  z1 = f3(x1,y1,z0);
  printf("%d\t%0.4f\t%0.4f\t%0.4f\n",count, x1,y1,z1);

  /* Error */
  e1 = fabs(x0-x1);
  e2 = fabs(y0-y1);
  e3 = fabs(z0-z1);

  count++;

  /* Set value for next iteration */
  x0 = x1;
  y0 = y1;
  z0 = z1;

 }while(e1>e && e2>e && e3>e);

 printf("\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n",x1,y1,z1);

}
   else
	{
		printf("invalid input\n");
		goto exit1;
	}
	goto abcd;
	exit1:
		printf("\n");


}





//interpolation





  else if(ch=='C')
  {
  	
  	int inputInter;
    abcde:
	printf("Welcome to the Solution for interpolation\n");
	printf("choose your problem\n");
	printf("0: Invalid Input\n1: Newton forward\n2:Newton Backward\n");
	scanf("%d",&inputInter);

	
	 if(inputInter==1)
	{
		
	float ax[100], ay [100], diff[100][5], nr=1.0, dr=1.0,x,p,h,yp;
    int n,i,j,k;
    printf("\nEnter the value of n:\n");
    scanf("%d",&n);

    printf("\nEnter the values in form x,y:\n");
    for (i=0;i<=n;i++)
        scanf("%f %f",&ax[i],&ay[i]);
    printf("\nEnter the value of x for which the value of y is wanted: \n");
    scanf("%f",&x);
    h=ax[1]-ax[0];

    //now making the difference table
    //calculating the 1st order of differences
    for (i=0;i<=n-1;i++)
        diff[i][1] = ay[i+1]-ay[i];

    //now calculating the second and higher order differences
    for (j=2;j<=5;j++)
        for(i=0;i<=n-j;i++)
        diff[i][j] = diff[i+1][j-1] - diff[i][j-1];

    //now finding x0
    i=0;
    while (!(ax[i]>x))
        i++;

    //now ax[i] is x0 and ay[i] is y0
    i--;
    p = (x-ax[i])/h;
    yp = ay[i];

    //now carrying out interpolation
    for (k=1;k<=5;k++)
    {
        nr *=p-k+1;
        dr *=k;
        yp +=(nr/dr)*diff[i][k];
    }
    printf("\nWhen x = %6.1f, corresponding y = %6.2f\n",x,yp);
	}
	
	
	
	
	
	else if(inputInter==2)
	{
		
      float x[20],y[20],f,s,d,h,p;
      int j,i,k,n;
      printf("enter the value of the elements :");
      scanf("%d",&n);
      printf("enter the value of x: nn");
      for(i=1;i<=n;i++)
      {
                       scanf("%f",&x[i]);
                       }
             printf("enter the value of y: nn");
      for(i=1;i<=n;i++)
      {
                       scanf("%f",&y[i]);
                       }     
                       h=x[2]-x[1];
           printf("enter the searching point f:");                  
scanf("%f",&f);
s=(f-x[n])/h;
d=y[n];
p=1;
for(i=n,k=1;i>=1,k<n;i--,k++)
{
                 for(j=n;j>=1;j--)
                 {
                                 y[j]=y[j]-y[j-1];
                                 }
                                 p=p*(s+k-1)/k;
                                 d=d+p*y[n];
	}
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
else if(ch=='D')
{
	int input;
	abcdef:
  	printf("Welcome to the Solution of Integration\n");
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
	//integration
else if(ch=='E')
{
	int input;
	abcdeff:
  	printf("Welcome to the Solution of ODE\n");
	printf("choose your problem\n");
	printf("0: Invalid Input\n1:Eular Method\n2:Picard Method\n");
	scanf("%d",&input);
	if(input==1)
	{
 		float x0, y0, xn, h, yn, slope;
 int i, n;

 cout<<"Enter Initial Condition"<< endl;
 cout<<"x0 = ";
 cin>> x0;
// cout<<"y0 = ";
// cin >> y0;
 cout<<"Enter calculation point xn = ";
 cin>>xn;
 cout<<"Enter number of steps: ";
 cin>> n;

 /* Calculating step size (h) */
 h = (xn-x0)/n;

 /* Euler's Method */
 cout<<"\nx0\ty0\tslope\tyn\n";
 cout<<"------------------------------\n";

 for(i=0; i < n; i++)
 {
  slope = f(x0);
  yn = y0 + h * slope;
  cout<< x0<<"\t"<< y0<<"\t"<< slope<<"\t"<< yn<< endl;
  y0 = yn;
  x0 = x0+h;
 }

 /* Displaying result */
 cout<<"\nValue of y at x = "<< xn<< " is " << yn;
 
}
  else if(input==2)
  {
 int step=1, N;
	 float x0, x1, e;

	/* Setting precision and writing floating point values in fixed-point notation. */
	 cout<< setprecision(6)<< fixed;
	 /* Inputs */
	 cout<<"Enter initial guess: ";
	 cin>>x0;

	 cout<<"Enter tolerable error: ";
	 cin>>e;

	 cout<<"Enter maximum iteration: ";
	 cin>>N;

	 /* Implementing Fixed Point Iteration */
	 cout<< endl<<"**************************"<< endl;
	 cout<<"Picard Method"<< endl;
	 cout<<"**************************"<< endl;
	 do
	 {
		  x1 = gn(x0);
		  cout<<"Iteration-"<< step<<":\t x1 = "<< setw(10)<< x1<<" and f(x1) = "<< setw(10) << fn(x1);

		  step = step + 1;

		  if(step>N)
		  {
			   cout<<"Not Convergent.";
			   exit(0);
		  }

		  x0 = x1;

	 }while( fabs(fn(x1)) > e);

	 cout<< endl<<"Root is "<< x1;	
		
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
