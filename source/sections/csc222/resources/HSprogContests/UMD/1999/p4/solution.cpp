#include <iostream>
#include <math.h>
using namespace std;

#define ROWS 20
#define COLS 50

class FrameBuffer {
    private:
    char buf[ROWS][COLS];

    public:
        FrameBuffer(void) {
        clear();
    }

    void clear() {
        int x, y;

        for (y=0; y<ROWS; y++) {
            for (x=0; x<COLS; x++) {
                buf[y][x] = '.';
            }
        }
    }

    void drawLine(int x1, int y1, int x2, int y2) {
        float x, y;
        float m;
        float xinc, yinc;
        int i, j;
        int done;

        // If in quadrants 5-8, then reverse order to 
        // switch to quadrants 1-4
        if (y2 < y1) {
            int tx = x1;
            int ty = y1;
            x1 = x2;
            y1 = y2;
            x2 = tx;
            y2 = ty;
        }

        // First compute increments
        if (x1 != x2) {
            m = (float)fabs(((float)(y2 - y1)) / (float)(x2 - x1));
            if (m <= 1.0f) {
                // Octants 1, 4
                xinc = (x2 < x1) ? -1.0f : 1.0f;
                yinc = m;
            } else {
                // Octants 2, 3
                yinc = (y2 < y1) ? -1.0f : 1.0f;
                xinc = 1.0f / m * ((x2 < x1) ? -1.0f : 1.0f);
            }
        } else {
            // Vertical lines
            xinc = 0.0f;
            yinc = 1.0f;
        }

        // Then loop painting point
        x = (float)x1;
        y = (float)y1;
        done = 0;
        do {
            i = (int)(x + 0.5f);
            j = (int)(y + 0.5f);
            buf[j][i] = 'X';
            x += xinc;
            y += yinc;
            if ((i == x2) && (j == y2)) {
                done = 1;
            }
        } while (!done);
    }

    void print() {
        int x, y;

        for (y=0; y<ROWS; y++) {
            for (x=0; x<COLS; x++) {
                cout << buf[y][x];
            }
            cout << "\n";
        }
    }
};

int main(int argc, char* argv[])
{
    int x1, y1, x2, y2;
    FrameBuffer fb;

    while (true) {
        cin >> x1;
        if (x1 == -1)
            break;
        cin >> y1 >> x2 >> y2;
        fb.drawLine(x1, y1, x2, y2);
    }

    fb.print();

    return 0;
}
