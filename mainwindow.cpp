#include "mainwindow.h"
#include <vector>
#include <fstream>
#include "tnam.h"
#include "rnamc.h"
#include "diagonalpriority.h"
#include "verticalpriority.h"
#include "horizontalpriority.h"
void MainWindow::on_pushButton_green_clicked()
{
    if (mode)
    {
        cv::Mat dst(NAM::TNAM::size, NAM::TNAM::size, CV_8UC1, cv::Scalar(255));
        cv::Mat seg(NAM::TNAM::size, NAM::TNAM::size, CV_8UC1, cv::Scalar(255));
        std::string log;
        CV::CV::binaryConvertToMatrix(img, matrix, 256, 256, log);
        NAM::TNAM::encode_square(matrix, q_tri, q_line, q_point, q_rect);
        NAM::TNAM::decode(dst, seg, q_tri, q_line, q_point, q_rect, res);
        cv::imwrite("D:\\seg.jpg", seg);
        QString s1 = QString::number(NAM::TNAM::num_of_total_triangular);
        QString s2 = QString::number(NAM::TNAM::num_of_total_rectangle + NAM::TNAM::num_of_lines);
        QString s3 = QString::number(NAM::TNAM::num_of_points);
        QString string = ui->textEdit->toPlainText();
        ui->textEdit->setText(string + '\n' + QString::fromWCharArray(L"已成功编码") + fileName + '\n' + QString::fromWCharArray(L"当前图片三角子模式数量：") + s1 + '\n' + QString::fromWCharArray(L"线段子模式数量：") + s2 + '\n' + QString::fromWCharArray(L"孤立点子模式数量：") + s3);
        {
            cv::Mat rgb;
            QImage img;
            QImage imgScaled;
            cv::Mat image = cv::imread("D:\\seg.jpg");
            if (image.channels() == 3) // cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char *)(rgb.data),
                             rgb.cols, rgb.rows,
                             rgb.cols * rgb.channels(),
                             QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char *)(image.data),
                             image.cols, image.rows,
                             image.cols * image.channels(),
                             QImage::Format_RGB888);
                cols = image.cols;
            }
            imgScaled = img.scaled(ui->show3->size(), Qt::KeepAspectRatio);
            ui->show3->setPixmap(QPixmap::fromImage(imgScaled));
            ui->show3->resize(ui->show3->pixmap()->size());
        }
        cv::imwrite("D:\\decode.jpg", dst);
        {
            cv::Mat rgb;
            QImage img;
            QImage imgScaled;
            cv::Mat image = cv::imread("D:\\decode.jpg");
            if (image.channels() == 3) // cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char *)(rgb.data),
                             rgb.cols, rgb.rows,
                             rgb.cols * rgb.channels(),
                             QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char *)(image.data),
                             image.cols, image.rows,
                             image.cols * image.channels(),
                             QImage::Format_RGB888);
                cols = image.cols;
            }
            imgScaled = img.scaled(ui->show2->size(), Qt::KeepAspectRatio);
            ui->show2->setPixmap(QPixmap::fromImage(imgScaled));
            ui->show2->resize(ui->show2->pixmap()->size());
        }
    }
    else
    {

        NAM::HorizontalPriority *horizontal = NAM::HorizontalPriority::getInstance();
        cv::Mat dst;
        cv::Mat seg;
        std::wstring wlog;
        horizontal->horizontalPriority(img, dst, seg, wlog);
        QString qlog = QString::fromStdWString(wlog);
        QString str = ui->textEdit->toPlainText();
        if (str == NULL)
        {
            ui->textEdit->setText(qlog);
        }
        else
        {
            ui->textEdit->setText(str + qlog);
        }
        cv::imwrite("D:\\seg.jpg", seg);
        {
            cv::Mat rgb;
            QImage img;
            QImage imgScaled;
            cv::Mat image = cv::imread("D:\\seg.jpg");

            if (image.channels() == 3) // cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char *)(rgb.data),
                             rgb.cols, rgb.rows,
                             rgb.cols * rgb.channels(),
                             QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char *)(image.data),
                             image.cols, image.rows,
                             image.cols * image.channels(),
                             QImage::Format_RGB888);
                cols = image.cols;
            }
            imgScaled = img.scaled(ui->show3->size(), Qt::KeepAspectRatio);
            ui->show3->setPixmap(QPixmap::fromImage(imgScaled));
            ui->show3->resize(ui->show3->pixmap()->size());
        }
        cv::imwrite("D:\\decode.jpg", dst);
        {
            cv::Mat rgb;
            QImage img;
            QImage imgScaled;
            cv::Mat image = cv::imread("D:\\decode.jpg");
            if (image.channels() == 3) // cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char *)(rgb.data),
                             rgb.cols, rgb.rows,
                             rgb.cols * rgb.channels(),
                             QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char *)(image.data),
                             image.cols, image.rows,
                             image.cols * image.channels(),
                             QImage::Format_RGB888);
                cols = image.cols;
            }
            imgScaled = img.scaled(ui->show2->size(), Qt::KeepAspectRatio);

            ui->show2->setPixmap(QPixmap::fromImage(imgScaled));
            ui->show2->resize(ui->show2->pixmap()->size());
        }
    }
}

