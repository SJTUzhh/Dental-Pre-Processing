#include "widget.h"
#include "ui_widget.h"
#include "tooth.h"

#include <vtkGenericOpenGLRenderWindow.h>

#include <string>

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Widget)
{
	ui->setupUi(this);

	char *filename1[2] = { "D:/—¿≥›/2all.stl", "D:/—¿≥›/1all.stl" };
	char *filename2[2] = { "D:/—¿≥›/2.stl", "D:/—¿≥›/1.stl" };

	//window1 ÕÍ’˚—¿≥›
	readerall = vtkSmartPointer<vtkSTLReader>::New();
	readerall->SetFileName(filename1[up_or_low]);
	readerall->Update();
	allMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	allMapper->SetInputConnection(readerall->GetOutputPort());
	allMapper->Update();
	allActor = vtkSmartPointer<vtkActor>::New();
	allActor->SetMapper(allMapper);
	allRenderer = vtkSmartPointer<vtkRenderer>::New();
	allRenderer->SetViewport(0, 0, 1, 1);
	allRenderer->AddActor(allActor);
	allRenderer->SetBackground(1, 0, 0);
	Window1 = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	Window1->AddRenderer(allRenderer);
	ui->qvtkWidget->SetRenderWindow(Window1);
	//window2 »•µÙ—¿ˆ∏
    reader = vtkSmartPointer<vtkSTLReader>::New();
	reader->SetFileName(filename2[up_or_low]);
	reader->Update();
	originalMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	originalMapper->SetInputConnection(reader->GetOutputPort());
	originalMapper->Update();
	originalActor = vtkSmartPointer<vtkActor>::New();
	originalActor->SetMapper(originalMapper);
	originalRenderer = vtkSmartPointer<vtkRenderer>::New();
	originalRenderer->SetViewport(0, 0, 1, 1);
	originalRenderer->AddActor(originalActor);
	originalRenderer->SetBackground(1, 0, 0);
	Window2 = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	Window2->AddRenderer(originalRenderer);
	ui->qvtkWidget_2->SetRenderWindow(Window2);
	//window3 —¿≥›¡¨Õ®∑÷¡øÃ·»°
	originalMapper1 = vtkSmartPointer<vtkPolyDataMapper>::New();
	originalMapper1->SetInputConnection(reader->GetOutputPort());
	originalMapper1->Update();
	originalActor1 = vtkSmartPointer<vtkActor>::New();
	originalActor1->SetMapper(originalMapper1);
	originalRenderer1 = vtkSmartPointer<vtkRenderer>::New();
	originalRenderer1->SetViewport(0, 0, 0.25, 0.25);
	originalRenderer1->AddActor(originalActor1);
	originalRenderer1->SetBackground(1, 0, 0);
	for (int i = 0; i < 15; ++i)
	{
		connectivityFilter[i] = vtkSmartPointer<vtkPolyDataConnectivityFilter>::New();
		connectivityFilter[i]->SetInputConnection(reader->GetOutputPort());
		connectivityFilter[i]->SetExtractionModeToSpecifiedRegions();
		connectivityFilter[i]->AddSpecifiedRegion(i);
		connectivityFilter[i]->Update();
		extractedMapper[i] = vtkSmartPointer<vtkPolyDataMapper>::New();
		extractedMapper[i]->SetInputConnection(connectivityFilter[i]->GetOutputPort());
		extractedMapper[i]->Update();
		extractedActor[i] = vtkSmartPointer<vtkActor>::New();
		extractedActor[i]->SetMapper(extractedMapper[i]);
		Renderer[i] = vtkSmartPointer<vtkRenderer>::New();
		Renderer[i]->SetViewport(a[i+1]);
		Renderer[i]->AddActor(extractedActor[i]);
	}
	Renderer[0]->SetBackground(0, 1, 0);
	Renderer[1]->SetBackground(0, 0, 1);
	Renderer[2]->SetBackground(1, 1, 0);
	Renderer[3]->SetBackground(1, 0, 1);
	Renderer[4]->SetBackground(0, 1, 1);
	Renderer[5]->SetBackground(1, 0, 0);
	Renderer[6]->SetBackground(0, 1, 0);
	Renderer[7]->SetBackground(0, 0, 1);
	Renderer[8]->SetBackground(1, 1, 0);
	Renderer[9]->SetBackground(1, 0, 1);
	Renderer[10]->SetBackground(0, 1, 1);
	Renderer[11]->SetBackground(1, 0, 0);
	Renderer[12]->SetBackground(0, 1, 0);
	Renderer[13]->SetBackground(0, 0, 1);
	Renderer[14]->SetBackground(1, 1, 0);
	Renderer[15]->SetBackground(1, 0, 1);
	Window3 = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	Window3->AddRenderer(originalRenderer1);
	for (int i = 0; i < 15; ++i)
	{
		Window3->AddRenderer(Renderer[i]);
	}
	originalRenderer1->ResetCamera();
	for (int i = 0; i < 15; ++i)
	{
		Renderer[i]->SetActiveCamera(originalRenderer1->GetActiveCamera());
	}
	ui->qvtkWidget_3->SetRenderWindow(Window3);
	//window4 —¿≥›º∆ ˝
	int regionNum = connectivityFilter[0]->GetNumberOfExtractedRegions();
	std::cout << "regionNum:" << regionNum << endl;
	nameactor = vtkSmartPointer<vtkTextActor>::New();
	nameactor->GetTextProperty()->SetFontFamily(VTK_FONT_FILE);
	nameactor->GetTextProperty()->SetFontFile("D:/—¿≥›/FZSJ-WAMBJW.TTF");
	nameactor->GetTextProperty()->SetJustificationToCentered();
	nameactor->GetTextProperty()->SetVerticalJustificationToCentered();
	nameactor->GetTextProperty()->SetFontSize(54);
	nameactor->GetTextProperty()->SetColor(0.0, 1.0, 0.7);
	nameactor->SetInput(u8"Group E2");
	nameactor->SetPosition(300, 110);
	textSource0 = vtkSmartPointer<vtkVectorText>::New();
	textSource0->SetText(num[regionNum]);
	textSource0->Update();
	textmapper0 = vtkSmartPointer<vtkPolyDataMapper>::New();
	textmapper0->SetInputConnection(textSource0->GetOutputPort());
	textactor0 = vtkSmartPointer<vtkActor>::New();
	textactor0->SetMapper(textmapper0);
	textactor0->GetProperty()->SetColor(1.0, 1.0, 0.0);
	textactor0->GetProperty()->SetLineWidth(10);
	numRenderer = vtkSmartPointer<vtkRenderer>::New();
	numRenderer->SetViewport(0, 0, 1, 1);
	numRenderer->AddActor(textactor0);
	numRenderer->AddActor(nameactor);
	numRenderer->SetBackground(1, 0, 0);
	Window4 = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	Window4->AddRenderer(numRenderer);
	ui->qvtkWidget_4->SetRenderWindow(Window4);
	//window7 ∞¸Œß∫–
	auto colors = vtkSmartPointer<vtkNamedColors>::New();
	for (int i = 0; i < 15; i++)
	{
		polyData[i] = connectivityFilter[i]->GetOutput();
		obbTree[i] = vtkSmartPointer<vtkOBBTree>::New();
		obbTree[i]->SetDataSet(polyData[i]);
		obbTree[i]->SetMaxLevel(maxLevel);
		obbTree[i]->BuildLocator();
		obbTree[i]->ComputeOBB(polyData[i], corner[i], max[i], mid[i], min[i], size[i]);
		std::cout << "Corner" << i << ":\t"
			<< corner[i][0] << ", " << corner[i][1] << ", " << corner[i][2] << std::endl
			<< "Max" << i << ":\t"
			<< max[i][0] << ", " << max[i][1] << ", " << max[i][2] << std::endl
			<< "Mid" << i << ":\t"
			<< mid[i][0] << ", " << mid[i][1] << ", " << mid[i][2] << std::endl
			<< "Min" << i << ":\t"
			<< min[i][0] << ", " << min[i][1] << ", " << min[i][2] << std::endl
			<< "Size" << i << ":\t"
			<< size[i][0] << ", " << size[i][1] << ", " << size[i][2] << std::endl;
		polydata[i] = vtkSmartPointer<vtkPolyData>::New();
		obbTree[i]->GenerateRepresentation(0, polydata[i]);
		obbtreeMapper[i] = vtkSmartPointer<vtkPolyDataMapper>::New();
		obbtreeMapper[i]->SetInputData(polydata[i]);
		obbtreeActor[i] = vtkSmartPointer<vtkActor>::New();
		obbtreeActor[i]->SetMapper(obbtreeMapper[i]);
		obbtreeActor[i]->GetProperty()->SetInterpolationToFlat();
		obbtreeActor[i]->GetProperty()->SetOpacity(.5);
		obbtreeActor[i]->GetProperty()->EdgeVisibilityOn();
		obbtreeActor[i]->GetProperty()->SetColor(
			colors->GetColor4d("SpringGreen").GetData());
	}
	bounds = new double*[15];
	for (int i = 0; i < 15; ++i)
	{
		bounds[i] = new double[6];
	}
	for (int i = 0; i < 15; ++i)
	{
		polyData[i]->GetBounds(bounds[i]);
		std::cout << "Region" << i << "£∫" << std::endl
			<< "xmin: " << bounds[i][0] << " "
			<< "xmax: " << bounds[i][1] << " "
			<< "xmid: " << (bounds[i][0] + bounds[i][1]) / 2 << std::endl
			<< "ymin: " << bounds[i][2] << " "
			<< "ymax: " << bounds[i][3] << " "
			<< "ymid: " << (bounds[i][2] + bounds[i][3]) / 2 << std::endl
			<< "zmin: " << bounds[i][4] << " "
			<< "zmax: " << bounds[i][5] << " "
			<< "zmid: " << (bounds[i][4] + bounds[i][5]) / 2 << std::endl;
	}
	originalMapper2 = vtkSmartPointer<vtkPolyDataMapper>::New();
	originalMapper2->SetInputConnection(reader->GetOutputPort());
	originalMapper2->Update();
	originalActor2 = vtkSmartPointer<vtkActor>::New();
	originalActor2->SetMapper(originalMapper2);
	originalRenderer2 = vtkSmartPointer<vtkRenderer>::New();
	originalRenderer2->SetViewport(0, 0, 1, 1);
	originalRenderer2->AddActor(originalActor2);
	for (int i = 0; i < 15; ++i)
	{
		originalRenderer2->AddActor(obbtreeActor[i]);
	}
	originalRenderer2->AddActor(Axesactor);
	originalRenderer2->SetBackground(1, 0, 0);
	Window7 = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	Window7->AddRenderer(originalRenderer2);
	ui->qvtkWidget_7->SetRenderWindow(Window7);
	//window5 —¿≥›±‡∫≈
	int* p = identify(regionNum, bounds, up_or_low);
	originalMapper4 = vtkSmartPointer<vtkPolyDataMapper>::New();
	originalMapper4->SetInputConnection(reader->GetOutputPort());
	originalMapper4->Update();
	originalActor4 = vtkSmartPointer<vtkActor>::New();
	originalActor4->SetMapper(originalMapper4);
	originalActor4->GetProperty()->SetOpacity(0.3);
	for (int i = 0; i < regionNum; ++i)
	{
		textSource[i] = vtkSmartPointer<vtkVectorText>::New();
		textSource[i]->SetText(id[p[i]]);
		textSource[i]->Update();
		textmapper[i] = vtkSmartPointer<vtkPolyDataMapper>::New();
		textmapper[i]->SetInputConnection(textSource[i]->GetOutputPort());
		textactor[i] = vtkSmartPointer<vtkActor>::New();
		textactor[i]->SetMapper(textmapper[i]);
		textactor[i]->GetProperty()->SetColor(1.0, 0.0, 0.0);
		textactor[i]->GetProperty()->SetLineWidth(10);
		textactor[i]->GetProperty()->SetPointSize(10);
		textactor[i]->SetPosition(corner[i][0] + (max[i][0] + mid[i][0] + min[i][0]) / 2, corner[i][1] + (max[i][1] + mid[i][1] + min[i][1]) / 2, corner[i][2] + (max[i][2] + mid[i][2] + min[i][2]) / 2);
//		textactor[i]->SetPosition((bounds[i][0] + bounds[i][0]) / 2, (bounds[i][2] + bounds[i][3]) / 2, (bounds[i][4] + bounds[i][5]) / 2);
	}
	originalRenderer4 = vtkSmartPointer<vtkRenderer>::New();
	originalRenderer4->SetViewport(0, 0, 1, 1);
	originalRenderer4->AddActor(originalActor4);
	for (int i = 0; i < 15; ++i)
	{
		originalRenderer4->AddActor(textactor[i]);
	}
	Window5 = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	Window5->AddRenderer(originalRenderer4);
	ui->qvtkWidget_5->SetRenderWindow(Window5);
	//window6 —¿≥›»± ß«Èøˆ
	if (up_or_low == 0)
	{
		for (int i = 0; i < 8; ++i)
		{
			if (Find_arr_key(p, regionNum, 11 + i) == -1)
				miss.push_back(11 + i);
			if (Find_arr_key(p, regionNum, 21 + i) == -1)
				miss.push_back(21 + i);
		}
	}
	else
	{
		for (int i = 0; i < 8; ++i)
		{
			if (Find_arr_key(p, regionNum, 31 + i) == -1)
				miss.push_back(31 + i);
			if (Find_arr_key(p, regionNum, 41 + i) == -1)
				miss.push_back(41 + i);
		}
	}
	
	if (!miss.empty())
	{
		strcpy(final, id[miss[0]]);
		for (int i = 1; i < miss.size(); ++i)
		{
			cout << miss.size() << endl;
			strcat(final, id[miss[i]]);
		}
	}
	
	nameactor1 = vtkSmartPointer<vtkTextActor>::New();
	nameactor1->GetTextProperty()->SetFontFamily(VTK_FONT_FILE);
	nameactor1->GetTextProperty()->SetFontFile("D:/—¿≥›/FZSJ-WAMBJW.TTF");
	nameactor1->GetTextProperty()->SetJustificationToCentered();
	nameactor1->GetTextProperty()->SetVerticalJustificationToCentered();
	nameactor1->GetTextProperty()->SetFontSize(54);
	nameactor1->GetTextProperty()->SetColor(0.0, 1.0, 0.7);
	nameactor1->SetInput(u8"Group E2");
	nameactor1->SetPosition(300, 110);
	textSource1 = vtkSmartPointer<vtkVectorText>::New();
	textSource1->SetText(final);
	textSource1->Update();
	textmapper1 = vtkSmartPointer<vtkPolyDataMapper>::New();
	textmapper1->SetInputConnection(textSource1->GetOutputPort());
	textactor1 = vtkSmartPointer<vtkActor>::New();
	textactor1->SetMapper(textmapper1);
	textactor1->GetProperty()->SetColor(1.0, 1.0, 0.0);
	textactor1->GetProperty()->SetLineWidth(10);
	numRenderer1 = vtkSmartPointer<vtkRenderer>::New();
	numRenderer1->SetViewport(0, 0, 1, 0.5);
	numRenderer1->AddActor(textactor1);
	numRenderer1->AddActor(nameactor1);
	numRenderer1->SetBackground(1, 0, 0);
	textSource2 = vtkSmartPointer<vtkVectorText>::New();
	textSource2->SetText(missorcomplete[0]);
	textSource2->Update();
	textmapper2 = vtkSmartPointer<vtkPolyDataMapper>::New();
	textmapper2->SetInputConnection(textSource2->GetOutputPort());
	textactor2 = vtkSmartPointer<vtkActor>::New();
	textactor2->SetMapper(textmapper2);
	textactor2->GetProperty()->SetColor(1.0, 1.0, 0.0);
	textactor2->GetProperty()->SetLineWidth(10);
	numRenderer2 = vtkSmartPointer<vtkRenderer>::New();
	numRenderer2->SetViewport(0, 0.5, 1, 1);
	numRenderer2->AddActor(textactor2);
	numRenderer2->SetBackground(1, 0, 0);
	Window6 = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	Window6->AddRenderer(numRenderer1);
	Window6->AddRenderer(numRenderer2);
	ui->qvtkWidget_6->SetRenderWindow(Window6);
	//window8 ÷·œÚ
	if (up_or_low == 1)
	{
		line(0, 0);
		line(1, 0);
		line(2, 0);
		line(3, 0);
		line(4, 2);
		line(5, 1);
		line(6, 2);
		line(7, 2);
		line(8, 2);
		line(9, 2);
		line(10, 2);
		line(11, 2);
		line(12, 2);
		line(13, 2);
		line(14, 2);
	}
	else
	{
		line(0, 0);
		line(1, 0);
		line(2, 2);
		line(3, 1);
		line(4, 1);
		line(5, 2);
		line(6, 1);
		line(7, 1);
		line(8, 2);
		line(9, 2);
		line(10, 2);
		line(11, 2);
		line(12, 2);
		line(13, 2);
		line(14, 2);
	}
	Axesactor = vtkSmartPointer<vtkAxesActor>::New();
	Axesactor->SetPosition(0, 0, 0);
	Axesactor->SetTotalLength(20, 20, 20);
	Axesactor->SetShaftType(0);
	Axesactor->SetAxisLabels(0);
	Axesactor->SetCylinderRadius(0.02);
	originalMapper3 = vtkSmartPointer<vtkPolyDataMapper>::New();
	originalMapper3->SetInputConnection(reader->GetOutputPort());
	originalMapper3->Update();
	originalActor3 = vtkSmartPointer<vtkActor>::New();
	originalActor3->SetMapper(originalMapper3);
	originalRenderer3 = vtkSmartPointer<vtkRenderer>::New();
	originalRenderer3->SetViewport(0, 0, 1, 1);
	originalRenderer3->AddActor(originalActor3);
	for (int i = 0; i < 15; ++i)
	{
		originalRenderer3->AddActor(actor[i]);
	}
	originalRenderer3->AddActor(Axesactor);
	originalRenderer3->SetBackground(1, 0, 0);
	Window8 = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	Window8->AddRenderer(originalRenderer3);
	ui->qvtkWidget_8->SetRenderWindow(Window8);

	ui->qvtkWidget->hide();
	ui->qvtkWidget_2->hide();
	ui->qvtkWidget_3->hide();
	ui->qvtkWidget_4->hide();
	ui->qvtkWidget_5->hide();
	ui->qvtkWidget_6->hide();
	ui->qvtkWidget_7->hide();
	ui->qvtkWidget_8->hide();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
	ui->qvtkWidget->show();
	ui->qvtkWidget_2->hide();
	ui->qvtkWidget_3->hide();
	ui->qvtkWidget_4->hide();
	ui->qvtkWidget_5->hide();
	ui->qvtkWidget_6->hide();
	ui->qvtkWidget_7->hide();
	ui->qvtkWidget_8->hide();
}

