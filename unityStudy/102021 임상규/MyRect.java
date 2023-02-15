import java.awt.*;

public class MyRect
{
	private Point pt;
	private int width, height;
	
	//method
	//1.constructor
	public MyRect(){
		pt = new Point(); //pt.x=0//pt.y=0
		width = 1;
		height =1;
	}
	public MyRect(Point pt){
		//pt = pt;
		this.pt = pt;
		width =1;
		height = 1;
	}
	public MyRect(int w,int h){
		pt = new Point();
		width = (w<1)?1:w;
		height = (h<1)?1:h;
	}
	public MyRect(Point pt,int w,int h){
		this.pt = pt;
		width = (w<1)?1:w;
		height = (h<1)?1:h;
	}
	public MyRect(int x,int y,int w,int h){
		pt = new Point();
		pt.x = x;
		pt.y =y;
		width = (w<1)?1:w;
		height = (h<1)?1:h;
	}
	
	//2.get/set
	public Point getPoint(){return pt;}
	public int getWidth(){return width;}
	public int getHeight(){return height;}
	public int getX() {return pt.x;}
	public int getY() {return pt.y;}
	
	public void setPoint(Point pt) {this.pt = pt;}
	public void setWidth(int w) {width = (w<1)?1:w;}
	public void setHeight(int h) {height = (h<1)?1:h;}
	public void setX(int x) {pt.x = x;}
	public void setY(int y) {pt.y = y;}
	public void setSize(int w,int h){
 		width = (w<1)?1:w;
		height = (h<1)?1:h;
 	}
 	public void setPosition(int x,int y){
 		pt.x=x;
 		pt.y=y;
 	}
 	public void setBounds(Point pt,int w,int h)
 	{
 		this.pt = pt;
 		width = (w<1)?1:w;
		height = (h<1)?1:h;
 	}
 	public void setBounds(int x,int y,int w,int h)
 	{
 		pt.x=x;
 		pt.y=y;
 		width = (w<1)?1:w;
		height = (h<1)?1:h;
 	}
 	//3.other
 	public int calcArea() {return (width*height);}
 	public int calcPerimeter() {return (width*2+height*2);}
	public boolean inPtInRect(Point pt)
	{
		if(this.pt.x <=pt.x && (this.pt.x+width)>=pt.x&&this.pt.y<=pt.y && (this.pt.y+height)>=pt.y)
			{return true;}
		else
		{return false;}
	}
	//4.toString()
	public String toString()
	{
		String str = "("+pt.x+", "+pt.y+", "+width+", "+height+")";
		return str;
	}
}