void MainWindow::on_pushButton_red_clicked()
{
    if (mode)
    {
        if (!flag)
        {
            QString string = ui->textEdit->toPlainText();
            if (string == NULL)
            {

                ui->textEdit->setText(QString::fromWCharArray(L"您未选择图片"));
            }
            else
            {

                ui->textEdit->setText(string + '\n' + QString::fromWCharArray(L"您未选择图片"));
            }
            return;
        }
        cv::Mat dst(NAM::TNAM::size, NAM::TNAM::size, CV_8UC1, cv::Scalar(255));
        cv::Mat seg(NAM::TNAM::size, NAM::TNAM::size, CV_8UC1, cv::Scalar(255));
        std::string log;
        CV::CV::binaryConvertToMatrix(img, matrix, 256, 256, log);
        NAM::TNAM::encode_tri(matrix, q_tri, q_line, q_point, q_rect);
        NAM::TNAM::decode(dst, seg, q_tri, q_line, q_point, q_rect, res);
        cv::imwrite("D:\\seg.jpg", seg);
        QString s1 = QString::number(NAM::TNAM::num_of_total_triangular);
        QString s2 = QString::number(NAM::TNAM::num_of_lines);
        QString s3 = QString::number(NAM::TNAM::num_of_points);
        QString string = ui->textEdit->toPlainText();
        ui->textEdit->setText(string + '\n' + QString::fromWCharArray(L"已成功编码") + fileName + '\n' + QString::fromWCharArray(L"当前图片三角子模式数量：") + s1 + '\n' + QString::fromWCharArray(L"线段子模式数量：") + s2 + '\n' + QString::fromWCharArray(L"孤立点子模式数量：") + s3);
        // QMessageBox::information(NULL, "Attention", "Decode succeed!");
        {
            cv::Mat rgb;
            QImage img;
            QImage imgScaled;
            cv::Mat image = cv::imread("D:\\seg.jpg");

            if (image.channels() == 3) // cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char *)(rgb.data),
                             rgb.cols, rgb.rows,
                             rgb.cols * rgb.channels(),
                             QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char *)(image.data),
                             image.cols, image.rows,
                             image.cols * image.channels(),
                             QImage::Format_RGB888);
                cols = image.cols;
            }
            imgScaled = img.scaled(ui->show3->size(), Qt::KeepAspectRatio);

            ui->show3->setPixmap(QPixmap::fromImage(imgScaled));
            ui->show3->resize(ui->show3->pixmap()->size());
        }
        cv::imwrite("D:\\decode.jpg", dst);
        // QMessageBox::information(NULL, "Attention", "Decode succeed!");
        {
            cv::Mat rgb;
            QImage img;
            QImage imgScaled;
            cv::Mat image = cv::imread("D:\\decode.jpg");

            if (image.channels() == 3) // cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char *)(rgb.data),
                             rgb.cols, rgb.rows,
                             rgb.cols * rgb.channels(),
                             QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char *)(image.data),
                             image.cols, image.rows,
                             image.cols * image.channels(),
                             QImage::Format_RGB888);
                cols = image.cols;
            }
            imgScaled = img.scaled(ui->show2->size(), Qt::KeepAspectRatio);

            ui->show2->setPixmap(QPixmap::fromImage(imgScaled));
            ui->show2->resize(ui->show2->pixmap()->size());
        }
    }
    else
    {
        NAM::VerticalPriority *horizontal = NAM::VerticalPriority::getInstance();
        cv::Mat dst;
        cv::Mat seg;
        std::wstring wlog;
        horizontal->verticalPriority(img, dst, seg, wlog);
        QString qlog = QString::fromStdWString(wlog);

        QString str = ui->textEdit->toPlainText();
        if (str == NULL)
        {
            ui->textEdit->setText(qlog);
        }
        else
        {
            ui->textEdit->setText(str + qlog);
        }
        cv::imwrite("D:\\seg.jpg", seg);
        {
            cv::Mat rgb;
            QImage img;
            QImage imgScaled;
            cv::Mat image = cv::imread("D:\\seg.jpg");

            if (image.channels() == 3) // cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char *)(rgb.data),
                             rgb.cols, rgb.rows,
                             rgb.cols * rgb.channels(),
                             QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char *)(image.data),
                             image.cols, image.rows,
                             image.cols * image.channels(),
                             QImage::Format_RGB888);
                cols = image.cols;
            }
            imgScaled = img.scaled(ui->show3->size(), Qt::KeepAspectRatio);

            ui->show3->setPixmap(QPixmap::fromImage(imgScaled));
            ui->show3->resize(ui->show3->pixmap()->size());
        }
        cv::imwrite("D:\\decode.jpg", dst);
        {
            cv::Mat rgb;
            QImage img;
            QImage imgScaled;
            cv::Mat image = cv::imread("D:\\decode.jpg");

            if (image.channels() == 3) // cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char *)(rgb.data),
                             rgb.cols, rgb.rows,
                             rgb.cols * rgb.channels(),
                             QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char *)(image.data),
                             image.cols, image.rows,
                             image.cols * image.channels(),
                             QImage::Format_RGB888);
                cols = image.cols;
            }
            imgScaled = img.scaled(ui->show2->size(), Qt::KeepAspectRatio);

            ui->show2->setPixmap(QPixmap::fromImage(imgScaled));
            ui->show2->resize(ui->show2->pixmap()->size());
        }
    }
}
// void MainWindow::on_pushButton_9_clicked()
// {
//     mode = !mode;
// }

