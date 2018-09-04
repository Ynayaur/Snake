/*
*   又看代码
*   看你妹啊                      .. .vr
*                             qBMBBBMBMY
*                            8BBBBBOBMBMv
*                          iMBMM5vOY:BMBBv
*           .r,            OBM;   .: rBBBBBY
*           vUl            7BB   .;7. LBMMBBM.
*          .@Wwz           :uvir .i:.iLMOMOBM..
*          vv::r;             iY. ...rv,@arqiao.
*           Li. i:             v:.::::7vOBBMBL..
*           ,i7: vSUi,         :M7.:.,:uO8OP. .
*             .N2k5u1ju7,..     BMGiiL7   ,i,i.
*              :rLjFYjvjLY7r::.  ;v  vr...rE8q,.:,,
*             751jSLXPFu5uU@guohezou.,1vjY2E8@Yizero.
*             BB:FMu rkM8Eq0PFjF15FZOXu15F25uuLuu25Gi.
*           ivSvvXL    :v58ZOGZXF2UUkFSFkU1u125uUJUUZ.
*         :@kevensun       ,iY2OGOXSUXkSuS2F5XXkUX5SEv.
*     .:iOBMBMBBOOBMUi:,        ,:8PkFP5NkPXkFqPEqqkZu.
*   .rqMqBBMOMMBMBBBM .           @kexianli.S11kFSU5q5
* .7BBOi1L1MM8BBBOMBB..,          8kqS52XkkU1Uqkk1kUEJ
* .;MBZ:iiMBMBMMOBBBu ,           1OkS1F1X5kPP112F51kU
*   .rPY  OMBMBBBMBB2 ,.          rME5SSSFk1XPqFNkSUPZ,.
*          ;;JuBML::r:.:.,,        SZPXOSXSP5kXGNP15UBr.
*            L     :@sanshao.      :MNZqNXqSqXk2EOPSXPE.
*          vuLBX.,,v8Bj. i:r7:      2ZkqqOXXSNNONOXXSXOU
*        :r2. rMBGBMGi .7Y, 1i::i   vOOPMNNSXXEqP@Secbone.
*        .i1r. .jkY     vE. iY....  2OFqOq5X5F1S2F22uuv1M;
*/
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "head.h"


//首页显示
void FirstPage();
//检测开始
void Testspace();
//难度选择
void Difficuty();
//打印背景
void Printbackground();
//随机位置产生蛇
void Setsnake();
//画蛇
void Printsnake();
//倒计时
void Counttime();
//改变方向
void Changedirection();
//运动
void Snakemove();
//随机产生食物
int ProduceFood();
//蛇变长
void Growup();
//计分
void Countscore();
//死亡判断
int TestGameover();
//消除前一条蛇尾
void Killsnake();
//游戏结束初始化蛇，还原背景
void Killwholesnake();
//游戏结束
void Gameover();
//游戏通关
void Ac();
//初始化全局变量，重新开始
void Refresh();






int main(void)
{
	while (1) {
		system("cls");
		//重新开始的标记
		int flaga = 1;
		char c;
		int i=20;
		//初始化全局变量，重新开始
		Refresh();
		if (!g_flaga||hard==20) {
			//首页显示
			FirstPage();
			//检测开始
			Testspace();
			//难度选择
			Difficuty();
		}
		else {
			//初始化通关标记
			g_flaga = 0;
			//进入下一关
			hard = hard - 40;
		}
		//设置蛇的位置
		Setsnake();
		//显示蛇
		Printsnake();
		//游戏界面
		while (1) {  
			//产生食物
			ProduceFood();
			//显示背景
			Printbackground();		
			//显示得分
			Countscore();			
			//倒计时
			Counttime();			
			//蛇变长
			Growup();			
			//检测方向
			Changedirection();			
			//移动
			Snakemove();			
			//死亡检测
			if (TestGameover()) {
				Sleep(500);
				Gameover();
				//游戏结束初始化蛇，还原背景
				Killwholesnake();
				break;
			}
			//通关检测
			if (score == length -3) {
				Sleep(500);
				g_flaga = 1;
				Ac();
				//游戏结束初始化蛇，还原背景
				Killwholesnake();
				//清除蛇头，解决通关后蛇头无法清除的问题
				strncpy(&background[snake[0][0]][snake[0][1]], "  ", 2);
				break;
			}
			//难度设定
			Sleep(hard);
		}
		//检测是否继续开始
		while (1) {
			c = _getch();
			if (c == ' ') {
				flaga = 0;
				break;
			}
			if(c=='y' || c == 'Y') break;

		}

		if (flaga == 0)	break;

	}

	return 0;

}



