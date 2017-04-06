/* 
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Assume that the total area is never beyond the maximum possible value of int.
*/

#include <iostream>
#include <set>

using namespace std;

// it is tedious and easy to make mistakes when considering all intersection situations
// think it anthor way
/*
int Intersect(int A, int B, int C, int D, int E, int F, int G, int H)
{
	if ((A == B && B == C && C == D) || (E == F && F == G && G == H)) return -1; // point
	else if (F <= B && B <= H && E <= C && C <= G) return 1;
	else if (E <= A && A <= G && F <= B && B <= H) return 2;
	else if (E <= A && A <= G && F <= D && D <= H) return 3;
	else if (E <= C && C <= G && F <= D && D <= H) return 4;
	else if (E <= A && A <= G && E <= C && C <= G) return 5;
	else if (E <= C && C <= G && F <= D && D <= H) return 6;
	else return 0;
}
*/

/*
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
{
	int area = (C-A)*(D-B)+(G-E)*(H-F);
	int situation = Intersect(A, B, C, D, E, F, G, H), intersection = 0;
	cout<<"situation: "<<situation<<endl;
	if (situation == -1)
	{
		intersection = 0;
	}
	else if (situation == 1)
	{
		intersection = (C-E)*(H-B);
	}
	else if (situation == 2)
	{
		intersection = (G-A)*(H-B);
	}
	else if (situation == 3)
	{
		intersection = (G-A)*(D-F);
	}
	else if (situation == 4)
	{
		intersection = (C-E)*(D-F);
	}
	return area-intersection;
}
*/

// This method does not need to check if two rectangles overlap since the overlapping area will be zero if overlapping does not exist.
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
{
    int left = max(A,E), right = max(min(C,G), left); // consider no overlap at the same time
    int bottom = max(B,F), top = max(min(D,H), bottom);
    return (C-A)*(D-B) - (right-left)*(top-bottom) + (G-E)*(H-F);
}

// common solution
int computeArea2(int A, int B, int C, int D, int E, int F, int G, int H) 
{
	if (A >= G || B >= H || C <= E || D <=F) // no overlap
		return (C-A)*(D-B)+(G-E)*(H-F);
	else // overlap
	{
		int bl_x = max(A, E), bl_y = max(B, F), tr_x = min(C, G), tr_y = min(D, H); // find the overlap bottom left and top right
		int intersection = (tr_x-bl_x)*(tr_y-bl_y);
		return (C-A)*(D-B)+(G-E)*(H-F)-intersection;
	}
}

int main()
{
	cout<<"covered area: "<<computeArea(-3, 0, 3, 4, 0, -1, 9, 2)<<endl;
	//cout<<"covered area: "<<computeArea(2, 2, 4, 4, 2, 2, 4, 4)<<endl;
	//cout<<"covered area: "<<computeArea(0, 0, 0, 0, -1, -1, 1, 1)<<endl;
	//cout<<"covered area: "<<computeArea2(0, 0, 0, 0, 1, 1, 1, 1)<<endl;
	return 0;
}
