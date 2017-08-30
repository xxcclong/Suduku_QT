#ifndef DIALOGCHOO_H
#define DIALOGCHOO_H

#include <QDialog>

namespace Ui {
class DialogChoo;
}

class DialogChoo : public QDialog
{
    Q_OBJECT

public:
    explicit DialogChoo(QWidget *parent = 0);
    DialogChoo(QWidget *parent = 0, int i =0);
    ~DialogChoo();
    int now;


private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

private:

    Ui::DialogChoo *ui;
};

#endif // DIALOGCHOO_H
