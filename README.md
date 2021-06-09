# Speed Reader
By: Ethan Yu

## About the Program
This program allows you to import or type in text and speed read it. 
Currently it only accepts .txt files to be imported. 

Developed in C++ using Qt.

## Installation
### Operating System: Windows
### Required Files: Everything in the "speed_reader_release_ver" folder

"speed_reader_code_files" folder not needed! It is only there for you to look at and fulfill the Qt free-use license.

## How to Run
Download the "speed_reader_release_ver" folder and run the "speed_reader.exe" file.

## Usage
### The program consists of 2 windows: 
![image](https://user-images.githubusercontent.com/35979646/121390019-f879da00-c91a-11eb-857a-6dd4525bdb03.png)
![image](https://user-images.githubusercontent.com/35979646/121389961-e9932780-c91a-11eb-9928-b640860767bf.png)

### First screen: Main Window
You type in text into the middle text box or import text into it using the "Choose File" button. 
Only .txt files are supported for importing because Qt functions give unexpected behavior when extracting text from other formats.
When you are done editing the text, then you hit the "Continue" button to go to the reading screen.
If you want to end the program, you can either click the "Exit" button or X in the top right corner. 
The first row of buttons on the bottom are for modifying the text box. You can undo and redo the text or you can clear the whole box using the corresponding buttons. 
In the taskbar, there's a "File" tab with the options "Open" and "Exit" which allow you to choose a file to import from or exit the application respectively and work the same as their button variants.

### Second screen: Speed Read Window
The top half of the screen is where the text is displayed. 
Under that is a progress bar which says how much of the text has been read and it updates after every word.
Above the buttons is a spin box where you can set the speed of the text in words per minute. 
The default is 200 because I read that that was the average reading speed of normal text. 
That might feel slow when the words are being flashed on the screen because our brains process words faster if it's only 1 word at a time.
1 is the slowest text speed, 10000 is the highest words per minute. The higher the number, the faster the words go by.
You can change the font size of the text using the "- Font Size" and "+ Font Size" buttons which change the size by intervals of 10. The starting size is 48.
When you first enter this screen, the words will not show up until you hit the "Start / Restart" button. That will start showing words at the top from the beginning of the inputted text.
If you want to pause or unpause, you can click the "Pause / Unpause" button. The word on top will not change while paused.
If you want to exit this screen, click the "Exit" button or click the X in the top right corner.

Both these screens can be resized to your desired size. The first screen cannot be used while the second screen is available.


## Sources Used
- How to switch windows: https://forum.qt.io/topic/104072/how-to-switch-windows-menus-qwidgets-normally 
- Good practices for includes in headers: https://stackoverflow.com/questions/17173208/switch-windows-in-qt-gui-app 
- Qt Tutorials For Beginners 9 - How to Show Another Window From MainWindow in QT: https://www.youtube.com/watch?v=VigUMAfE2q4 
- QDialog Documentation: https://doc.qt.io/qt-6/qdialog.html 
- QT Signals and Slots: https://doc.qt.io/qt-6/signalsandslots.html 
- QT C++ Notepad App: https://youtu.be/I96uPDifZ1w 
- How to set the font size of the label on pushbutton in Qt?: https://stackoverflow.com/questions/13984811/how-to-set-the-font-size-of-the-label-on-pushbutton-in-qt 
- How to pass data from one window to another | PyQt5 Tutorial: https://www.youtube.com/watch?v=NrijKenny3Y 
- How to open a new window from the main window in Qt?: https://stackoverflow.com/questions/17988292/how-to-open-a-new-window-from-the-main-window-in-qt 
- QDialog documentation: https://doc.qt.io/qt-6/qdialog.html
- QLabel documentation: https://doc.qt.io/qt-6/qlabel.html  
- QTextEdit documentation: https://doc.qt.io/qt-6/qtextedit.html 
- Timer documentation: https://doc.qt.io/qt-6/timers.html 
- ProgressBar documentation: https://doc.qt.io/qt-6/qml-qtquick-controls2-progressbar.html 
- QString documentation: https://doc.qt.io/qt-6/qstring.html
- Qt Tutorials For Beginners 24 - QTimer: https://www.youtube.com/watch?v=E4L4IjAR-Ww 
- Qt Tutorials For Beginners 7 - Layouts in QT (Horizontal, Vertical, Grid and Form): https://youtu.be/gWa2rqe8l6E 
- Deployment Qt apps on Windows: https://youtu.be/8qozxqSZQEg 
- How to release a Qt/C++ application on Linux and Windows?: https://stackoverflow.com/questions/49982419/how-to-release-a-qt-c-application-on-linux-and-windows 
- Qt Creator: how to set debug or release mode: https://stackoverflow.com/questions/26594465/qt-creator-how-to-set-debug-or-release-mode 
- Qt for Windows - Deployment: https://doc.qt.io/qt-5/windows-deployment.html 
