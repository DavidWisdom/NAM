#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/types_c.h>
#include <vector>
#include <QMainWindow>
#include <QProcess>
#include <QDesktopServices>
#include <QUrl>
#include <QMouseEvent>
#include <QFrame>
#include <QMenu>
#include <QFile>
#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QButtonGroup>
#include <QListWidgetItem>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QScrollBar>
#include <QPixmap>
#include <QDateTime>
#include <QDebug>
#include <QTime>
#include <QtGlobal>
#include <QDataStream>
#include <QString>
#include <QByteArray>
#include <QFileDialog>
#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include <QMessageBox>
#include "horizontalpriority.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
    ~MainWindow();
    void MainWindow::mousePressEvent(QMouseEvent* event);
    void MainWindow::mouseMoveEvent(QMouseEvent* event);
    QPoint last_mouse_position_;
    bool clicked = false;

private slots:
    void readImage();
    void save();
    void on_pushButton_12_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_15_clicked(bool clicked);
    void on_pushButton_9_clicked(bool clicked);
    void on_pushButton_red_clicked();
    void on_pushButton_yellow_clicked();
    void on_pushButton_green_clicked();

private:
    Ui::MainWindowClass *ui;
    cv::Mat img;
    cv::Mat image;
    bool flag = false;
    bool mode = true;
	const int size = 256;
	QString fileName;
    float cols = 0;
    std::vector<std::vector<int>> q_tri;
    std::vector<std::vector<int>> q_line;
    std::vector<std::vector<int>> q_point;
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> q_rect;
    std::vector<std::vector<int>> res;
};
