#include "Calculator.h"

double previousNum = 0.0;

void Calculator::setOperation(QString operation)
{
    if (!lineEdit->text().isEmpty())
    {
        previousNum = lineEdit->text().toDouble();
        lineEdit->clear();
    }

    if(currentOperation == "+")
    {
        s += previousNum;
    }
    else if (currentOperation == "-")
    {
        s -= previousNum;
    }
    else if (currentOperation == "*")
    {
        s *= previousNum;
    }
    else if (currentOperation == "/")
    {
        if (previousNum != 0.0)
        {
            s /= previousNum;
        }
        else
        {
            lineEdit->setText("Error!");
            return;
        }
    }
    else
    {
        s = previousNum;
    }
    currentOperation = operation;
}

void Calculator::equals()
{
    double currentNum = lineEdit->text().toDouble();
    if (currentOperation == "+")
    {
        result = s + currentNum;
    }
    else if (currentOperation == "-")
    {
        result = s - currentNum;
    }
    else if (currentOperation == "*")
    {
        result = s * currentNum;
    }
    else if (currentOperation == "/")
    {
        if (currentNum != 0.0)
        {
            result = s / currentNum;
        }
        else
        {
            lineEdit->setText("Error!");
            return;
        }
    }
    lineEdit->setText(QString::number(result));
    result = 0.0;
    s = 0.0;
}

void Calculator::appendNumber()
{
    if(lineEdit->text() == "0")
    {
        lineEdit->clear();
    }

    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button)
    {
        QString number = button->text();
        QString currentText = lineEdit->text();

        if (number == "." && currentText.contains("."))
        {
            return;
        }

        if (currentText == "0" && number == ".")
        {
            lineEdit->setText("0.");
        }
        else if (lineEdit)
        {
            lineEdit->insert(number);
        }
    }
}

void Calculator::funZero()
{
    lineEdit->insert("0");
    result = 0.0;
}

void Calculator::Quit()
{
    qApp->exit();
}

void Calculator::funcForLbl() {
    lineEdit = new QLineEdit(this);
    lineEdit->setReadOnly(true);
    result = 0.0;
}

void Calculator::backspace()
{
    QString currentText = lineEdit->text();
    if (!currentText.isEmpty())
    {
        currentText.chop(1);
        lineEdit->setText(currentText);
        if (lineEdit->text().isEmpty())
        {
            lineEdit->setText("0");
        }

    }
}