void Widget::on_pushButton_2_clicked()
{
	ui->qvtkWidget->hide();
	ui->qvtkWidget_2->show();
	ui->qvtkWidget_3->hide();
	ui->qvtkWidget_4->hide();
	ui->qvtkWidget_5->hide();
	ui->qvtkWidget_6->hide();
	ui->qvtkWidget_7->hide();
	ui->qvtkWidget_8->hide();
}

void Widget::on_pushButton_3_clicked()
{
	ui->qvtkWidget->hide();
	ui->qvtkWidget_2->hide();
	ui->qvtkWidget_3->show();
	ui->qvtkWidget_4->hide();
	ui->qvtkWidget_5->hide();
	ui->qvtkWidget_6->hide();
	ui->qvtkWidget_7->hide();
	ui->qvtkWidget_8->hide();
}

void Widget::on_pushButton_4_clicked()
{
	ui->qvtkWidget->hide();
	ui->qvtkWidget_2->hide();
	ui->qvtkWidget_3->hide();
	ui->qvtkWidget_4->show();
	ui->qvtkWidget_5->hide();
	ui->qvtkWidget_6->hide();
	ui->qvtkWidget_7->hide();
	ui->qvtkWidget_8->hide();
}

void Widget::on_pushButton_5_clicked()
{
	ui->qvtkWidget->hide();
	ui->qvtkWidget_2->hide();
	ui->qvtkWidget_3->hide();
	ui->qvtkWidget_4->hide();
	ui->qvtkWidget_5->show();
	ui->qvtkWidget_6->hide();
	ui->qvtkWidget_7->hide();
	ui->qvtkWidget_8->hide();
}

