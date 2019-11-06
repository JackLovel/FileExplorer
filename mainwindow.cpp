#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    getDirButton = new QPushButton("获取目录");

    listWidget = new QListWidget();

    currentPath = "C:\\";
    showDirectory(currentPath);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(listWidget);
    layout->addWidget(getDirButton);

    widget = new QWidget();
    widget->setLayout(layout);


    connect(getDirButton, &QPushButton::clicked,this, &MainWindow::setDirSlots);
    connect(listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem *)),this,SLOT(doubleclicked(QListWidgetItem *)));

    resize(500, 500);
    setCentralWidget(widget);
    setWindowTitle("文件浏览器");
}

MainWindow::~MainWindow()
{

}

void MainWindow::doubleclicked(QListWidgetItem *item)
{

    QString itemName = item->text();
    QDir sourceDir(currentPath);
    //qDebug() << sourceDir.absoluteFilePath(itemName);
    currentPath = sourceDir.absoluteFilePath(itemName);
    listWidget->clear();
    showDirectory(currentPath);
}

void MainWindow::showDirectory(const QString &path)
{
    QDir dir;
    dir.setPath(path);
    //qDebug() << dir.currentPath();
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
}

void MainWindow::setDirSlots()
{
    dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "C:\\",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);

    currentPath = dir;
    showDirectory(dir);
}

