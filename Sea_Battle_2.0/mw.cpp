#include "mw.h"
#include "ui_mw.h"
///#include <QcoreApplication>
#include <QTextDocument>
///#include <Ui_MWClass>

MW::MW(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MWClass)
 {
  i=false;
  srand(time(NULL));
  ui->setupUi(this);
  ui->cbp_2->setChecked(1);
  g1.set_cbp_2(1);
  ui->cbai_11->setChecked(1);
  g1.set_cbai_11(1);
  ui->pole_1->ship_2.set_name(ui->p_2->toPlainText());
  ui->pole_1->ship_1.set_name(ui->p_1->toPlainText());
 }

MW::~MW()
 {
  delete ui;
 }

void MW::on_pushButton_clicked()       ///выход
 {
  QCoreApplication::exit(1);
 }

void MW::on_pushButton_2_clicked()     ///кнопка рестарт
 {
  ui->pole_1->stop=1;
  ui->p_1->setText(QString::fromLocal8Bit("easy"));
  ui->p_2->setText(QString::fromLocal8Bit("player2"));
  ui->p_1->setDisabled(0);
  ui->p_2->setDisabled(0);
  ui->cbai_12->setChecked(0);
  ui->cbai_13->setChecked(0);
  ui->cbai_21->setChecked(0);
  ui->cbai_22->setChecked(0);
  ui->cbai_23->setChecked(0);
  ui->cbp_1->setChecked(0);
  ui->pole_1->ship_1.ship_erase();
  ui->pole_1->ship_2.ship_erase();
  ui->pole_1->setEnabled(0);
  ui->cbp_1->setDisabled(0);
  ui->cbp_2->setDisabled(0);
  ui->cbai_11->setDisabled(0);
  ui->cbai_12->setDisabled(0);
  ui->cbai_13->setDisabled(0);
  ui->cbai_21->setDisabled(0);
  ui->cbai_22->setDisabled(0);
  ui->cbai_23->setDisabled(0);
  g1.reset();
  ui->cbp_2->setChecked(1);
  g1.set_cbp_2(1);
  ui->cbai_11->setChecked(1);
  g1.set_cbai_11(1);
  update();
 }

void MW::on_pushButton_3_clicked()     /// кнопка бой
 {
  ui->pole_1->stop=0;
  ui->centralWidget->setDisabled(0);
  ui->pole_1->setDisabled(0);
  ui->pole_1->ship_1.ship_erase();
  ui->pole_1->ship_2.ship_erase();
  ui->pole_1->ship_1.set_isai(1);
  ui->pole_1->ship_1.setmas();
  ui->pole_1->ship_2.set_isai(0);
  ui->pole_1->ship_2.setmas();
  ui->pole_1->setEnabled(1);
  ui->p_1->setDisabled(1);
  ui->p_2->setDisabled(1);
  ui->cbp_1->setDisabled(1);
  ui->cbp_2->setDisabled(1);
  ui->cbai_11->setDisabled(1);
  ui->cbai_12->setDisabled(1);
  ui->cbai_13->setDisabled(1);
  ui->cbai_21->setDisabled(1);
  ui->cbai_22->setDisabled(1);
  ui->cbai_23->setDisabled(1);
  game::set_hod(rand()%2+1);
  if (game::get_hod()==1 &&
      game::get_cbp_1()==0 &&
      game::get_cbp_2()!=0)
    {
     ui->pole_1->setDisabled(1);
     ui->pole_1->ppstep();
    }
  ///air=game::ai_step(ui->pole_1->ship_1,ui->pole_1->ship_2);
  if (game::get_hod()==2 &&
      game::get_cbp_2()==0 && 
      game::get_cbp_1()!=0)
    {
     ui->pole_1->setDisabled(1);
     ui->pole_1->ppstep();
    }
  if (game::get_cbp_1()==0 &&
      game::get_cbp_2()==0)
    {
     game::hod=rand()%2+1;
     ///while(game::if_win(ui->pole_1->ship_1,ui->pole_1->ship_2)==0)
     ui->pole_1->pcvpc(ui->pole_1->ship_1, ui->pole_1->ship_2);
     update();
     ui->centralWidget->setDisabled(0);
     ui->pole_1->setDisabled(1);
    }
  if (game::get_cbp_1()==1 &&
      game::get_cbp_2()==1)
  ui->pole_1->setDisabled(0);
  update();
 }

