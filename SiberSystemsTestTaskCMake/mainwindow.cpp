#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      first_list(nullptr),
      second_list(nullptr),
      third_list(nullptr),
      start_pressed(false),
      first_list_is_valid(false),
      second_list_is_valid(false),
      third_list_is_valid(false)
{
    setWindowTitle(QString(" "));
    createWidgets();
    createActions();
    createToolBar();
    createLayout();
    createConnections();
}

MainWindow::~MainWindow()
{
    reset();
}

void MainWindow::createWidgets()
{
    startButton  = new QPushButton("Start");
    stopButton  = new QPushButton("Stop");
    QRegExp lineRegex("([0-9]+,?)+");
    QValidator *lineValidator = new QRegExpValidator(lineRegex,this);
    firstListLineEdit = new ValidationLineEdit(this);
    firstListLineEdit->setPlaceholderText("Example: 1,2,3,4");
    firstListLineEdit->setValidator(lineValidator);
    firstListLineEdit->setText(QString("2,7,12,40"));
    secondListLineEdit = new ValidationLineEdit(this);
    secondListLineEdit->setPlaceholderText("Example: 1,2,3,4");
    secondListLineEdit->setValidator(lineValidator);
    secondListLineEdit->setText(QString("1,8,15,16,35"));
    thirdListLineEdit = new ValidationLineEdit(this);
    thirdListLineEdit->setPlaceholderText("Example: 1,2,3,4");
    thirdListLineEdit->setValidator(lineValidator);
    thirdListLineEdit->setText(QString("10,13,14"));
    resultTextEdit = new QTextEdit(this);
    updateFirstList();
    updateSecondList();
    updateThirdList();
    styleSheetTimeLine = new QTimeLine(2000,this);
    styleSheetTimeLine->setFrameRange(0,100);
    // TODO: find out, why idea with property animation didn't work
    /*
    firstListLineEditAnimation = new QPropertyAnimation(firstListLineEdit,"CustomStyleSheet");
    firstListLineEditAnimation->setDuration(2000);
    firstListLineEditAnimation->setStartValue("background-color: red; color: red");
    firstListLineEditAnimation->setEndValue("background-color: white; color: black");
    */
}

void MainWindow::createActions()
{
    clearResultTextEditAction = new QAction(QIcon(":/img/images/Clear-icon.png"),QString("Clear text edit"),this);
    clearResultTextEditAction->setToolTip(QString("Clear text edit"));
    nextElementAction = new QAction(QIcon(":/img/images/Button-Next-icon.png"),QString("Get next element"),this);
    nextElementAction->setToolTip(QString("Get next element"));
}

void MainWindow::createToolBar()
{
    resultTextEditToolBar = new QToolBar(this);
    resultTextEditToolBar->addAction(clearResultTextEditAction);
    resultTextEditToolBar->addAction(nextElementAction);
}



void MainWindow::createConnections()
{
    connect(stopButton,&QPushButton::clicked,[&]()
    {
        if(start_pressed)
        {
            reset();
            statusBar()->showMessage(QString("Retrieving procedure has stopped"));
        }
    });

    connect(styleSheetTimeLine,&QTimeLine::finished,[&]()
    {
        firstListLineEdit->setValid();
        secondListLineEdit->setValid();
        thirdListLineEdit->setValid();
    });

    connect(styleSheetTimeLine,&QTimeLine::frameChanged,[&](int frame)
    {
        Q_UNUSED(frame);
        // During counting all events should be processed
        QEventLoop elp;
        elp.processEvents();
    });

    connect(startButton,&QPushButton::clicked,[&]()
    {
        createFirstList();
        createSecondList();
        createThirdList();
        // clear all lists
        if(!first_list_is_valid)
        {
            styleSheetTimeLine->stop();
            firstListLineEdit->setNonValid();
            styleSheetTimeLine->start();
            return;
        }
        else if(!second_list_is_valid)
        {
            styleSheetTimeLine->stop();
            secondListLineEdit->setNonValid();
            styleSheetTimeLine->start();
            return;
        }
        else if(!third_list_is_valid)
        {
            styleSheetTimeLine->stop();
            thirdListLineEdit->setNonValid();
            styleSheetTimeLine->start();
            return;
        }
        else
        {
            threeListClass.reset(new ThreeListClass(first_list, firstList.size(),
                                                    second_list, secondList.size(),
                                                    third_list, thirdList.size()));
            startButton->setEnabled(false);
            firstListLineEdit->setEnabled(false);
            secondListLineEdit->setEnabled(false);
            thirdListLineEdit->setEnabled(false);
            start_pressed = true;
            statusBar()->showMessage(QString("Start of elements retrieving procedure. Press \"GetNext\" for next element"));
        }

    });

    connect(clearResultTextEditAction,&QAction::triggered,[&]()
    {
        resultTextEdit->clear();
    });

    connect(nextElementAction,&QAction::triggered,[&]()
    {
        if(start_pressed)
        {
            int next_value = threeListClass->getNext();
            if(next_value == 0)
            {
                reset();
                statusBar()->showMessage(QString("All elements are shown"));
                return;
            }
            resultTextEdit->append(QString::number(next_value));
        }
    });


    connect(firstListLineEdit,&ValidationLineEdit::editingFinished,[&]()
    {
        createFirstList();
    });

    connect(secondListLineEdit,&ValidationLineEdit::editingFinished,[&]()
    {
        createSecondList();
    });

    connect(thirdListLineEdit,&ValidationLineEdit::editingFinished,[&]()
    {
        createThirdList();
    });
}

