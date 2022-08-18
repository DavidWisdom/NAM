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
			// QString string = ui->textEdit->toPlainText();
			// if (string == NULL)
			// {
			//
			// 	ui->textEdit->setText(QString::fromWCharArray(L"您未选择图片"));
			// }
			// else
			// {
			//
			// 	ui->textEdit->setText(string + '\n' + QString::fromWCharArray(L"您未选择图片"));
			// }
			// return;
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
        //QMessageBox::information(NULL, "Attention", "Decode succeed!");
        {
            cv::Mat rgb;
            QImage img;
            QImage imgScaled;
            cv::Mat image = cv::imread("D:\\seg.jpg");

            if (image.channels() == 3)      //cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char*)(rgb.data),
                    rgb.cols, rgb.rows,
                    rgb.cols * rgb.channels(),
                    QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char*)(image.data),
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

        //QMessageBox::information(NULL, "Attention", "Decode succeed!");
        {
            cv::Mat rgb;
            QImage img;
            QImage imgScaled;
            cv::Mat image = cv::imread("D:\\decode.jpg");

            if (image.channels() == 3)      //cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char*)(rgb.data),
                    rgb.cols, rgb.rows,
                    rgb.cols * rgb.channels(),
                    QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char*)(image.data),
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

			NAM::HorizontalPriority* horizontal = NAM::HorizontalPriority::getInstance();
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

				if (image.channels() == 3)      //cvt Mat BGR 2 QImage RGB
				{
					cvtColor(image, rgb, CV_BGR2RGB);
					img = QImage((const unsigned char*)(rgb.data),
						rgb.cols, rgb.rows,
						rgb.cols * rgb.channels(),
						QImage::Format_RGB888);
					cols = rgb.cols;
				}
				else
				{
					img = QImage((const unsigned char*)(image.data),
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

				if (image.channels() == 3)      //cvt Mat BGR 2 QImage RGB
				{
					cvtColor(image, rgb, CV_BGR2RGB);
					img = QImage((const unsigned char*)(rgb.data),
						rgb.cols, rgb.rows,
						rgb.cols * rgb.channels(),
						QImage::Format_RGB888);
					cols = rgb.cols;
				}
				else
				{
					img = QImage((const unsigned char*)(image.data),
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
        //QMessageBox::information(NULL, "Attention", "Decode succeed!");
        {
            cv::Mat rgb;
            QImage img;
            QImage imgScaled;
            cv::Mat image = cv::imread("D:\\seg.jpg");

            if (image.channels() == 3)      //cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char*)(rgb.data),
                    rgb.cols, rgb.rows,
                    rgb.cols * rgb.channels(),
                    QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char*)(image.data),
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

        //QMessageBox::information(NULL, "Attention", "Decode succeed!");
        {
            cv::Mat rgb;
            QImage img;
            QImage imgScaled;
            cv::Mat image = cv::imread("D:\\decode.jpg");

            if (image.channels() == 3)      //cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char*)(rgb.data),
                    rgb.cols, rgb.rows,
                    rgb.cols * rgb.channels(),
                    QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char*)(image.data),
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
        NAM::VerticalPriority* horizontal = NAM::VerticalPriority::getInstance();
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

            if (image.channels() == 3)      //cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char*)(rgb.data),
                    rgb.cols, rgb.rows,
                    rgb.cols * rgb.channels(),
                    QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char*)(image.data),
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

            if (image.channels() == 3)      //cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char*)(rgb.data),
                    rgb.cols, rgb.rows,
                    rgb.cols * rgb.channels(),
                    QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char*)(image.data),
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
        //QMessageBox::information(NULL, "Attention", "Decode succeed!");
        {
            cv::Mat rgb;
            QImage img;
            QImage imgScaled;
            cv::Mat image = cv::imread("D:\\seg.jpg");

            if (image.channels() == 3)      //cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char*)(rgb.data),
                    rgb.cols, rgb.rows,
                    rgb.cols * rgb.channels(),
                    QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char*)(image.data),
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

        //QMessageBox::information(NULL, "Attention", "Decode succeed!");
        {
            cv::Mat rgb;
            QImage img;
            QImage imgScaled;
            cv::Mat image = cv::imread("D:\\decode.jpg");

            if (image.channels() == 3)      //cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char*)(rgb.data),
                    rgb.cols, rgb.rows,
                    rgb.cols * rgb.channels(),
                    QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char*)(image.data),
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
        NAM::DiagonalPriority* horizontal = NAM::DiagonalPriority::getInstance();
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

            if (image.channels() == 3)      //cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char*)(rgb.data),
                    rgb.cols, rgb.rows,
                    rgb.cols * rgb.channels(),
                    QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char*)(image.data),
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

            if (image.channels() == 3)      //cvt Mat BGR 2 QImage RGB
            {
                cvtColor(image, rgb, CV_BGR2RGB);
                img = QImage((const unsigned char*)(rgb.data),
                    rgb.cols, rgb.rows,
                    rgb.cols * rgb.channels(),
                    QImage::Format_RGB888);
                cols = rgb.cols;
            }
            else
            {
                img = QImage((const unsigned char*)(image.data),
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
    if (img.empty()) {
        //QMessageBox::information(this, "Attention", "Could not open the file!");
        return;
    }
    qDebug() << "filenames:" << fileName;
    if (fileName.isEmpty()) {         //String类型判断为空
        //QMessageBox::information(NULL, "Attention", "Image loading failed!");
        return;
    }
    image = cv::imread(fileName.toUtf8().data()); //image从文件中读出数据,将toLatin1改成toUtf8后支持了中文文件名
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
    for (int i = 0; i < img.rows; ++i) {
        for (int j = 0; j < img.cols; ++j) {
            //org[i][j] = static_cast<int>(f[i][j]);
            if (img.at<uchar>(i, j) != 0 && img.at<uchar>(i, j) != 255) {

                QString string = ui->textEdit->toPlainText();
                ui->textEdit->setText(string + '\n' + QString::fromWCharArray(L"选取的图像不是二值图，请重新选择图像"));
                flag = false;
                return;
            }
        }
    }

    {
        //image = cv::imread(fileName.toLatin1().data()); //image从文件中读出数据
        QString string = ui->textEdit->toPlainText();
        ui->textEdit->setText(string + '\n' + QString::fromWCharArray(L"已成功读取图像") + fileName);
        flag = true;
        //QMessageBox::information(NULL, "Attention", "Image loading succeed!");

        cv::Mat rgb;
        QImage img;
        QImage imgScaled;
        if (image.channels() == 3)      //cvt Mat BGR 2 QImage RGB
        {
            cvtColor(image, rgb, CV_BGR2RGB);
            img = QImage((const unsigned char*)(rgb.data),
                rgb.cols, rgb.rows,
                rgb.cols * rgb.channels(),
                QImage::Format_RGB888);
            cols = rgb.cols;
        }
        else
        {
            img = QImage((const unsigned char*)(image.data),
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
 //    // {
 //    //     for (int i = 0; i < img.rows; ++i) {
 //    //         for (int j = 0; j < img.cols; ++j) {
 //    //             f[i][j] = static_cast<double>(img.at<uchar>(i, j)) / 255;
 //    //             mark[i][j] = f[i][j];
 //    //             //org[i][j] = static_cast<int>(f[i][j]);
 //    //         }
 //    //     }
 //    //     tnam();
 //    //     std::ofstream ofs;
 //    //     ofs.open("q_tri.txt", std::ios::out);
 //    //     for (auto& tr : q_tri)
 //    //     {
 //    //         for (auto& it : tr)
 //    //         {
 //    //             ofs << it << " ";
 //    //         }
 //    //         ofs << "\n";
 //    //     }
 //    //     ofs.close();
 //    //     std::ofstream ofs2;
 //    //     ofs2.open("q_line_and_point.txt", std::ios::out);
 //    //     for (auto& tr : q_line_and_point)
 //    //     {
 //    //         for (auto& it : tr)
 //    //         {
 //    //             ofs2 << it << " ";
 //    //         }
 //    //         ofs2 << "\n";
 //    //     }
 //    //     ofs2.close();
 //    QString s1 = QString::number(NAM::TNAM::num_of_total_triangular);
 //    QString s2 = QString::number(NAM::TNAM::num_of_lines);
 //    QString s3 = QString::number(NAM::TNAM::num_of_points);
 //    QString string = ui->textEdit->toPlainText();
 //    ui->textEdit->setText(string + '\n' + QString::fromWCharArray(L"已成功编码") + fileName + '\n' + QString::fromWCharArray(L"当前图片三角子模式数量：") + s1 + '\n' + QString::fromWCharArray(L"线段子模式数量：") + s2 + '\n' + QString::fromWCharArray(L"孤立点子模式数量：") + s3);
 //
 //
 //    //{
 // //       QString fileName = QFileDialog::getOpenFileName(this, tr("选择日志文件"), "", tr("TXT(*.txt)")); //选择路径
 // //       if (fileName.isEmpty()) {
 // //           QMessageBox::information(NULL, "Attention", "File loading failed!");
 // //           return;
 // //       }//如果未选择文件便确认，即返回 
 // //       QString strFileCopyPath = "D:\\user\\projects\\VS\\QtWidgetsApplication1\\QtWidgetsApplication1\\";
 // //       QString strFileName = "q_tri";
 // //       QFile::copy(fileName, strFileCopyPath + strFileName + ".txt");
 // //       std::ifstream ifs;
 // //       ifs.open("q_tri.txt", std::ios::in);
 // //       if (!ifs.is_open())
 // //       {
 // //           QMessageBox::information(NULL, "Attention", "File loading failed!");
 // //           return;
 // //       }
 // //       else
 // //       {
 // //           QMessageBox::information(NULL, "Attention", "File loading succeed!");
 // //       }
 // //       int val1;
 // //       int val2;
 // //       int val3;
 // //       int val4;
 // //       int val5;
 // //       while (ifs >> val1 >> val2 >> val3 >> val4 >> val5)
 // //       {
 // //           tri.push_back({ val1, val2, val3, val4, val5 });
 // //       }
 // //       ifs.close();
 //
 //    //}
 //    //{
 // //       QString fileName = QFileDialog::getOpenFileName(this, tr("选择日志文件"), "", tr("TXT(*.txt)")); //选择路径
 // //       if (fileName.isEmpty()) {
 // //           QMessageBox::information(NULL, "Attention", "File loading failed!");
 // //           return;
 // //       }//如果未选择文件便确认，即返回 
 // //       QString strFileCopyPath = "D:\\user\\projects\\VS\\QtWidgetsApplication1\\QtWidgetsApplication1\\";
 // //       QString strFileName = "q_line_and_point";
 // //       QFile::copy(fileName, strFileCopyPath + strFileName + ".txt");
 // //       std::ifstream ifs;
 // //       ifs.open("q_line_and_point.txt", std::ios::in);
 // //       //ifs.open("q_tri.txt", std::ios::in);
 // //       if (!ifs.is_open())
 // //       {
 // //           QMessageBox::information(NULL, "Attention", "File loading failed!");
 // //           return;
 // //       }
 // //       else
 // //       {
 // //           QMessageBox::information(NULL, "Attention", "File loading succeed!");
 // //       }
 // //       //std::ifstream ifs;
 // //       //if (!ifs.is_open())
 // //       //{
 // //       //    assert(false);
 // //       //}
 // //       int val1;
 // //       int val2;
 // //       int val3;
 // //       int val4;
 // //       //int val5;
 // //       while (ifs >> val1 >> val2 >> val3 >> val4)
 // //       {
 // //           line.push_back({ val1, val2, val3, val4 });
 // //       }
 // //       ifs.close();
 //
 //    //}
 //    // std::ofstream ofs;
 //    // ofs.open("matrix.txt", std::ios::out);
 //    // cv::Mat decode(256, 256, CV_8UC1, cv::Scalar(255));
 //    // cv::Mat original(256, 256, CV_8UC1, cv::Scalar(255));
 //    // //cv::imwrite("decode.bmp", decode);
 //    //
 //    // for (size_t k = 0; k < tri.size(); ++k)
 //    // {
 //    //     const int flag = tri[k][0];
 //    //     const int x1_abs = tri[k][1];
 //    //     const int y1_abs = tri[k][2];
 //    //     const int x2_abs = tri[k][3];
 //    //     const int y2_abs = tri[k][4];
 //    //     switch (flag)
 //    //     {
 //    //     case 0:
 //    //     {
 //    //         int step = 0;
 //    //         for (int i = x1_abs; i <= x2_abs; ++i)
 //    //         {
 //    //             for (int j = y1_abs + step; j <= y2_abs; ++j)
 //    //             {
 //    //                 res[i - 1][j - 1] = 0;
 //    //             }
 //    //             step++;
 //    //         }
 //    //         //cv::Point2d p0(x1_abs, y1_abs);
 //    //         //cv::Point2d p1(x1_abs, y2_abs);
 //    //         //cv::Point2d p2(x2_abs, y2_abs);
 //    //         cv::Point2d p0(y1_abs, x1_abs);
 //    //         cv::Point2d p1(y2_abs, x1_abs);
 //    //         cv::Point2d p2(y2_abs, x2_abs);
 //    //         cv::line(decode, p0, p1, cv::Scalar(0, 0, 0));
 //    //         cv::line(decode, p0, p2, cv::Scalar(0, 0, 0));
 //    //         cv::line(decode, p1, p2, cv::Scalar(0, 0, 0));
 //    //         //f();
 //    //         //Sleep(1000);
 //    //     }
 //    //     break;
 //    //     case 1:
 //    //     {
 //    //         int step = 0;
 //    //         for (int i = x1_abs; i <= x2_abs; ++i)
 //    //         {
 //    //             for (int j = y1_abs; j <= y1_abs + step; ++j)
 //    //             {
 //    //                 res[i - 1][j - 1] = 0;
 //    //
 //    //             }
 //    //             step++;
 //    //         }
 //    //         //cv::Point2d p0(x1_abs, y1_abs);
 //    //         //cv::Point2d p1(x2_abs, y1_abs);
 //    //         //cv::Point2d p2(x2_abs, y1_abs + step - 1);
 //    //         cv::Point2d p0(y1_abs, x1_abs);
 //    //         cv::Point2d p1(y1_abs, x2_abs);
 //    //         cv::Point2d p2(y1_abs + step - 1, x2_abs);
 //    //         cv::line(decode, p0, p1, cv::Scalar(0, 0, 0));
 //    //         cv::line(decode, p0, p2, cv::Scalar(0, 0, 0));
 //    //         cv::line(decode, p1, p2, cv::Scalar(0, 0, 0));
 //    //         //f();
 //    //         //Sleep(1000);
 //    //     }
 //    //     break;
 //    //     default:
 //    //         break;
 //    //     }
 //    // }
 //    // for (size_t j = 0; j < line.size(); ++j)
 //    // {
 //    //     const int x = line[j][0];
 //    //     const int y = line[j][1];
 //    //     const int maxLength = line[j][2];
 //    //     const int maxWidth = line[j][3];
 //    //     for (int a = x; a <= x + maxLength - 1; ++a)
 //    //     {
 //    //         for (int b = y; b <= y + maxWidth - 1; ++b)
 //    //         {
 //    //             res[a - 1][b - 1] = 0;
 //    //         }
 //    //     }
 //    //     //cv::Point2d p0(x, y);
 //    //     cv::Point2d p0(y, x);
 //    //     cv::Point2d p1(y + maxWidth - 1, x + maxLength - 1);
 //    //     //cv::Point2d p1(x + maxLength - 1, y + maxWidth - 1);
 //    //     cv::line(decode, p0, p1, cv::Scalar(0, 0, 0));
 //    //     //f();
 //    //     //Sleep(1000);
 //    // }
 //    // //cv::Mat encode;
 //    //
 //    // for (auto& tr : res)
 //    // {
 //    //     for (auto& it : tr)
 //    //     {
 //    //         ofs << it << " ";
 //    //     }
 //    //     ofs << "\n";
 //    // }
 //
 //    //{ cv::Mat rgb;
 //    //QImage img;
 //    //QImage imgScaled;
 //    //cv::Mat image = cv::imread("decode.bmp");
 //    //if (image.channels() == 3)      //cvt Mat BGR 2 QImage RGB
 //    //{
 //    //    cvtColor(image, rgb, CV_BGR2RGB);
 //    //    img = QImage((const unsigned char*)(rgb.data),
 //    //        rgb.cols, rgb.rows,
 //    //        rgb.cols * rgb.channels(),
 //    //        QImage::Format_RGB888);
 //    //    cols = rgb.cols;
 //    //}
 //    //else
 //    //{
 //    //    img = QImage((const unsigned char*)(image.data),
 //    //        image.cols, image.rows,
 //    //        image.cols * image.channels(),
 //    //        QImage::Format_RGB888);
 //    //    cols = image.cols;
 //    //}
 //    //imgScaled = img.scaled(ui->show2->size(), Qt::KeepAspectRatio);
 //
 //    //ui->show2->setPixmap(QPixmap::fromImage(imgScaled));
 //    //ui->show2->resize(ui->show2->pixmap()->size());
 //    //}
 //    //auto f = [&]() {
 //    cv::imwrite("D:\\seg.jpg", seg);
 //
 //    //QMessageBox::information(NULL, "Attention", "Decode succeed!");
 //    {
 //        cv::Mat rgb;
 //        QImage img;
 //        QImage imgScaled;
 //        cv::Mat image = cv::imread("D:\\seg.jpg");
 //
 //        if (image.channels() == 3)      //cvt Mat BGR 2 QImage RGB
 //        {
 //            cvtColor(image, rgb, CV_BGR2RGB);
 //            img = QImage((const unsigned char*)(rgb.data),
 //                rgb.cols, rgb.rows,
 //                rgb.cols * rgb.channels(),
 //                QImage::Format_RGB888);
 //            cols = rgb.cols;
 //        }
 //        else
 //        {
 //            img = QImage((const unsigned char*)(image.data),
 //                image.cols, image.rows,
 //                image.cols * image.channels(),
 //                QImage::Format_RGB888);
 //            cols = image.cols;
 //        }
 //        imgScaled = img.scaled(ui->show3->size(), Qt::KeepAspectRatio);
 //
 //        ui->show3->setPixmap(QPixmap::fromImage(imgScaled));
 //        ui->show3->resize(ui->show3->pixmap()->size());
 //    }
 //    cv::imwrite("D:\\decode.jpg", dst);
 //
 //    //QMessageBox::information(NULL, "Attention", "Decode succeed!");
 //    {
 //        cv::Mat rgb;
 //        QImage img;
 //        QImage imgScaled;
 //        cv::Mat image = cv::imread("D:\\decode.jpg");
 //
 //        if (image.channels() == 3)      //cvt Mat BGR 2 QImage RGB
 //        {
 //            cvtColor(image, rgb, CV_BGR2RGB);
 //            img = QImage((const unsigned char*)(rgb.data),
 //                rgb.cols, rgb.rows,
 //                rgb.cols * rgb.channels(),
 //                QImage::Format_RGB888);
 //            cols = rgb.cols;
 //        }
 //        else
 //        {
 //            img = QImage((const unsigned char*)(image.data),
 //                image.cols, image.rows,
 //                image.cols * image.channels(),
 //                QImage::Format_RGB888);
 //            cols = image.cols;
 //        }
 //        imgScaled = img.scaled(ui->show2->size(), Qt::KeepAspectRatio);
 //
 //        ui->show2->setPixmap(QPixmap::fromImage(imgScaled));
 //        ui->show2->resize(ui->show2->pixmap()->size());
 //    }
if (ui->show3->pixmap() != nullptr) {
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
else {
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
        "QPushButton:hover{background:rgb(168, 220, 255);}\n""\n"
        "\n"
        ""));
    QIcon icon;
    icon.addFile(QString::fromUtf8("./image/shezhi.png"), QSize(), QIcon::Normal, QIcon::Off);
    ui->tabWidget->setTabIcon(0, QIcon("./image/shezhi.png"));
    this->setWindowIcon(QIcon("./image/person.png"));
    //对于命名为on_pushButton_clicked的槽函数来说，QT内部已经为其连接好了信号与槽，因此不需要再重复使用connect函数进行信号链接
    connect(this->ui->pushButton_10, SIGNAL(clicked()), this, SLOT(readImage()));
    //connect(this->ui->pushButton_23, SIGNAL(clicked()), this, SLOT(encode()));
    connect(this->ui->pushButton_12, SIGNAL(clicked()), this, SLOT(save()));
    connect(this->ui->pushButton_4, SIGNAL(clicked()), this, SLOT(on_pushButton_4_clicked()));
    connect(this->ui->pushButton_5, SIGNAL(clicked()), this, SLOT(on_pushButton_5_clicked()));
    connect(this->ui->pushButton_8, SIGNAL(clicked()), this, SLOT(on_pushButton_8_clicked()));
    connect(this->ui->pushButton_15, SIGNAL(clicked()), this, SLOT(on_pushButton_15_clicked(bool)));
    //connect(this->ui->pushButton_12, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    connect(this->ui->pushButton_9, SIGNAL(clicked()), this, SLOT(on_pushButton_9_clicked(bool)));
    ui->pushButton_9->setCheckable(true);
    //connect(this->ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    connect(this->ui->pushButton_14, SIGNAL(clicked()), this, SLOT(on_pushButton_red_clicked()));
    connect(this->ui->pushButton_13, SIGNAL(clicked()), this, SLOT(on_pushButton_green_clicked()));
    connect(this->ui->pushButton_11, SIGNAL(clicked()), this, SLOT(on_pushButton_yellow_clicked()));
    ui->textEdit->installEventFilter(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    setFixedSize(this->width(), this->height());
    setAttribute(Qt::WA_TranslucentBackground);//窗口透明度设置
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(0, 0);          //设置向哪个方向产生阴影效果(dx,dy)，特别地，(0,0)代表向四周发散
    effect->setColor(Qt::gray);       //设置阴影颜色，也可以setColor(QColor(220,220,220))
    effect->setBlurRadius(20);        //设定阴影的模糊半径，数值越大越模糊
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
        if (string == NULL) {
            ui->textEdit->setText(QString::fromWCharArray(L"已成功切换模式"));
        }
        else {
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
        if (string == NULL) {
            ui->textEdit->setText(QString::fromWCharArray(L"已成功切换模式"));
        }
        else {
            ui->textEdit->setText(string + '\n' + QString::fromWCharArray(L"已成功切换模式"));
        }
    }
}
// const int size = 256;
// std::vector<std::vector<double>> f(size, std::vector<double>(size, 0));
// std::vector<std::vector<double>> mark(size, std::vector<double>(size, 0));
// std::vector<std::vector<int>> q_tri(0, std::vector<int>(5));
// std::vector<std::vector<int>> q_line_and_point(0, std::vector<int>(4));
// bool sum_of_current_matrix = false;
// size_t num_of_upper_triangular = 0;
// size_t num_of_lower_triangular = 0;
// size_t num_of_total_triangular = 0;
// size_t num_of_points = 0;
// size_t num_of_lines = 0;
// size_t num_of_black_node = 0;
// QString fileName;
// float cols;
// void triu(const int& r1, const int& r2, const int& c1, const int& c2, const int& k)
// {
//     sum_of_current_matrix = false;
//     for (int i = r1; i <= r2; ++i)
//     {
//         for (int j = c1; j <= c2; ++j)
//         {
//             if ((j - c1) - (i - r1) >= k)
//             {
//                 if (mark[i][j] > 0.)
//                 {
//                     sum_of_current_matrix = true;
//                     return;
//                 }
//             }
//         }
//     }
// }
// void tril(const int& r1, const int& r2, const int& c1, const int& c2, const int& k)
// {
//     sum_of_current_matrix = false;
//     for (int i = r1; i <= r2; ++i)
//     {
//         for (int j = c1; j <= c2; ++j)
//         {
//             if ((i - r1) - (j - c1) >= k)
//             {
//                 if (mark[i][j] > 0.)
//                 {
//                     sum_of_current_matrix = true;
//                     return;
//                 }
//             }
//         }
//     }
// }
//
// std::vector<std::vector<int>> tri;
// std::vector<std::vector<int>> line;
//
// void tnam()
// {
//     tri.clear();
//     line.clear();
//     //cv::Mat sketch;
//     num_of_upper_triangular = 0;
//     num_of_lower_triangular = 0;
//     num_of_total_triangular = 0;
//     num_of_points = 0;
//     num_of_lines = 0;
//     num_of_black_node = 0;
//     for (int x = 1; x <= size - 1; ++x)
//     {
//         for (int y = 1; y <= size - 1; ++y)
//         {
//             for (int step = size - 1; step >= 1; --step)
//             {
//                 if (x + step <= size && y + step <= size)
//                 {
//                     int k1 = -0x3f3f3f;
//                     int k2 = 0x3f3f3f;
//                     const int size_temp = step + 1;
//                     for (int k = 0; k <= size_temp - 2;)
//                     {
//                         triu(x - 1, x + step - 1, y - 1, y + step - 1, k);
//                         if (!sum_of_current_matrix)
//                         {
//                             num_of_upper_triangular++;
//                             num_of_total_triangular++;
//                             k1 = k;
//                         }
//                         break;
//                     }
//                     for (int k = 0; k >= -size_temp + 2;)
//                     {
//                         tril(x - 1, x + step - 1, y - 1, y + step - 1, k);
//                         if (!sum_of_current_matrix)
//                         {
//                             num_of_lower_triangular++;
//                             num_of_total_triangular++;
//                             k2 = k;
//                         }
//                         break;
//                     }
//                     if (k1 != -0x3f3f3f)
//                     {
//                         const int& k = k1;
//                         const int x1 = 1;
//                         const int y1 = k + 1;
//                         const int x2 = size_temp - k;
//                         const int y2 = size_temp;
//                         const int x1_abs = x1 + x - 1;
//                         const int y1_abs = y1 + y - 1;
//                         const int x2_abs = x2 + x - 1;
//                         const int y2_abs = y2 + y - 1;
//                         std::vector<int> tr = { 0, x1_abs, y1_abs, x2_abs, y2_abs };
//                         q_tri.emplace_back(tr);
//                         tri.emplace_back(tr);
//                         for (int i = x1; i <= x2; ++i)
//                         {
//                             for (int j = (i + k); j <= y2; ++j)
//                             {
//                                 mark[i + x - 2][j + y - 2] = 8.;
//                             }
//                         }
//                     }
//                     if (k2 != 0x3f3f3f)
//                     {
//                         const int& k = k2;
//                         const int x1 = 1 - k;
//                         const int y1 = 1;
//                         const int x2 = size_temp;
//                         const int y2 = size_temp + k;
//                         const int x1_abs = x1 + x - 1;
//                         const int y1_abs = y1 + y - 1;
//                         const int x2_abs = x2 + x - 1;
//                         const int y2_abs = y2 + y - 1;
//                         std::vector<int> tri = { 1, x1_abs, y1_abs, x2_abs, y2_abs };
//                         q_tri.emplace_back(tri);
//                         for (int i = x1; i <= x2; ++i)
//                         {
//                             for (int j = 1; j <= i + k; ++j)
//                             {
//                                 mark[i + x - 2][j + y - 2] = 9.;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     f = mark;
//     int length0 = 1;
//     int width0 = 1;
//     for (int x = 1; x <= size; ++x)
//     {
//         for (int y = 1; y <= size; ++y)
//         {
//             int sp_x = x;
//             int sp_y = y;
//             if (f[x - 1][y - 1] == 0.)
//             {
//                 int length = 1;
//                 int width = 1;
//                 int maxLength = 1;
//                 int maxWidth = 1;
//                 int maxArea = 0;
//                 int last = 0;
//                 for (int j = y; j <= size; ++j)
//                 {
//                     length0 = 0;
//                     for (int k = x; k <= size; ++k)
//                     {
//                         //TODO:补充
//                         if (j != y && (k - sp_x + 1 > last))
//                         {
//                             break;
//                         }
//                         if (f[k - 1][j - 1] != 0.)
//                         {
//                             break;
//                         }
//                         length0++;
//                     }
//                     if (j == y || length0 < last)
//                     {
//                         last = length0;
//                     }
//                     //TODO:补充
//                     if (f[x - 1][j - 1] != 0.)
//                     {
//                         break;
//                     }
//                     width0++;
//                     int area = last * (j - sp_y + 1);
//                     length = last;
//                     width = j - sp_y + 1;
//                     if (area > maxArea)
//                     {
//                         maxArea = area;
//                         maxLength = last;
//                         maxWidth = j - sp_y + 1;
//                     }
//                 }
//                 if (maxLength * maxWidth == 1)
//                 {
//                     num_of_points++;
//                 }
//                 else
//                 {
//                     num_of_lines++;
//                 }
//                 num_of_black_node++;
//                 q_line_and_point.push_back({ x, y, maxLength, maxWidth });
//                 line.push_back({ x, y, maxLength, maxWidth });
//                 for (int a = x; a <= x + maxLength - 1; ++a)
//                 {
//                     for (int b = y; b <= y + maxWidth - 1; ++b)
//                     {
//                         f[a - 1][b - 1] = 7;
//                     }
//                 }
//             }
//         }
//     }
// }
// void MainWindow::readImage()
// {
//     flag = false;
//     fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files (*.bmp)"));
//     //弹出文件选取框，选取一个来自该三种格式的图片,图片来源路径不能有中文，不然无法显示
//     img = cv::imread(cv::String(fileName.toLocal8Bit().toStdString()), -1);
//     if (img.empty()) {
//         //QMessageBox::information(this, "Attention", "Could not open the file!");
//         return;
//     }
//     qDebug() << "filenames:" << fileName;
//     if (fileName.isEmpty()) {         //String类型判断为空
//         //QMessageBox::information(NULL, "Attention", "Image loading failed!");
//         return;
//     }
//     image = cv::imread(fileName.toUtf8().data()); //image从文件中读出数据,将toLatin1改成toUtf8后支持了中文文件名
//     cv::Mat tmp = image;
//     /*cv::imwrite("origin.jpg", tmp);
//     image = cv::imread("./origin.jpg", -1);*/
//     QString str = ui->textEdit->toPlainText();
//     if (str == NULL)
//     {
//
//         ui->textEdit->setText(QString::fromWCharArray(L"选择图像") + fileName);
//     }
//     else
//     {
//
//         ui->textEdit->setText(str + '\n' + QString::fromWCharArray(L"选择图像") + fileName);
//     }
//     QString filename = fileName;
//     for (int i = 0; i < img.rows; ++i) {
//         for (int j = 0; j < img.cols; ++j) {
//             //org[i][j] = static_cast<int>(f[i][j]);
//             if (img.at<uchar>(i, j) != 0 && img.at<uchar>(i, j) != 255) {
//
//                 QString string = ui->textEdit->toPlainText();
//                 ui->textEdit->setText(string + '\n' + QString::fromWCharArray(L"选取的图像不是二值图，请重新选择图像"));
//                 flag = false;
//                 return;
//             }
//         }
//     }
//
//     {
//         //image = cv::imread(fileName.toLatin1().data()); //image从文件中读出数据
//         QString string = ui->textEdit->toPlainText();
//         ui->textEdit->setText(string + '\n' + QString::fromWCharArray(L"已成功读取图像") + fileName);
//         flag = true;
//         cv::Mat rgb;
//         QImage img;
//         QImage imgScaled;
//         if (image.channels() == 3)      //cvt Mat BGR 2 QImage RGB
//         {
//             cvtColor(image, rgb, CV_BGR2RGB);
//             img = QImage((const unsigned char*)(rgb.data),
//                 rgb.cols, rgb.rows,
//                 rgb.cols * rgb.channels(),
//                 QImage::Format_RGB888);
//             cols = rgb.cols;
//         }
//         else
//         {
//             img = QImage((const unsigned char*)(image.data),
//                 image.cols, image.rows,
//                 image.cols * image.channels(),
//                 QImage::Format_RGB888);
//             cols = image.cols;
//         }
//         imgScaled = img.scaled(ui->show1->size(), Qt::KeepAspectRatio);
//         ui->show1->setPixmap(QPixmap::fromImage(imgScaled));
//         ui->show1->resize(ui->show1->pixmap()->size());
//     }
// }
//
// std::vector<std::vector<int>> res(256, std::vector<int>(256, 1));
//
// void MainWindow::encode()
// {
//     if (!flag)
//     {
//         QString string = ui->textEdit->toPlainText();
//         if (string == NULL)
//         {
//
//             ui->textEdit->setText(QString::fromWCharArray(L"您未选择图片"));
//         }
//         else
//         {
//
//             ui->textEdit->setText(string + '\n' + QString::fromWCharArray(L"您未选择图片"));
//         }
//         return;
//     }
//     {
//         for (int i = 0; i < img.rows; ++i) {
//             for (int j = 0; j < img.cols; ++j) {
//                 f[i][j] = static_cast<double>(img.at<uchar>(i, j)) / 255;
//                 mark[i][j] = f[i][j];
//                 //org[i][j] = static_cast<int>(f[i][j]);
//             }
//         }
//         tnam();
//         std::ofstream ofs;
//         ofs.open("q_tri.txt", std::ios::out);
//         for (auto& tr : q_tri)
//         {
//             for (auto& it : tr)
//             {
//                 ofs << it << " ";
//             }
//             ofs << "\n";
//         }
//         ofs.close();
//         std::ofstream ofs2;
//         ofs2.open("q_line_and_point.txt", std::ios::out);
//         for (auto& tr : q_line_and_point)
//         {
//             for (auto& it : tr)
//             {
//                 ofs2 << it << " ";
//             }
//             ofs2 << "\n";
//         }
//         ofs2.close();
//         QString s1 = QString::number(num_of_total_triangular);
//         QString s2 = QString::number(num_of_lines);
//         QString s3 = QString::number(num_of_points);
//         QString string = ui->textEdit->toPlainText();
//         ui->textEdit->setText(string + '\n' + QString::fromWCharArray(L"已成功编码") + fileName + '\n' + QString::fromWCharArray(L"当前图片三角子模式数量：") + s1 + '\n' + QString::fromWCharArray(L"线段子模式数量：") + s2 + '\n' + QString::fromWCharArray(L"孤立点子模式数量：") + s3);
//
//     }
//     //{
//  //       QString fileName = QFileDialog::getOpenFileName(this, tr("选择日志文件"), "", tr("TXT(*.txt)")); //选择路径
//  //       if (fileName.isEmpty()) {
//  //           QMessageBox::information(NULL, "Attention", "File loading failed!");
//  //           return;
//  //       }//如果未选择文件便确认，即返回 
//  //       QString strFileCopyPath = "D:\\user\\projects\\VS\\QtWidgetsApplication1\\QtWidgetsApplication1\\";
//  //       QString strFileName = "q_tri";
//  //       QFile::copy(fileName, strFileCopyPath + strFileName + ".txt");
//  //       std::ifstream ifs;
//  //       ifs.open("q_tri.txt", std::ios::in);
//  //       if (!ifs.is_open())
//  //       {
//  //           QMessageBox::information(NULL, "Attention", "File loading failed!");
//  //           return;
//  //       }
//  //       else
//  //       {
//  //           QMessageBox::information(NULL, "Attention", "File loading succeed!");
//  //       }
//  //       int val1;
//  //       int val2;
//  //       int val3;
//  //       int val4;
//  //       int val5;
//  //       while (ifs >> val1 >> val2 >> val3 >> val4 >> val5)
//  //       {
//  //           tri.push_back({ val1, val2, val3, val4, val5 });
//  //       }
//  //       ifs.close();
//
//     //}
//     //{
//  //       QString fileName = QFileDialog::getOpenFileName(this, tr("选择日志文件"), "", tr("TXT(*.txt)")); //选择路径
//  //       if (fileName.isEmpty()) {
//  //           QMessageBox::information(NULL, "Attention", "File loading failed!");
//  //           return;
//  //       }//如果未选择文件便确认，即返回 
//  //       QString strFileCopyPath = "D:\\user\\projects\\VS\\QtWidgetsApplication1\\QtWidgetsApplication1\\";
//  //       QString strFileName = "q_line_and_point";
//  //       QFile::copy(fileName, strFileCopyPath + strFileName + ".txt");
//  //       std::ifstream ifs;
//  //       ifs.open("q_line_and_point.txt", std::ios::in);
//  //       //ifs.open("q_tri.txt", std::ios::in);
//  //       if (!ifs.is_open())
//  //       {
//  //           QMessageBox::information(NULL, "Attention", "File loading failed!");
//  //           return;
//  //       }
//  //       else
//  //       {
//  //           QMessageBox::information(NULL, "Attention", "File loading succeed!");
//  //       }
//  //       //std::ifstream ifs;
//  //       //if (!ifs.is_open())
//  //       //{
//  //       //    assert(false);
//  //       //}
//  //       int val1;
//  //       int val2;
//  //       int val3;
//  //       int val4;
//  //       //int val5;
//  //       while (ifs >> val1 >> val2 >> val3 >> val4)
//  //       {
//  //           line.push_back({ val1, val2, val3, val4 });
//  //       }
//  //       ifs.close();
//
//     //}
//     std::ofstream ofs;
//     ofs.open("matrix.txt", std::ios::out);
//     cv::Mat decode(256, 256, CV_8UC1, cv::Scalar(255));
//     cv::Mat original(256, 256, CV_8UC1, cv::Scalar(255));
//     //cv::imwrite("decode.bmp", decode);
//
//     for (size_t k = 0; k < tri.size(); ++k)
//     {
//         const int flag = tri[k][0];
//         const int x1_abs = tri[k][1];
//         const int y1_abs = tri[k][2];
//         const int x2_abs = tri[k][3];
//         const int y2_abs = tri[k][4];
//         switch (flag)
//         {
//         case 0:
//         {
//             int step = 0;
//             for (int i = x1_abs; i <= x2_abs; ++i)
//             {
//                 for (int j = y1_abs + step; j <= y2_abs; ++j)
//                 {
//                     res[i - 1][j - 1] = 0;
//                 }
//                 step++;
//             }
//             //cv::Point2d p0(x1_abs, y1_abs);
//             //cv::Point2d p1(x1_abs, y2_abs);
//             //cv::Point2d p2(x2_abs, y2_abs);
//             cv::Point2d p0(y1_abs, x1_abs);
//             cv::Point2d p1(y2_abs, x1_abs);
//             cv::Point2d p2(y2_abs, x2_abs);
//             cv::line(decode, p0, p1, cv::Scalar(0, 0, 0));
//             cv::line(decode, p0, p2, cv::Scalar(0, 0, 0));
//             cv::line(decode, p1, p2, cv::Scalar(0, 0, 0));
//             //f();
//             //Sleep(1000);
//         }
//         break;
//         case 1:
//         {
//             int step = 0;
//             for (int i = x1_abs; i <= x2_abs; ++i)
//             {
//                 for (int j = y1_abs; j <= y1_abs + step; ++j)
//                 {
//                     res[i - 1][j - 1] = 0;
//
//                 }
//                 step++;
//             }
//             //cv::Point2d p0(x1_abs, y1_abs);
//             //cv::Point2d p1(x2_abs, y1_abs);
//             //cv::Point2d p2(x2_abs, y1_abs + step - 1);
//             cv::Point2d p0(y1_abs, x1_abs);
//             cv::Point2d p1(y1_abs, x2_abs);
//             cv::Point2d p2(y1_abs + step - 1, x2_abs);
//             cv::line(decode, p0, p1, cv::Scalar(0, 0, 0));
//             cv::line(decode, p0, p2, cv::Scalar(0, 0, 0));
//             cv::line(decode, p1, p2, cv::Scalar(0, 0, 0));
//             //f();
//             //Sleep(1000);
//         }
//         break;
//         default:
//             break;
//         }
//     }
//     for (size_t j = 0; j < line.size(); ++j)
//     {
//         const int x = line[j][0];
//         const int y = line[j][1];
//         const int maxLength = line[j][2];
//         const int maxWidth = line[j][3];
//         for (int a = x; a <= x + maxLength - 1; ++a)
//         {
//             for (int b = y; b <= y + maxWidth - 1; ++b)
//             {
//                 res[a - 1][b - 1] = 0;
//             }
//         }
//         //cv::Point2d p0(x, y);
//         cv::Point2d p0(y, x);
//         cv::Point2d p1(y + maxWidth - 1, x + maxLength - 1);
//         //cv::Point2d p1(x + maxLength - 1, y + maxWidth - 1);
//         cv::line(decode, p0, p1, cv::Scalar(0, 0, 0));
//         //f();
//         //Sleep(1000);
//     }
//     //cv::Mat encode;
//
//     for (auto& tr : res)
//     {
//         for (auto& it : tr)
//         {
//             ofs << it << " ";
//         }
//         ofs << "\n";
//     }
//
//     //{ cv::Mat rgb;
//     //QImage img;
//     //QImage imgScaled;
//     //cv::Mat image = cv::imread("decode.bmp");
//     //if (image.channels() == 3)      //cvt Mat BGR 2 QImage RGB
//     //{
//     //    cvtColor(image, rgb, CV_BGR2RGB);
//     //    img = QImage((const unsigned char*)(rgb.data),
//     //        rgb.cols, rgb.rows,
//     //        rgb.cols * rgb.channels(),
//     //        QImage::Format_RGB888);
//     //    cols = rgb.cols;
//     //}
//     //else
//     //{
//     //    img = QImage((const unsigned char*)(image.data),
//     //        image.cols, image.rows,
//     //        image.cols * image.channels(),
//     //        QImage::Format_RGB888);
//     //    cols = image.cols;
//     //}
//     //imgScaled = img.scaled(ui->show2->size(), Qt::KeepAspectRatio);
//
//     //ui->show2->setPixmap(QPixmap::fromImage(imgScaled));
//     //ui->show2->resize(ui->show2->pixmap()->size());
//     //}
//     //auto f = [&]() {
//
//     cv::imwrite(".\\decode.jpg", decode);
//     //QMessageBox::information(NULL, "Attention", "Decode succeed!");
//     { cv::Mat rgb;
//     QImage img;
//     QImage imgScaled;
//     cv::Mat image = cv::imread(".\\decode.jpg");
//     if (image.channels() == 3)      //cvt Mat BGR 2 QImage RGB
//     {
//         cvtColor(image, rgb, CV_BGR2RGB);
//         img = QImage((const unsigned char*)(rgb.data),
//             rgb.cols, rgb.rows,
//             rgb.cols * rgb.channels(),
//             QImage::Format_RGB888);
//         cols = rgb.cols;
//     }
//     else
//     {
//         img = QImage((const unsigned char*)(image.data),
//             image.cols, image.rows,
//             image.cols * image.channels(),
//             QImage::Format_RGB888);
//         cols = image.cols;
//     }
//     imgScaled = img.scaled(ui->show3->size(), Qt::KeepAspectRatio);//将图片适应到展示窗口大小
//     ui->show3->setPixmap(QPixmap::fromImage(imgScaled));
//     ui->show3->resize(ui->show3->pixmap()->size());
//     }
//     ofs.close();
//
// }

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

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
        last_mouse_position_ = event->globalPos();
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if (!event->buttons().testFlag(Qt::LeftButton))
        return;
    const QPoint position = pos() + event->globalPos() - last_mouse_position_; //the position of mainfrmae + (current_mouse_position - last_mouse_position)
    move(position.x(), position.y());
    last_mouse_position_ = event->globalPos();
}


