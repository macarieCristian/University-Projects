/********************************************************************************
** Form generated from reading UI file 'practicmodel2.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRACTICMODEL2_H
#define UI_PRACTICMODEL2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PracticModel2Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PracticModel2Class)
    {
        if (PracticModel2Class->objectName().isEmpty())
            PracticModel2Class->setObjectName(QStringLiteral("PracticModel2Class"));
        PracticModel2Class->resize(600, 400);
        menuBar = new QMenuBar(PracticModel2Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        PracticModel2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PracticModel2Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PracticModel2Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(PracticModel2Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PracticModel2Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PracticModel2Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PracticModel2Class->setStatusBar(statusBar);

        retranslateUi(PracticModel2Class);

        QMetaObject::connectSlotsByName(PracticModel2Class);
    } // setupUi

    void retranslateUi(QMainWindow *PracticModel2Class)
    {
        PracticModel2Class->setWindowTitle(QApplication::translate("PracticModel2Class", "PracticModel2", 0));
    } // retranslateUi

};

namespace Ui {
    class PracticModel2Class: public Ui_PracticModel2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRACTICMODEL2_H