void MainWindow::createLayout()
{
    QWidget *mainWindowWidget = new QWidget();
    QGridLayout *mainWindowLayout = new QGridLayout();

    QLabel *title = new QLabel("Application \"Union of three lists\"");

    QWidget *buttonsWidget = new QWidget();
    QHBoxLayout *buttonsWidgetLayout = new QHBoxLayout();
    buttonsWidgetLayout->addWidget(startButton);
    buttonsWidgetLayout->addWidget(stopButton);
    buttonsWidget->setLayout(buttonsWidgetLayout);

    QLabel *firstListLineEditLabel = new QLabel("First list");
    QLabel *secondListLineEditLabel = new QLabel("Second list");
    QLabel *thirdListLineEditLabel = new QLabel("Third list");
    QGroupBox *listsLineEditGroupBox = new QGroupBox("Lists for unition");
    QGridLayout *listsLineEditGroupBoxLayout = listsLineEditGroupBoxLayout = new QGridLayout();
    listsLineEditGroupBoxLayout->addWidget(firstListLineEditLabel,0,0,1,1);
    listsLineEditGroupBoxLayout->addWidget(firstListLineEdit,0,1,1,1);
    listsLineEditGroupBoxLayout->addWidget(secondListLineEditLabel,1,0,1,1);
    listsLineEditGroupBoxLayout->addWidget(secondListLineEdit,1,1,1,1);
    listsLineEditGroupBoxLayout->addWidget(thirdListLineEditLabel,2,0,1,1);
    listsLineEditGroupBoxLayout->addWidget(thirdListLineEdit,2,1,1,1);
    listsLineEditGroupBoxLayout->addWidget(buttonsWidget,3,0,1,2,Qt::AlignCenter);
    listsLineEditGroupBox->setLayout(listsLineEditGroupBoxLayout);

    QGroupBox *resultTextEditGroupBox = new QGroupBox("Resulting text");
    QVBoxLayout *resultTextEditGroupBoxLayout = new QVBoxLayout();
    resultTextEditGroupBoxLayout->addWidget(resultTextEdit);
    resultTextEditGroupBox->setLayout(resultTextEditGroupBoxLayout);

    mainWindowLayout->addWidget(title,0,0,1,1,Qt::AlignCenter);
    mainWindowLayout->addWidget(listsLineEditGroupBox,1,0,1,1);
    mainWindowLayout->addWidget(resultTextEditToolBar,2,0,1,1);
    mainWindowLayout->addWidget(resultTextEditGroupBox,3,0,1,1);
    mainWindowWidget->setLayout(mainWindowLayout);

    //установка стилей
    title->setFont(QFont("Arial",16,QFont::Bold,true));
    listsLineEditGroupBox->setFont(QFont(QString("Arial"),12,-1,true));
    resultTextEditGroupBox->setFont(QFont(QString("Arial"),12,-1,true));
    mainWindowWidget->setStyleSheet("background-color: #0e7fc9; color: white;");
    listsLineEditGroupBox->setStyleSheet("background-color: #7ec4f2");
    resultTextEditGroupBox->setStyleSheet("background-color: #7ec4f2");
    resultTextEdit->setStyleSheet("background-color: white; color: black");
    firstListLineEdit->setStyleSheet("background-color: white; color: black");
    secondListLineEdit->setStyleSheet("background-color: white; color: black");
    thirdListLineEdit->setStyleSheet("background-color: white; color: black");
    startButton->setStyleSheet("background-color: #0e7fc9; color: white; font-size: 12pt");
    stopButton->setStyleSheet("background-color: #0e7fc9; color: white; font-size: 12pt");

    setCentralWidget(mainWindowWidget);
    setMinimumWidth(400);
}

void MainWindow::createFirstList()
{
    if(first_list != nullptr)
    {
        delete[] first_list;
        first_list = nullptr;
    }
    updateFirstList();
    if(firstList.isEmpty())
    {
        first_list_is_valid = false;
    }
    else
    {
        //check uniqueness of numbers in first list
        if((std::none_of(firstList.begin(),firstList.end(),[&](const QString &s){return secondList.contains(s);})) &&
           (std::none_of(firstList.begin(),firstList.end(),[&](const QString &s){return thirdList.contains(s);})) &&
           (std::all_of(firstList.begin(),firstList.end(),[&](const QString &s){return (std::count(firstList.begin(),firstList.end(),s)) == 1; }))
          )
        {
            std::sort(firstList.begin(),firstList.end(),[](const QString &s1, const QString &s2){ return s1.toInt() < s2.toInt(); });
            firstListLineEdit->setText(firstList.toList().join(","));
            first_list = new int[firstList.size()];
            for(auto i = 0; i < firstList.size(); ++i)
            {
                first_list[i] = firstList[i].toInt();
            }
            first_list_is_valid = true;
        }
        else
        {
            styleSheetTimeLine->stop();
            first_list_is_valid = false;
            firstListLineEdit->setNonValid();
            styleSheetTimeLine->start();
            statusBar()->showMessage(QString("There are equal numbers in lists"),5000);
        }
    }
}

