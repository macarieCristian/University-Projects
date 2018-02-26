/********************************************************************************
** Form generated from reading UI file 'projectdogs.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTDOGS_H
#define UI_PROJECTDOGS_H

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

class Ui_ProjectDogsClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProjectDogsClass)
    {
        if (ProjectDogsClass->objectName().isEmpty())
            ProjectDogsClass->setObjectName(QStringLiteral("ProjectDogsClass"));
        ProjectDogsClass->resize(600, 400);
        menuBar = new QMenuBar(ProjectDogsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ProjectDogsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProjectDogsClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ProjectDogsClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ProjectDogsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ProjectDogsClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ProjectDogsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ProjectDogsClass->setStatusBar(statusBar);

        retranslateUi(ProjectDogsClass);

        QMetaObject::connectSlotsByName(ProjectDogsClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProjectDogsClass)
    {
        ProjectDogsClass->setWindowTitle(QApplication::translate("ProjectDogsClass", "ProjectDogs", 0));
    } // retranslateUi

};

namespace Ui {
    class ProjectDogsClass: public Ui_ProjectDogsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTDOGS_H
