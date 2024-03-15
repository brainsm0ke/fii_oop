#include "Canvas.h"
#include <iostream>

Canvas::Canvas(int width, int height){
	w = width;
	h = height;
	s.resize(w*h, ' ');
}

void Canvas::DrawCircle(int x, int y,int ray, char ch){
	int xn, yn;
	bool in = false;
	for(int i=0; i<w; i++){
		for(int j=0; j<h; j++){
			xn = j - x;
			yn = i - y;
			if(xn*xn + yn*yn <= ray*ray){
				if(in == false) SetPoint(i,j,ch);
				in = true;
			} else {
				if(in == true) SetPoint(i,j-1,ch);
				in = false;
			}
		}
	}
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			xn = i - x;
			yn = j - y;
			if(xn*xn + yn*yn <= ray*ray){
				if(in == false) SetPoint(j,i,ch);
				in = true;
			} else {
				if(in == true) SetPoint(j-1,i,ch);
				in = false;
			}
		}
	}
	
}

void Canvas::FillCircle(int x, int y, int ray, char ch){
	int xn, yn;
	for(int i=0; i<w; i++){
		for(int j=0; j<h; j++){
			xn = i - x;
			yn = j - y;
			if(xn*xn + yn*yn <= ray*ray){
				SetPoint(i,j,ch);
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch){
	for(int i=left; i<=right;i++){
		SetPoint(i,top,ch);
		SetPoint(i,bottom,ch);
	}
	for(int i=top; i<=bottom; i++){
		SetPoint(left,i,ch);
		SetPoint(right,i,ch);
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch){
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(i >= top && i <= bottom && j>= left && j <= right) SetPoint(j,i,ch);
		}
	}
}


void Canvas::SetPoint(int x, int y, char ch) {
	s[y*w+x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch){
	if(std::abs(x1-x2) > std::abs(y1-y2)){
		if(x1 > x2){
			int tx = x1;
			int ty = y1;
			x1 = x2;
			x2 = tx;
			y1 = y2;
			y2 = ty;
		}
		int dx = x2 - x1;
		int dy = y2 - y1;
		int yi = 1;
		if(dy < 0){
			yi = -1;
			dy = -dy;
		}
		int D = (2*dx) - dy;
		int y = y1;
		for(int x=x1; x<=x2; x++){
			SetPoint(x,y,ch);
			if(D>0){
				y += yi;
				D += 2*(dy-dx);
			} else D += 2*dy;
		}
	} else {
		if(y1 > y2){
			int tx = x1;
			int ty = y1;
			x1 = x2;
			x2 = tx;
			y1 = y2;
			y2 = ty;
		}
		int dx = x2 - x1;
		int dy = y2 - y1;
		int xi = 1;
		if(dx < 0){
			xi = -1;
			dx = -dx;
		}
		int D = (2*dx) - dy;
		int x = x1;
		for(int y=y1; y<=y2; y++){
			SetPoint(x,y,ch);
			if(D>0){
				x += xi;
				D += 2*(dx-dy);
			} else D += 2*dx;
		}
	}
}

void Canvas::Print() {
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			std::cout << s[i+j*h];
		}
		std::cout << '\n';
	}
}

void Canvas::Clear(){
	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
			s[i+j*h] = ' ';
}
