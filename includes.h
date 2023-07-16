#ifndef INCLUDES_
#define INCLUDES_

#include <httplib.h>
#include <fstream>
#include <json.h>
#include <Windows.h>
#include <vector>
// Qt
#include <QTimer>
#include <QApplication>
#include <QMessageBox>
#include <QFile>
#include <QPushbutton>
#include <QDebug>

// debug
#ifndef deb
#include <iostream>
#define deb(str) std::cout<<"deb"<<str<<std::endl;
#endif

#endif