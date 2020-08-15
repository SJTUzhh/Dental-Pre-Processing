/********************************************************************************
** Form generated from reading UI file 'widgetNhIGxv.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WIDGETNHIGXV_H
#define WIDGETNHIGXV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "QVTKOpenGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
	QVTKOpenGLWidget *qvtkWidget;
	QPushButton *pushButton;
	QPushButton *pushButton_2;
	QPushButton *pushButton_3;
	QVTKOpenGLWidget *qvtkWidget_2;
	QPushButton *pushButton_4;
	QPushButton *pushButton_5;
	QPushButton *pushButton_6;
	QPushButton *pushButton_7;
	QPushButton *pushButton_8;
	QVTKOpenGLWidget *qvtkWidget_3;
	QVTKOpenGLWidget *qvtkWidget_4;
	QVTKOpenGLWidget *qvtkWidget_5;
	QVTKOpenGLWidget *qvtkWidget_6;
	QVTKOpenGLWidget *qvtkWidget_7;
	QVTKOpenGLWidget *qvtkWidget_8;

	void setupUi(QWidget *Widget)
	{
		if (Widget->objectName().isEmpty())
			Widget->setObjectName(QString::fromUtf8("Widget"));
		Widget->resize(1144, 888);
		qvtkWidget = new QVTKOpenGLWidget(Widget);
		qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));
		qvtkWidget->setGeometry(QRect(20, 20, 851, 871));
		pushButton = new QPushButton(Widget);
		pushButton->setObjectName(QString::fromUtf8("pushButton"));
		pushButton->setGeometry(QRect(950, 50, 101, 31));
		pushButton_2 = new QPushButton(Widget);
		pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
		pushButton_2->setGeometry(QRect(950, 110, 101, 31));
		pushButton_3 = new QPushButton(Widget);
		pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
		pushButton_3->setGeometry(QRect(950, 170, 101, 31));
		qvtkWidget_2 = new QVTKOpenGLWidget(Widget);
		qvtkWidget_2->setObjectName(QString::fromUtf8("qvtkWidget_2"));
		qvtkWidget_2->setGeometry(QRect(20, 20, 851, 871));
		pushButton_4 = new QPushButton(Widget);
		pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
		pushButton_4->setGeometry(QRect(950, 410, 101, 31));//950, 230, 101, 31
		pushButton_5 = new QPushButton(Widget);
		pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
		pushButton_5->setGeometry(QRect(950, 290, 101, 31));
		pushButton_6 = new QPushButton(Widget);
		pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
		pushButton_6->setGeometry(QRect(950, 350, 101, 31));
		pushButton_7 = new QPushButton(Widget);
		pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
		pushButton_7->setGeometry(QRect(950, 230, 101, 31));//950, 410, 101, 31
		pushButton_8 = new QPushButton(Widget);
		pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
		pushButton_8->setGeometry(QRect(950, 470, 101, 31));
		qvtkWidget_3 = new QVTKOpenGLWidget(Widget);
		qvtkWidget_3->setObjectName(QString::fromUtf8("qvtkWidget_3"));
		qvtkWidget_3->setGeometry(QRect(20, 20, 851, 871));
		qvtkWidget_4 = new QVTKOpenGLWidget(Widget);
		qvtkWidget_4->setObjectName(QString::fromUtf8("qvtkWidget_4"));
		qvtkWidget_4->setGeometry(QRect(20, 20, 851, 871));
		qvtkWidget_5 = new QVTKOpenGLWidget(Widget);
		qvtkWidget_5->setObjectName(QString::fromUtf8("qvtkWidget_5"));
		qvtkWidget_5->setGeometry(QRect(20, 20, 851, 871));
		qvtkWidget_6 = new QVTKOpenGLWidget(Widget);
		qvtkWidget_6->setObjectName(QString::fromUtf8("qvtkWidget_6"));
		qvtkWidget_6->setGeometry(QRect(20, 20, 851, 871));
		qvtkWidget_7 = new QVTKOpenGLWidget(Widget);
		qvtkWidget_7->setObjectName(QString::fromUtf8("qvtkWidget_7"));
		qvtkWidget_7->setGeometry(QRect(20, 20, 851, 871));
		qvtkWidget_8 = new QVTKOpenGLWidget(Widget);
		qvtkWidget_8->setObjectName(QString::fromUtf8("qvtkWidget_8"));
		qvtkWidget_8->setGeometry(QRect(20, 20, 851, 871));

		retranslateUi(Widget);

		QMetaObject::connectSlotsByName(Widget);
	} // setupUi

	void retranslateUi(QWidget *Widget)
	{
		Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
		pushButton->setText(QCoreApplication::translate("Widget", "\347\211\231\351\275\277\346\250\241\345\236\213", nullptr));
		pushButton_2->setText(QCoreApplication::translate("Widget", "\345\216\273\351\231\244\347\211\231\351\276\210", nullptr));
		pushButton_3->setText(QCoreApplication::translate("Widget", "\350\277\236\351\200\232\345\210\206\351\207\217\346\217\220\345\217\226", nullptr));
		pushButton_4->setText(QCoreApplication::translate("Widget", "\347\211\231\351\275\277\346\225\260\351\207\217", nullptr));
		pushButton_5->setText(QCoreApplication::translate("Widget", "FDI\347\211\231\344\275\215\350\241\250\347\244\272\346\263\225", nullptr));
		pushButton_6->setText(QCoreApplication::translate("Widget", "\347\211\231\351\275\277\347\274\272\345\244\261\346\203\205\345\206\265", nullptr));
		pushButton_7->setText(QCoreApplication::translate("Widget", "\345\214\205\345\233\264\347\233\222", nullptr));
		pushButton_8->setText(QCoreApplication::translate("Widget", "\350\275\264\345\220\221", nullptr));
	} // retranslateUi

};

namespace Ui {
	class Widget : public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WIDGETNHIGXV_H
