#include<iostream.h>
#include<conio.h>
class complex
{
	private:
		int a,b;
	public:
		void setData(int x,int y)
		{
			a=x;b=y;
			cout<<"a->"<<a<<" b->"<<b;
		}
		friend complex operator +(complex,complex);
		friend complex operator *(complex,complex);
};
complex operator +(complex X,complex Y)
{
	complex temp;
	temp.a=X.a+Y.a;
	temp.b=X.b+Y.b;
	cout<<"\nAddition->"<<temp.a<<"+i"<<temp.b;
	return(temp);
}
complex operator *(complex X,complex Y)
{
	complex temp2;
	temp2.a=(Y.b*X.a)+(Y.a*X.b);
	temp2.b=(Y.b*X.b)+(Y.a*X.a);
	cout<<"\nProduct->"<<temp2.a<<"+i"<<temp2.b;
	return(temp2);
}
int main()
{
	clrscr();
	complex c1,c2,c3,c4;
	c1.setData(3,4);
	c2.setData(5,6);
	c3=c1+c2;
	c4=c1*c2;
	getch();
	return 0;
}