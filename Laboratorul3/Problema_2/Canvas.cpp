#include "Canvas.h"
#include <iostream>

Canvas:: Canvas(int width, int height){
	this->width = width;
	this->height = height;
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			this->matrix[i][j] = ' ';
		}
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			if ((i - x) * (i - x) + (j - y) * (j - y) == ray * ray) {
				this->matrix[i][j] = ch;
			}
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray) {
				this->matrix[i][j] = ch;
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	if (left > right) {
		std:: swap(left, right);
	}
	if (top > bottom) {
		std::swap(top, bottom);
	}
	for (int i = left; i <= right; i++) {
		this->matrix[top][i] = ch;
		this->matrix[bottom][i] = ch;
	}

	for (int i = top; i < bottom; i++) {
		this->matrix[i][left] = ch;
		this->matrix[i][right] = ch;
	}

}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	if (left > right) {
		std::swap(left, right);
	}
	if (top > bottom) {
		std::swap(top, bottom);
	}
	for (int i = top; i < bottom; i++) {
		for (int j = left; j < right; j++) {
			this->matrix[i][j] = ch;
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch) {
	this->matrix[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
	this->matrix[x1][y1] = ch;
	int dx = x2 - x1;
	int dy = y2 - y1;
	int d = 2 * dy - dx, d_next; //variabile de decizie
	while (x1 != x2 || y1 != y2)
	{
		if (d > 0) {
			d_next = d + 2 * dy - 2 * dx;
			x1 = x1 + 1;
			y1 = y1 + 1;
			
			this->matrix[x1][y1] = ch;
			d = d_next;
		}
		else if(d < 0) {
			d_next = d + 2 * dy;
			x1 = x1 + 1;
			y1 = y1;
			
			this->matrix[x1][y1] = ch;
			d = d_next;
		}
	}


}

void Canvas::Print() {
	for (int i = 0; i < this->width; i++) {
		for (int j = 0; j < this->height; j++) {
			std::cout << this->matrix[i][j]<<" ";
		}
		std::cout << "\n";
	}
}

void Canvas::Clear() {
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			this->matrix[i][j] = ' ';
		}
	}
}