//首页显示
void FirstPage()
{
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t      <欢迎进入贪吃蛇>\n\n\n");
	printf("\t\t\t\t\t\t<w a s d或方向键控制蛇的方向>\n\n\n");
	printf("\t\t\t\t\t\t      <按空格键以继续>\n");
}

//检测开始
void Testspace()
{
	char chinput;
	while (1) {
		chinput = _getch();
		if (chinput == ' ')	break;
	}
}
//难度选择
void Difficuty()
{
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t  请选择难度0-9（9为最简单）：");

	while (1) {
		hard = (int)_getch();
		if (hard <= 57 && hard >= 48)		break;
	}
	hard = (hard - 48) * 40 +20;
}

//打印边框1
/*void Printbackground1()
{
char a[20][23];
int i, j;


for (i = 0;i < 20;i++) {
for (j = 0;j < 23;j++) {
if (i == 0 || i == 19 || j == 0 || j == 22 || (i == 10 && j == 10) || (i == 10 && j == 11)) {
printf("■");
if (j == 22) printf("\n");
}

else printf("  ");
}
}
}*/

//打印边框2
/*void Printbackground2()
{
printf("■■■■■■■■■■■■■■■■■■■■■■■\n■                                          ■\n■                                          ■\n■                                          ■\n■                                          ■\n■                                          ■\n■                                          ■\n■                                          ■\n■                                          ■\n■                                          ■\n■                  ■■                    ■\n■                                          ■\n■                                          ■\n■                                          ■\n■                                          ■\n■                                          ■\n■                                          ■\n■                                          ■\n■                                          ■\n■■■■■■■■■■■■■■■■■■■■■■■\n");

}*/

//打印背景
void Printbackground()
{
	int i = 0;
	for (i = 0;i < 20;i++) {		
		//设置光标位置
		COORD position;
		position.X = 35;
		position.Y = 5 + i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		//打印背景
		printf(background[i]);
	}
}
//倒计时
void Counttime()
{
	int i;
	//设置光标位置
	COORD pos;
	pos.X = 90;
	pos.Y = 4;
	//进入倒计时的条件
	if (1 == flag) {
		flag = 0;
		//倒计时
		for (i = 3;i >= 0;i--) {
			Sleep(1000);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			printf("游戏将在%d秒后开始", i);
		}
		//清除倒计时字符
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		printf("                 ");
		//初始化初始方向改变量，解决在等待页面按方向键后再次开始初始方向改变的问题
		Changedirection();
		snakedirection = left;
	}
}

//随机位置产生蛇
void Setsnake()
{
	int nX = 0;
	int nY = 0;

	//种种子
	srand((unsigned int)time(NULL));

	//随机产生坐标
	nX = rand() % 15+4;
	nY = rand() % 18+1;

	//初始化蛇头
	snake[0][0] = nY;//行
	snake[0][1] = nX * 2;//列
	snake[0][2] = left;//初始方向
    //第二个节点
	snake[1][0] = nY;//行
	snake[1][1] = nX * 2 + 2;//列
	snake[1][2] = left;
	//第三个节点
	snake[2][0] = nY;//行
	snake[2][1] = nX * 2 + 4;//列
	snake[2][2] = left;
}

//画蛇
void Printsnake()
{
	int i = 0;
	if(i==0)	strncpy(&background[snake[i][0]][snake[i][1]], "□", 2);
	for (i = 1;snake[i][0] != 0;i++)	strncpy(&background[snake[i][0]][snake[i][1]], "■", 2);
}

//死亡判断
//int TestGameover()
//{
//	if (left == snake[0][2] || right == snake[0][2]) {
//		if (!strncmp(&background[snake[0][0]][snake[0][1] + snake[0][2]], "■", 2))		return 1;
//	}
//
//	else if (up == snake[0][2] || down == snake[0][2]) {
//		if (!strncmp(&background[snake[0][0] + snake[0][2]][snake[0][1]], "■", 2))		return 1;
//	}
//	return 0;
//}