void Widget::on_pushButton_6_clicked()
{
	ui->qvtkWidget->hide();
	ui->qvtkWidget_2->hide();
	ui->qvtkWidget_3->hide();
	ui->qvtkWidget_4->hide();
	ui->qvtkWidget_5->hide();
	ui->qvtkWidget_6->show();
	ui->qvtkWidget_7->hide();
	ui->qvtkWidget_8->hide();
}

void Widget::on_pushButton_7_clicked()
{
	ui->qvtkWidget->hide();
	ui->qvtkWidget_2->hide();
	ui->qvtkWidget_3->hide();
	ui->qvtkWidget_4->hide();
	ui->qvtkWidget_5->hide();
	ui->qvtkWidget_6->hide();
	ui->qvtkWidget_7->show();
	ui->qvtkWidget_8->hide();
}

void Widget::on_pushButton_8_clicked()
{
	ui->qvtkWidget->hide();
	ui->qvtkWidget_2->hide();
	ui->qvtkWidget_3->hide();
	ui->qvtkWidget_4->hide();
	ui->qvtkWidget_5->hide();
	ui->qvtkWidget_6->hide();
	ui->qvtkWidget_7->hide();
	ui->qvtkWidget_8->show();
}

void Widget::line(int i, int flag)
{
	switch (flag)
	{
	case 0:
	{
		lineSource[i] = vtkSmartPointer<vtkLineSource>::New();
		lineSource[i]->SetPoint1(corner[i][0] + (max[i][0] + mid[i][0]) / 2 - min[i][0], corner[i][1] + (max[i][1] + mid[i][1]) / 2 - min[i][1], corner[i][2] + (max[i][2] + mid[i][2]) / 2 - min[i][2]);
		lineSource[i]->SetPoint2(corner[i][0] + (max[i][0] + mid[i][0]) / 2 + 2 * min[i][0], corner[i][1] + (max[i][1] + mid[i][1]) / 2 + 2 * min[i][1], corner[i][2] + (max[i][2] + mid[i][2]) / 2 + 2 * min[i][2]);
		lineSource[i]->Update();

		break;
	}
	case 1:
	{
		lineSource[i] = vtkSmartPointer<vtkLineSource>::New();
		lineSource[i]->SetPoint1(corner[i][0] + (max[i][0] + min[i][0]) / 2 - mid[i][0], corner[i][1] + (max[i][1] + min[i][1]) / 2 - mid[i][1], corner[i][2] + (max[i][2] + min[i][2]) / 2 - mid[i][2]);
		lineSource[i]->SetPoint2(corner[i][0] + (max[i][0] + min[i][0]) / 2 + 2 * mid[i][0], corner[i][1] + (max[i][1] + min[i][1]) / 2 + 2 * mid[i][1], corner[i][2] + (max[i][2] + min[i][2]) / 2 + 2 * mid[i][2]);
		lineSource[i]->Update();
		break;
	}
	case 2:
	{
		lineSource[i] = vtkSmartPointer<vtkLineSource>::New();
		lineSource[i]->SetPoint1(corner[i][0] + (min[i][0] + mid[i][0]) / 2 - max[i][0], corner[i][1] + (min[i][1] + mid[i][1]) / 2 - max[i][1], corner[i][2] + (min[i][2] + mid[i][2]) / 2 - max[i][2]);
		lineSource[i]->SetPoint2(corner[i][0] + (min[i][0] + mid[i][0]) / 2 + 2 * max[i][0], corner[i][1] + (min[i][1] + mid[i][1]) / 2 + 2 * max[i][1], corner[i][2] + (min[i][2] + mid[i][2]) / 2 + 2 * max[i][2]);
		lineSource[i]->Update();
		break;
	}
	}
		mapper[i] = vtkSmartPointer<vtkPolyDataMapper>::New();
		mapper[i]->SetInputConnection(lineSource[i]->GetOutputPort());
		mapper[i]->Update();
		actor[i] = vtkSmartPointer<vtkActor>::New();
		actor[i]->SetMapper(mapper[i]);
		actor[i]->GetProperty()->SetColor(0, 1, 1);
		actor[i]->GetProperty()->SetLineWidth(10);
}

