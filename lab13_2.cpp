#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void plotImage(bool image[][M], int x, int y){
    if(x >= 0 && x < N && y >= 0 && y < M) image[x][y] = 1;
}

void updateImage(bool image[][M], int size, int x0, int y0)
{
    int r = size - 1;
    int l = 0;
    int border = floor(sin(M_PI / 4) * r);
    int dx = r;
    for(int dy = 0; dy <= min(border, M); dy++){
        if(sqrt(pow(dx, 2) + pow(dy, 2)) > r){
            dx--;
        }
        for(int i = dx; i >= l; i--){
            plotImage(image, x0 - i, y0 + dy);
            plotImage(image, x0 - dy, y0 + i);
            plotImage(image, x0 - i, y0 - dy);
            plotImage(image, x0 - dy, y0 - i);
            plotImage(image, x0 + i, y0 + dy);
            plotImage(image, x0 + dy, y0 + i);
            plotImage(image, x0 + i, y0 - dy);
            plotImage(image, x0 + dy, y0 - i);
        }
        l++;
        
    }
}

void showImage(const bool image[][M])
{
    cout << "------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "|";
        for (int j = 0; j < M; j++)
        {
            if (image[i][j] == 0)
                cout << " ";
            else
                cout << "*";
        }
        cout << "|" << endl;
    }
    cout << "------------------------------------------------------------------------" << endl;
}