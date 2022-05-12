#ifndef __POINT_H_
#define __POINT_H_

#include<iostream>

class Point
{
	private:
		int xpos,ypos;
	public:
		Point(int x=0,int y=0);
		friend std::ostream& operator<<(std::ostream& os,const Point& pos);
};

#endif
