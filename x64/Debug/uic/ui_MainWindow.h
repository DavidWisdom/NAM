/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QLabel *label_3;
    QPushButton *pushButton_10;
    QTextEdit *textEdit;
    QPushButton *pushButton_12;
    QLabel *show1;
    QLabel *show2;
    QLabel *show3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_23;
    QLabel *label;
    QPushButton *pushButton_9;
    QPushButton *pushButton_11;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QLabel *label_2;
    QPushButton *pushButton_6;
    QWidget *widget_3;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QLabel *label_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_8;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(690, 995);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, -15, 1020, 761));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(8, 38, 1003, 718));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget{border:none;}\n"
"QTabWidget::tab-bar { alignment: center; } \n"
"QTabBar::tab{ background: rgb(50, 50, 50); }\n"
"QTabBar::tab:hover { background: rgb(80, 80, 80); }\n"
"QTabBar::tab:selected { background: rgb(89, 164, 222); }\n"
"\n"
"image: url(:/image/biaoqing.png);"));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(70, 72));
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(true);
        tabWidget->setTabBarAutoHide(false);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 520, 611, 201));
        label_3->setStyleSheet(QString::fromUtf8(""));
        pushButton_10 = new QPushButton(tab_3);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(30, 527, 34, 34));
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/image/wenjian.png);}\n"
"QPushButton:hover{background-color: rgb(168, 220, 255)}"));
        textEdit = new QTextEdit(tab_3);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(27, 570, 561, 121));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        textEdit->setFont(font1);
        textEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit->setReadOnly(true);
        pushButton_12 = new QPushButton(tab_3);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(100, 527, 34, 34));
        pushButton_12->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/image/tianjia.png);}\n"
"QPushButton:hover{background-color: rgb(168, 220, 255)}"));
        show1 = new QLabel(tab_3);
        show1->setObjectName(QString::fromUtf8("show1"));
        show1->setGeometry(QRect(0, 80, 201, 201));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(show1->sizePolicy().hasHeightForWidth());
        show1->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font2.setPointSize(6);
        show1->setFont(font2);
        show1->setStyleSheet(QString::fromUtf8("border:2px solid rgb(177, 177, 177)\357\274\233"));
        show1->setScaledContents(false);
        show1->setAlignment(Qt::AlignCenter);
        show2 = new QLabel(tab_3);
        show2->setObjectName(QString::fromUtf8("show2"));
        show2->setGeometry(QRect(0, 280, 201, 201));
        sizePolicy.setHeightForWidth(show2->sizePolicy().hasHeightForWidth());
        show2->setSizePolicy(sizePolicy);
        show2->setFont(font2);
        show2->setStyleSheet(QString::fromUtf8("border:2px solid rgb(177, 177, 177)\357\274\233"));
        show2->setScaledContents(false);
        show2->setAlignment(Qt::AlignCenter);
        show3 = new QLabel(tab_3);
        show3->setObjectName(QString::fromUtf8("show3"));
        show3->setGeometry(QRect(201, 80, 401, 401));
        sizePolicy.setHeightForWidth(show3->sizePolicy().hasHeightForWidth());
        show3->setSizePolicy(sizePolicy);
        show3->setFont(font2);
        show3->setStyleSheet(QString::fromUtf8("border:2px solid rgb(177, 177, 177)\357\274\233"));
        show3->setScaledContents(false);
        show3->setAlignment(Qt::AlignCenter);
        pushButton_8 = new QPushButton(tab_3);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(135, 527, 34, 34));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/image/more.png);}\n"
"QPushButton:hover{background-color: rgb(168, 220, 255)}"));
        pushButton_23 = new QPushButton(tab_3);
        pushButton_23->setObjectName(QString::fromUtf8("pushButton_23"));
        pushButton_23->setGeometry(QRect(65, 526, 34, 36));
        pushButton_23->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/image/riqi.png);}\n"
"QPushButton:hover{background-color: rgb(168, 220, 255)}"));
        label = new QLabel(tab_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 40, 611, 481));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 240, 250);"));
        pushButton_9 = new QPushButton(tab_3);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(170, 527, 34, 34));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/image/more.png);}\n"
"QPushButton:hover{background-color: rgb(168, 220, 255)}"));
        pushButton_11 = new QPushButton(tab_3);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(550, 527, 34, 34));
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/image/more.png);}\n"
"QPushButton:hover{background-color: rgb(168, 220, 255)}"));
        pushButton_13 = new QPushButton(tab_3);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(515, 527, 34, 34));
        pushButton_13->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/image/more.png);}\n"
"QPushButton:hover{background-color: rgb(168, 220, 255)}"));
        pushButton_14 = new QPushButton(tab_3);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setGeometry(QRect(480, 527, 34, 34));
        pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/image/more.png);}\n"
