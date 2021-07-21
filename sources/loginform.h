#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <memory>
#include "Database.h"

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
  Q_OBJECT

public:
  explicit LoginForm(QWidget *parent = nullptr);
  ~LoginForm();
  void setDatabase(std::shared_ptr<Database> dbPtr);

signals:
  void registerRequested();
  void accepted(int userId, QString userName);
  void rejected();

private slots:
  void on_buttonBox_accepted();
  void on_buttonBox_rejected();
  void on_registrationPushButton_clicked();

private:
  Ui::LoginForm *ui;
  std::shared_ptr<Database> m_dbPtr;
};

#endif // LOGINFORM_H
