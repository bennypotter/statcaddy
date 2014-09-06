/********************************************************************************
** Form generated from reading UI file 'filter.ui'
**
** Created: Mon Apr 1 16:49:05 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTER_H
#define UI_FILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Filter
{
public:
    QHBoxLayout *horizontalLayout_10;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *basicBtn;
    QPushButton *advancedBtn;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_8;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QComboBox *courseComboBox;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QCheckBox *sunnyBox;
    QCheckBox *windyBox;
    QCheckBox *foggyBox;
    QCheckBox *rainyBox;
    QCheckBox *windandrainBox;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QSpinBox *parSpinBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpinBox *distanceSpinBox_1;
    QLabel *label_3;
    QSpinBox *distanceSpinBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpinBox *strokeindexSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QComboBox *shapeComboBox;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QComboBox *positionComboBox;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_2;
    QCheckBox *firCheckBox;
    QCheckBox *girCheckBox;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_6;
    QCheckBox *udCheckBox;
    QCheckBox *sandsaveCheckBox;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *puttsSpinBox;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_4;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *cancelBtn;
    QPushButton *okBtn;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(704, 475);
        horizontalLayout_10 = new QHBoxLayout(Dialog);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setAutoFillBackground(false);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        basicBtn = new QPushButton(groupBox);
        basicBtn->setObjectName(QString::fromUtf8("basicBtn"));
        QPalette palette;
        QBrush brush(QColor(85, 214, 89, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        basicBtn->setPalette(palette);
        basicBtn->setAutoFillBackground(false);
        basicBtn->setFlat(false);

        verticalLayout->addWidget(basicBtn);

        advancedBtn = new QPushButton(groupBox);
        advancedBtn->setObjectName(QString::fromUtf8("advancedBtn"));

        verticalLayout->addWidget(advancedBtn);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout_10->addWidget(groupBox);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        stackedWidget = new QStackedWidget(Dialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setAutoFillBackground(false);
        stackedWidget->setFrameShape(QFrame::WinPanel);
        stackedWidget->setFrameShadow(QFrame::Raised);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        verticalLayout_7 = new QVBoxLayout(page_3);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        groupBox_2 = new QGroupBox(page_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        courseComboBox = new QComboBox(groupBox_2);
        courseComboBox->setObjectName(QString::fromUtf8("courseComboBox"));

        verticalLayout_2->addWidget(courseComboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        sunnyBox = new QCheckBox(groupBox_2);
        sunnyBox->setObjectName(QString::fromUtf8("sunnyBox"));
        sunnyBox->setChecked(true);

        gridLayout->addWidget(sunnyBox, 0, 0, 1, 1);

        windyBox = new QCheckBox(groupBox_2);
        windyBox->setObjectName(QString::fromUtf8("windyBox"));
        windyBox->setChecked(true);

        gridLayout->addWidget(windyBox, 0, 1, 1, 1);

        foggyBox = new QCheckBox(groupBox_2);
        foggyBox->setObjectName(QString::fromUtf8("foggyBox"));
        foggyBox->setChecked(true);

        gridLayout->addWidget(foggyBox, 0, 2, 1, 1);

        rainyBox = new QCheckBox(groupBox_2);
        rainyBox->setObjectName(QString::fromUtf8("rainyBox"));
        rainyBox->setChecked(true);

        gridLayout->addWidget(rainyBox, 1, 0, 1, 1);

        windandrainBox = new QCheckBox(groupBox_2);
        windandrainBox->setObjectName(QString::fromUtf8("windandrainBox"));
        windandrainBox->setChecked(true);

        gridLayout->addWidget(windandrainBox, 1, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout_7->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(page_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        groupBox_4 = new QGroupBox(groupBox_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(groupBox_4);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        parSpinBox = new QSpinBox(groupBox_4);
        parSpinBox->setObjectName(QString::fromUtf8("parSpinBox"));
        parSpinBox->setMinimum(0);
        parSpinBox->setMaximum(6);
        parSpinBox->setValue(0);

        horizontalLayout_5->addWidget(parSpinBox);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        distanceSpinBox_1 = new QSpinBox(groupBox_4);
        distanceSpinBox_1->setObjectName(QString::fromUtf8("distanceSpinBox_1"));
        distanceSpinBox_1->setMinimum(50);
        distanceSpinBox_1->setMaximum(900);
        distanceSpinBox_1->setSingleStep(25);
        distanceSpinBox_1->setValue(50);

        horizontalLayout_4->addWidget(distanceSpinBox_1);

        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        distanceSpinBox_2 = new QSpinBox(groupBox_4);
        distanceSpinBox_2->setObjectName(QString::fromUtf8("distanceSpinBox_2"));
        distanceSpinBox_2->setMinimum(50);
        distanceSpinBox_2->setMaximum(900);
        distanceSpinBox_2->setSingleStep(25);
        distanceSpinBox_2->setValue(900);

        horizontalLayout_4->addWidget(distanceSpinBox_2);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        strokeindexSpinBox = new QSpinBox(groupBox_4);
        strokeindexSpinBox->setObjectName(QString::fromUtf8("strokeindexSpinBox"));
        strokeindexSpinBox->setMinimum(0);
        strokeindexSpinBox->setMaximum(18);
        strokeindexSpinBox->setValue(0);

        horizontalLayout_3->addWidget(strokeindexSpinBox);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        shapeComboBox = new QComboBox(groupBox_4);
        shapeComboBox->setObjectName(QString::fromUtf8("shapeComboBox"));

        horizontalLayout_2->addWidget(shapeComboBox);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_7->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(groupBox_3);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_5 = new QVBoxLayout(groupBox_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        positionComboBox = new QComboBox(groupBox_5);
        positionComboBox->setObjectName(QString::fromUtf8("positionComboBox"));
        positionComboBox->setEditable(false);
        positionComboBox->setMinimumContentsLength(0);
        positionComboBox->setFrame(true);

        verticalLayout_4->addWidget(positionComboBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        verticalLayout_5->addLayout(verticalLayout_4);


        horizontalLayout_7->addWidget(groupBox_5);


        verticalLayout_6->addLayout(horizontalLayout_7);

        groupBox_6 = new QGroupBox(groupBox_3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_2 = new QGridLayout(groupBox_6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        firCheckBox = new QCheckBox(groupBox_6);
        firCheckBox->setObjectName(QString::fromUtf8("firCheckBox"));
        firCheckBox->setChecked(true);

        gridLayout_2->addWidget(firCheckBox, 0, 0, 1, 1);

        girCheckBox = new QCheckBox(groupBox_6);
        girCheckBox->setObjectName(QString::fromUtf8("girCheckBox"));
        girCheckBox->setChecked(true);

        gridLayout_2->addWidget(girCheckBox, 0, 1, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        label_6 = new QLabel(groupBox_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_8->addWidget(label_6);


        gridLayout_2->addLayout(horizontalLayout_8, 0, 2, 1, 1);

        udCheckBox = new QCheckBox(groupBox_6);
        udCheckBox->setObjectName(QString::fromUtf8("udCheckBox"));
        udCheckBox->setChecked(true);

        gridLayout_2->addWidget(udCheckBox, 1, 0, 1, 1);

        sandsaveCheckBox = new QCheckBox(groupBox_6);
        sandsaveCheckBox->setObjectName(QString::fromUtf8("sandsaveCheckBox"));
        sandsaveCheckBox->setChecked(true);

        gridLayout_2->addWidget(sandsaveCheckBox, 1, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        puttsSpinBox = new QSpinBox(groupBox_6);
        puttsSpinBox->setObjectName(QString::fromUtf8("puttsSpinBox"));
        puttsSpinBox->setMinimum(-1);
        puttsSpinBox->setValue(-1);

        horizontalLayout_6->addWidget(puttsSpinBox);


        gridLayout_2->addLayout(horizontalLayout_6, 1, 2, 1, 1);


        verticalLayout_6->addWidget(groupBox_6);


        verticalLayout_7->addWidget(groupBox_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        stackedWidget->addWidget(page_4);

        verticalLayout_8->addWidget(stackedWidget);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);

        cancelBtn = new QPushButton(Dialog);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));

        horizontalLayout_9->addWidget(cancelBtn);

        okBtn = new QPushButton(Dialog);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));

        horizontalLayout_9->addWidget(okBtn);


        verticalLayout_8->addLayout(horizontalLayout_9);


        horizontalLayout_10->addLayout(verticalLayout_8);


        retranslateUi(Dialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        groupBox->setTitle(QString());
        basicBtn->setText(QApplication::translate("Dialog", "Basic Filters", 0));
        advancedBtn->setText(QApplication::translate("Dialog", "Advanced Filters", 0));
        groupBox_2->setTitle(QApplication::translate("Dialog", "Course and Weather", 0));
        sunnyBox->setText(QApplication::translate("Dialog", "Sunny", 0));
        windyBox->setText(QApplication::translate("Dialog", "Windy", 0));
        foggyBox->setText(QApplication::translate("Dialog", "Foggy", 0));
        rainyBox->setText(QApplication::translate("Dialog", "Rainy", 0));
        windandrainBox->setText(QApplication::translate("Dialog", "Windy + Rainy", 0));
        groupBox_3->setTitle(QApplication::translate("Dialog", "Hole and Position", 0));
        groupBox_4->setTitle(QApplication::translate("Dialog", "Hole", 0));
        label->setText(QApplication::translate("Dialog", "Par", 0));
        label_2->setText(QApplication::translate("Dialog", "Distance", 0));
        label_3->setText(QApplication::translate("Dialog", "to:", 0));
        label_4->setText(QApplication::translate("Dialog", "SI", 0));
        label_5->setText(QApplication::translate("Dialog", "Shape", 0));
        groupBox_5->setTitle(QApplication::translate("Dialog", "Position", 0));
        groupBox_6->setTitle(QApplication::translate("Dialog", "Result", 0));
        firCheckBox->setText(QApplication::translate("Dialog", "FIR", 0));
        girCheckBox->setText(QApplication::translate("Dialog", "GIR", 0));
        label_6->setText(QApplication::translate("Dialog", "Number of Putts:", 0));
        udCheckBox->setText(QApplication::translate("Dialog", "Up and Down", 0));
        sandsaveCheckBox->setText(QApplication::translate("Dialog", "Sand Save", 0));
        cancelBtn->setText(QApplication::translate("Dialog", "Cancel", 0));
        okBtn->setText(QApplication::translate("Dialog", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class Filter: public Ui_Filter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTER_H
