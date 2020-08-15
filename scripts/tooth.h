#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/*计算两点之间的距离在xz平面上的投影*/
double xz_distance(double a[], double b[]) {
	return  sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
}

/*牙齿类*/
class Tooth{//牙齿类里面保存的是其面片在m_FacetList中所处的索引，这样可节省内存
public:
	class AABB{ //圆柱体AABB包围盒
	public:
		double R, y_up, y_down;//底面半径、圆柱体顶部y坐标、圆柱体底部y坐标
		double center[3];//中心点
		AABB() {}
	};
	int original_order;
	AABB aabb;
	int name;//牙齿编号
	bool isNull;//是否为空牙齿
	Tooth() {}

	//中心点的x值越小，定义牙齿越“<”
	bool operator<(Tooth t) {
		if (this->aabb.center[0] < t.aabb.center[0]) return true;
		else return false;
	}
};

/*给定一系列bounds，按照bounds原先的顺序，返回对应的牙齿编号*/
//up_or_low：输入的模型是上颚(传入0)还是下颚(传入1); num_of_realTooth：连通分量的个数
int* identify(int num_of_realTooth, double** bound, int up_or_low) {
	/*建立牙齿队列*/
	vector<Tooth>TeethList;
	int right1;//第一颗右门牙的坐标
	for (int i = 0; i < num_of_realTooth; i++) {
		Tooth tmp;
		tmp.aabb.center[0] = (bound[i][0] + bound[i][1]) * 0.5;//x
		tmp.aabb.center[1] = (bound[i][2] + bound[i][3]) * 0.5;//y
		tmp.aabb.center[2] = (bound[i][4] + bound[i][5]) * 0.5;//z
		tmp.aabb.R = 0.5 * sqrt((bound[i][1] - bound[i][0]) * (bound[i][1] - bound[i][0]) + (bound[i][5] - bound[i][4]) * (bound[i][5] - bound[i][4]));
		tmp.isNull = false;
		tmp.aabb.y_up = bound[i][3];
		tmp.aabb.y_down = bound[i][2];
		tmp.original_order = i;//初始顺序
		TeethList.push_back(tmp);
	}
	sort(TeethList.begin(), TeethList.end());//按照牙齿中心点的x的值对牙齿进行排序
    /*从左往右扫描进行牙齿补齐*/
	//设计空牙齿是为了应付右门牙为空的情况
	//这个补齐过程补齐的牙齿仅限于内部缺牙时，如果是最左边或者是最右边的磨牙缺失，则无法补齐
	for (int i = 0; i < num_of_realTooth - 1; i++) {
		double sum_of_R = (TeethList[i].aabb.R + TeethList[i + 1].aabb.R);
		double xz_d = xz_distance(TeethList[i].aabb.center, TeethList[i + 1].aabb.center);
		if (xz_d > sum_of_R) {  //存在缺牙
			Tooth empty;		//补充一个空牙齿
			//空牙齿内部参数的赋值
			empty.aabb.center[0] = (TeethList[i].aabb.center[0] + TeethList[i + 1].aabb.center[0]) * 0.5;
			empty.aabb.center[1] = (TeethList[i].aabb.center[1] + TeethList[i + 1].aabb.center[1]) * 0.5;
			empty.aabb.center[2] = (TeethList[i].aabb.center[2] + TeethList[i + 1].aabb.center[2]) * 0.5;
			empty.aabb.R = (xz_d - sum_of_R) * 0.5;
			empty.aabb.y_down = (TeethList[i].aabb.y_down + TeethList[i + 1].aabb.y_down) * 0.5;
			empty.aabb.y_up = (TeethList[i].aabb.y_up + TeethList[i + 1].aabb.y_up) * 0.5;
			empty.isNull = true;
			//空牙齿不设置original_order

			TeethList.push_back(empty);//空牙齿入队
		}
	}
	sort(TeethList.begin(), TeethList.end());//添加了空牙齿后重新对牙齿队列按照center.x的大小进行排序

	/*找出center.x大于零且center.x最小的那颗牙齿的下标，即右半边的第一颗门牙*/
	//该方法可行的前提是：牙齿模型的z轴在牙模正中间
	right1 = TeethList.size() - 1;//初始化right1为最右边的牙齿
	for (int i = 0; i < TeethList.size(); i++) {
		if (TeethList[i].aabb.center[0] > 0) {
			right1 = i;
			break;//因为已经排好序了，第一个大于零的即为所求
		}
	}

	/*牙齿的命名，使用FDI牙位表示法*/
	//(以病人的角度定义左右)
	int quadrant;	//表示牙齿处于哪个象限；
					//右上：quadrant = 10
					//左上：quadrant = 20
					//左下：quadrant = 30
					//右下：quadrant = 40
	//右侧命名：
	if (up_or_low == 0) quadrant = 10;//右上
	else quadrant = 40;//右下
	for (int i = right1; i < TeethList.size(); i++) {
		TeethList[i].name = quadrant + i - right1 + 1;
	}
	//左侧命名：
	if (up_or_low == 0) quadrant = 20;//左上
	else quadrant = 30;//左下
	for (int i = right1 - 1; i >= 0; i--) {
		TeethList[i].name = quadrant + right1 - i;
	}
	/*返回编号*/
	int *bianhao = new int[16];//动态数组
	for (int i = 0; i < TeethList.size(); i++) {
		if (TeethList[i].isNull == true) continue;//空牙齿跳过
		bianhao[TeethList[i].original_order] = TeethList[i].name;
	}
	return bianhao;
}