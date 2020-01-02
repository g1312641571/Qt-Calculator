#include "widget.h"
#include "ui_widget.h"
#include "calculation.h"


std::string replace_all(std::string str, std::string old_value, std::string new_value)
{
        for (std::string::size_type pos(0); pos != std::string::npos; pos += new_value.length())
        {
            if ((pos = str.find(old_value, pos)) != std::string::npos)
                str.replace(pos, old_value.length(), new_value);
            else
                break;
        }
    return str;
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
}

Widget::~Widget()
{
    delete ui;
}

std::string Widget::get_string()
{
    std::string str = ui->lineEdit->text().toStdString();
    str = replace_all(str, "×", "*");
    str = replace_all(str, "÷", "/");
    return str;
}

bool Widget::isNum()
{
    double i = ui->lineEdit->text().toDouble();
    if(i == 0.0)
        return false;
    else
        return true;
}

bool Widget::last_is_num()
{
    if( ui->lineEdit->text().at(ui->lineEdit->text().length() - 1) == "1" ||
        ui->lineEdit->text().at(ui->lineEdit->text().length() - 1) == "2" ||
        ui->lineEdit->text().at(ui->lineEdit->text().length() - 1) == "3" ||
        ui->lineEdit->text().at(ui->lineEdit->text().length() - 1) == "4" ||
        ui->lineEdit->text().at(ui->lineEdit->text().length() - 1) == "5" ||
        ui->lineEdit->text().at(ui->lineEdit->text().length() - 1) == "6" ||
        ui->lineEdit->text().at(ui->lineEdit->text().length() - 1) == "7" ||
        ui->lineEdit->text().at(ui->lineEdit->text().length() - 1) == "8" ||
        ui->lineEdit->text().at(ui->lineEdit->text().length() - 1) == "9" ||
        ui->lineEdit->text().at(ui->lineEdit->text().length() - 1) == "0")
        return true;
    else
        return false;
}

bool Widget::last_is_operate()
{
    if( ui->lineEdit->text().at(ui->lineEdit->text().length() - 1) == "+" ||
        ui->lineEdit->text().at(ui->lineEdit->text().length() - 1) == "-" ||
        ui->lineEdit->text().at(ui->lineEdit->text().length() - 1) == "×" ||
        ui->lineEdit->text().at(ui->lineEdit->text().length() - 1) == "÷" )
        return true;
    else
        return false;
}

bool Widget::last_is_point()
{
    if( ui->lineEdit->text().at(ui->lineEdit->text().length() - 1) == ".")
        return true;
    else
        return false;
}

bool Widget::last_is_left_bracket()
{
    if( ui->lineEdit->text().at(ui->lineEdit->text().length() - 1) == "(")
        return true;
    else
        return false;
}

bool Widget::last_is_right_bracket()
{
    if( ui->lineEdit->text().at(ui->lineEdit->text().length() - 1) == ")")
        return true;
    else
        return false;
}

void Widget::on_pushButton_0_clicked()
{
    if(ui->lineEdit->text().isEmpty() || last_is_left_bracket() || last_is_point() || last_is_num() || last_is_operate())
        ui->lineEdit->setText(ui->lineEdit->text() + "0");
    else
        return;
}

void Widget::on_pushButton_1_clicked()
{
    if(ui->lineEdit->text().isEmpty() || last_is_left_bracket() || last_is_point() || last_is_num() || last_is_operate())
        ui->lineEdit->setText(ui->lineEdit->text() + "1");
    else
        return;
}

void Widget::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text().isEmpty() || last_is_left_bracket() || last_is_point() || last_is_num() || last_is_operate())
        ui->lineEdit->setText(ui->lineEdit->text() + "2");
    else
        return;
}

void Widget::on_pushButton_3_clicked()
{
    if(ui->lineEdit->text().isEmpty() || last_is_left_bracket() || last_is_point() || last_is_num() || last_is_operate())
        ui->lineEdit->setText(ui->lineEdit->text() + "3");
    else
        return;
}

void Widget::on_pushButton_4_clicked()
{
    if(ui->lineEdit->text().isEmpty() || last_is_left_bracket() || last_is_point() || last_is_num() || last_is_operate())
        ui->lineEdit->setText(ui->lineEdit->text() + "4");
    else
        return;
}

void Widget::on_pushButton_5_clicked()
{
    if(ui->lineEdit->text().isEmpty() || last_is_left_bracket() || last_is_point() || last_is_num() || last_is_operate())
        ui->lineEdit->setText(ui->lineEdit->text() + "5");
    else
        return;
}

void Widget::on_pushButton_6_clicked()
{
    if(ui->lineEdit->text().isEmpty() || last_is_left_bracket() || last_is_point() || last_is_num() || last_is_operate())
        ui->lineEdit->setText(ui->lineEdit->text() + "6");
    else
        return;
}

void Widget::on_pushButton_7_clicked()
{
    if(ui->lineEdit->text().isEmpty() || last_is_left_bracket() || last_is_point() || last_is_num() || last_is_operate())
        ui->lineEdit->setText(ui->lineEdit->text() + "7");
    else
        return;
}

void Widget::on_pushButton_8_clicked()
{
    if(ui->lineEdit->text().isEmpty() || last_is_left_bracket() || last_is_point() || last_is_num() || last_is_operate())
        ui->lineEdit->setText(ui->lineEdit->text() + "8");
    else
        return;
}

