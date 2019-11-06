#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDir>
#include <QListWidgetItem>
#include <QFileInfoList>
#include <QListWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QIcon>
#include <QStringList>
#include <QDebug>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showDirectory(const QString &path);

private slots:
    void doubleclicked(QListWidgetItem *item);
    void setDirSlots();

private:
    QString dir;
    QListWidget *listWidget;
    QWidget *widget;
    QListWidgetItem *item;
    QPushButton *getDirButton;
    QString currentPath;
};
#endif // MAINWINDOW_H