void MainWindow::createSecondList()
{
    if(second_list != nullptr)
    {
        delete[] second_list;
        second_list = nullptr;
    }
    updateSecondList();
    if(secondList.isEmpty())
    {
        second_list_is_valid = false;
    }
    else
    {

        //check uniqueness of numbers in second list
        if((std::none_of(secondList.begin(),secondList.end(),[&](const QString &s){return firstList.contains(s);})) &&
           (std::none_of(secondList.begin(),secondList.end(),[&](const QString &s){return thirdList.contains(s);})) &&
           (std::all_of(secondList.begin(),secondList.end(),[&](const QString &s){return (std::count(secondList.begin(),secondList.end(),s)) == 1; }))
          )
        {
            std::sort(secondList.begin(),secondList.end(),[](const QString &s1, const QString &s2){ return s1.toInt() < s2.toInt(); });
            secondListLineEdit->setText(secondList.toList().join(","));
            second_list = new int[secondList.size()];
            for(auto i = 0; i < secondList.size(); ++i)
            {
                second_list[i] = secondList[i].toInt();
            }
            second_list_is_valid = true;
        }
        else
        {
            styleSheetTimeLine->stop();
            second_list_is_valid = false;
            secondListLineEdit->setNonValid();
            styleSheetTimeLine->start();
            statusBar()->showMessage(QString("There are equal numbers in lists"),5000);
        }
    }
}

void MainWindow::createThirdList()
{
    if(third_list != nullptr)
    {
        delete[] third_list;
        third_list = nullptr;
    }
    updateThirdList();
    if(thirdList.isEmpty())
    {
        third_list_is_valid = false;
    }
    else
    {

        //check uniqueness of numbers in third list
        if((std::none_of(thirdList.begin(),thirdList.end(),[&](const QString &s){return firstList.contains(s);})) &&
           (std::none_of(thirdList.begin(),thirdList.end(),[&](const QString &s){return secondList.contains(s);})) &&
           (std::all_of(thirdList.begin(),thirdList.end(),[&](const QString &s){return (std::count(thirdList.begin(),thirdList.end(),s)) == 1; }))
          )
        {
            std::sort(thirdList.begin(),thirdList.end(),[](const QString &s1, const QString &s2){ return s1.toInt() < s2.toInt(); });
            thirdListLineEdit->setText(thirdList.toList().join(","));
            third_list = new int[thirdList.size()];
            for(auto i = 0; i < thirdList.size(); ++i)
            {
                third_list[i] = thirdList[i].toInt();
            }
            third_list_is_valid = true;
        }
        else
        {
            styleSheetTimeLine->stop();
            third_list_is_valid = false;
            thirdListLineEdit->setNonValid();
            styleSheetTimeLine->start();
            statusBar()->showMessage(QString("There are equal numbers in lists"),5000);
        }
    }
}

void MainWindow::updateFirstList()
{
    firstList = firstListLineEdit->text().split(",").toVector();
    if(!firstList.isEmpty())
    {
        if(firstList.last() == QString(""))
        {
            // remove empty string
            firstList.removeLast();
        }
        first_list_is_valid = true; // just for now let us think that list is valid
    }
}

void MainWindow::updateSecondList()
{
    secondList = secondListLineEdit->text().split(",").toVector();
    if(!secondList.isEmpty())
    {
        if(secondList.last() == QString(""))
        {
            // remove empty string
            secondList.removeLast();
        }
        second_list_is_valid = true; // just for now let us think that list is valid
    }
}

void MainWindow::updateThirdList()
{
    thirdList = thirdListLineEdit->text().split(",").toVector();
    if(!thirdList.isEmpty())
    {
        if(thirdList.last() == QString(""))
        {
            // remove empty string
            thirdList.removeLast();
        }
        third_list_is_valid = true; // just for now let us think that list is valid
    }
}

void MainWindow::delay(int msecs)
{
    QEventLoop loop;
    QTimer::singleShot(msecs, &loop, &QEventLoop::quit);
    loop.exec();
}

void MainWindow::reset()
{
    startButton->setEnabled(true);
    firstListLineEdit->setEnabled(true);
    secondListLineEdit->setEnabled(true);
    thirdListLineEdit->setEnabled(true);
    start_pressed = false;
    first_list_is_valid = false;
    second_list_is_valid = false;
    third_list_is_valid = false;
    firstList.clear();
    secondList.clear();
    thirdList.clear();
    delete[] first_list;
    first_list = nullptr;
    delete[] second_list;
    second_list = nullptr;
    delete[] third_list;
    third_list = nullptr;
}

