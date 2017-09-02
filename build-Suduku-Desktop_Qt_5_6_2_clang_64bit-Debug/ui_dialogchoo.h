/********************************************************************************
** Form generated from reading UI file 'dialogchoo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCHOO_H
#define UI_DIALOGCHOO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogChoo
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_8;
    QPushButton *pushButton_3;
    QPushButton *pushButton_9;
    QPushButton *pushButton_7;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;

    void setupUi(QDialog *DialogChoo)
    {
        if (DialogChoo->objectName().isEmpty())
            DialogChoo->setObjectName(QStringLiteral("DialogChoo"));
        DialogChoo->resize(161, 128);
        DialogChoo->setWindowOpacity(0.7);
        gridLayoutWidget = new QWidget(DialogChoo);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 161, 131));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setMouseTracking(true);
        pushButton->setAutoDefault(false);

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setMouseTracking(true);
        pushButton_2->setAutoDefault(false);

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_6->setMouseTracking(true);
        pushButton_6->setAutoDefault(false);

        gridLayout->addWidget(pushButton_6, 2, 1, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_5->setMouseTracking(true);
        pushButton_5->setAutoDefault(false);

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setMouseTracking(true);
        pushButton_4->setAutoDefault(false);

        gridLayout->addWidget(pushButton_4, 0, 1, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_8->setAutoDefault(false);

        gridLayout->addWidget(pushButton_8, 1, 2, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setMouseTracking(true);
        pushButton_3->setAutoDefault(false);

        gridLayout->addWidget(pushButton_3, 2, 0, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_9->setMouseTracking(true);
        pushButton_9->setAutoDefault(false);

        gridLayout->addWidget(pushButton_9, 2, 2, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_7->setMouseTracking(true);
        pushButton_7->setAutoDefault(false);

        gridLayout->addWidget(pushButton_7, 0, 2, 1, 1);

        pushButton_10 = new QPushButton(gridLayoutWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setAutoDefault(false);

        gridLayout->addWidget(pushButton_10, 3, 0, 1, 1);

        pushButton_11 = new QPushButton(gridLayoutWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setAutoDefault(false);

        gridLayout->addWidget(pushButton_11, 3, 1, 1, 2);


        retranslateUi(DialogChoo);

        pushButton->setDefault(false);
        pushButton_10->setDefault(true);
        pushButton_11->setDefault(false);


        QMetaObject::connectSlotsByName(DialogChoo);
    } // setupUi

    void retranslateUi(QDialog *DialogChoo)
    {
        DialogChoo->setWindowTitle(QApplication::translate("DialogChoo", "Dialog", 0));
        pushButton->setText(QApplication::translate("DialogChoo", "1", 0));
        pushButton_2->setText(QApplication::translate("DialogChoo", "4", 0));
        pushButton_6->setText(QApplication::translate("DialogChoo", "8", 0));
        pushButton_5->setText(QApplication::translate("DialogChoo", "5", 0));
        pushButton_4->setText(QApplication::translate("DialogChoo", "2", 0));
        pushButton_8->setText(QApplication::translate("DialogChoo", "6", 0));
        pushButton_3->setText(QApplication::translate("DialogChoo", "7", 0));
        pushButton_9->setText(QApplication::translate("DialogChoo", "9", 0));
        pushButton_7->setText(QApplication::translate("DialogChoo", "3", 0));
        pushButton_10->setText(QString());
        pushButton_11->setText(QApplication::translate("DialogChoo", "back", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogChoo: public Ui_DialogChoo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCHOO_H
