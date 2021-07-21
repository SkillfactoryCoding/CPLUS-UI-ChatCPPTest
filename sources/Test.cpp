#include <iostream>
#include <QApplication>
#include "CommandLineInterface.h"
#include "mainwindow.h"
#include <QTranslator>

using namespace std;

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QTranslator myappTranslator;
  myappTranslator.load("translations/my_ru.qm");
  a.installTranslator(&myappTranslator);

  QTranslator qtTranslator;
  qtTranslator.load("translations/qt_ru.qm");
  a.installTranslator(&qtTranslator);

  auto w = MainWindow::createClient();
  if(w)
    w->show();
  else
    return 0;
  return a.exec();
}


