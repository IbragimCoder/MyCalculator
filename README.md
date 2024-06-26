# Calculator

It is a calculator with basic operations such as plus or minus division and multiplication.

In order for the code to work, you should download Qt (preferably Qt6).

My calculator also has an additional button with its own functionality. Its functionality will be shown below.

Here is a code from the project:

### `Description`


Here is my constructor from my class "Calculator" in which buttons are created from the <QPushButton> library, then they are given their location. Some css for the interface.

Now about the button that we asked earlier. There is a special button called "bimbimbambam" when you click on this button, the calculator closes and opens on YouTube the video "По полям Синий трактор едет к нам - A cartoon song for children".

At the end, we connect all the buttons with their functionality.

``` c++

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

```


``Other methods from my class "Calculator"", that is, the functionality that works when you click on the buttons.``


A method that determines which arithmetic operation takes place and performs the necessary actions accordingly.

``` c++

void Calculator::setOperation(QString operation)
{
    if (!lineEdit->text().isEmpty())
    {
        double currentNum = lineEdit->text().toDouble();
        if (currentOperation == "+")
        {
            s += currentNum;
        }
        else if (currentOperation == "-")
        {
            s -= currentNum;
        }
        else if (currentOperation == "*")
        {
            s *= currentNum;
        }
        else if (currentOperation == "/")
        {
            if (currentNum != 0.0)
            {
                s /= currentNum;
            }
            else
            {
                lineEdit->setText("Ошибка!");
                return;
            }
        }
        else
        {
            s = currentNum;
        }
        lineEdit->clear();
    }
    currentOperation = operation;
}

```

Methods that, when clicked on equal, calculate everything, process errors and give the desired result.


```c++
void Calculator::equals()
{
    double currentNum = lineEdit->text().toDouble();
    if (currentOperation == "+")
    {
        s += currentNum;
    }
    else if (currentOperation == "-")
    {
        s -= currentNum;
    }
    else if (currentOperation == "*")
    {
        s *= currentNum;
    }
    else if (currentOperation == "/")
    {
        if (currentNum != 0.0)
        {
            s /= currentNum;
        }
        else
        {
            lineEdit->setText("Ошибка!");
            return;
        }
    }
    lineEdit->setText(QString::number(s));
    s = 0.0;
    currentOperation = "";
}
```

A method that allows you to add as many numbers as you want to the calculator to perform various operations.


``` c++

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

```


Here are a few methods that clean "lineEdit", close the calculator, delete the last number.


``` c++

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

```

### Calculator interface

<img src="image.jpg" alt>


### Video that shows the functionality in detail

![video](video.gif)