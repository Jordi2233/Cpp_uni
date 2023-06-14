#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action_Koniec, SIGNAL(triggered()), this, SLOT(koniec_programu()) );
    //change default icon to pause and connect przycisk to function changeIcon
    ui->przycisk->setIcon(QIcon(":/images/media-playback-pause.png"));
    connect(ui->przycisk, SIGNAL(clicked()), this, SLOT(changeIcon()));
    // set icons instead koniec and o programie
    ui->action_Koniec->setIcon(QIcon(":/images/shutdown.png"));
    ui->action_O_programie->setIcon(QIcon(":/images/questionmark.png"));
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::koniec_programu()
{
    QMessageBox msgBox;
    // set icon of question mark
    QPixmap iconPixmap(":/images/questionmark.png");
    // resize it cuz its too big
    QPixmap resizedPixmap = iconPixmap.scaled(QSize(32, 32), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    msgBox.setIconPixmap(resizedPixmap);
    // set text that is sayign if user wanna quit the programm
    msgBox.setInformativeText("Czy chcesz wyjść?");
    QPushButton* yesButton = msgBox.addButton(tr("Tak"), QMessageBox::ActionRole);
    QPushButton* noButton = msgBox.addButton(tr("Nie"), QMessageBox::ActionRole);
    msgBox.exec();
    if (msgBox.clickedButton() == yesButton)
        qApp->quit();

}


void MainWindow::on_action_O_programie_triggered()
{
 QMessageBox::aboutQt(this,"O wspaniałym programie");
}

//function that changes icon of stop and pause animation doing by circles
void MainWindow::changeIcon()
{
    if (iconSet)
    {
        ui->przycisk->setIcon(QIcon(":/images/media-playback-start.png"));
        iconSet = false;
    }
    else
    {
        ui->przycisk->setIcon(QIcon(":/images/media-playback-pause.png"));
        iconSet = true;
    }
}
