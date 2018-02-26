/********************************************************************************
** Form generated from reading UI file 'gui2.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI2_H
#define UI_GUI2_H

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

class Ui_gui2
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButtonRemove;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonDone;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *gui2)
    {
        if (gui2->objectName().isEmpty())
            gui2->setObjectName(QStringLiteral("gui2"));
        gui2->resize(558, 394);
        centralWidget = new QWidget(gui2);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButtonRemove = new QPushButton(centralWidget);
        pushButtonRemove->setObjectName(QStringLiteral("pushButtonRemove"));

        horizontalLayout->addWidget(pushButtonRemove);

        pushButtonStart = new QPushButton(centralWidget);
        pushButtonStart->setObjectName(QStringLiteral("pushButtonStart"));

        horizontalLayout->addWidget(pushButtonStart);

        pushButtonDone = new QPushButton(centralWidget);
        pushButtonDone->setObjectName(QStringLiteral("pushButtonDone"));

        horizontalLayout->addWidget(pushButtonDone);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        gui2->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(gui2);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 558, 21));
        gui2->setMenuBar(menuBar);
        mainToolBar = new QToolBar(gui2);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        gui2->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(gui2);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        gui2->setStatusBar(statusBar);

        retranslateUi(gui2);

        QMetaObject::connectSlotsByName(gui2);
    } // setupUi

    void retranslateUi(QMainWindow *gui2)
    {
        gui2->setWindowTitle(QApplication::translate("gui2", "gui2", 0));
        label->setText(QApplication::translate("gui2", "Description:", 0));
        pushButton->setText(QApplication::translate("gui2", "Add Task", 0));
        pushButtonRemove->setText(QApplication::translate("gui2", "Remove", 0));
        pushButtonStart->setText(QApplication::translate("gui2", "Start Task", 0));
        pushButtonDone->setText(QApplication::translate("gui2", "Done", 0));
    } // retranslateUi

};

namespace Ui {
    class gui2: public Ui_gui2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI2_H
