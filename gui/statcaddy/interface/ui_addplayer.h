/********************************************************************************
** Form generated from reading UI file 'addplayer.ui'
**
** Created: Sun Nov 4 17:20:10 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPLAYER_H
#define UI_ADDPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddPlayer
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spinBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonOk;
    QLabel *label_4;

    void setupUi(QDialog *AddPlayer)
    {
        if (AddPlayer->objectName().isEmpty())
            AddPlayer->setObjectName(QString::fromUtf8("AddPlayer"));
        AddPlayer->resize(262, 242);
        AddPlayer->setMinimumSize(QSize(262, 242));
        AddPlayer->setMaximumSize(QSize(262, 242));
        layoutWidget = new QWidget(AddPlayer);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 60, 217, 157));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(-10);
        spinBox->setMaximum(36);
        spinBox->setValue(18);

        horizontalLayout_3->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButtonCancel = new QPushButton(layoutWidget);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));

        horizontalLayout_4->addWidget(pushButtonCancel);

        pushButtonOk = new QPushButton(layoutWidget);
        pushButtonOk->setObjectName(QString::fromUtf8("pushButtonOk"));

        horizontalLayout_4->addWidget(pushButtonOk);


        verticalLayout_2->addLayout(horizontalLayout_4);

        label_4 = new QLabel(AddPlayer);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 20, 141, 31));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label_4->setFont(font);

        retranslateUi(AddPlayer);

        QMetaObject::connectSlotsByName(AddPlayer);
    } // setupUi

    void retranslateUi(QDialog *AddPlayer)
    {
        AddPlayer->setWindowTitle(QApplication::translate("AddPlayer", "Dialog", 0));
        label->setText(QApplication::translate("AddPlayer", "First Name:", 0));
        label_2->setText(QApplication::translate("AddPlayer", "Last Name:", 0));
        label_3->setText(QApplication::translate("AddPlayer", "Handicap:", 0));
        pushButtonCancel->setText(QApplication::translate("AddPlayer", "&Cancel", 0));
        pushButtonOk->setText(QApplication::translate("AddPlayer", "&OK", 0));
        label_4->setText(QApplication::translate("AddPlayer", "New Player", 0));
    } // retranslateUi

};

namespace Ui {
    class AddPlayer: public Ui_AddPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPLAYER_H
