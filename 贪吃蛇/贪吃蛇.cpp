#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <limits>

using namespace std;

int sum0 = 0;
int x1, yy1, x2, y2;
bool st[20][20][20][20];
int n;
bool q;//是否存在果实的标记
int long0 = 3;
int timer = 2;

struct rect {
    int a1;
    int b1;
    int a2;
    int b2;
}rects[50000000];
struct guoshi {
    int x;
    int y;
}_guoshi;
void fuzhi(int a1, int b1, int a2, int b2)//将使用过的坐标存入结构体
{
    rects[n].a1 = a1;
    rects[n].b1 = b1;
    rects[n].a2 = a2;
    rects[n].b2 = b2;
    n++;
}
void tushetoubu(int a1, int b1, int a2, int b2)//填充色块
{
    setfillcolor(RGB(82, 241, 83));
    if (a1 >= 0 && a2 >= 0 && b1 >= 0 && b2 > 0 && a1 <= 760 && a2 <= 760 && b1 <= 760 && b2 <= 760)
    {
        if (st[a1 / 40][b1 / 40][a2 / 40][b2 / 40] == false)
        {
            fillrectangle(a1, b1, a2, b2);
            sum0++;
            fuzhi(a1, b1, a2, b2);
            st[a1 / 40][b1 / 40][a2 / 40][b2 / 40] = true;
        }
    }
    setfillcolor(RGB(118, 227, 250));
}
void tushe(int a1, int b1, int a2, int b2)//填充色块
{
    settextcolor(BLACK);
    settextstyle(20, 10, _T("宋体"));
    TCHAR m[] = _T("wow");
    outtextxy(10, 60, m);
    if (timer <= 0)
    {
        cleardevice();
        settextcolor(RED);
        settextstyle(100, 50, _T("宋体"));
        outtextxy(180, 300, _T("Game Over!"));
        settextcolor(BLACK);
        settextstyle(50, 25, _T("宋体"));
        outtextxy(200, 400, _T("按任意键退出游戏"));
        if (_getch())
        {
            closegraph();
            exit(0);
        }
    }
    if (a1 >= 0 && a2 >= 0 && b1 >= 0 && b2 > 0 && a1 <= 760 && a2 <= 760 && b1 <= 760 && b2 <= 760)
    {
        if (st[a1 / 40][b1 / 40][a2 / 40][b2 / 40] == false)
        {
            fillrectangle(a1, b1, a2, b2);
            sum0++;
            fuzhi(a1, b1, a2, b2);
            st[a1 / 40][b1 / 40][a2 / 40][b2 / 40] = true;
            timer = 2;
        }
        else timer--;
    }
    else
        timer--;
}
void sheng() //生成果实
{
    setfillcolor(RGB(244, 170, 242));
    int x = rand() % 20 * 40 + 40;
    int y = rand() % 20 * 40 + 40;
    if (x - 40 >= 0 && x <= 760 && y - 40 >= 0 && y <= 760)
    {
        if (st[x / 40 - 1][y / 40 - 1][x / 40][y / 40] == false)
        {
            fillrectangle(x - 40, y - 40, x, y);
            q = 1;
            _guoshi.x = x;
            _guoshi.y = y;
        }
    }
    setfillcolor(RGB(118, 227, 250));
    if (q == 0)
        sheng();
}
void chushihua()//初始化生成长度为三的小蛇
{
    if (sum0 >= 2)
        return;
    int a = rand() % 4;//用随机数生成四个方向
    if (a == 0)
        tushe(x1 - 40, yy1, x2 - 40, y2);
    if (a == 1)
        tushe(x1 + 40, yy1, x2 + 40, y2);
    if (a == 2)
        tushe(x1, yy1 + 40, x2, y2 + 40);
    if (a == 3)
        tushe(x1, yy1 - 40, x2, y2 - 40);
    if (sum0 < 2)
        chushihua();
}
void clear(int m)
{
    setfillcolor(WHITE);
    fillrectangle(rects[m].a1, rects[m].b1, rects[m].a2, rects[m].b2);
    st[rects[m].a1 / 40][rects[m].b1 / 40][rects[m].a2 / 40][rects[m].b2 / 40] = false;
    setfillcolor(RGB(118, 227, 250));
}
int main()
{
    initgraph(800, 800);
    setorigin(20, 20);
    setbkcolor(WHITE);
    cleardevice();
    int x0 = 0;
    int y0 = 0;
    setlinecolor(BLACK);
    setfillcolor(RGB(118, 227, 250));
    srand((unsigned int)time(NULL));
    int c = rand() % 20 * 40 + 40;
    int d = rand() % 20 * 40 + 40;
    fillrectangle(c - 40, d - 40, c, d);
    x1 = c - 40;
    yy1 = d - 40;
    x2 = c;
    y2 = d;
    fuzhi(x1, yy1, x2, y2);
    st[x1 / 40][yy1 / 40][x2 / 40][y2 / 40] = true;
    for (int i = 0; i < 20; i++)
    {
        line(x0, 0, x0, 760);
        line(0, y0, 760, y0);
        x0 += 40;
        y0 += 40;
    }
    chushihua();
    char f;
    sheng();
    f = _getch();
    if (f == 'w')
        goto W;
    if (f == 's')
        goto S;
    if (f == 'a')
        goto A;
    if (f == 'd')
        goto D;
W:while (1)
{
    tushe(rects[n - 1].a1, rects[n - 1].b1 - 40, rects[n - 1].a2, rects[n - 1].b2 - 40);
    if (rects[n - 2].a1 == _guoshi.x - 40 && rects[n - 2].b1 == _guoshi.y)
    {
        if (rects[n - 2].a2 == _guoshi.x && rects[n - 2].b2 - 40 == _guoshi.y)
            long0++, q = 0, sheng();
    }
    if (n == 4)
        clear(1);
    else if (n == 5)
        clear(0);
    else
        clear(n - long0 - 1);
    Sleep(100);
    if (_kbhit())
    {
        f = _getch();
        if (f == 'a')
            goto A;
        if (f == 'd')
            goto D;
        if (f == 's');
    }
}
S:while (1)
{
    tushe(rects[n - 1].a1, rects[n - 1].b1 + 40, rects[n - 1].a2, rects[n - 1].b2 + 40);
    if (rects[n - 2].a1 == _guoshi.x - 40 && rects[n - 2].b1 + 40 == _guoshi.y - 40)
    {
        if (rects[n - 2].a2 == _guoshi.x && rects[n - 2].b2 + 40 == _guoshi.y)
            long0++, q = 0, sheng();
    }
    if (n == 4)
        clear(1);
    else if (n == 5)
        clear(0);
    else
        clear(n - long0 - 1);
    Sleep(100);
    if (_kbhit())
    {
        f = _getch();
        if (f == 'a')
            goto A;
        if (f == 'd')
            goto D;
        if (f == 'w');
    }
}
A: while (1)
{
    tushe(rects[n - 1].a1 - 40, rects[n - 1].b1, rects[n - 1].a2 - 40, rects[n - 1].b2);
    if (rects[n - 2].a1 == _guoshi.x && rects[n - 2].b1 == _guoshi.y - 40)
    {
        if (rects[n - 2].a2 - 40 == _guoshi.x && rects[n - 2].b2 == _guoshi.y)
            long0++, q = 0, sheng();
    }
    if (n == 4)
        clear(1);
    else if (n == 5)
        clear(0);
    else
        clear(n - long0 - 1);
    Sleep(100);
    if (_kbhit())
    {
        f = _getch();
        if (f == 'w')
            goto W;
        if (f == 's')
            goto S;
        if (f == 'd');
    }
}
D:while (1)
{
    tushe(rects[n - 1].a1 + 40, rects[n - 1].b1, rects[n - 1].a2 + 40, rects[n - 1].b2);
    if (rects[n - 2].a1 + 40 == _guoshi.x - 40 && rects[n - 2].b1 == _guoshi.y - 40)
    {
        if (rects[n - 2].a2 + 40 == _guoshi.x && rects[n - 2].b2 == _guoshi.y)
            long0++, q = 0, sheng();
    }
    if (n == 4)
        clear(1);
    else if (n == 5)
        clear(0);
    else
        clear(n - long0 - 1);

    Sleep(100);
    if (_kbhit())
    {
        f = _getch();
        if (f == 'w')
            goto W;
        if (f == 's')
            goto S;
        if (f == 'a');
    }
}
_getch();
return 0;
}