//死亡判断
int TestGameover()
{
	int i=1;
	//撞边界
	if (snake[0][0] == 0 || snake[0][0] == 19 || snake[0][1] == 0 || snake[0][1] == 44) {
		strncpy(&background[snake[0][0]][snake[0][1]], "■", 2);
		return 1;
	}
	//撞自己
	for (i = 1;i <= lengthofsnake+1;i++) {
		if (snake[0][0] == snake[i][0] && snake[0][1] == snake[i][1]) {
			strncpy(&background[snake[0][0]][snake[0][1]], "  ", 2);
			return 1;
		}

	}
	return 0;
}

//游戏结束初始化蛇，还原背景
void Killwholesnake()
{
	int i = 0;
	//还原背景
	for (i = 1;i<=lengthofsnake;i++) {
		strncpy(&background[snake[i][0]][snake[i][1]], "  ", 2);
		//初始化蛇数组
		snake[i][0] = 0;
		snake[i][1] = 0;
		snake[i][2] = left;
	}
}

//消除前一条蛇的尾
void Killsnake()
{
	strncpy(&background[snake[lengthofsnake][0]][snake[lengthofsnake][1]], "  ", 2);
}

//改变方向
void Changedirection()
{
	//方向检测及方向改变
	if ((GetAsyncKeyState('W')|| (GetAsyncKeyState(VK_UP))) && snake[0][2] != down)	snakedirection = up;
	else if ((GetAsyncKeyState('S')  ||( GetAsyncKeyState(VK_DOWN))) && snake[0][2] != up)	snakedirection = down;
	else if ((GetAsyncKeyState('A') ||( GetAsyncKeyState(VK_LEFT)))&& snake[0][2] != right)	snakedirection = left;
	else if ((GetAsyncKeyState('D') ||( GetAsyncKeyState(VK_RIGHT)))&& snake[0][2] != left)	snakedirection = right;
	//检测暂停
	else if (GetAsyncKeyState('P')){
		//设置光标位置
		COORD position;
		position.X = 90;
		position.Y = 11;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

		system("pause");
		system("cls");
	}
}

//运动
void Snakemove()
{
	int i = length - 1;

	//清除前一条蛇尾
	Killsnake();

	for (i;i >= 1;i--) {
		if (snake[i][1] == 0)	continue;
		//把前一个节点，赋值给当前节点
			snake[i][0] = snake[i - 1][0];
			snake[i][1] = snake[i - 1][1];
			snake[i][2] = snake[i - 1][2];
	}
	//处理蛇头
	snake[0][2] = snakedirection;
	if (left == snake[0][2] || right == snake[0][2])	snake[0][1] += snake[0][2];
	else if (up == snake[0][2] || down == snake[0][2])  snake[0][0] += snake[0][2];

	//画蛇
	//Printsnake();
	//画蛇头
	strncpy(&background[snake[0][0]][snake[0][1]], "□", 2);
	strncpy(&background[snake[1][0]][snake[1][1]], "■", 2);

	//处理吃星时长长的问题
	if (food == 2 && Y == snake[0][0] && 2 * X == snake[0][1])
	strncpy(&background[snake[lengthofsnake -1][0]][snake[lengthofsnake - 1][1]], "■", 2);

	/*if (food == 2 && Y == snake[0][0] && 2 * X == snake[0][1]) {
		if (left == snake[0][2] || right == snake[0][2]) {
			strncpy(&background[snake[0][0]][snake[0][1] + snake[0][2]], "■", 2);
			strncpy(&background[snake[0][0]][snake[0][1]], "■", 2);
		}
		else if (up == snake[0][2] || down == snake[0][2]) {
			strncpy(&background[snake[0][0] + snake[0][2]][snake[0][1] ], "■", 2);
			strncpy(&background[snake[0][0]][snake[0][1]], "■", 2);
		}
	}
	else strncpy(&background[snake[0][0]][snake[0][1]], "■", 2);*/
}
//随机产生食物
int ProduceFood()
{
	int i = 0;
	int flag;

	//检测星是否出现
	if (food != 2) {
		//设置决定星是否出现的随机数
		srand((unsigned int)time(NULL));
		m = rand() % 2;
	}
	//星消失
	if (food == 2) {
		if (j == 0) {
			if(snake[0][0]==Y&&snake[0][1]==X)	strncpy(&background[Y][2 * X], "■", 2);
			else strncpy(&background[Y][2 * X], "  ", 2);
			food = 0;
		}
		j--;
	}
	//判断是否产生新食物
	if (food)	return 0;
	//随机产生食物坐
	for (;;) {
		flag = 1;
		srand((unsigned int)time(NULL));
		Y = rand() % 15 + 2;//18+1
		X = rand() % 17 + 2;//20+1
		//判断食物是否与蛇重合
		for (i = 0;snake[i][1] != 0;i++) {
			if (2 * X == snake[i][1] && Y == snake[i][0]) {
				flag = 0;
				break;
			}
		}
		if (flag)	break;
	}
	if (score < 3) {
		if (m != 0 || j == -1) {
			//画食物
			strncpy(&background[Y][2 * X], "■", 2);
			//食物标记
			food = 1;
			j = 0;
		}
	}
	else if (score >= 3) {
		if (m != 1 || j == -1) {
			//画食物
			strncpy(&background[Y][2 * X], "■", 2);
			//食物标记
			food = 1;
			j = 0;
		}
		//画星
		if (m == 1 && j != -1) {
			if (food == 0) {
				//画食物
				strncpy(&background[Y][2 * X], "★", 2);
				//食物标记
				food = 2;
				j = (((hard - 20) / 40 + 3)) * 3 + 10;


			}
		}
	}
}

