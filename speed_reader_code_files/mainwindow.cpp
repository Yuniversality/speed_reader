#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "speedreadwindow.h"

//To access and work with files
#include <QFileDialog>
//For popup warning messages
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/****************************************
 *  Menu Bar Buttons Functions
*****************************************/

//When you click the File > Exit button, exit application
void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

//When you click the File > Open button, open a file and
// copy its text to the textEdit
//Only accepts .txt files to extract from because the
// extract function doesn't work with the other file types
void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    if (!fileName.contains(".txt"))
    {
        QMessageBox::warning(this, "Warning", "This file will not work with the program. Please only import .txt files");
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
        return;
    }
    ui->textEdit->clear();
    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());
    file.close();
}

/****************************************
*     Bottom Clickable Button Functions
*****************************************/

//When you click the "Choose File" button, do the same
// thing as on_actionOpen_triggered()
void MainWindow::on_chooseFileButton_clicked()
{
    on_actionOpen_triggered();
}

//When you click the "Continue" button, open the
// speedReadWindow QDialog
//Also checks to see if anything was inputted
// (just whitespace doesn't count) and prompts
// the user to enter something if nothing was
// inputted
void MainWindow::on_continueButton_clicked()
{
    speedReadWindow newWindow;
    QString textToRead = ui->textEdit->toPlainText();
    textToRead = textToRead.simplified();
    newWindow.setReadingText(textToRead);

    if (textToRead.isEmpty() || textToRead.isNull())
    {
        QMessageBox::warning(this, "Warning", "No text given, please enter some words");
        ui->textEdit->clear();
        return;
    }
    else
    {
        newWindow.setModal(true);
        newWindow.exec();
    }
}

//When you click the "Exit" button, exit application
void MainWindow::on_exitButton_clicked()
{
    QApplication::quit();
}

//When you click the "Clear" button, remove all text
// from the textEdit
void MainWindow::on_clearButton_clicked()
{
    ui->textEdit->clear();
}

//When you click the "Undo" button, undo the last change
// in the textEdit (if possible)
void MainWindow::on_undoButton_clicked()
{
    ui->textEdit->undo();
}

//When you click the "Redo" button, redo the last change
// in the textEdit (if possible)
void MainWindow::on_redoButton_clicked()
{
    ui->textEdit->redo();
}
