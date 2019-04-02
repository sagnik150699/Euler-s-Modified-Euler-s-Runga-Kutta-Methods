#include<stdio.h>
#include<math.h>
float f1(float x,float y,float h)
{
    return (h*(x+y));
}
void eulers(float x,float y,float a,float h)
{
    while(x<=a)
    {
        y=y+f1(x,y,h);
        x=x+h;
        printf("%0.3f \t%0.3f \n",x,y);
    }
}
float f2(float x,float y)
{
    return ((x*x)+(y*y*x));
}
void rk(float x,float y,float a,float h)
{
    float k1,k2,k3,k4,k;
    int i;
    float n=(a-x)/h;
    for(i=0;i<n;i++) 
    {
        k1=h*f2(x,y);
        k2=h*f2(x+(h/2),y+(k1/2));
        k3=h*f2(x+(h/2),y+(k2/2));
        k4=h*f2(x+h,y+k3);
        k=(k1+(2*k2)+(2*k3)+k4)/6;
        y=y+k;x=x+h;
    }
    printf("The required value= %.3f\n",y);
}
float f3(float x,float y)
{
    return ((x*x)+y);
}
void meulers(float x,float y,float a,float h)
{
    float m0;
    float k,t=0;
    float m1,m2,w;
    int i;
    printf("The respective values of x and y are...\n");
    printf("x \t y \n"); 
    for(i=0;x<=a;i++)
    {
        w=100;
        m0=f3(x,y);
        printf("%.3f\t%.3f\n",x,y);
        x=x+h;
        k=y;
        while(w>0.0001)
        {
            m1=f3(x,k);
            m2=(m0+m1)/2;
            t=y+(m2*h);
            w=k-t;
            w=fabs(w);
            k=t;
           // printf("%.3f\n",t);
        }
        y=t;
    }
}
int main()
{
    float x,y,a,h;
    printf("Enter a point (x,y)\n");
    scanf("%f%f",&x,&y);
    printf("Enter the x for which the value of y is to be found\n");
    scanf("%f",&a);
    printf("Enter value of h\n");
    scanf("%f",&h);
    printf("1-->Euler's\n2-->Modified eulers\n3-->Runga kutta\nEnter choice\n");
    int c;
    scanf("%d",&c);
    switch (c)
    {
        case 1:
            eulers(x,y,a,h);
            break;
        case 2:
            meulers(x,y,a,h);
            break;
        case 3:
            rk(x,y,a,h);
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}
