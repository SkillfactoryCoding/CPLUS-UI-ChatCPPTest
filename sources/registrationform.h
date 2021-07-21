#ifndef REGISTRATIONFORM_H
#define REGISTRATIONFORM_H

#include <QWidget>
#include <memory>
#include "Database.h"

namespace Ui {
class RegistrationForm;
}

class RegistrationForm : public QWidget
{
  Q_OBJECT

public:
  explicit RegistrationForm(QWidget *parent = nullptr);
  ~RegistrationForm();
  void setDatabase(std::shared_ptr<Database> dbPtr);

signals:
  void loginRequested();
  void accepted(int userId, QString userName);
  void rejected();

private slots:
  void on_loginButton_clicked();
  void on_buttonBox_accepted();
  void on_buttonBox_rejected();

private:
  Ui::RegistrationForm *ui;
  std::shared_ptr<Database> m_dbPtr;
};

#endif // REGISTRATIONFORM_H