void MainWindow::on_pushButton_yellow_clicked()
{
    if (mode)
    {
        if (!flag)
        {
            QString string = ui->textEdit->toPlainText();
            if (string == NULL)
            {

                ui->textEdit->setText(QString::fromWCharArray(L"您未选择图片"));
            }
            else
            {

                ui->textEdit->setText(string + '\n' + QString::fromWCharArray(L"您未选择图片"));
            }
            return;
        }
        cv::Mat dst(NAM::TNAM::size, NAM::TNAM::size, CV_8UC1, cv::Scalar(255));
        cv::Mat seg(NAM::TNAM::size, NAM::TNAM::size, CV_8UC1, cv::Scalar(255));
        std::string log;
        CV::CV::binaryConvertToMatrix(img, matrix, 256, 256, log);
        NAM::TNAM::encode_tri_and_square(matrix, q_tri, q_line, q_point, q_rect);
        NAM::TNAM::decode(dst, seg, q_tri, q_line, q_point, q_rect, res);
        cv::imwrite("D:\\seg.jpg", seg);
        QString s1 = QString::number(NAM::TNAM::num_of_total_triangular);
        QString s2 = QString::number(NAM::TNAM::num_of_total_rectangle);
        QString s3 = QString::number(NAM::TNAM::num_of_points);
        QString string = ui->textEdit->toPlainText();
        ui->textEdit->setText(string + '\n' + QString::fromWCharArray(L"已成功编码") + fileName + '\n' + QString::fromWCharArray(L"当前图片三角子模式数量：") + s1 + '\n' + QString::fromWCharArray(L"线段子模式数量：") + s2 + '\n' + QString::fromWCharArray(L"孤立点子模式数量：") + s3);
        // QMessageBox::information(NULL, "Attention", "Decode succeed!");
        {
            cv::Mat rgb;
            QImage img;
            QImage imgScaled;
            cv::Mat image = cv::imread("D:\\seg.jpg");

            if (image.channels() == 3) // cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char *)(rgb.data),
                             rgb.cols, rgb.rows,
                             rgb.cols * rgb.channels(),
                             QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char *)(image.data),
                             image.cols, image.rows,
                             image.cols * image.channels(),
                             QImage::Format_RGB888);
                cols = image.cols;
            }
            imgScaled = img.scaled(ui->show3->size(), Qt::KeepAspectRatio);

            ui->show3->setPixmap(QPixmap::fromImage(imgScaled));
            ui->show3->resize(ui->show3->pixmap()->size());
        }
        cv::imwrite("D:\\decode.jpg", dst);

        // QMessageBox::information(NULL, "Attention", "Decode succeed!");
        {
            cv::Mat rgb;
            QImage img;
            QImage imgScaled;
            cv::Mat image = cv::imread("D:\\decode.jpg");

            if (image.channels() == 3) // cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char *)(rgb.data),
                             rgb.cols, rgb.rows,
                             rgb.cols * rgb.channels(),
                             QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char *)(image.data),
                             image.cols, image.rows,
                             image.cols * image.channels(),
                             QImage::Format_RGB888);
                cols = image.cols;
            }
            imgScaled = img.scaled(ui->show2->size(), Qt::KeepAspectRatio);

            ui->show2->setPixmap(QPixmap::fromImage(imgScaled));
            ui->show2->resize(ui->show2->pixmap()->size());
        }
    }
    else
    {
        NAM::DiagonalPriority *horizontal = NAM::DiagonalPriority::getInstance();
        cv::Mat dst;
        cv::Mat seg;
        std::wstring log;
        horizontal->diagonalPriority(img, dst, seg, log);
        QString qlog = QString::fromStdWString(log);

        QString str = ui->textEdit->toPlainText();
        if (str == NULL)
        {

            ui->textEdit->setText(qlog);
        }
        else
        {

            ui->textEdit->setText(str + qlog);
        }
        cv::imwrite("D:\\seg.jpg", seg);
        {
            cv::Mat rgb;
            QImage img;
            QImage imgScaled;
            cv::Mat image = cv::imread("D:\\seg.jpg");

            if (image.channels() == 3) // cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char *)(rgb.data),
                             rgb.cols, rgb.rows,
                             rgb.cols * rgb.channels(),
                             QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char *)(image.data),
                             image.cols, image.rows,
                             image.cols * image.channels(),
                             QImage::Format_RGB888);
                cols = image.cols;
            }
            imgScaled = img.scaled(ui->show3->size(), Qt::KeepAspectRatio);

            ui->show3->setPixmap(QPixmap::fromImage(imgScaled));
            ui->show3->resize(ui->show3->pixmap()->size());
        }
        cv::imwrite("D:\\decode.jpg", dst);
        {
            cv::Mat rgb;
            QImage img;
            QImage imgScaled;
            cv::Mat image = cv::imread("D:\\decode.jpg");

            if (image.channels() == 3) // cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char *)(rgb.data),
                             rgb.cols, rgb.rows,
                             rgb.cols * rgb.channels(),
                             QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char *)(image.data),
                             image.cols, image.rows,
                             image.cols * image.channels(),
                             QImage::Format_RGB888);
                cols = image.cols;
            }
            imgScaled = img.scaled(ui->show2->size(), Qt::KeepAspectRatio);

            ui->show2->setPixmap(QPixmap::fromImage(imgScaled));
            ui->show2->resize(ui->show2->pixmap()->size());
        }
    }
}

