#ifndef TIMER_H
#define TIMER_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Timer; }
QT_END_NAMESPACE

class Timer : public QMainWindow
{
    Q_OBJECT

public:
    Timer(QWidget *parent = nullptr);
    ~Timer();

private:
    Ui::Timer *ui;
    QTimer *timer;
    int hour, minutes, seconds = 0;
    bool flag = true;


private slots:
    void TimerSlot();
    void SpinSlot();
    void on_spinBox_valueChanged(int arg1);
    void on_spinBox_2_valueChanged(int arg1);
    void on_spinBox_3_valueChanged(int arg1);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};
#endif // TIMER_H
