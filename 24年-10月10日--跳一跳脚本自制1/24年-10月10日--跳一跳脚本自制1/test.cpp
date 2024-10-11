#define _CRT_SECURE_NO_WARNINGS 1



//#include <graphics.h>		// 引用图形库头文件
//#include <conio.h>
//int main()
//{
//	initgraph(640, 480);	// 创建绘图窗口，大小为 640x480 像素
//	circle(200, 200, 100);	// 画圆，圆心(200, 200)，半径 100
//	_getch();				// 按任意键继续
//	closegraph();			// 关闭绘图窗口
//	return 0;
//}


#include<stdlib.h>
#include <easyx.h>
#include<stdio.h>
#include<math.h>

// 相似值
double isSamilar(unsigned long c1, unsigned long c2)
{
	int b1 = (c1 >> 16) & 0xff;
	int g1 = (c1 >> 8) & 0xff;
	int r1 = (c1)&0xff;

	int b2 = (c2 >> 16) & 0xff;
	int g2 = (c2 >> 8) & 0xff;
	int r2 = (c2) & 0xff;

	return sqrt(double((r1 - r2) * (r1 - r2) + (b1 - b2) * (b1 - b2) + (c1 - c2) * (c1 - c2)));
}
 
int main()
{
	// 手机截图并保存到sdcard文件夹下，命名为1
	system("adb shell screencap -p /sdcard/1.png");
	// 从手机中拉/sdcard/1.png到电脑中
	system("adb pull /sdcard/1.png");
	// push 将电脑中的数据传输到手机的端

	IMAGE image; //定义一张图片
	loadimage(&image, L"1.png", 1080, 2340);

	IMAGE img;
	// SetWorkingImage 函数用于设置当前的工作图像
	SetWorkingImage(&image);
	getimage(&img, 100, 700, 900, 900);

	SetWorkingImage(&img); // 900*900

	int px, py;
	unsigned long color;
	for (py = 899; py > 0; py--)
	{
		for (px = 0; px < 900; px++)
		{
			color = getpixel(px, py);
			if (color == RGB(56, 58, 100))
				break;
		}
		if (color == RGB(56, 58, 100))
			break;
	}
	printf("人的坐标 :px = %d , py = %d\n", px, py);

	//// 测试图片
	//initgraph(900, 900);
	//SetWorkingImage(NULL);
	//putimage(0, 0, &img);
	//system("pause");

	return 0;
}


