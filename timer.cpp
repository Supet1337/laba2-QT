#include "timer.h"
#include "ui_timer.h"

Timer::Timer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Timer)
{
    ui->setupUi(this);
    hour = 0;
    minutes = 0;
    seconds = 0;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerSlot()));
}

Timer::~Timer()
{
    delete ui;
}

void Timer::TimerSlot()
{

    if(seconds <= 0 && minutes <= 0 && hour <= 0){
            hour = ui->spinBox->value();
            minutes = ui->spinBox_2->value();
            seconds = ui->spinBox_3->value();
            ui->spinBox->setEnabled(true);
            ui->spinBox_2->setEnabled(true);
            ui->spinBox_3->setEnabled(true);

            flag = true;
            timer->stop();

    }
    else{
        ui->spinBox->setEnabled(false);
        ui->spinBox_2->setEnabled(false);
        ui->spinBox_3->setEnabled(false);

       if (seconds > 0)
           seconds--;
           
       else if (seconds == 0 && minutes > 0){
         seconds = 59;
         minutes--;
       }
       else if (seconds == 0 && minutes == 0 && hour > 0){
         seconds = 59;
         minutes = 59;
         hour--;
       }



        ui->label->setText(QString::number(hour));
        ui->label_2->setText(QString::number(minutes));
        ui->label_3->setText(QString::number(seconds));
    }
}



void Timer::on_spinBox_valueChanged(int arg1)
{
    hour = arg1;
}


void Timer::on_spinBox_2_valueChanged(int arg1)
{
    minutes = arg1;
}


void Timer::on_spinBox_3_valueChanged(int arg1)
{
    seconds = arg1;
}


void Timer::on_pushButton_clicked()
{
    flag = !flag;

    if(flag){
        timer->stop();
    }
    else{
        timer->start(1000);
    }
}


void Timer::on_pushButton_2_clicked()
{
    hour = 0;
    minutes = 0;
    seconds = 0;
    ui->spinBox->setEnabled(true);
    ui->spinBox_2->setEnabled(true);
    ui->spinBox_3->setEnabled(true);

    ui->label->setText(QString::number(0));
    ui->label_2->setText(QString::number(0));
    ui->label_3->setText(QString::number(0));

    ui->spinBox->setValue(0);
    ui->spinBox_2->setValue(0);
    ui->spinBox_3->setValue(0);

    flag = true;
    timer->stop();
}


