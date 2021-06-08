#ifndef SPEEDREADWINDOW_H
#define SPEEDREADWINDOW_H

#include <QDialog>

namespace Ui {
class speedReadWindow;
}

class speedReadWindow : public QDialog
{
    Q_OBJECT

public:
    explicit speedReadWindow(QWidget *parent = nullptr);
    ~speedReadWindow();

    inline void setReadingText(QString newText) {
        readingText = newText;
    }
    inline QString getReadingText(void) {
        return readingText;
    }

private slots:
    //My own function to connect to the timer
    void updateTextLabel();

    //Auto-generated slot functions
    void on_exitButton_clicked();

    void on_startRestartButton_clicked();

    void on_pauseResumeButton_clicked();

    void on_DecreaseFontSize_clicked();

    void on_IncreaseFontSize_clicked();

    void on_spinBox_valueChanged(int newSpeed);

private:
    Ui::speedReadWindow *ui;
    QString readingText;
    int textLength;
    int numWordsRead;
    int readingSpeed;
    int fontSize;
    QStringList stringList;
    QStringList::const_iterator currentWord;
    QTimer *timer;

    void updateFontSize(int changeAmount);
    void updateProgressBar(void);
};

#endif // SPEEDREADWINDOW_H
