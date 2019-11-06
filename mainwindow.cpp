#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    listWidget = new QListWidget();

    QDir dir("E:\\codePro\\FileExplorer");
    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i)
    {
        QFileInfo fileInfo = list.at(i);

        QString fileName = fileInfo.fileName();
        item = new QListWidgetItem;
        item->setText(fileName);


        QString iconPath;
        if (fileInfo.isDir()) {
            iconPath = ":/img/dir.png";
        }
        if (fileInfo.isFile()) {
            iconPath = ":/img/file.png";
        }

        item->setIcon(QIcon(iconPath));
        listWidget->insertItem(i, item);
    }

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(listWidget);

    widget = new QWidget();
    widget->setLayout(layout);

    resize(500, 500);
    setCentralWidget(widget);
    setWindowTitle("文件浏览器");
}

MainWindow::~MainWindow()
{

}