void MW::on_cbp_2_clicked(bool checked)
 {
  g1.set_cbp_2(1);
  ui->cbp_2->setChecked(1);
  ui->cbai_21->setChecked(0);
  ui->cbai_22->setChecked(0);
  ui->cbai_23->setChecked(0);
  g1.set_cbai_21(0);
  g1.set_cbai_22(0);
  g1.set_cbai_23(0);
  ui->p_2->setText(QString::fromLocal8Bit("player2"));
 }

void MW::on_cbai_12_clicked(bool checked)
 {
  g1.set_cbai_12(1);
  ui->cbai_12->setChecked(1);
  g1.set_cbp_1(0);
  g1.set_cbai_11(0);
  g1.set_cbai_13(0);
  ui->cbai_11->setChecked(0);
  ui->cbp_1->setChecked(0);
  ui->cbai_13->setChecked(0);
  ui->p_1->setText(QString::fromLocal8Bit("normal"));
 }

void MW::on_cbp_1_clicked(bool checked)
 {
  g1.set_cbp_1(1);
  ui->cbp_1->setChecked(1);
  g1.set_cbai_11(0);
  g1.set_cbai_12(0);
  g1.set_cbai_13(0);
  ui->cbai_11->setChecked(0);
  ui->cbai_12->setChecked(0);
  ui->cbai_13->setChecked(0);
  ui->p_1->setText(QString::fromLocal8Bit("player1"));
 }

void MW::on_cbai_11_clicked(bool checked)
 {
  g1.set_cbai_11(1);
  ui->cbai_11->setChecked(1);
  g1.set_cbp_1(0);
  g1.set_cbai_12(0);
  g1.set_cbai_13(0);
  ui->cbp_1->setChecked(0);
  ui->cbai_12->setChecked(0);
  ui->cbai_13->setChecked(0);
  ui->p_1->setText(QString::fromLocal8Bit("easy"));
 }

void MW::on_cbai_13_clicked(bool checked)
 {
  g1.set_cbai_13(1);
  ui->cbai_13->setChecked(1);
  g1.set_cbai_11(0);
  g1.set_cbai_12(0);
  g1.set_cbp_1(0);
  ui->cbai_11->setChecked(0);
  ui->cbai_12->setChecked(0);
  ui->cbp_1->setChecked(0);
  ui->p_1->setText(QString::fromLocal8Bit("hard"));
 }

void MW::on_cbai_21_clicked(bool checked)
 {
  g1.set_cbai_21(1);
  ui->cbai_21->setChecked(1);
  g1.set_cbai_22(0);
  g1.set_cbai_23(0);
  g1.set_cbp_2(0);
  ui->cbai_22->setChecked(0);
  ui->cbai_23->setChecked(0);
  ui->cbp_2->setChecked(0);
  ui->p_2->setText(QString::fromLocal8Bit("easy"));
 }

void MW::on_cbai_22_clicked(bool checked)
 {
  g1.set_cbai_22(1);
  ui->cbai_22->setChecked(1);
  g1.set_cbai_21(0);
  g1.set_cbai_23(0);
  g1.set_cbp_2(0);
  ui->cbai_21->setChecked(0);
  ui->cbai_23->setChecked(0);
  ui->cbp_2->setChecked(0);
  ui->p_2->setText(QString::fromLocal8Bit("normal"));
 }

void MW::on_cbai_23_clicked(bool checked)
 {
  g1.set_cbai_23(1);
  ui->cbai_23->setChecked(1);
  g1.set_cbai_21(0);
  g1.set_cbai_22(0);
  g1.set_cbp_2(0);
  ui->cbai_21->setChecked(0);
  ui->cbai_22->setChecked(0);
  ui->cbp_2->setChecked(0);
  ui->p_2->setText(QString::fromLocal8Bit("hard"));
 }

void MW::on_p_1_textChanged()
 {
  ui->pole_1->ship_1.set_name(ui->p_1->toPlainText());
 }

void MW::on_p_2_textChanged()
 {
  ui->pole_1->ship_2.set_name(ui->p_2->toPlainText());
 }

void MW::on_pushButton_4_clicked()     ///кнопка рекорды
 {
  ui->records->tab.reload();
  if (!i)                              /// Надпись Рекорды?
    {
     ui->pole_1->setVisible(0);        /// Скрыть игровое поле
     ui->records->setVisible(1);       /// Показать таблицу рекордов
     ui->pushButton_4->setText(QString::fromLocal8Bit("Обратно"));
    };
  if (i)                               /// Надпись Обратно?
    {
     ui->pole_1->setVisible(1);        /// Показать игровое поле
     ui->records->setVisible(0);       /// Скрыть таблицу рекордов
     ui->pushButton_4->setText(QString::fromLocal8Bit("Рекорды"));
    };
  i=!i;
  update();
 }
