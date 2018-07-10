#include "qtdialog.h"

#include <string>

#include <boost/lexical_cast.hpp>

#include "ui_qtdialog.h"

QtDialog::QtDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtDialog)
{
  ui->setupUi(this);

  QTableWidget * const t = ui->tableWidget;
  const int n_rows = t->rowCount();
  const int n_cols = t->columnCount();
  for (int x=0; x!=n_cols; ++x)
  {
    for (int y=0; y!=n_rows; ++y)
    {
      const QString s = "("
        + QString::number(x)
        + ","
        + QString::number(y)
        + ")"
      ;
      QTableWidgetItem * const i = new QTableWidgetItem(s);
      t->setItem(y, x, i);
    }
  }
}

QtDialog::~QtDialog()
{
  delete ui;
}