Calculator::Calculator()
{
    funcForLbl();
    grid = new QGridLayout(this);
    QPushButton *dltBtn = new QPushButton("delete",this);
    QPushButton *plsBtn = new QPushButton("+",this);
    QPushButton *mnsBtn = new QPushButton("-",this);
    QPushButton *mltpBtn = new QPushButton("*",this);
    QPushButton *dvdBtn = new QPushButton("/",this);
    QPushButton *equal = new QPushButton("=",this);
    QPushButton *clear = new QPushButton("clear",this);
    QPushButton *bimbimbambam = new QPushButton("bimbimbambam",this);
    QPushButton *point = new QPushButton(".",this);

    lineEdit->setReadOnly(true);
    result = 0.0;
    setFixedSize(430,550);

    grid->addWidget(bimbimbambam, 2,0,1,3);
    bimbimbambam->setMaximumSize(100000, 10000);

    grid->addWidget(point,1,2);
    point->setMaximumSize(100000, 10000);

    grid->addWidget(dltBtn, 1,1,1,1);
    dltBtn->setMaximumSize(100000, 10000);

    grid->addWidget(clear, 1,0,1,1);
    equal->setMaximumSize(100000, 10000);

    grid->addWidget(plsBtn, 4,3);
    plsBtn->setMaximumSize(100000, 10000);

    grid->addWidget(mnsBtn, 3,3);
    mnsBtn->setMaximumSize(100000, 10000);

    grid->addWidget(mltpBtn, 2,3);
    mltpBtn->setMaximumSize(100000, 10000);

    grid->addWidget(dvdBtn, 1,3);
    dvdBtn->setMaximumSize(100000, 10000);

    grid->addWidget(equal, 5,3,2,1);
    clear->setMaximumSize(100000, 10000);

    grid->addWidget(lineEdit, 0, 0, 1, 4);

    for(int i = 0; i < 10; i++)
    {
        QPushButton *btn = new QPushButton((symOfnumbers[i]), this);
        btnOfNumbers.push_back(btn);
    }

    for(int i = 0; i < 10; i++)
    {
        btnOfNumbers[i]->setMaximumSize(100000, 10000);
    }

    int k = -1;
    int t = 0;
    int q = 0;
    int l = 0;

    grid->addWidget(btnOfNumbers[7], 3, 0);
    grid->addWidget(btnOfNumbers[8], 3, 1);
    grid->addWidget(btnOfNumbers[9], 3, 2);
    grid->addWidget(btnOfNumbers[4], 4, 0);
    grid->addWidget(btnOfNumbers[5], 4, 1);
    grid->addWidget(btnOfNumbers[6], 4, 2);
    grid->addWidget(btnOfNumbers[1], 5, 0);
    grid->addWidget(btnOfNumbers[2], 5, 1);
    grid->addWidget(btnOfNumbers[3], 5, 2);
    grid->addWidget(btnOfNumbers[0], 6, 0, 1, 3);

    setStyleSheet("QWidget {"
                  "    background-color: black;"
                  "}"
                  "QPushButton {"
                  "    background-color: white;"
                  "    color: black;"
                  "    border-style: outset;"
                  "    border-width: 2px;"
                  "    border-radius: 10px;"
                  "    border-color: beige;"
                  "    font: bold 15px;"
                  "    min-width: 4em;"
                  "    padding: 6px;"
                  "}"
                  "QPushButton#dltBtn {"
                  "    background-color: red;"
                  "}"
                  "QPushButton#equal {"
                  "    background-color: orange;"
                  "}"
                  "QPushButton#clear {"
                  "    background-color: #ADD8E6;"
                  "}"
                  "QPushButton#bimbimbambam {"
                  "    background-color: #800080;"
                  "}"
                  "QLineEdit {"
                  "    background-color: #FFFFFF;"
                  "    color: black;"
                  "    border-style: solid;"
                  "    border-width: 2px;"
                  "    border-color: #C0C0C0;"
                  "    font: bold 14px;"
                  "    padding: 6px;"
                  "}");

    dltBtn->setObjectName("dltBtn");
    equal->setObjectName("equal");
    clear->setObjectName("clear");
    bimbimbambam->setObjectName("bimbimbambam");

    for(int i = 0; i < 10; i++)
    {
        btnOfNumbers[i]->setMaximumSize(100000, 10000);
    }

    lineEdit->insert("0");

    for(int i = 0; i < 10; i++) {
        connect(btnOfNumbers[i], &QPushButton::clicked, this, &Calculator::appendNumber);
    }

    connect(bimbimbambam, &QPushButton::clicked, this, [this]()
    {
        QDesktopServices::openUrl(QUrl("https://www.youtube.com/watch?v=LbOve_UZZ54"));
    });

    connect(bimbimbambam, &QPushButton::clicked, this,&Calculator::Quit);
    connect (clear,&QPushButton::clicked,lineEdit,&QLineEdit::clear);
    connect (clear,&QPushButton::clicked,this,&Calculator::funZero);
    connect(plsBtn, &QPushButton::clicked, this, [this](){ setOperation("+"); });
    connect(mnsBtn, &QPushButton::clicked, this, [this](){ setOperation("-"); });
    connect(mltpBtn, &QPushButton::clicked, this, [this](){ setOperation("*"); });
    connect(dvdBtn, &QPushButton::clicked, this, [this](){ setOperation("/"); });
    connect(equal, &QPushButton::clicked, this, &Calculator::equals);
    connect(dltBtn, &QPushButton::clicked, this, &Calculator::backspace);
    connect(point, &QPushButton::clicked, this, &Calculator::appendNumber);

    setLayout(grid);
}

Calculator::~Calculator()
{
    delete lineEdit;
    delete grid;
}