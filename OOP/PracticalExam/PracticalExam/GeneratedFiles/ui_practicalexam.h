/********************************************************************************
** Form generated from reading UI file 'practicalexam.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRACTICALEXAM_H
#define UI_PRACTICALEXAM_H

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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PracticalExamClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditDesc;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditAct;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonAccept;
    QPushButton *pushButtonSavePlot;
    QPushButton *pushButtonDevelop;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QPushButton *pushButtonSave;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PracticalExamClass)
    {
        if (PracticalExamClass->objectName().isEmpty())
            PracticalExamClass->setObjectName(QStringLiteral("PracticalExamClass"));
        PracticalExamClass->resize(639, 470);
        centralWidget = new QWidget(PracticalExamClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_2->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditDesc = new QLineEdit(centralWidget);
        lineEditDesc->setObjectName(QStringLiteral("lineEditDesc"));

        horizontalLayout->addWidget(lineEditDesc);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditAct = new QLineEdit(centralWidget);
        lineEditAct->setObjectName(QStringLiteral("lineEditAct"));

        horizontalLayout_2->addWidget(lineEditAct);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButtonAdd = new QPushButton(centralWidget);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));

        horizontalLayout_3->addWidget(pushButtonAdd);

        pushButtonAccept = new QPushButton(centralWidget);
        pushButtonAccept->setObjectName(QStringLiteral("pushButtonAccept"));

        horizontalLayout_3->addWidget(pushButtonAccept);

        pushButtonSavePlot = new QPushButton(centralWidget);
        pushButtonSavePlot->setObjectName(QStringLiteral("pushButtonSavePlot"));

        horizontalLayout_3->addWidget(pushButtonSavePlot);

        pushButtonDevelop = new QPushButton(centralWidget);
        pushButtonDevelop->setObjectName(QStringLiteral("pushButtonDevelop"));

        horizontalLayout_3->addWidget(pushButtonDevelop);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit1 = new QLineEdit(centralWidget);
        lineEdit1->setObjectName(QStringLiteral("lineEdit1"));

        verticalLayout->addWidget(lineEdit1);

        lineEdit2 = new QLineEdit(centralWidget);
        lineEdit2->setObjectName(QStringLiteral("lineEdit2"));

        verticalLayout->addWidget(lineEdit2);

        pushButtonSave = new QPushButton(centralWidget);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));

        verticalLayout->addWidget(pushButtonSave);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        PracticalExamClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PracticalExamClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 639, 21));
        PracticalExamClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PracticalExamClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PracticalExamClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PracticalExamClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PracticalExamClass->setStatusBar(statusBar);

        retranslateUi(PracticalExamClass);

        QMetaObject::connectSlotsByName(PracticalExamClass);
    } // setupUi

    void retranslateUi(QMainWindow *PracticalExamClass)
    {
        PracticalExamClass->setWindowTitle(QApplication::translate("PracticalExamClass", "PracticalExam", 0));
        label->setText(QApplication::translate("PracticalExamClass", "Description:", 0));
        label_2->setText(QApplication::translate("PracticalExamClass", "Act:", 0));
        pushButtonAdd->setText(QApplication::translate("PracticalExamClass", "Add", 0));
        pushButtonAccept->setText(QApplication::translate("PracticalExamClass", "Accept", 0));
        pushButtonSavePlot->setText(QApplication::translate("PracticalExamClass", "Save Plot", 0));
        pushButtonDevelop->setText(QApplication::translate("PracticalExamClass", "Develop", 0));
        pushButtonSave->setText(QApplication::translate("PracticalExamClass", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class PracticalExamClass: public Ui_PracticalExamClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRACTICALEXAM_H
