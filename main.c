#include"stdio.h"
#include"math.h"
#include"windows.h"
#include "winuser.h"
#define point POINT
#define 鼠标 mouse_event
#define 读取鼠标 GetCursorPos
#define   VK_v  0x56


//b=sqrt(a) means that b^2=a
int three();
int two();
int xy();
int hk();
int xiaoxi();
int CFDJ();
int sushu();
int runnian();
int SP(void);
int Three_(double x1, double x2, double x3, double *y1, double *y2, double *y3);
int XY_(double a, double b, double c);
int MaxMin_(double a, double b, double c, double* d, double* e, double* f, double* g);
int RunNianCalNew(int year);
int ShuangJi(int n);


//to choose whitch tools will be used
int main()
{
	int a, b = 0;//欢迎界面的用法选择
	printf("**欢迎使用宇宙中超级无敌无主角光环系统！！！**\n");
	printf("********************请按照提示输入*******************\n");
	Sleep(100);
	printf("系");
	Sleep(100);	printf("统");
	Sleep(100);	printf("启");
	Sleep(100);	printf("动");
	Sleep(100);	printf("中");
	Sleep(100);	printf("……\n");
	Sleep(1000);
	for (; b <= 5; b++)
	{
		Beep(8000, 500);
	}
	printf("剩余时间(s)：5");
	for (b = 5; b >= 0; b--)
	{
		printf("\b%d", b);
		Sleep(1000);
	}
	printf("\n\n");
	Beep(8000, 1000);
	while (1)
	{
		printf("\n\n1、使用三点式确定解析式\n2、使用顶点和另外一点确定解析式\n3、给出解析式算出与坐标轴的交点\n");
		printf("4、qq词云预处理（每格几行输出一行）\n");
		printf("5、自动点击\n");
		printf("6、验证是否为素数（只支持自然数）\n");
		printf("7、验证某一年是否为闰年\n");
		printf("8、QQ刷屏\n");
		scanf("%d", &a);
		switch (a)
		{
		case 0:
			exit(0);
			break;
		case 1:
			three();
			break;
		case 2:
			hk();
			break;
		case 3:
			xy();
			break;
		case 4:
			xiaoxi();
			break;
		case 5:
			CFDJ();
			break;
		case 6:
			sushu();
			break;
		case 7:
			runnian();
			break;
		case 8:
			SP();
			break;
		default:
			printf(" worning : please enter a right number!\n\n");
			break;
		}
	}
	return 0;
}  
int three()
{
	//calculate the coeffs (a,b,c) of function y = a*x^2 + b*x + c
		//according to three input coordinators (x1,y1),(x2,y2),(x3,y3)
	int right;
	double a, b, c;
	double x1, x2, x3;
	double y1, y2, y3;
a_:	printf("输入坐标，中间用空格隔开\n\n");
	printf("请输入第一个坐标（如：“x1 y1”）:");
	scanf("%lf %lf", &x1, &y1);
	printf("请输入第二个坐标（如：“x2 y2”）:");
	scanf("%lf %lf", &x2, &y2);
	printf("请输入第一个坐标（如：“x3 y3”）:");
	scanf("%lf %lf", &x3, &y3);
	right = Three_(x1, x2, x3, &y1, &y2, &y3);
	if (right == 1)
	{
		printf("这个不是二次函数！\n");
		goto a_;//重新运行一便这程序
	}
	else
	{
		printf("a=%lf\nb=%lf\nc=%lf\n", y1, y2, y3);
		XY_(y1, y2, y3);
		return 0;
	}
}
int hk()
{
	double h, k;
	double x1, y1;
	double a, b, c;
	printf("输入坐标，中间用空格隔开\n\n");
	printf("请输入顶点坐标（如：“x1 y1”）:");
	scanf("%lf %lf", &h, &k);
	printf("请输入另一个坐标（如：“x2 y2”）:");
	scanf("%lf %lf", &x1, &y1);
	a = (y1 - k) / ((x1 - h) * (x1 - h));
	b = (-2) * a * h;
	c = a * h * h + k;
	printf("a=%lf\nb=%lf\nc=%lf\n", a, b, c);
	XY_(a, b, c);
	return 0;
}
int xy()
{
	double x, y, z;
	printf("请输入a,b,c三个参数求出该二次函数最值、与x轴交点(空格隔开）：");
	scanf("%lf %lf %lf", &x, &y, &z);
	XY_(x, y, z);
	return 0;
}
int xiaoxi()
{
	FILE* fp = NULL;
	char fname[50];/* 用于存放文件名 */
	char line[1024];/* txt一行最多1024字符 */
	int a;
	int b = 0;//格几行输出一行字符；
	printf("输入文件名：");
	scanf("%s", &fname);

	fp = fopen(fname, "r"); /* 只供读取 */
	FILE* fp2 = fopen("output.txt", "a+");//打开并在指定地点创建只写文件。
	FILE* fp3 = fopen("rubbish.txt", "a+");//打开并在指定地点创建只写文件。
/*
FILE *fp = fopen("路径","写入模式");
"w"  =>  创建并写入（覆盖式写入）
"a"  =>  创建并写入（接续式写入）
"a+" =>     创建并写入（分行式写入）
*/
	printf("请输入隔几行输出一行字符（eg：输入3，将输出第一、四、七行):");
	scanf("%d", &a);
	if (NULL == fp)
	{
		printf("该文件名无效，即将退出！");
		Sleep(2000);
		return -1; /* 要返回错误代码 */
	}
	while (!feof(fp))
	{
		fgets(line, 1024, fp);
		printf("%s\n", line);
		if (b % a == 0)
		{
			fprintf(fp2, "%s", line);
		}
		else
		{
			fprintf(fp3, "%s", line);
		}
		b = b + 1;
	}

	Sleep(3000);
	return 0;
}
int CFDJ()
{
	{
		int a = 10000;
		int b;
		b = MessageBox(NULL, TEXT("*****即将开始重复点击，是否确定*****"), TEXT("重复点击"), MB_YESNO);
		if (b == 6)
		{
a_:			printf("请输入双击次数：");
			scanf_s("%d", &a);
			MessageBox(NULL, TEXT("*****五秒后开始重复点击*****"), TEXT("重复点击"), MB_OK);
			Sleep(5000);
			ShuangJi(a);
			b = MessageBox(NULL, TEXT("*****是否再次执行？*****"), TEXT("重复点击"), MB_YESNO);
			if (b == 6)
			{
				goto a_;
			}
			else
			{
				return 0;
			}

		}
		else
			return 0;
	}
}
int sushu()
{
	int m, i, k;
	printf("请输入一个需要验证的数：");
	scanf_s("%d", &m);
	k = sqrt(m)+1;
	for (i = 2; i <= k; i++)
	{
		if (m % i == 0)
			break;
	}
	if (i >= k)
		printf("%d是素数\n", m);
	else
		printf("%d不是素数\n", m);
	return 0;
}
int runnian()
{
	int a, b;
	printf("请输入您需要到的年份：");
	scanf_s("%d", &a);
	b = RunNianCalNew(a);
	if (b == 1)
	{
		printf("%d是闰年\n", a);
	}
	else
	{
		printf("%d不闰年\n", a);
	}
	return 0;
}
int SP(void)
{
	/* 读取文件内容 */
	char data[2000], data1[2000];
	int j, i;
	j = NULL;
	FILE* file = fopen("sendtext.txt", "r");
	if (!file)
	{
		printf("请将要发送的信息写到该文件目录下的 sendtext.txt 文件中\n如果没有，请新建一个sendtext.txt文件！\n");
		printf("注意：不能超过2000个字符，一个中文字等于2个字符，不能存在空格！");
		system("pause");
		printf("\n");
		return 0;
	}
	else if (!feof(file))
	{
		/* 读入文件数据 */
		fscanf(file, "%s", data);
		//替换原来的剪辑板数据
		if (OpenClipboard(NULL))//打开剪辑板
		{
			if (IsClipboardFormatAvailable(CF_TEXT))
			{
				HANDLE hClip;
				char* pBuf;
				EmptyClipboard();//清空剪辑板
				hClip = GlobalAlloc(GMEM_MOVEABLE, strlen(data) + 1);
				pBuf = (char*)GlobalLock(hClip);
				strcpy(pBuf, data);
				GlobalUnlock(hClip);//解锁
				SetClipboardData(CF_TEXT, pBuf);//写入新的剪辑板数据
				CloseClipboard();
				strcpy(data1, data);
			}
			else
				CloseClipboard();//关闭剪辑板
		}
	}
	fclose(file);//关闭文件
	printf("发送次数：");
	scanf("%d", &j);
	int result = MessageBox(NULL, TEXT("即将开始次数为%d的刷屏", j), TEXT("刷屏"), MB_ICONINFORMATION | MB_YESNO);
	if (result == 7)
	{
		return 0;
	}
	for (i = 0; i < j; i++)
	{
		keybd_event(VK_CONTROL, 0, 0, 0);
		keybd_event(VK_v, 0, 0, 0);
		keybd_event(VK_CONTROL, 0, 2, 0);
		keybd_event(VK_v, 0, 2, 0);
		keybd_event(VK_RETURN, 0, 0, 0);
		keybd_event(VK_RETURN, 0, 2, 0);
		Sleep(100);
	}
	printf("刷屏完毕！需要刷 %d 次 一共刷了 %d 次！\n", i, j);
	keybd_event(VK_CONTROL, 0, 2, 0);
	keybd_event(VK_v, 0, 2, 0);
	keybd_event(VK_RETURN, 0, 2, 0);
	system("pause");
	return 0;
}