void MainWindow::readImage()
{
    flag = false;
    fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files (*.bmp)"));
    //弹出文件选取框，选取一个来自该三种格式的图片
    img = cv::imread(cv::String(fileName.toLocal8Bit().toStdString()), -1);
    if (img.empty())
    {
        // QMessageBox::information(this, "Attention", "Could not open the file!");
        return;
    }
    qDebug() << "filenames:" << fileName;
    if (fileName.isEmpty())
    { // String类型判断为空
        // QMessageBox::information(NULL, "Attention", "Image loading failed!");
        return;
    }
    image = cv::imread(fileName.toUtf8().data()); // image从文件中读出数据,将toLatin1改成toUtf8后支持了中文文件名
    QString str = ui->textEdit->toPlainText();
    if (str == NULL)
    {

        ui->textEdit->setText(QString::fromWCharArray(L"选择图像") + fileName);
    }
    else
    {

        ui->textEdit->setText(str + '\n' + QString::fromWCharArray(L"选择图像") + fileName);
    }
    QString filename = fileName;
    for (int i = 0; i < img.rows; ++i)
    {
        for (int j = 0; j < img.cols; ++j)
        {
            // org[i][j] = static_cast<int>(f[i][j]);
            if (img.at<uchar>(i, j) != 0 && img.at<uchar>(i, j) != 255)
            {

                QString string = ui->textEdit->toPlainText();
                ui->textEdit->setText(string + '\n' + QString::fromWCharArray(L"选取的图像不是二值图，请重新选择图像"));
                flag = false;
                return;
            }
        }
    }

    {
        // image = cv::imread(fileName.toLatin1().data()); //image从文件中读出数据
        QString string = ui->textEdit->toPlainText();
        ui->textEdit->setText(string + '\n' + QString::fromWCharArray(L"已成功读取图像") + fileName);
        flag = true;
        // QMessageBox::information(NULL, "Attention", "Image loading succeed!");

        cv::Mat rgb;
        QImage img;
        QImage imgScaled;
        if (image.channels() == 3) // cvt Mat BGR 2 QImage RGB
        {
            cvtColor(image, rgb, CV_BGR2RGB);
            img = QImage((const unsigned char *)(rgb.data),
                         rgb.cols, rgb.rows,
                         rgb.cols * rgb.channels(),
                         QImage::Format_RGB888);
            cols = rgb.cols;
        }
        else
        {
            img = QImage((const unsigned char *)(image.data),
                         image.cols, image.rows,
                         image.cols * image.channels(),
                         QImage::Format_RGB888);
            cols = image.cols;
        }
        imgScaled = img.scaled(ui->show1->size(), Qt::KeepAspectRatio);
        ui->show1->setPixmap(QPixmap::fromImage(imgScaled));
        ui->show1->resize(ui->show1->pixmap()->size());
    }
}

