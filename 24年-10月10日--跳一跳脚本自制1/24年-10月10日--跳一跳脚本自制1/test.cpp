#define _CRT_SECURE_NO_WARNINGS 1



//#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
//#include <conio.h>
//int main()
//{
//	initgraph(640, 480);	// ������ͼ���ڣ���СΪ 640x480 ����
//	circle(200, 200, 100);	// ��Բ��Բ��(200, 200)���뾶 100
//	_getch();				// �����������
//	closegraph();			// �رջ�ͼ����
//	return 0;
//}


#include<stdlib.h>
#include <easyx.h>
#include<stdio.h>
#include<math.h>

// ����ֵ
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
	// �ֻ���ͼ�����浽sdcard�ļ����£�����Ϊ1
	system("adb shell screencap -p /sdcard/1.png");
	// ���ֻ�����/sdcard/1.png��������
	system("adb pull /sdcard/1.png");
	// push �������е����ݴ��䵽�ֻ��Ķ�

	IMAGE image; //����һ��ͼƬ
	loadimage(&image, L"1.png", 1080, 2340);

	IMAGE img;
	// SetWorkingImage �����������õ�ǰ�Ĺ���ͼ��
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
	printf("�˵����� :px = %d , py = %d\n", px, py);

	//// ����ͼƬ
	//initgraph(900, 900);
	//SetWorkingImage(NULL);
	//putimage(0, 0, &img);
	//system("pause");

	return 0;
}


