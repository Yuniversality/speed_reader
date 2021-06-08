#include "speedreadwindow.h"
#include "ui_speedreadwindow.h"

//For using timer functions
#include <QTimer>
//For doing qDebug() like cout for debugging
//#include <QDebug>

//1 minute = 60k (60000) milliseconds
constexpr int millisecondsInMinute = 60000;
constexpr int fontSizeChangeAmount = 10;
constexpr int defaultReadingSpeed = 200;
constexpr int defaultFontSize = 48;

speedReadWindow::speedReadWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::speedReadWindow)
{
    //Set up some member variables
    //Others set in on_startRestartButton_clicked()
    readingSpeed = defaultReadingSpeed;
    fontSize = defaultFontSize;

    //Setting up the timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTextLabel()));
    timer->setInterval(millisecondsInMinute / readingSpeed);

    //Set up the ui elements
    ui->setupUi(this);
}

speedReadWindow::~speedReadWindow()
{
    delete ui;
}

/************************************
 *  Timer and UI Changing Functions
*************************************/

//Once the timer finishes an interval, change the word
// displayed on the screen. If it is the last word,
// then stop the timer
//Also updates the progress bar
void speedReadWindow::updateTextLabel()
{
    if (currentWord != stringList.cend())
    {
        ui->speedReadLabel->setText(*currentWord);
        numWordsRead++;
        updateProgressBar();
        currentWord++;
    }
    else
    {
        updateProgressBar();
        timer->stop();
    }
}

//When the value in the spinbox changes, calculate the new
// interval of the timer using the new value
// Note: This is triggered for every char changed in the
// spinbox
//If you want to go from 200 to 300 by deleting
// the 2 and replacing by 3, the values will go from 200
// to 0 then to 300
//If you highlight and replace the 2 with a 3, then it
// will go straight from 200 to 300
void speedReadWindow::on_spinBox_valueChanged(int newSpeed)
{
    readingSpeed = newSpeed;
    timer->setInterval(millisecondsInMinute / readingSpeed);
}

//Change the font size of the word display label
void speedReadWindow::updateFontSize(int changeAmount)
{
    QFont font;
    fontSize = fontSize + changeAmount;
    font.setPointSize(fontSize);
    ui->speedReadLabel->setFont(font);
}

//Sets the progress bar percent based on how much of
// the text is read
void speedReadWindow::updateProgressBar(void)
{
    double progressPercent = (numWordsRead * 100) / textLength;
    ui->progressBar->setValue(progressPercent);
}

/*****************************
*   Bottom button functions
******************************/

//When you click the "Exit" button, close the window
void speedReadWindow::on_exitButton_clicked()
{
    //Since the timer is made with new, we need to
    // delete it after use
    delete timer;

    //Exit by saying we're done with this window
    done(0);
}

//When you click the "Start/Reset" button, restart timer
// and start the text from the beginning
//Also sets up the textLength and stringList member variables
void speedReadWindow::on_startRestartButton_clicked()
{
    stringList = readingText.split(" ");
    textLength = stringList.length();
    numWordsRead = 0;
    currentWord = stringList.cbegin();
    ui->speedReadLabel->setText(*currentWord);
    timer->start();
}

//When you click the "Pause/Resume" button, it either
// pauses the timer if it's running or starts it if
// it was paused
void speedReadWindow::on_pauseResumeButton_clicked()
{
    timer->isActive() ? timer->stop() : timer->start();
}

//When you click the "Decrease Font Size Button", decrease font
// size by set amount of points
void speedReadWindow::on_DecreaseFontSize_clicked()
{
    updateFontSize(-fontSizeChangeAmount);
}

//When you click the "Increase Font Size Button", increase font
// size by set amount of points
void speedReadWindow::on_IncreaseFontSize_clicked()
{
    updateFontSize(fontSizeChangeAmount);
}




