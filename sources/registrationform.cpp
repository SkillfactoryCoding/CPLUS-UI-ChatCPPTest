#include "registrationform.h"
#include "ui_registrationform.h"
#include <QMessageBox>

RegistrationForm::RegistrationForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::RegistrationForm)
{
  ui->setupUi(this);
}

RegistrationForm::~RegistrationForm()
{
  delete ui;
}

void RegistrationForm::setDatabase(std::shared_ptr<Database> dbPtr)
{
  m_dbPtr = dbPtr;
}

void RegistrationForm::on_loginButton_clicked()
{
  emit loginRequested();
}

void RegistrationForm::on_buttonBox_accepted()
{
  if(ui->passwordEdit->text() !=
     ui->passwordConfirmEdit->text())
  {
    QMessageBox::critical(this,
                          tr("Error"),
                          tr("Passwords not match"));
    return;
  }
  auto userId = m_dbPtr->addUser(ui->loginEdit->text().toStdString(),
                                 ui->passwordEdit->text().toStdString());
  switch(userId)
  {
  case -1:
    QMessageBox::critical(this,
                          tr("Error"),
                          tr("Incorrect login"));
    return;
  case -2:
    QMessageBox::critical(this,
                          tr("Error"),
                          tr("Login alredy exists"));
    return;
  default:
    emit accepted(userId, ui->loginEdit->text());
  }

}

void RegistrationForm::on_buttonBox_rejected()
{
  emit rejected();
}
