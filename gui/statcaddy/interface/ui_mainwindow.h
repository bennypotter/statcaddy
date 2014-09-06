/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../include/piechart.h"
#include "../include/plotter.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QToolButton *toolButton_8;
    QToolButton *toolButton_7;
    QToolButton *toolButton_11;
    QToolButton *toolButton_10;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_5;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_9;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_7;
    QListView *listView;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_7;
    PieChart *statsChart;
    PieChart *scores_Chart;
    PieChart *putts_Chart;
    QSpacerItem *verticalSpacer;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_4;
    QToolButton *toolButton_3;
    QToolButton *filterBtn;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QTabWidget *reportsTab;
    QWidget *graphedRounds_tab;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    Plotter *plotter;
    QWidget *rounds_tab;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
    QTableWidget *tableWidget_3;
    QWidget *tab_6;
    QWidget *tab_3;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuAbout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(680, 640);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(100, 70));
        tabWidget->setTabPosition(QTabWidget::North);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_6 = new QVBoxLayout(tab);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        toolButton_5 = new QToolButton(tab);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        sizePolicy.setHeightForWidth(toolButton_5->sizePolicy().hasHeightForWidth());
        toolButton_5->setSizePolicy(sizePolicy);
        toolButton_5->setMinimumSize(QSize(100, 70));
        toolButton_5->setBaseSize(QSize(50, 50));
        QIcon icon;
        icon.addFile(QStringLiteral(":/buttonicons/images/Database.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon);
        toolButton_5->setIconSize(QSize(50, 50));
        toolButton_5->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(toolButton_5);

        toolButton_6 = new QToolButton(tab);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        sizePolicy.setHeightForWidth(toolButton_6->sizePolicy().hasHeightForWidth());
        toolButton_6->setSizePolicy(sizePolicy);
        toolButton_6->setMinimumSize(QSize(100, 70));
        toolButton_6->setBaseSize(QSize(50, 50));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/buttonicons/images/Settings_48x48.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon1);
        toolButton_6->setIconSize(QSize(50, 50));
        toolButton_6->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(toolButton_6);

        toolButton_8 = new QToolButton(tab);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        sizePolicy.setHeightForWidth(toolButton_8->sizePolicy().hasHeightForWidth());
        toolButton_8->setSizePolicy(sizePolicy);
        toolButton_8->setMinimumSize(QSize(100, 70));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/buttonicons/images/user.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_8->setIcon(icon2);
        toolButton_8->setIconSize(QSize(50, 50));
        toolButton_8->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(toolButton_8);

        toolButton_7 = new QToolButton(tab);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        sizePolicy.setHeightForWidth(toolButton_7->sizePolicy().hasHeightForWidth());
        toolButton_7->setSizePolicy(sizePolicy);
        toolButton_7->setMinimumSize(QSize(100, 70));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/buttonicons/images/Download_48x48.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon3);
        toolButton_7->setIconSize(QSize(40, 40));
        toolButton_7->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(toolButton_7);

        toolButton_11 = new QToolButton(tab);
        toolButton_11->setObjectName(QStringLiteral("toolButton_11"));
        sizePolicy.setHeightForWidth(toolButton_11->sizePolicy().hasHeightForWidth());
        toolButton_11->setSizePolicy(sizePolicy);
        toolButton_11->setMinimumSize(QSize(100, 70));
        toolButton_11->setIcon(icon3);
        toolButton_11->setIconSize(QSize(40, 40));
        toolButton_11->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(toolButton_11);

        toolButton_10 = new QToolButton(tab);
        toolButton_10->setObjectName(QStringLiteral("toolButton_10"));
        sizePolicy.setHeightForWidth(toolButton_10->sizePolicy().hasHeightForWidth());
        toolButton_10->setSizePolicy(sizePolicy);
        toolButton_10->setMinimumSize(QSize(100, 70));
        toolButton_10->setIcon(icon3);
        toolButton_10->setIconSize(QSize(40, 40));
        toolButton_10->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(toolButton_10);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_6->addLayout(horizontalLayout_2);

        frame = new QFrame(tab);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(200, 200));

        horizontalLayout_4->addWidget(pushButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout_12->addLayout(horizontalLayout_4);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(7);
        verticalLayout_11 = new QVBoxLayout(frame_2);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_9->addWidget(label);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_9->addWidget(label_2);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_9->addWidget(label_3);


        horizontalLayout_3->addLayout(verticalLayout_9);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_8->addWidget(label_6);

        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_8->addWidget(label_5);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_8->addWidget(label_4);


        horizontalLayout_3->addLayout(verticalLayout_8);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_11->addLayout(horizontalLayout_3);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_10->addWidget(label_7);

        listView = new QListView(frame_2);
        listView->setObjectName(QStringLiteral("listView"));

        verticalLayout_10->addWidget(listView);


        verticalLayout_11->addLayout(verticalLayout_10);


        verticalLayout_12->addWidget(frame_2);


        horizontalLayout_5->addLayout(verticalLayout_12);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        statsChart = new PieChart(frame);
        statsChart->setObjectName(QStringLiteral("statsChart"));
        statsChart->setMaximumSize(QSize(360, 400));

        verticalLayout_7->addWidget(statsChart);

        scores_Chart = new PieChart(frame);
        scores_Chart->setObjectName(QStringLiteral("scores_Chart"));
        scores_Chart->setMaximumSize(QSize(360, 475));

        verticalLayout_7->addWidget(scores_Chart);

        putts_Chart = new PieChart(frame);
        putts_Chart->setObjectName(QStringLiteral("putts_Chart"));
        putts_Chart->setMaximumSize(QSize(360, 475));

        verticalLayout_7->addWidget(putts_Chart);


        horizontalLayout_5->addLayout(verticalLayout_7);


        verticalLayout_6->addWidget(frame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        toolButton_4 = new QToolButton(tab_2);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        sizePolicy.setHeightForWidth(toolButton_4->sizePolicy().hasHeightForWidth());
        toolButton_4->setSizePolicy(sizePolicy);
        toolButton_4->setMinimumSize(QSize(100, 70));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/buttonicons/images/Refresh_48x48.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon4);
        toolButton_4->setIconSize(QSize(50, 50));
        toolButton_4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton_4);

        toolButton_3 = new QToolButton(tab_2);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        sizePolicy.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy);
        toolButton_3->setMinimumSize(QSize(100, 70));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/buttonicons/images/Cancel_48x48.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon5);
        toolButton_3->setIconSize(QSize(50, 50));
        toolButton_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton_3);

        filterBtn = new QToolButton(tab_2);
        filterBtn->setObjectName(QStringLiteral("filterBtn"));
        sizePolicy.setHeightForWidth(filterBtn->sizePolicy().hasHeightForWidth());
        filterBtn->setSizePolicy(sizePolicy);
        filterBtn->setMinimumSize(QSize(100, 70));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/buttonicons/images/filter.png"), QSize(), QIcon::Normal, QIcon::Off);
        filterBtn->setIcon(icon6);
        filterBtn->setIconSize(QSize(50, 50));
        filterBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(filterBtn);

        toolButton = new QToolButton(tab_2);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        sizePolicy.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy);
        toolButton->setMinimumSize(QSize(100, 70));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/buttonicons/images/chart.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon7);
        toolButton->setIconSize(QSize(40, 40));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(tab_2);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        sizePolicy.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy);
        toolButton_2->setMinimumSize(QSize(100, 70));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/buttonicons/images/Calendar_48x48.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon8);
        toolButton_2->setIconSize(QSize(50, 50));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        reportsTab = new QTabWidget(tab_2);
        reportsTab->setObjectName(QStringLiteral("reportsTab"));
        graphedRounds_tab = new QWidget();
        graphedRounds_tab->setObjectName(QStringLiteral("graphedRounds_tab"));
        verticalLayout_4 = new QVBoxLayout(graphedRounds_tab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        plotter = new Plotter(graphedRounds_tab);
        plotter->setObjectName(QStringLiteral("plotter"));
        QPalette palette;
        QBrush brush(QColor(33, 33, 33, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(80, 84, 80, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        QBrush brush2(QColor(26, 26, 26, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        plotter->setPalette(palette);

        verticalLayout_3->addWidget(plotter);


        verticalLayout_4->addLayout(verticalLayout_3);

        reportsTab->addTab(graphedRounds_tab, QString());
        rounds_tab = new QWidget();
        rounds_tab->setObjectName(QStringLiteral("rounds_tab"));
        verticalLayout_5 = new QVBoxLayout(rounds_tab);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        tableWidget = new QTableWidget(rounds_tab);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setSortingEnabled(true);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(0);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->horizontalHeader()->setMinimumSectionSize(100);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);
        tableWidget->verticalHeader()->setMinimumSectionSize(19);

        verticalLayout_5->addWidget(tableWidget);

        tableWidget_2 = new QTableWidget(rounds_tab);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));

        verticalLayout_5->addWidget(tableWidget_2);

        tableWidget_3 = new QTableWidget(rounds_tab);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));

        verticalLayout_5->addWidget(tableWidget_3);

        reportsTab->addTab(rounds_tab, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        reportsTab->addTab(tab_6, QString());

        verticalLayout_2->addWidget(reportsTab);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 680, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuAbout->menuAction());

        retranslateUi(MainWindow);
        QObject::connect(tabWidget, SIGNAL(currentChanged(int)), reportsTab, SLOT(setCurrentIndex(int)));

        tabWidget->setCurrentIndex(1);
        reportsTab->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        toolButton_5->setText(QApplication::translate("MainWindow", "Database", 0));
        toolButton_6->setText(QApplication::translate("MainWindow", "Settings", 0));
        toolButton_8->setText(QApplication::translate("MainWindow", "Player", 0));
        toolButton_7->setText(QApplication::translate("MainWindow", "Download \n"
"Rounds", 0));
        toolButton_11->setText(QApplication::translate("MainWindow", "Add\n"
"Course", 0));
        toolButton_10->setText(QApplication::translate("MainWindow", "Add\n"
"Round", 0));
        pushButton->setText(QApplication::translate("MainWindow", "PICTURE", 0));
        label->setText(QApplication::translate("MainWindow", "Name:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Handicap:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Best Score:", 0));
        label_6->setText(QApplication::translate("MainWindow", "Ben Eyres", 0));
        label_5->setText(QApplication::translate("MainWindow", "2.1", 0));
        label_4->setText(QApplication::translate("MainWindow", "65", 0));
        label_7->setText(QApplication::translate("MainWindow", "Last 10 Rounds:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Home", 0));
        toolButton_4->setText(QApplication::translate("MainWindow", "Refresh", 0));
        toolButton_3->setText(QApplication::translate("MainWindow", "Clear Filters", 0));
        filterBtn->setText(QApplication::translate("MainWindow", "Filter", 0));
        toolButton->setText(QApplication::translate("MainWindow", "More \n"
"Reports", 0));
        toolButton_2->setText(QApplication::translate("MainWindow", "Date Range", 0));
        reportsTab->setTabText(reportsTab->indexOf(graphedRounds_tab), QApplication::translate("MainWindow", "Graphed Rounds", 0));
        reportsTab->setTabText(reportsTab->indexOf(rounds_tab), QApplication::translate("MainWindow", "Rounds", 0));
        reportsTab->setTabText(reportsTab->indexOf(tab_6), QApplication::translate("MainWindow", "Page", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Reports", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Last Session", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
