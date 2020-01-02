#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    std::string get_string();
private slots:
    void on_pushButton_0_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_point_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_sub_clicked();

    void on_pushButton_mul_clicked();

    void on_pushButton_div_clicked();

    void on_pushButton_pos_or_neg_clicked();

    void on_pushButton_reciprocal_clicked();

    void on_pushButton_square_clicked();

    void on_pushButton_sin_clicked();

    void on_pushButton_cos_clicked();

    void on_pushButton_tan_clicked();

    void on_pushButton_C_clicked();

    void on_pushButton_backspace_clicked();

    void on_pushButton_left_bracket_clicked();

    void on_pushButton_right_bracket_clicked();

    void on_pushButton_lg_clicked();

    void on_pushButton_exp_clicked();
public slots:
    void on_pushButton_equal_clicked();

private:
    Ui::Widget *ui;
    bool isNum();
    bool last_is_operate();
    bool last_is_num();
    bool last_is_right_bracket();
    bool last_is_left_bracket();
    bool last_is_point();
    int fre = 0;
    int point = 0;
};

#endif // WIDGET_H
