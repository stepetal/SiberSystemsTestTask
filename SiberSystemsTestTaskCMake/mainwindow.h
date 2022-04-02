#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSharedPointer>
#include <QMenu>
#include <QAction>
#include <QGroupBox>
#include <QLabel>
#include <QToolBar>
#include <QIcon>
#include <QTextEdit>
#include <QStatusBar>
#include <QRegExpValidator>
#include <QRegExp>
#include <QtAlgorithms>
#include <QPropertyAnimation>
#include <QTimer>
#include <QEventLoop>
#include <QTimeLine>
#include "memory"
#include "validationlineedit.h"
#include "../SiberSystemsTestTask/threelistclass.h"





using namespace std::chrono_literals;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QPushButton *startButton;
    QPushButton *stopButton;
    ValidationLineEdit *firstListLineEdit;
    ValidationLineEdit *secondListLineEdit;
    ValidationLineEdit *thirdListLineEdit;
    QTextEdit *resultTextEdit;
    QToolBar *resultTextEditToolBar;
    QAction *clearResultTextEditAction;
    QAction *nextElementAction;
    QSharedPointer<ThreeListClass> threeListClass;
    QVector<QString> firstList;
    QVector<QString> secondList;
    QVector<QString> thirdList;
    int *first_list;
    int *second_list;
    int *third_list;
    bool start_pressed;
    bool first_list_is_valid;
    bool second_list_is_valid;
    bool third_list_is_valid;
    QTimeLine *styleSheetTimeLine;
    /*
     * Remove until find out what was wrong with stylesheet animation
    QPropertyAnimation *firstListLineEditAnimation;
    QPropertyAnimation *secondListLineEditAnimation;
    QPropertyAnimation *thirdListLineEditAnimation;
    */


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createWidgets();
    void createActions();
    void createToolBar();
    void createConnections();
    void createLayout();
private:
    void createFirstList();
    void createSecondList();
    void createThirdList();
    void updateFirstList();
    void updateSecondList();
    void updateThirdList();
    void delay(int msecs = 2000);
    void reset();

};
#endif // MAINWINDOW_H
