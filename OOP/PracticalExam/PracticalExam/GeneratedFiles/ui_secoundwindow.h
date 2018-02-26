/********************************************************************************
** Form generated from reading UI file 'secoundwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECOUNDWINDOW_H
#define UI_SECOUNDWINDOW_H

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

class Ui_SecoundWindow
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SecoundWindow)
    {
        if (SecoundWindow->objectName().isEmpty())
            SecoundWindow->setObjectName(QStringLiteral("SecoundWindow"));
        SecoundWindow->resize(572, 384);
        centralWidget = new QWidget(SecoundWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SecoundWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SecoundWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 572, 21));
        SecoundWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SecoundWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SecoundWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SecoundWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SecoundWindow->setStatusBar(statusBar);

        retranslateUi(SecoundWindow);

        QMetaObject::connectSlotsByName(SecoundWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SecoundWindow)
    {
        SecoundWindow->setWindowTitle(QApplication::translate("SecoundWindow", "SecoundWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class SecoundWindow: public Ui_SecoundWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECOUNDWINDOW_H