void MainWindow::save()
{
    if (ui->show3->pixmap() != nullptr)
    {
        QString filename = QFileDialog::getSaveFileName(this,
                                                        QString::fromStdWString(L"保存图片"),
                                                        "E:/Qtworks/MainWindow/images/images.png",
                                                        tr("*.png;; *.jpg;; *.bmp;; *.tif;; *.GIF")); //选择路径
        if (filename.isEmpty())
        {
            return;
        }
        else
        {
            if (!(ui->show3->pixmap()->toImage().save(filename))) //保存图像
            {

                QMessageBox::information(this,
                                         QString::fromStdWString(L"图片保存成功！"),
                                         QString::fromStdWString(L"图片保存失败！"));
                return;
            }
            ui->statusBar->showMessage(QString::fromStdWString(L"图片保存成功！"));
        }
    }
    else
    {
        QMessageBox::warning(nullptr, QString::fromStdWString(L"提示"), QString::fromStdWString(L"请先打开图片！"), QMessageBox::Yes | QMessageBox::Yes);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass),
      q_tri(0, std::vector<int>(3)),
      q_line(0, std::vector<int>(4)),
      q_point(0, std::vector<int>(4)),
      matrix(256, std::vector<int>(256)),
      q_rect(0, std::vector<int>(4)),
      res(256, std::vector<int>(256))
{
    ui->setupUi(this);
    ui->widget_3->hide();
    ui->pushButton_6->setStyleSheet(QString::fromUtf8("image: url(./image/person.png);"));
    ui->pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(./image/wenjian2.png);}\n"
                                                       "QPushButton:hover{background-color: rgb(168, 220, 255)}"));
    ui->pushButton_12->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(./image/save2.png);}\n"
                                                       "QPushButton:hover{background-color: rgb(168, 220, 255)}"));
    ui->pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(./image/bin.png);}\n"
                                                      "QPushButton:hover{background-color: rgb(168, 220, 255)}"));
    ui->pushButton_23->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(./image/decode2.png);}\n"
                                                       "QPushButton:hover{background-color: rgb(168, 220, 255)}"));
    ui->pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(./image/change.png);}\n"
                                                      "QPushButton:hover{background-color: rgb(168, 220, 255)}"));
    ui->pushButton_9->setCheckable(true);
    ui->pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(./image/trisqu.png);}\n"
                                                       "QPushButton:hover{background-color: rgb(168, 220, 255)}"));
    ui->pushButton_13->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(./image/square1.png);}\n"
                                                       "QPushButton:hover{background-color: rgb(168, 220, 255)}"));
    ui->pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(./image/triangle1.png);}\n"
                                                       "QPushButton:hover{background-color: rgb(168, 220, 255)}"));
    ui->pushButton_15->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(./image/more2.png);background: rgb(50, 50, 50);}\n"
                                                       "QPushButton:hover{background: rgb(80, 80, 80);}"));
    ui->pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(./image/person.png);background: rgb(238, 247, 255);}\n"
                                                      "QPushButton:hover{background: rgb(255, 80, 83);}"));
    ui->pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(./image/close2.png);background: rgb(238, 247, 255);}\n"
                                                      "QPushButton:hover{background: rgb(255, 80, 83);}"));
    ui->pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(./image/minimum2.png);background: rgb(238, 247, 255);}\n"
                                                      "QPushButton:hover{background:rgb(168, 220, 255);}\n"
                                                      "\n"
                                                      "\n"
                                                      ""));
    QIcon icon;
    icon.addFile(QString::fromUtf8("./image/shezhi.png"), QSize(), QIcon::Normal, QIcon::Off);
    ui->tabWidget->setTabIcon(0, QIcon("./image/shezhi.png"));
    this->setWindowIcon(QIcon("./image/person.png"));
    //对于命名为on_pushButton_clicked的槽函数来说，QT内部已经为其连接好了信号与槽，因此不需要再重复使用connect函数进行信号链接
    connect(this->ui->pushButton_10, SIGNAL(clicked()), this, SLOT(readImage()));
    // connect(this->ui->pushButton_23, SIGNAL(clicked()), this, SLOT(encode()));
    connect(this->ui->pushButton_12, SIGNAL(clicked()), this, SLOT(save()));
    connect(this->ui->pushButton_4, SIGNAL(clicked()), this, SLOT(on_pushButton_4_clicked()));
    connect(this->ui->pushButton_5, SIGNAL(clicked()), this, SLOT(on_pushButton_5_clicked()));
    connect(this->ui->pushButton_8, SIGNAL(clicked()), this, SLOT(on_pushButton_8_clicked()));
    connect(this->ui->pushButton_15, SIGNAL(clicked()), this, SLOT(on_pushButton_15_clicked(bool)));
    // connect(this->ui->pushButton_12, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    connect(this->ui->pushButton_9, SIGNAL(clicked()), this, SLOT(on_pushButton_9_clicked(bool)));
    ui->pushButton_9->setCheckable(true);
    // connect(this->ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    connect(this->ui->pushButton_14, SIGNAL(clicked()), this, SLOT(on_pushButton_red_clicked()));
    connect(this->ui->pushButton_13, SIGNAL(clicked()), this, SLOT(on_pushButton_green_clicked()));
    connect(this->ui->pushButton_11, SIGNAL(clicked()), this, SLOT(on_pushButton_yellow_clicked()));
    ui->textEdit->installEventFilter(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    setFixedSize(this->width(), this->height());
    setAttribute(Qt::WA_TranslucentBackground); //窗口透明度设置
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(0, 0);    //设置向哪个方向产生阴影效果(dx,dy)，特别地，(0,0)代表向四周发散
    effect->setColor(Qt::gray); //设置阴影颜色，也可以setColor(QColor(220,220,220))
    effect->setBlurRadius(20);  //设定阴影的模糊半径，数值越大越模糊
    ui->frame->setGraphicsEffect(effect);
}

