#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMessageBox>
#include "func.h"
#include <QMainWindow>
#include <QMenu>
#include <qlabel.h>
#include <qpushbutton.h>
#include <QLineEdit>
#include "dialog.h"
#include <QInputDialog>
#include "arch.h"
#include <QtWidgets>


#include <QMainWindow>

class QAction;
class QActionGroup;
class QLabel;
class QMenu;

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    fold *r;
    func *f;
    arch *c;
    void contextMenuEvent(QContextMenuEvent *event) override;
    void createActions();
    void createMenus();
    void addRoot(QString name,QString Descripcion);
    QTreeWidgetItem *addchild2(QString name,QString Descripcion);
    void addChild(QTreeWidgetItem *parent, QString name,QString Descripcion);
    QTreeWidgetItem *itm2;
    QList<QTreeWidgetItem*>itm3;
private slots:
    void refresh();
    void eliminate();
    void open();
    void read();
    void edit();
    void text();
    void copy();
    void habilitarCarpeta();
    void habilitarArchivo();
    int buscar();
    void dibujar();
    void colorear();
    void paste();
    void addTitule(string n);
    QTreeWidgetItem *PosicionArbol(QTreeWidgetItem* u);
    void on_actionCARPETA_triggered();
    void on_actionARCHIVO_triggered();
    void on_pushButton_clicked();
    void on_pushButton2_clicked();
    void on_pegar_clicked();
    void on_regresar_clicked();
    void on_actionLeer_triggered();
    void on_actionEditar_2_triggered();
    void on_actionCopiar_triggered();
    void on_actionPegar_triggered();
    void on_actionEliminar_triggered();
    void on_actionAbrir_triggered();
    void on_actionCopiar_2_triggered();
    void on_actionEliminar_2_triggered();
    void on_actionPegar_2_triggered();

private:
    Ui::MainWindow *ui;
    int cb,cl,Y, X;
    QList<QPushButton*> lc;
    QList<QPushButton*> lb;
    QList<QLineEdit*> le;
    string *lista;
    QMessageBox b;
    Dialog texting;
    int bloques;
    //QPushButton lbloques[12]={};


    string t;
    string rt;
    fold *a;
    string n,d;
    int x;

    QMenu *editMenu;
    QMenu *algo;
    QAction *leerAct;
    QAction *editarAct;
    QAction *copiarAct;
    QAction *pegarAct;
    QAction *eliminarAct;
    QAction *abrirAct;
};

#endif // MAINWINDOW_H