//蛇变长
void Growup()
{
	if (Y == snake[0][0] && 2 * X == snake[0][1]) {

		if (left == snake[lengthofsnake][2]) {
			snake[lengthofsnake + 1][0] = snake[lengthofsnake][0];
			snake[lengthofsnake + 1][1] = snake[lengthofsnake][1] + 2;
			snake[lengthofsnake + 1][2] = snake[lengthofsnake][2];
			//处理吃星后蛇长长的问题
			if (food == 2) {
				snake[lengthofsnake + 2][0] = snake[lengthofsnake][0];
				snake[lengthofsnake + 2][1] = snake[lengthofsnake][1] + 4;
				snake[lengthofsnake + 2][2] = snake[lengthofsnake][2];
			}
		}
		if (right == snake[lengthofsnake][2]) {
			snake[lengthofsnake + 1][0] = snake[lengthofsnake][0];
			snake[lengthofsnake + 1][1] = snake[lengthofsnake][1] - 2;
			snake[lengthofsnake + 1][2] = snake[lengthofsnake][2];
			//处理吃星后蛇长长的问题
			if (food == 2) {
				snake[lengthofsnake + 2][0] = snake[lengthofsnake][0];
				snake[lengthofsnake + 2][1] = snake[lengthofsnake][1] - 4;
				snake[lengthofsnake + 2][2] = snake[lengthofsnake][2];
			}
		}
		if (up == snake[lengthofsnake][2]) {
			snake[lengthofsnake + 1][0] = snake[lengthofsnake][0] + 1;
			snake[lengthofsnake + 1][1] = snake[lengthofsnake][1];
			snake[lengthofsnake + 1][2] = snake[lengthofsnake][2];
			//处理吃星后蛇长长的问题
			if (food == 2) {
				snake[lengthofsnake + 2][0] = snake[lengthofsnake][0] + 2;
				snake[lengthofsnake + 2][1] = snake[lengthofsnake][1];
				snake[lengthofsnake + 2][2] = snake[lengthofsnake][2];
			}
		}
		if (down == snake[lengthofsnake][2]) {
			snake[lengthofsnake + 1][0] = snake[lengthofsnake][0] - 1;
			snake[lengthofsnake + 1][1] = snake[lengthofsnake][1];
			snake[lengthofsnake + 1][2] = snake[lengthofsnake][2];
			//处理吃星后蛇长长的问题
			if (food == 2) {
				snake[lengthofsnake + 2][0] = snake[lengthofsnake][0] - 2;
				snake[lengthofsnake + 2][1] = snake[lengthofsnake][1];
				snake[lengthofsnake + 2][2] = snake[lengthofsnake][2];
			}
		}
		//统计吃的食物
		if (food == 1)	foodb++;
		if (food == 2)	fooda++;
		//蛇数组
		lengthofsnake+=food;
		//分数
		score= score+food;
		//食物标记还原
		food = 0;

	}

}

