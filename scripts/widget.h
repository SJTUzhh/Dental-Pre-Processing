#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkActor.h>
#include <vtkConeSource.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkLight.h>
#include <vtkCamera.h>
#include <vtkActor2D.h>
#include <vtkTextActor.h>
#include <vtkProperty2D.h>
#include <vtkTextProperty.h>
#include <vtkBoxWidget.h>
#include <vtkVectorText.h>
#include <vtkTextSource.h>
#include <vtkVectorText.h>

#include <vtkAutoInit.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkConeSource.h>
#include <vtkAppendPolyData.h>
#include <vtkPolyDataConnectivityFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSTLReader.h>
#include <vtkOBBTree.h>
#include <vtkNamedColors.h>
#include <vtkAxesActor.h>
#include <vtkArrowSource.h>
#include <vtkLineSource.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkUnicodeString.h>
#include <vtkStdString.h>
#include <windows.h>
#include <string.h>
#include <vtkVectorText.h>
#include <vtkFollower.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkGenericOpenGLRenderWindow.h>



using namespace std;


namespace Ui {
	class Widget;
}

class Widget : public QWidget
{
	Q_OBJECT

public:
	explicit Widget(QWidget *parent = 0);
	~Widget();

private slots:
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();
	void on_pushButton_4_clicked();
	void on_pushButton_5_clicked();
	void on_pushButton_6_clicked();
	void on_pushButton_7_clicked();
	void on_pushButton_8_clicked();

private:
	Ui::Widget *ui;

	int up_or_low = 0;

	vtkSmartPointer<vtkGenericOpenGLRenderWindow> Window1;
	vtkSmartPointer<vtkSTLReader> readerall;
	vtkSmartPointer<vtkPolyDataMapper> allMapper;
	vtkSmartPointer<vtkActor> allActor;
	vtkSmartPointer<vtkRenderer> allRenderer;

	vtkSmartPointer<vtkGenericOpenGLRenderWindow> Window2;
	vtkSmartPointer<vtkSTLReader> reader;
	vtkSmartPointer<vtkPolyDataMapper> originalMapper;
	vtkSmartPointer<vtkActor> originalActor;
	vtkSmartPointer<vtkRenderer> originalRenderer;

	vtkSmartPointer<vtkGenericOpenGLRenderWindow> Window3;
	vtkSmartPointer<vtkPolyDataConnectivityFilter> connectivityFilter[15];
	vtkSmartPointer<vtkPolyDataMapper> extractedMapper[15];
	vtkSmartPointer<vtkActor> extractedActor[15];
	vtkSmartPointer<vtkRenderer> Renderer[15];
	vtkSmartPointer<vtkPolyDataMapper> originalMapper1;
	vtkSmartPointer<vtkActor> originalActor1;
	vtkSmartPointer<vtkRenderer> originalRenderer1;

	vtkSmartPointer<vtkGenericOpenGLRenderWindow> Window4;
	vtkSmartPointer<vtkRenderer> numRenderer;
	vtkSmartPointer<vtkVectorText> textSource0;
	vtkSmartPointer<vtkPolyDataMapper> textmapper0;
	vtkSmartPointer<vtkActor> textactor0;
	vtkSmartPointer<vtkTextActor> nameactor;

	vtkSmartPointer<vtkGenericOpenGLRenderWindow> Window5;
	vtkSmartPointer<vtkPolyDataMapper> originalMapper4;
	vtkSmartPointer<vtkActor> originalActor4;
	vtkSmartPointer<vtkRenderer> originalRenderer4;
	vtkSmartPointer<vtkVectorText> textSource[15];
	vtkSmartPointer<vtkPolyDataMapper> textmapper[15];
	vtkSmartPointer<vtkActor> textactor[15];
	char *num[49] = { "num:0","num:1","num:2","num:3","num:4","num:5","num:6","num:7","num:8","num:9","num:10","num:11","num:12","num:13","num:14","num:15","num:16",
	"num:17","num:18","num:19","num:20","num:21","num:22","num:23","num:24","num:25","num:26","num:27","num:28","num:29","num:30","num:31","num:32",
	"num:33","num:34","num:35","num:36","num:37","num:38","num:39","num:40","num:41","num:42","num:43","num:44","num:45","num:46","num:47","num:48" };

