#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDateTime>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // 状态栏
    QTimer* mStatusBarTimer = Q_NULLPTR;
    QLabel* mStatusBarTimeLabel = Q_NULLPTR;
    void initStatusBar();

private slots:
    void updateStatusBarTimeLabel();
};
#endif // MAINWINDOW_H