"QPushButton:hover{background-color: rgb(168, 220, 255)}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/chat.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_3, icon, QString());
        label->raise();
        label_3->raise();
        textEdit->raise();
        pushButton_10->raise();
        pushButton_12->raise();
        show1->raise();
        show2->raise();
        pushButton_8->raise();
        pushButton_23->raise();
        show3->raise();
        pushButton_9->raise();
        pushButton_11->raise();
        pushButton_13->raise();
        pushButton_14->raise();
        pushButton_15 = new QPushButton(frame);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setGeometry(QRect(8, 676, 79, 79));
        pushButton_15->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/image/more2.png);background: rgb(50, 50, 50);}\n"
"QPushButton:hover{background: rgb(80, 80, 80);}"));
        pushButton_15->setCheckable(true);
        pushButton_15->setFlat(false);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(92, 8, 611, 71));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 247, 253);"));
        pushButton_6 = new QPushButton(frame);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(18, 18, 60, 60));
        pushButton_6->setStyleSheet(QString::fromUtf8("image: url(:/touxiang/paidaxing.jpg);"));
        pushButton_6->setIconSize(QSize(60, 60));
        pushButton_6->setCheckable(true);
        widget_3 = new QWidget(frame);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(88, 638, 131, 101));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_16 = new QPushButton(widget_3);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setGeometry(QRect(0, 0, 131, 51));
        pushButton_16->setFont(font1);
        pushButton_16->setStyleSheet(QString::fromUtf8("QPushButton{border-style:none;background: rgb(50, 50, 50);color: rgb(210, 210, 210);}\n"
"QPushButton:hover{background: rgb(100, 100, 100);color: rgb(230, 230, 230);}"));
        pushButton_17 = new QPushButton(widget_3);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setGeometry(QRect(0, 50, 131, 51));
        pushButton_17->setFont(font1);
        pushButton_17->setStyleSheet(QString::fromUtf8("QPushButton{border-style:none;background: rgb(50, 50, 50);color: rgb(210, 210, 210);}\n"
"QPushButton:hover{background: rgb(100, 100, 100);color: rgb(230, 230, 230);}"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(8, 8, 81, 751));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 50, 50);"));
        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(640, 10, 51, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/image/close2.png);background: rgb(238, 247, 255);}\n"
"QPushButton:hover{background: rgb(255, 80, 83);}"));
        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(589, 10, 51, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/image/minimum2.png);background: rgb(238, 247, 255);}\n"
"QPushButton:hover{background:rgb(168, 220, 255);}\n"
"\n"
"\n"
""));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(88, 8, 60, 70));
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 247, 253);"));
        plainTextEdit = new QPlainTextEdit(frame);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(200, 25, 351, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font3.setPointSize(20);
        plainTextEdit->setFont(font3);
        plainTextEdit->setLayoutDirection(Qt::LeftToRight);
        plainTextEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 247, 253);"));
        plainTextEdit->setFrameShape(QFrame::NoFrame);
        plainTextEdit->setReadOnly(true);
        plainTextEdit->setBackgroundVisible(false);
        plainTextEdit->setCenterOnScroll(false);
        label_5->raise();
        tabWidget->raise();
        pushButton_15->raise();
        label_2->raise();
        pushButton_6->raise();
        widget_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        label_8->raise();
        plainTextEdit->raise();
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 690, 22));
        MainWindowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QCoreApplication::translate("MainWindowClass", "MainWindow", nullptr));
        label_3->setText(QString());
        pushButton_10->setText(QString());
        pushButton_12->setText(QString());
        show1->setText(QCoreApplication::translate("MainWindowClass", "\345\216\237\345\247\213\345\233\276\347\211\207", nullptr));
        show2->setText(QCoreApplication::translate("MainWindowClass", "\350\247\243\347\240\201\345\233\276\347\211\207", nullptr));
        show3->setText(QCoreApplication::translate("MainWindowClass", "\345\210\206\345\211\262\347\244\272\346\204\217\345\233\276", nullptr));
        pushButton_8->setText(QString());
        pushButton_23->setText(QString());
        label->setText(QString());
        pushButton_9->setText(QString());
        pushButton_11->setText(QString());
        pushButton_13->setText(QString());
        pushButton_14->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QString());
        pushButton_15->setText(QString());
        label_2->setText(QString());
        pushButton_6->setText(QString());
        pushButton_16->setText(QCoreApplication::translate("MainWindowClass", "\344\275\240\345\245\275", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindowClass", "\346\254\242\350\277\216\344\275\277\347\224\250", nullptr));
        label_5->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        label_8->setText(QString());
        plainTextEdit->setPlainText(QCoreApplication::translate("MainWindowClass", "\347\201\260\345\272\246\345\233\276\345\203\217\345\244\204\347\220\206\345\260\217\345\212\251\346\211\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