void Widget::on_pushButton_9_clicked()
{
    if(ui->lineEdit->text().isEmpty() || last_is_left_bracket() || last_is_point() || last_is_num() || last_is_operate())
        ui->lineEdit->setText(ui->lineEdit->text() + "9");
    else
        return;
}

void Widget::on_pushButton_point_clicked()
{
    if(ui->lineEdit->text().isEmpty())
        return;
    else if(point == 1)
        return;
    else
    {
        ++point;
        ui->lineEdit->setText(ui->lineEdit->text() + ".");
    }
}

void Widget::on_pushButton_add_clicked()
{
    if(ui->lineEdit->text().isEmpty() || last_is_left_bracket() ||last_is_point() || last_is_operate())
        return;
    else
        ui->lineEdit->setText(ui->lineEdit->text() + "+");
    if(point == 1)
        --point;
}

void Widget::on_pushButton_sub_clicked()
{
    if(ui->lineEdit->text().isEmpty() || last_is_left_bracket() ||last_is_point() || last_is_operate())
        return;
    else
        ui->lineEdit->setText(ui->lineEdit->text() + "-");
    if(point == 1)
        --point;
}

void Widget::on_pushButton_mul_clicked()
{
    if(ui->lineEdit->text().isEmpty() || last_is_left_bracket() ||last_is_point() || last_is_operate())
        return;
    else
       ui->lineEdit->setText(ui->lineEdit->text() + "×");
    if(point == 1)
        --point;
}

void Widget::on_pushButton_div_clicked()
{
    if(ui->lineEdit->text().isEmpty() || last_is_left_bracket() ||last_is_point() || last_is_operate())
        return;
    else
        ui->lineEdit->setText(ui->lineEdit->text() + "÷");
    if(point == 1)
        --point;
}

void Widget::on_pushButton_pos_or_neg_clicked()
{
    if(!isNum())
        return;
    QString qstr = ui->lineEdit->text();
    if(ui->lineEdit->text()[0] != "-")
        ui->lineEdit->setText("-" + qstr);
    else
    {
        std::string str = qstr.toStdString();
        str.erase(0, 1);
        ui->lineEdit->setText(QString::fromStdString(str));
    }
}

void Widget::on_pushButton_reciprocal_clicked()
{
    if(!isNum())
        return;
    QString str = ui->lineEdit->text();
    if(str.toDouble() == 0.0)
        return;
    else
        ui->lineEdit->setText(QString::number(1.0 / str.toDouble()));
}

void Widget::on_pushButton_square_clicked()
{
    if(ui->lineEdit->text() == "0")
        ui->lineEdit->setText("0");
    else if(!isNum())
        return;
    else
    {
         double i = ui->lineEdit->text().toDouble();
         i *= i;
         ui->lineEdit->setText(QString::number(i));
    }
}

void Widget::on_pushButton_sin_clicked()
{
    if(ui->lineEdit->text() == "0")
        ui->lineEdit->setText("0");
    else if(!isNum())
        return;
    else
    {
         double i = ui->lineEdit->text().toDouble();
         ui->lineEdit->setText(QString::number(sin(i)));
    }
}

void Widget::on_pushButton_cos_clicked()
{
    if(ui->lineEdit->text() == "0")
        ui->lineEdit->setText("1");
    else if(!isNum())
        return;
    else
    {
         double i = ui->lineEdit->text().toDouble();
         ui->lineEdit->setText(QString::number(cos(i)));
    }
}

void Widget::on_pushButton_tan_clicked()
{
    if(ui->lineEdit->text() == "0")
        ui->lineEdit->setText("0");
    else if(!isNum())
        return;
    else
    {
         double i = ui->lineEdit->text().toDouble();
         ui->lineEdit->setText(QString::number(tan(i)));
    }
}

void Widget::on_pushButton_C_clicked()
{
    ui->lineEdit->clear();
}

void Widget::on_pushButton_backspace_clicked()
{
    if(ui->lineEdit->text().isEmpty())
        return;
    if(last_is_point())
        --point;
    if(last_is_right_bracket())
        ++fre;
    if(last_is_left_bracket())
        --fre;
    QString qstr = ui->lineEdit->text();
    ui->lineEdit->setText(ui->lineEdit->text().left(qstr.length() - 1));
}

void Widget::on_pushButton_left_bracket_clicked()
{
    if(ui->lineEdit->text().isEmpty() || last_is_operate())
    {
        ++fre;
        ui->lineEdit->setText(ui->lineEdit->text() + "(");
    }
    else
        return;
    if(point == 1)
        --point;
}

void Widget::on_pushButton_right_bracket_clicked()
{
    if(fre <= 0 || last_is_left_bracket() || last_is_point() || last_is_operate())
        return;
    else
    {
        ui->lineEdit->setText(ui->lineEdit->text() + ")");
        --fre;
    }
}

void Widget::on_pushButton_lg_clicked()
{
    if(!isNum())
        return;
    else
    {
         double i = ui->lineEdit->text().toDouble();
         ui->lineEdit->setText(QString::number(log(i)));
    }
}

void Widget::on_pushButton_exp_clicked()
{
    if(!isNum())
        return;
    else
    {
         double i = ui->lineEdit->text().toDouble();
         ui->lineEdit->setText(QString::number(exp(i)));
    }
}

void Widget::on_pushButton_equal_clicked()
{
    calculation cal;
    cal.set(get_string());
    cal.calculate();
    ui->lineEdit->setText(QString::number(cal.get()));
}
