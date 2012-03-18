/********************************************************************************
** Form generated from reading UI file 'scenegraphlib.ui'
**
** Created: Sun Mar 18 03:26:42 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCENEGRAPHLIB_H
#define UI_SCENEGRAPHLIB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "myanimationslider.h"
#include "mybutton.h"
#include "mycontrolbox.h"
#include "myframewidget.h"
#include "myglwidget.h"
#include "myslider.h"
#include "mytreewidget.h"

QT_BEGIN_NAMESPACE

class Ui_sceneGraphLibClass
{
public:
    QAction *actionQuit;
    QAction *actionReset_Graph;
    QAction *actionCreated_By_Michael_Rivera;
    QAction *actionCIS277_HW3;
    QAction *actionHello_Puppet_v1_0;
    QWidget *centralWidget;
    QPushButton *Button_Reset;
    QToolButton *remove;
    QToolButton *add;
    QLabel *X_scale;
    QLabel *translateLabel;
    QLabel *rotateLabel;
    MyGLWidget *widget;
    QLabel *Y_scale;
    QLabel *scaleLabel;
    QLabel *X_trans;
    QLabel *Y_stans;
    MyControlBox *controlBox_ScaleY;
    MyControlBox *controlBox_ScaleX;
    MyControlBox *controlBox_TranslateY;
    MyControlBox *controlBox_TranslateX;
    QFrame *line;
    MySlider *rotateSlider;
    MyTreeWidget *treeWidget;
    QFrame *line_3;
    QLabel *colorLabel;
    MySlider *redSlider;
    QFrame *line_4;
    MySlider *greenSlider;
    MySlider *blueSlider;
    QLabel *r;
    QLabel *G;
    QLabel *B;
    QLineEdit *lineEdit;
    QLabel *rotateLabel_2;
    QFrame *line_5;
    MySlider *geometrySlider;
    QLabel *rotateLabel_3;
    QLabel *rotateLabel_4;
    QLabel *rotateLabel_5;
    QFrame *line_6;
    QLabel *rotateLabel_6;
    QFrame *line_7;
    QLabel *rotateLabel_7;
    QLabel *rotateLabel_8;
    MySlider *nodeModeSlider;
    QLabel *rotateLabel_9;
    QLabel *rotate360;
    QLabel *rotate0;
    MyControlBox *controlBox_sideCount;
    QFrame *line_8;
    QFrame *line_9;
    QFrame *line_10;
    QFrame *line_12;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    MyFrameWidget *tableWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QCheckBox *checkBox;
    MyControlBox *controlBox_Frames;
    QPushButton *pushButton_3;
    QWidget *tab_6;
    QPushButton *pushButton_4;
    QLabel *rotateLabel_10;
    MyControlBox *controlBox_Frames_2;
    QPushButton *pushButton_5;
    MyAnimationSlider *animationSlider;
    MyButton *pushButton_6;
    QPushButton *pushButton_7;
    QLabel *rotateLabel_14;
    QFrame *line_13;
    QLabel *rotateLabel_15;
    MyControlBox *controlBox_Frames_3;
    QCheckBox *checkBox_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *sceneGraphLibClass)
    {
        if (sceneGraphLibClass->objectName().isEmpty())
            sceneGraphLibClass->setObjectName(QString::fromUtf8("sceneGraphLibClass"));
        sceneGraphLibClass->setEnabled(true);
        sceneGraphLibClass->resize(1023, 833);
        sceneGraphLibClass->setStyleSheet(QString::fromUtf8(""));
        actionQuit = new QAction(sceneGraphLibClass);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionReset_Graph = new QAction(sceneGraphLibClass);
        actionReset_Graph->setObjectName(QString::fromUtf8("actionReset_Graph"));
        actionCreated_By_Michael_Rivera = new QAction(sceneGraphLibClass);
        actionCreated_By_Michael_Rivera->setObjectName(QString::fromUtf8("actionCreated_By_Michael_Rivera"));
        actionCIS277_HW3 = new QAction(sceneGraphLibClass);
        actionCIS277_HW3->setObjectName(QString::fromUtf8("actionCIS277_HW3"));
        actionHello_Puppet_v1_0 = new QAction(sceneGraphLibClass);
        actionHello_Puppet_v1_0->setObjectName(QString::fromUtf8("actionHello_Puppet_v1_0"));
        centralWidget = new QWidget(sceneGraphLibClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Button_Reset = new QPushButton(centralWidget);
        Button_Reset->setObjectName(QString::fromUtf8("Button_Reset"));
        Button_Reset->setGeometry(QRect(80, 280, 81, 21));
        remove = new QToolButton(centralWidget);
        remove->setObjectName(QString::fromUtf8("remove"));
        remove->setGeometry(QRect(40, 720, 51, 21));
        add = new QToolButton(centralWidget);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(150, 720, 51, 21));
        X_scale = new QLabel(centralWidget);
        X_scale->setObjectName(QString::fromUtf8("X_scale"));
        X_scale->setGeometry(QRect(20, 410, 16, 20));
        translateLabel = new QLabel(centralWidget);
        translateLabel->setObjectName(QString::fromUtf8("translateLabel"));
        translateLabel->setGeometry(QRect(160, 380, 61, 16));
        rotateLabel = new QLabel(centralWidget);
        rotateLabel->setObjectName(QString::fromUtf8("rotateLabel"));
        rotateLabel->setGeometry(QRect(40, 490, 41, 16));
        widget = new MyGLWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(250, 10, 741, 491));
        widget->setStyleSheet(QString::fromUtf8("background: rgb(25, 25, 25);"));
        Y_scale = new QLabel(centralWidget);
        Y_scale->setObjectName(QString::fromUtf8("Y_scale"));
        Y_scale->setGeometry(QRect(20, 440, 16, 20));
        scaleLabel = new QLabel(centralWidget);
        scaleLabel->setObjectName(QString::fromUtf8("scaleLabel"));
        scaleLabel->setGeometry(QRect(50, 380, 31, 16));
        X_trans = new QLabel(centralWidget);
        X_trans->setObjectName(QString::fromUtf8("X_trans"));
        X_trans->setGeometry(QRect(140, 410, 16, 20));
        Y_stans = new QLabel(centralWidget);
        Y_stans->setObjectName(QString::fromUtf8("Y_stans"));
        Y_stans->setGeometry(QRect(140, 440, 16, 20));
        controlBox_ScaleY = new MyControlBox(centralWidget);
        controlBox_ScaleY->setObjectName(QString::fromUtf8("controlBox_ScaleY"));
        controlBox_ScaleY->setGeometry(QRect(40, 440, 51, 22));
        controlBox_ScaleY->setMinimum(-30);
        controlBox_ScaleY->setMaximum(30);
        controlBox_ScaleY->setSingleStep(0.1);
        controlBox_ScaleY->setValue(1);
        controlBox_ScaleX = new MyControlBox(centralWidget);
        controlBox_ScaleX->setObjectName(QString::fromUtf8("controlBox_ScaleX"));
        controlBox_ScaleX->setGeometry(QRect(40, 410, 51, 22));
        controlBox_ScaleX->setMinimum(-30);
        controlBox_ScaleX->setMaximum(30);
        controlBox_ScaleX->setSingleStep(0.1);
        controlBox_ScaleX->setValue(1);
        controlBox_TranslateY = new MyControlBox(centralWidget);
        controlBox_TranslateY->setObjectName(QString::fromUtf8("controlBox_TranslateY"));
        controlBox_TranslateY->setGeometry(QRect(160, 440, 51, 22));
        controlBox_TranslateY->setMinimum(-800);
        controlBox_TranslateY->setMaximum(800);
        controlBox_TranslateY->setSingleStep(5);
        controlBox_TranslateY->setValue(0);
        controlBox_TranslateX = new MyControlBox(centralWidget);
        controlBox_TranslateX->setObjectName(QString::fromUtf8("controlBox_TranslateX"));
        controlBox_TranslateX->setGeometry(QRect(160, 410, 51, 22));
        controlBox_TranslateX->setMinimum(-800);
        controlBox_TranslateX->setMaximum(800);
        controlBox_TranslateX->setSingleStep(5);
        controlBox_TranslateX->setValue(0);
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(110, 380, 20, 91));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        rotateSlider = new MySlider(centralWidget);
        rotateSlider->setObjectName(QString::fromUtf8("rotateSlider"));
        rotateSlider->setGeometry(QRect(50, 530, 20, 51));
        rotateSlider->setMaximum(360);
        rotateSlider->setOrientation(Qt::Vertical);
        treeWidget = new MyTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("Scene Graph"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(10, 10, 221, 261));
        treeWidget->setStyleSheet(QString::fromUtf8("gridline-color: rgb(85, 255, 255);\n"
"border-color: rgb(84, 84, 84);"));
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(110, 490, 20, 101));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        colorLabel = new QLabel(centralWidget);
        colorLabel->setObjectName(QString::fromUtf8("colorLabel"));
        colorLabel->setGeometry(QRect(160, 490, 41, 16));
        redSlider = new MySlider(centralWidget);
        redSlider->setObjectName(QString::fromUtf8("redSlider"));
        redSlider->setGeometry(QRect(150, 510, 61, 19));
        redSlider->setStyleSheet(QString::fromUtf8("QSlider::handle:horizontal {\n"
"     background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #FF0000, stop:1 #8f8f8f);\n"
"\n"
"     border: 1px solid #5c5c5c;\n"
"     width: 18px;\n"
"     margin: -2px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"     border-radius: 4px;\n"
"}"));
        redSlider->setMaximum(100);
        redSlider->setSingleStep(1);
        redSlider->setOrientation(Qt::Horizontal);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(10, 470, 221, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        greenSlider = new MySlider(centralWidget);
        greenSlider->setObjectName(QString::fromUtf8("greenSlider"));
        greenSlider->setGeometry(QRect(150, 540, 61, 19));
        greenSlider->setStyleSheet(QString::fromUtf8("QSlider::handle:horizontal {\n"
"     background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #00BB00, stop:1 #8f8f8f);\n"
"\n"
"     border: 1px solid #5c5c5c;\n"
"     width: 18px;\n"
"     margin: -2px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"     border-radius: 4px;\n"
"}"));
        greenSlider->setMaximum(100);
        greenSlider->setOrientation(Qt::Horizontal);
        blueSlider = new MySlider(centralWidget);
        blueSlider->setObjectName(QString::fromUtf8("blueSlider"));
        blueSlider->setGeometry(QRect(150, 570, 61, 19));
        blueSlider->setStyleSheet(QString::fromUtf8("QSlider::handle:horizontal {\n"
"     background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #000099, stop:1 #8f8f8f);\n"
"     border: 1px solid #5c5c5c;\n"
"     width: 18px;\n"
"     margin: -2px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"     border-radius: 4px;\n"
"}"));
        blueSlider->setMaximum(100);
        blueSlider->setOrientation(Qt::Horizontal);
        r = new QLabel(centralWidget);
        r->setObjectName(QString::fromUtf8("r"));
        r->setGeometry(QRect(210, 510, 16, 16));
        G = new QLabel(centralWidget);
        G->setObjectName(QString::fromUtf8("G"));
        G->setGeometry(QRect(210, 540, 16, 16));
        B = new QLabel(centralWidget);
        B->setObjectName(QString::fromUtf8("B"));
        B->setGeometry(QRect(210, 570, 16, 16));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 640, 91, 20));
        rotateLabel_2 = new QLabel(centralWidget);
        rotateLabel_2->setObjectName(QString::fromUtf8("rotateLabel_2"));
        rotateLabel_2->setGeometry(QRect(130, 670, 31, 16));
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(10, 590, 221, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        geometrySlider = new MySlider(centralWidget);
        geometrySlider->setObjectName(QString::fromUtf8("geometrySlider"));
        geometrySlider->setGeometry(QRect(150, 640, 51, 20));
        geometrySlider->setMaximum(1);
        geometrySlider->setPageStep(1);
        geometrySlider->setSliderPosition(0);
        geometrySlider->setOrientation(Qt::Horizontal);
        rotateLabel_3 = new QLabel(centralWidget);
        rotateLabel_3->setObjectName(QString::fromUtf8("rotateLabel_3"));
        rotateLabel_3->setGeometry(QRect(30, 610, 61, 16));
        rotateLabel_4 = new QLabel(centralWidget);
        rotateLabel_4->setObjectName(QString::fromUtf8("rotateLabel_4"));
        rotateLabel_4->setGeometry(QRect(130, 640, 16, 16));
        rotateLabel_5 = new QLabel(centralWidget);
        rotateLabel_5->setObjectName(QString::fromUtf8("rotateLabel_5"));
        rotateLabel_5->setGeometry(QRect(210, 640, 16, 16));
        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(110, 610, 20, 91));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);
        rotateLabel_6 = new QLabel(centralWidget);
        rotateLabel_6->setObjectName(QString::fromUtf8("rotateLabel_6"));
        rotateLabel_6->setGeometry(QRect(160, 610, 51, 16));
        line_7 = new QFrame(centralWidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(10, 700, 221, 20));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        rotateLabel_7 = new QLabel(centralWidget);
        rotateLabel_7->setObjectName(QString::fromUtf8("rotateLabel_7"));
        rotateLabel_7->setGeometry(QRect(45, 330, 41, 31));
        rotateLabel_8 = new QLabel(centralWidget);
        rotateLabel_8->setObjectName(QString::fromUtf8("rotateLabel_8"));
        rotateLabel_8->setGeometry(QRect(160, 335, 31, 21));
        nodeModeSlider = new MySlider(centralWidget);
        nodeModeSlider->setObjectName(QString::fromUtf8("nodeModeSlider"));
        nodeModeSlider->setGeometry(QRect(90, 340, 61, 20));
        nodeModeSlider->setMaximum(1);
        nodeModeSlider->setPageStep(1);
        nodeModeSlider->setSliderPosition(1);
        nodeModeSlider->setOrientation(Qt::Horizontal);
        rotateLabel_9 = new QLabel(centralWidget);
        rotateLabel_9->setObjectName(QString::fromUtf8("rotateLabel_9"));
        rotateLabel_9->setGeometry(QRect(90, 320, 61, 20));
        rotate360 = new QLabel(centralWidget);
        rotate360->setObjectName(QString::fromUtf8("rotate360"));
        rotate360->setGeometry(QRect(50, 510, 21, 20));
        rotate0 = new QLabel(centralWidget);
        rotate0->setObjectName(QString::fromUtf8("rotate0"));
        rotate0->setGeometry(QRect(50, 580, 16, 16));
        controlBox_sideCount = new MyControlBox(centralWidget);
        controlBox_sideCount->setObjectName(QString::fromUtf8("controlBox_sideCount"));
        controlBox_sideCount->setGeometry(QRect(170, 670, 51, 22));
        controlBox_sideCount->setDecimals(1);
        controlBox_sideCount->setMinimum(-100);
        controlBox_sideCount->setMaximum(100);
        controlBox_sideCount->setSingleStep(1);
        controlBox_sideCount->setValue(0);
        line_8 = new QFrame(centralWidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(230, 270, 20, 471));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);
        line_9 = new QFrame(centralWidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(10, 360, 221, 20));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        line_10 = new QFrame(centralWidget);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setGeometry(QRect(250, 650, 431, 51));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);
        line_12 = new QFrame(centralWidget);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setGeometry(QRect(10, 300, 221, 20));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(250, 510, 741, 211));
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tableWidget = new MyFrameWidget(tab_5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 711, 131));
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(tab_5);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(550, 150, 91, 31));
        pushButton_2 = new QPushButton(tab_5);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(450, 150, 91, 31));
        checkBox = new QCheckBox(tab_5);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(650, 150, 81, 31));
        checkBox->setChecked(true);
        controlBox_Frames = new MyControlBox(tab_5);
        controlBox_Frames->setObjectName(QString::fromUtf8("controlBox_Frames"));
        controlBox_Frames->setGeometry(QRect(140, 160, 41, 16));
        controlBox_Frames->setDecimals(0);
        controlBox_Frames->setMinimum(1);
        controlBox_Frames->setMaximum(100);
        controlBox_Frames->setSingleStep(1);
        controlBox_Frames->setValue(1);
        pushButton_3 = new QPushButton(tab_5);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 150, 101, 31));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        pushButton_4 = new QPushButton(tab_6);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(490, 50, 121, 31));
        rotateLabel_10 = new QLabel(tab_6);
        rotateLabel_10->setObjectName(QString::fromUtf8("rotateLabel_10"));
        rotateLabel_10->setGeometry(QRect(470, 20, 161, 21));
        rotateLabel_10->setAlignment(Qt::AlignCenter);
        controlBox_Frames_2 = new MyControlBox(tab_6);
        controlBox_Frames_2->setObjectName(QString::fromUtf8("controlBox_Frames_2"));
        controlBox_Frames_2->setGeometry(QRect(100, 50, 61, 31));
        controlBox_Frames_2->setDecimals(0);
        controlBox_Frames_2->setMinimum(1);
        controlBox_Frames_2->setMaximum(10000);
        controlBox_Frames_2->setSingleStep(1);
        controlBox_Frames_2->setValue(1);
        pushButton_5 = new QPushButton(tab_6);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(170, 50, 81, 31));
        animationSlider = new MyAnimationSlider(tab_6);
        animationSlider->setObjectName(QString::fromUtf8("animationSlider"));
        animationSlider->setGeometry(QRect(10, 100, 711, 20));
        animationSlider->setMaximum(0);
        animationSlider->setPageStep(1);
        animationSlider->setOrientation(Qt::Horizontal);
        animationSlider->setTickInterval(1);
        pushButton_6 = new MyButton(tab_6);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(670, 130, 51, 23));
        pushButton_7 = new QPushButton(tab_6);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(610, 130, 51, 23));
        rotateLabel_14 = new QLabel(tab_6);
        rotateLabel_14->setObjectName(QString::fromUtf8("rotateLabel_14"));
        rotateLabel_14->setGeometry(QRect(120, 20, 131, 20));
        line_13 = new QFrame(tab_6);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setGeometry(QRect(360, 10, 16, 81));
        line_13->setFrameShape(QFrame::VLine);
        line_13->setFrameShadow(QFrame::Sunken);
        rotateLabel_15 = new QLabel(tab_6);
        rotateLabel_15->setObjectName(QString::fromUtf8("rotateLabel_15"));
        rotateLabel_15->setGeometry(QRect(450, 120, 81, 41));
        controlBox_Frames_3 = new MyControlBox(tab_6);
        controlBox_Frames_3->setObjectName(QString::fromUtf8("controlBox_Frames_3"));
        controlBox_Frames_3->setGeometry(QRect(540, 130, 61, 20));
        controlBox_Frames_3->setDecimals(0);
        controlBox_Frames_3->setMinimum(0);
        controlBox_Frames_3->setMaximum(3600);
        controlBox_Frames_3->setSingleStep(1);
        controlBox_Frames_3->setValue(40);
        checkBox_2 = new QCheckBox(tab_6);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(670, 160, 51, 20));
        tabWidget->addTab(tab_6, QString());
        pushButton_6->raise();
        pushButton_4->raise();
        rotateLabel_10->raise();
        controlBox_Frames_2->raise();
        pushButton_5->raise();
        animationSlider->raise();
        pushButton_7->raise();
        rotateLabel_14->raise();
        line_13->raise();
        rotateLabel_15->raise();
        controlBox_Frames_3->raise();
        checkBox_2->raise();
        sceneGraphLibClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(sceneGraphLibClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1023, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        sceneGraphLibClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(sceneGraphLibClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        sceneGraphLibClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(sceneGraphLibClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        sceneGraphLibClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionReset_Graph);
        menuFile->addAction(actionQuit);
        menuAbout->addSeparator();
        menuAbout->addAction(actionHello_Puppet_v1_0);
        menuAbout->addSeparator();
        menuAbout->addAction(actionCreated_By_Michael_Rivera);
        menuAbout->addAction(actionCIS277_HW3);

        retranslateUi(sceneGraphLibClass);
        QObject::connect(actionQuit, SIGNAL(triggered()), sceneGraphLibClass, SLOT(close()));
        QObject::connect(controlBox_TranslateX, SIGNAL(valueChanged(double)), widget, SLOT(translateX(double)));
        QObject::connect(controlBox_ScaleX, SIGNAL(valueChanged(double)), widget, SLOT(scaleX(double)));
        QObject::connect(controlBox_ScaleY, SIGNAL(valueChanged(double)), widget, SLOT(scaleY(double)));
        QObject::connect(controlBox_TranslateY, SIGNAL(valueChanged(double)), widget, SLOT(translateY(double)));
        QObject::connect(rotateSlider, SIGNAL(valueChanged(int)), widget, SLOT(spin(int)));
        QObject::connect(Button_Reset, SIGNAL(clicked()), widget, SLOT(resetGraph()));
        QObject::connect(actionReset_Graph, SIGNAL(triggered()), widget, SLOT(resetGraph()));
        QObject::connect(widget, SIGNAL(buildTree(Graph*,bool)), treeWidget, SLOT(getTreeForBuilding(Graph*,bool)));
        QObject::connect(treeWidget, SIGNAL(sendGraphFromTree(Graph*)), controlBox_ScaleX, SLOT(receiveGraphFromTree(Graph*)));
        QObject::connect(controlBox_ScaleX, SIGNAL(sendGraphFromControlBox(Graph*)), controlBox_ScaleY, SLOT(receiveGraphFromControlBox(Graph*)));
        QObject::connect(controlBox_ScaleY, SIGNAL(sendGraphFromControlBox(Graph*)), controlBox_TranslateX, SLOT(receiveGraphFromControlBox(Graph*)));
        QObject::connect(controlBox_TranslateX, SIGNAL(sendGraphFromControlBox(Graph*)), controlBox_TranslateY, SLOT(receiveGraphFromControlBox(Graph*)));
        QObject::connect(controlBox_TranslateY, SIGNAL(sendGraphFromControlBox(Graph*)), controlBox_sideCount, SLOT(receiveGraphFromControlBox(Graph*)));
        QObject::connect(treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), controlBox_ScaleX, SLOT(grabNodeFromClick(QTreeWidgetItem*,int)));
        QObject::connect(controlBox_ScaleX, SIGNAL(sendClickedNode(Node*,int)), controlBox_ScaleY, SLOT(receiveClickedNode(Node*,int)));
        QObject::connect(controlBox_ScaleY, SIGNAL(sendClickedNode(Node*,int)), controlBox_TranslateX, SLOT(receiveClickedNode(Node*,int)));
        QObject::connect(controlBox_TranslateX, SIGNAL(sendClickedNode(Node*,int)), controlBox_TranslateY, SLOT(receiveClickedNode(Node*,int)));
        QObject::connect(controlBox_TranslateY, SIGNAL(sendClickedNode(Node*,int)), controlBox_sideCount, SLOT(receiveClickedNode(Node*,int)));
        QObject::connect(controlBox_sideCount, SIGNAL(sendName(QString)), lineEdit, SLOT(setText(QString)));
        QObject::connect(controlBox_sideCount, SIGNAL(passData(float,float,float,float,int,int)), redSlider, SLOT(receiveData(float,float,float,float,int,int)));
        QObject::connect(redSlider, SIGNAL(passDataSlider(float,float,float,float,int,int)), greenSlider, SLOT(receiveData(float,float,float,float,int,int)));
        QObject::connect(greenSlider, SIGNAL(passDataSlider(float,float,float,float,int,int)), blueSlider, SLOT(receiveData(float,float,float,float,int,int)));
        QObject::connect(blueSlider, SIGNAL(passDataSlider(float,float,float,float,int,int)), rotateSlider, SLOT(receiveData(float,float,float,float,int,int)));
        QObject::connect(rotateSlider, SIGNAL(passDataSlider(float,float,float,float,int,int)), geometrySlider, SLOT(receiveData(float,float,float,float,int,int)));
        QObject::connect(redSlider, SIGNAL(valueChanged(int)), widget, SLOT(colorRed(int)));
        QObject::connect(greenSlider, SIGNAL(valueChanged(int)), widget, SLOT(colorGreen(int)));
        QObject::connect(blueSlider, SIGNAL(valueChanged(int)), widget, SLOT(colorBlue(int)));
        QObject::connect(widget, SIGNAL(resetValues(double)), controlBox_TranslateX, SLOT(setValue(double)));
        QObject::connect(widget, SIGNAL(resetValues(double)), controlBox_TranslateY, SLOT(setValue(double)));
        QObject::connect(widget, SIGNAL(resetValues(double)), controlBox_ScaleX, SLOT(setValue(double)));
        QObject::connect(widget, SIGNAL(resetValues(double)), controlBox_ScaleY, SLOT(setValue(double)));
        QObject::connect(widget, SIGNAL(resetValues(double)), controlBox_sideCount, SLOT(setValue(double)));
        QObject::connect(lineEdit, SIGNAL(textChanged(QString)), widget, SLOT(updateName(QString)));
        QObject::connect(nodeModeSlider, SIGNAL(valueChanged(int)), widget, SLOT(updateMode(int)));
        QObject::connect(lineEdit, SIGNAL(textChanged(QString)), widget, SLOT(saveNewName(QString)));
        QObject::connect(controlBox_sideCount, SIGNAL(valueChanged(double)), widget, SLOT(saveSides(double)));
        QObject::connect(geometrySlider, SIGNAL(valueChanged(int)), widget, SLOT(saveGeometry(int)));
        QObject::connect(rotateSlider, SIGNAL(valueChanged(int)), widget, SLOT(saveRotation(int)));
        QObject::connect(redSlider, SIGNAL(valueChanged(int)), widget, SLOT(saveRed(int)));
        QObject::connect(greenSlider, SIGNAL(valueChanged(int)), widget, SLOT(saveGreen(int)));
        QObject::connect(blueSlider, SIGNAL(valueChanged(int)), widget, SLOT(saveBlue(int)));
        QObject::connect(controlBox_TranslateY, SIGNAL(valueChanged(double)), widget, SLOT(saveTransY(double)));
        QObject::connect(controlBox_TranslateX, SIGNAL(valueChanged(double)), widget, SLOT(saveTransX(double)));
        QObject::connect(controlBox_ScaleY, SIGNAL(valueChanged(double)), widget, SLOT(saveScaleY(double)));
        QObject::connect(controlBox_ScaleX, SIGNAL(valueChanged(double)), widget, SLOT(saveScaleX(double)));
        QObject::connect(add, SIGNAL(clicked()), widget, SLOT(createNode()));
        QObject::connect(remove, SIGNAL(clicked()), widget, SLOT(deleteTreeNode()));
        QObject::connect(widget, SIGNAL(clearSelection()), treeWidget, SLOT(clearSelection()));
        QObject::connect(widget, SIGNAL(resetValues(int)), redSlider, SLOT(setValue(int)));
        QObject::connect(widget, SIGNAL(resetValues(int)), greenSlider, SLOT(setValue(int)));
        QObject::connect(widget, SIGNAL(resetValues(int)), blueSlider, SLOT(setValue(int)));
        QObject::connect(widget, SIGNAL(resetValues(int)), rotateSlider, SLOT(setValue(int)));
        QObject::connect(widget, SIGNAL(clearSelection()), lineEdit, SLOT(clear()));
        QObject::connect(widget, SIGNAL(resetValues(int)), geometrySlider, SLOT(setValue(int)));
        QObject::connect(controlBox_Frames, SIGNAL(valueChanged(double)), widget, SLOT(setMultiFramesValue(double)));
        QObject::connect(pushButton_3, SIGNAL(clicked()), widget, SLOT(addMultiFrames()));
        QObject::connect(pushButton, SIGNAL(clicked()), widget, SLOT(addFrame()));
        QObject::connect(tableWidget, SIGNAL(cellClicked(int,int)), tableWidget, SLOT(setClicked(int,int)));
        QObject::connect(widget, SIGNAL(sendImage(QImage,int)), tableWidget, SLOT(getImage(QImage,int)));
        QObject::connect(tableWidget, SIGNAL(changeFrame(int)), widget, SLOT(updateSelectedFrame(int)));
        QObject::connect(widget, SIGNAL(setSelectedColumn(int)), tableWidget, SLOT(selectColumn(int)));
        QObject::connect(tableWidget, SIGNAL(eraseFrame()), widget, SLOT(deleteFrame()));
        QObject::connect(widget, SIGNAL(sendUpdatedImage(QImage,int)), tableWidget, SLOT(updateImage(QImage,int)));
        QObject::connect(Button_Reset, SIGNAL(clicked()), tableWidget, SLOT(resetFrames()));
        QObject::connect(checkBox, SIGNAL(clicked(bool)), widget, SLOT(updateInterpolateMode(bool)));
        QObject::connect(pushButton_2, SIGNAL(clicked()), tableWidget, SLOT(removeFrame()));
        QObject::connect(tabWidget, SIGNAL(currentChanged(int)), widget, SLOT(setAnimateViewMode(int)));
        QObject::connect(controlBox_Frames_2, SIGNAL(valueChanged(double)), widget, SLOT(setNumAnimateFrames(double)));
        QObject::connect(pushButton_5, SIGNAL(clicked()), widget, SLOT(animate()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), widget, SLOT(stopAnimation()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), widget, SLOT(changeIsPaused()));
        QObject::connect(widget, SIGNAL(setAnimationSliderMax(int)), animationSlider, SLOT(setMaxValue(int)));
        QObject::connect(widget, SIGNAL(setAnimationSliderValue(int)), animationSlider, SLOT(setValue(int)));
        QObject::connect(widget, SIGNAL(sendPlayString(QString)), pushButton_6, SLOT(changeName(QString)));
        QObject::connect(animationSlider, SIGNAL(sliderMoved(int)), widget, SLOT(setCurrentAnimateFrame(int)));
        QObject::connect(widget, SIGNAL(sendKeyFrameString(QString)), rotateLabel_10, SLOT(setText(QString)));
        QObject::connect(pushButton_4, SIGNAL(clicked()), widget, SLOT(makeKeyFrame()));
        QObject::connect(controlBox_Frames_3, SIGNAL(valueChanged(double)), widget, SLOT(setPlaybackSpeed(double)));
        QObject::connect(checkBox_2, SIGNAL(clicked()), widget, SLOT(setLoop()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(sceneGraphLibClass);
    } // setupUi

    void retranslateUi(QMainWindow *sceneGraphLibClass)
    {
        sceneGraphLibClass->setWindowTitle(QApplication::translate("sceneGraphLibClass", "sceneGraphLib", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("sceneGraphLibClass", "Quit", 0, QApplication::UnicodeUTF8));
        actionReset_Graph->setText(QApplication::translate("sceneGraphLibClass", "Reset Graph", 0, QApplication::UnicodeUTF8));
        actionCreated_By_Michael_Rivera->setText(QApplication::translate("sceneGraphLibClass", "Created By Michael Rivera", 0, QApplication::UnicodeUTF8));
        actionCIS277_HW3->setText(QApplication::translate("sceneGraphLibClass", "CIS277 - HW5", 0, QApplication::UnicodeUTF8));
        actionHello_Puppet_v1_0->setText(QApplication::translate("sceneGraphLibClass", "Hello Puppet v5.0", 0, QApplication::UnicodeUTF8));
        Button_Reset->setText(QApplication::translate("sceneGraphLibClass", "Reset Graph", 0, QApplication::UnicodeUTF8));
        remove->setText(QApplication::translate("sceneGraphLibClass", "Delete", 0, QApplication::UnicodeUTF8));
        add->setText(QApplication::translate("sceneGraphLibClass", "Add", 0, QApplication::UnicodeUTF8));
        X_scale->setText(QApplication::translate("sceneGraphLibClass", "  X", 0, QApplication::UnicodeUTF8));
        translateLabel->setText(QApplication::translate("sceneGraphLibClass", "Translate", 0, QApplication::UnicodeUTF8));
        rotateLabel->setText(QApplication::translate("sceneGraphLibClass", " Rotate", 0, QApplication::UnicodeUTF8));
        Y_scale->setText(QApplication::translate("sceneGraphLibClass", "  Y", 0, QApplication::UnicodeUTF8));
        scaleLabel->setText(QApplication::translate("sceneGraphLibClass", "Scale", 0, QApplication::UnicodeUTF8));
        X_trans->setText(QApplication::translate("sceneGraphLibClass", "  X", 0, QApplication::UnicodeUTF8));
        Y_stans->setText(QApplication::translate("sceneGraphLibClass", "  Y", 0, QApplication::UnicodeUTF8));
        colorLabel->setText(QApplication::translate("sceneGraphLibClass", "  Color", 0, QApplication::UnicodeUTF8));
        r->setText(QApplication::translate("sceneGraphLibClass", "  R", 0, QApplication::UnicodeUTF8));
        G->setText(QApplication::translate("sceneGraphLibClass", "  G", 0, QApplication::UnicodeUTF8));
        B->setText(QApplication::translate("sceneGraphLibClass", "  B", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QString());
        rotateLabel_2->setText(QApplication::translate("sceneGraphLibClass", "Sides", 0, QApplication::UnicodeUTF8));
        rotateLabel_3->setText(QApplication::translate("sceneGraphLibClass", "  Node Name", 0, QApplication::UnicodeUTF8));
        rotateLabel_4->setText(QApplication::translate("sceneGraphLibClass", "No", 0, QApplication::UnicodeUTF8));
        rotateLabel_5->setText(QApplication::translate("sceneGraphLibClass", "Yes", 0, QApplication::UnicodeUTF8));
        rotateLabel_6->setText(QApplication::translate("sceneGraphLibClass", " Geometry", 0, QApplication::UnicodeUTF8));
        rotateLabel_7->setText(QApplication::translate("sceneGraphLibClass", "Creator", 0, QApplication::UnicodeUTF8));
        rotateLabel_8->setText(QApplication::translate("sceneGraphLibClass", "Editor", 0, QApplication::UnicodeUTF8));
        rotateLabel_9->setText(QApplication::translate("sceneGraphLibClass", "Node Mode", 0, QApplication::UnicodeUTF8));
        rotate360->setText(QApplication::translate("sceneGraphLibClass", "360", 0, QApplication::UnicodeUTF8));
        rotate0->setText(QApplication::translate("sceneGraphLibClass", "  0", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("sceneGraphLibClass", "Add Frame", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("sceneGraphLibClass", "Remove Frame", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("sceneGraphLibClass", "Interpolate       ", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("sceneGraphLibClass", "Multi-Add Frames", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("sceneGraphLibClass", "Key Frame Editor", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("sceneGraphLibClass", "Make KeyFrame", 0, QApplication::UnicodeUTF8));
        rotateLabel_10->setText(QApplication::translate("sceneGraphLibClass", "None Selected", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("sceneGraphLibClass", "Animate", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("sceneGraphLibClass", "Play", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("sceneGraphLibClass", "Stop", 0, QApplication::UnicodeUTF8));
        rotateLabel_14->setText(QApplication::translate("sceneGraphLibClass", "    Frames in Animation", 0, QApplication::UnicodeUTF8));
        rotateLabel_15->setText(QApplication::translate("sceneGraphLibClass", "Playback Speed", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("sceneGraphLibClass", "Loop", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("sceneGraphLibClass", "Animator", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("sceneGraphLibClass", "File", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("sceneGraphLibClass", "About", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class sceneGraphLibClass: public Ui_sceneGraphLibClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENEGRAPHLIB_H
