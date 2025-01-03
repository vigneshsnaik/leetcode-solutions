class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,int x2, int y2) {
        int X = max(x1, min(x2, xCenter)), Y = max(y1, min(y2, yCenter));
        int distX = xCenter - X, distY = yCenter - Y;
        return distX * distX + distY * distY <= radius * radius;
    }
};