//计分
void Countscore()
{
	//设置光标位置
	COORD position;
	position.X = 90;
	position.Y = 7;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	printf("     难度：%d",(hard-20)/40);

	//设置光标位置
	position.X = 90;
	position.Y = 11;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	printf("按P即可键暂停哦^0^");

	//隐藏光标
	CONSOLE_CURSOR_INFO	hideit;
	hideit.dwSize = sizeof(hideit);
	hideit.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &hideit);

	//设置光标位置
	position.X = 90;
	position.Y = 15;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	printf("    score:  %d", score * 10);

	//设置光标位置
	position.X = 90;
	position.Y = 19;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	printf("    ★   *   %d        %2d", fooda,j);

	//设置光标位置
	position.X = 90;
	position.Y = 23;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	printf("    ■   *   %d", foodb);
}

//游戏结束
void Gameover()
{
	int i = 0;
	COORD position;
	system("cls");
	printf("\t\t\t\t\t\t         Sorry! GameOver\n\t\t\t\t\t\t            score: %d", score * 10);
	if (hard == 340 || hard == 300 || hard == 260 || hard == 220 || hard == 180 || hard == 140 || hard == 100 || hard == 60 || hard == 20) {
		//设置光标位置
		position.X = 35;
		position.Y = 2 + i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		printf("*  这么简单都过不了的吗?          .. .vr\n ");
		for (i = 0;i < 24;i++) {
			//设置光标位置
			position.X = 35;
			position.Y = 3 + i;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
			printf(boomy[i]);
		}
		printf("\n\t\t\t\t\t\t\t\t        按空格键退出游戏，按'Y'键重新开始哦-.-");
	}
	if (hard == 380) {
		//设置光标位置
			position.X = 35;
			position.Y = 2 + i;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
			printf("* 这游戏也许真的不适合你           .. .vr\n ");
			for (i = 0;i < 24;i++) {
				//设置光标位置
				position.X = 35;
				position.Y = 3 + i;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				printf(boomy[i]);
		}
			printf("\n\t\t\t\t\t\t\t\t      按空格键退出游戏，按'Y'键重新开始哦-.-");

	}
	Sleep(3000);
}

//游戏通关
void Ac()
{
	int flagb = 0;
	//清屏
	system("cls");
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t      You Are Win！\n\n\n\t\t\t\t\t\t      score:  %d", score * 10);
	if (hard == 380 || hard == 340 || hard == 300 || hard == 260 || hard == 220 || hard == 180 || hard == 140 || hard == 100 || hard == 60) {
		printf("\n\n\n\t\t\t\t\t\t    Congratulations!\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t      按空格键有彩蛋哦！-.-");
		while (1) {
			if (_getch() == ' ') {
				flagb = 1;
				break;
			}
		}
		if (flagb == 1) {
			int i=0;
			//选择光标位置打印
			system("cls");
			COORD position;
			position.X = 35;
			position.Y = 2 + i;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
			printf("* 零级难度都没过就想要彩蛋-_-\n\t\t\t\t   *   \t\t想的美！\t .. .vr\n ");
			for (i = 0;i < 24;i++) {
				position.X = 35;
				position.Y = 3 + i;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				printf(boomy[i]);

			}
			printf("\n\n\t\t\t\t\t\t\t\t            按空格键退出游戏，按'Y'键进入下一关哦-.-");

		}
	}

	if (hard == 20) {
		printf("\n\n\n\n\t\t\t\t\t\t   应该没人到这吧=_=\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t 其实并没有什么彩蛋=_=\n\n");

		printf("\t\t\t\t\t\t\t\t\t   按空格键退出游戏，按'Y'键重新开始哦-.-");
	}

		Sleep(3000);

}

//初始化全局变量，重新开始
void Refresh()
{
	//清除上次未吃的食物
	if(food)	strncpy(&background[Y][2 * X], "  ", 2);
	//初始化蛇的脚标
	lengthofsnake = 2;
	//初始化分数
	score = 0;
	//初始化初始方向改变量，解决在结束页面按方向键后再次开始初始方向改变的问题
	Changedirection();
	snakedirection = left;
	//初始化食物标记
	food = 0;
	//初始化倒计时标记
	flag = 1;
	//两种食物的统计
	fooda = 0;
	foodb = 0;
	//星停留的时间
	j = 0;
}