int RunNianCalNew(int year)
{
	int b;

	b = year;

	if ((b % 4 == 0 && b % 100 != 0 || b % 400 == 0))
	{
		return 1;//是闰年
	}
	else
	{
		return 0;//不是
	}
}
int ShuangJi(int n)
{
	point a;
	long long int i = 0;
	GetCursorPos(&a);
	int x1 = a.x;
	int y1 = a.y;
	for (; i <= n; i++)
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN, x1, y1, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, x1, y1, 0, 0);
		Sleep(10);
		mouse_event(MOUSEEVENTF_LEFTDOWN, x1, y1, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, x1, y1, 0, 0);
		Sleep(10);
	}
	return 0;
}
int Three_(double x1, double x2, double x3, double *y1_, double *y2_, double *y3_)
//输入三个点坐标，返回的abc,abc为三个点的y坐标
{
	double a, b, c;
	double y1, y2, y3;
	double aup, adown;
	y1 = *y1_;	y2 = *y2_;	y3 = *y3_;
	if (x1 == x2 || x1 == x3 || x2 == x3)
	{
		printf("任意两个点的横坐标不能相同！\n");
	}
	else
	{
		aup = (y1 - y2) * (x2 - x3) - (y2 - y3) * (x1 - x2);
		adown = (x1 * x1 - x2 * x2) * (x2 - x3) - (x2 * x2 - x3 * x3) * (x1 - x2);
		a = aup / adown;

		aup = (y1 - y2) * (x2 * x2 - x3 * x3) - (y2 - y3) * (x1 * x1 - x2 * x2);
		adown = (x1 - x2) * (x2 * x2 - x3 * x3) - (x2 - x3) * (x1 * x1 - x2 * x2);
		b = aup / adown;

		c = y1 - a * x1 * x1 - b * x1;

		if (a == 0)
		{
			printf("这个函数不是二次函数！\n");
			return 1;
		}
		*y1_ = a;
		*y2_ = b;
		*y3_ = c;
	}
	return 0;
}
int XY_(double a, double b, double c)
//输入abc求出与x交点、顶点
{
	double d;
	double e;
	double f;
	double g;
b_:	if (a == 0)
{
	printf("该函数不是二次函数！\n");
	goto b_;
}
MaxMin_(a, b, c, &d, &e, &f, &g);
if (d == NULL)
{
	printf("该函数与x轴无交点！\n");
}
else
{
	printf("交点横坐标为：x1=%lf  ,x2=%lf\n", d, e);
}
if (a < 0)
{
	printf("该函数有最大值，X=%lf  时Ymax=%lf\n\n", f, g);
}
else
{
	printf("该函数有最小值，X=%lf  时Ymin=%lf\n\n", f, g);
}
return 0;
}
int MaxMin_(double a, double b, double c, double *d, double *e, double *f, double *g)
//输入了abc，d和e是交点坐标，fg为顶点坐标
{
	double delta, sqrtde, x1, x2, x;
	double y;
	delta = b * b - 4 * a * c;
	y = (-delta) / (4 * a);
	sqrtde = sqrt(delta);
	if (a == 0)
	{
		return 1;
	}
	x = (-b) / (2 * a);
	if (delta < 0)
	{
		*d = NULL;
		*e = NULL;
	}
	else //交点坐标
	{
		if (delta == 0)
		{
			*d = x;
			*e = x;
		}
		else
		{
			x1 = x - sqrtde / (2 * a);
			x2 = x + sqrtde / (2 * a);
			*d = x1;
			*e = x2;
		}
	}
		*f = x;  //顶点坐标
		*g = y;
		return 0;
}