	char *id[49] = { "id:0","id:1","id:2","id:3","id:4","id:5","id:6","id:7","id:8","id:9","id:10","id:11","id:12","id:13","id:14","id:15","id:16",
	"id:17","id:18","id:19","id:20","id:21","id:22","id:23","id:24","id:25","id:26","id:27","id:28","id:29","id:30","id:31","id:32",
	"id:33","id:34","id:35","id:36","id:37","id:38","id:39","id:40","id:41","id:42","id:43","id:44","id:45","id:46","id:47","id:48" };

	char *missorcomplete[2] = { "miss","complete" };

	char final[100];

	vtkSmartPointer<vtkGenericOpenGLRenderWindow> Window6;
	vtkSmartPointer<vtkRenderer> numRenderer1;
	vtkSmartPointer<vtkVectorText> textSource1;
	vtkSmartPointer<vtkPolyDataMapper> textmapper1;
	vtkSmartPointer<vtkActor> textactor1;
	vtkSmartPointer<vtkRenderer> numRenderer2;
	vtkSmartPointer<vtkVectorText> textSource2;
	vtkSmartPointer<vtkPolyDataMapper> textmapper2;
	vtkSmartPointer<vtkActor> textactor2;
	vtkSmartPointer<vtkTextActor> nameactor1;
	vector<int> miss;
	int Find_arr_key(int arr[], int n, int key)
	{
		for (int i = 0; i < n; ++i)
		{
			if (arr[i] == key)
				return i;
		}
		return -1;
	}

	vtkSmartPointer<vtkGenericOpenGLRenderWindow> Window7;
	vtkSmartPointer<vtkPolyDataMapper> originalMapper2;
	vtkSmartPointer<vtkActor> originalActor2;
	vtkSmartPointer<vtkRenderer> originalRenderer2;
	vtkSmartPointer<vtkPolyData> polyData[15];
	vtkSmartPointer<vtkOBBTree> obbTree[15];
	vtkSmartPointer<vtkPolyData> polydata[15];
	vtkSmartPointer<vtkPolyDataMapper> obbtreeMapper[15];
	vtkSmartPointer<vtkActor> obbtreeActor[15];
	int maxLevel = 5;
	double **bounds;
	double corner[15][3] = { 0 };
	double max[15][3] = { 0 };
	double mid[15][3] = { 0 };
	double min[15][3] = { 0 };
	double size[15][3] = { 0 };
	
	
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> Window8;
	vtkSmartPointer<vtkPolyDataMapper> originalMapper3;
	vtkSmartPointer<vtkActor> originalActor3;
	vtkSmartPointer<vtkRenderer> originalRenderer3;
	vtkSmartPointer<vtkLineSource> lineSource[15];
	vtkSmartPointer<vtkPolyDataMapper> mapper[15];
	vtkSmartPointer<vtkActor> actor[15];
	vtkSmartPointer<vtkAxesActor> Axesactor;
	void line(int i, int flag);
	
	double a[16][4] = {
		{ 0.0,0.0,0.25,0.25 },
		{ 0.25,0.0,0.5,0.25 },
		{ 0.5,0.0,0.75,0.25 },
		{ 0.75,0.0,1.0,0.25 },
		{ 0.0,0.25,0.25,0.5 },
		{ 0.25,0.25,0.5,0.5 },
		{ 0.5,0.25,0.75,0.5 },
		{ 0.75,0.25,1.0,0.5 },
		{ 0.0,0.5,0.25,0.75 },
		{ 0.25,0.5,0.5,0.75 },
		{ 0.5,0.5,0.75,0.75 },
		{ 0.75,0.5,1.0,0.75 },
		{ 0.0,0.75,0.25,1.0 },
		{ 0.25,0.75,0.5,1.0 },
		{ 0.5,0.75,0.75,1.0 },
		{ 0.75,0.75,1.0,1.0 }
	};

};

#endif // WIDGET_H