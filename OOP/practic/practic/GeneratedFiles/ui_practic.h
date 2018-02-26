/********************************************************************************
** Form generated from reading UI file 'practic.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRACTIC_H
#define UI_PRACTIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_practicClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonSort;
    QPushButton *pushButtonRemove;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButtonShow;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QMenuBar *menuBar;
    QMenu *menuGenes_List;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *practicClass)
    {
        if (practicClass->objectName().isEmpty())
            practicClass->setObjectName(QStringLiteral("practicClass"));
        practicClass->resize(563, 536);
        centralWidget = new QWidget(practicClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_2->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonSort = new QPushButton(centralWidget);
        pushButtonSort->setObjectName(QStringLiteral("pushButtonSort"));

        horizontalLayout->addWidget(pushButtonSort);

        pushButtonRemove = new QPushButton(centralWidget);
        pushButtonRemove->setObjectName(QStringLiteral("pushButtonRemove"));

        horizontalLayout->addWidget(pushButtonRemove);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButtonShow = new QPushButton(centralWidget);
        pushButtonShow->setObjectName(QStringLiteral("pushButtonShow"));

        verticalLayout->addWidget(pushButtonShow);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_3->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        practicClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(practicClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 563, 21));
        menuGenes_List = new QMenu(menuBar);
        menuGenes_List->setObjectName(QStringLiteral("menuGenes_List"));
        practicClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(practicClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        practicClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(practicClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        practicClass->setStatusBar(statusBar);

        menuBar->addAction(menuGenes_List->menuAction());

        retranslateUi(practicClass);

        QMetaObject::connectSlotsByName(practicClass);
    } // setupUi

    void retranslateUi(QMainWindow *practicClass)
    {
        practicClass->setWindowTitle(QApplication::translate("practicClass", "practic", 0));
        pushButtonSort->setText(QApplication::translate("practicClass", "Sort", 0));
        pushButtonRemove->setText(QApplication::translate("practicClass", "Remove", 0));
        label->setText(QApplication::translate("practicClass", "organism:", 0));
        pushButtonShow->setText(QApplication::translate("practicClass", "Show Genes", 0));
        label_2->setText(QApplication::translate("practicClass", "number of genes:", 0));
        menuGenes_List->setTitle(QApplication::translate("practicClass", "Genes List", 0));
    } // retranslateUi

};

namespace Ui {
    class practicClass: public Ui_practicClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRACTIC_H
