class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        int nx,ny;
        if(xc<x1) nx=x1;
        else if(x2<xc) nx=x2;
        else nx=xc;

        if(yc<y1) ny=y1;
        else if(y2<yc) ny=y2;
        else ny=yc;

        int dx=xc-nx;
        int dy=yc-ny;
        return (dx*dx)+(dy*dy)<=r*r;
    }
};