void MainWindow::on_pushButton_9_clicked(bool checked)
{
    mode = !mode;
    if (checked)
    {
        ui->pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(./image/diagonal.png);}\n"
                                                           "QPushButton:hover{background-color: rgb(168, 220, 255)}"));
        ui->pushButton_13->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(./image/horizontal.png);}\n"
                                                           "QPushButton:hover{background-color: rgb(168, 220, 255)}"));
        ui->pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(./image/vertical.png);}\n"
                                                           "QPushButton:hover{background-color: rgb(168, 220, 255)}"));
        QString string = ui->textEdit->toPlainText();
        if (string == NULL)
        {
            ui->textEdit->setText(QString::fromWCharArray(L"已成功切换模式"));
        }
        else
        {
            ui->textEdit->setText(string + '\n' + QString::fromWCharArray(L"已成功切换模式"));
        }
    }
    else
    {
        ui->pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(./image/trisqu.png);}\n"
                                                           "QPushButton:hover{background-color: rgb(168, 220, 255)}"));
        ui->pushButton_13->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(./image/square1.png);}\n"
                                                           "QPushButton:hover{background-color: rgb(168, 220, 255)}"));
        ui->pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(./image/triangle1.png);}\n"
                                                           "QPushButton:hover{background-color: rgb(168, 220, 255)}"));
        QString string = ui->textEdit->toPlainText();
        if (string == NULL)
        {
            ui->textEdit->setText(QString::fromWCharArray(L"已成功切换模式"));
        }
        else
        {
            ui->textEdit->setText(string + '\n' + QString::fromWCharArray(L"已成功切换模式"));
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_12_clicked()
{
}

void MainWindow::on_pushButton_4_clicked()
{
    close();
}

void MainWindow::on_pushButton_5_clicked()
{
    showMinimized();
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->textEdit->clear();
    ui->show1->clear();
    ui->show2->clear();
    ui->show3->clear();
    ui->show1->setText(QStringLiteral("原始图片"));
    ui->show2->setText(QStringLiteral("解码图片"));
    ui->show3->setText(QStringLiteral("分割示意图"));
}

void MainWindow::on_pushButton_15_clicked(bool clicked)
{
    if (clicked == false)
    {
        clicked = true;
        ui->widget_3->show();
    }
    else
    {
        clicked = false;
        ui->widget_3->close();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        last_mouse_position_ = event->globalPos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (!event->buttons().testFlag(Qt::LeftButton))
        return;
    const QPoint position = pos() + event->globalPos() - last_mouse_position_; // the position of mainfrmae + (current_mouse_position - last_mouse_position)
    move(position.x(), position.y());
    last_mouse_position_ = event->globalPos();
}
