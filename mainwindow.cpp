#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHeaderLabels(QStringList()<<"Nombre"<<"Tipo");
    f =new func();
    itm2 =new QTreeWidgetItem();
    r =new fold("Raiz","Raiz/");
    a =r;
    rt =a->dir();
    ui->lineEdit->setText(rt.c_str());
    c =NULL;
    cb =0;
    cl =0;
    x=0;
    lista = new string[cb];
    ui->regresar->setStyleSheet("border-image: url(:/image/folder1.png);");
    createActions();
    refresh();
    createMenus();
    f->CrearDiscoVirtual();
    colorear();
    bloques=2;
   // lbloques=new QPushButton("p");

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::colorear()
{
    /*
        lbloques[0]=ui->mb;
        lbloques[1]=ui->fe;
        lbloques[2]=ui->b3;
        lbloques[3]=ui->b4;
        lbloques[4]=ui->b5;
        lbloques[5]=ui->b6;
        lbloques[6]=ui->b7;
        lbloques[7]=ui->b8;
        lbloques[8]=ui->b9;
        lbloques[9]=ui->b10;
        lbloques[10]=ui->b11;
        lbloques[11]=ui->b12;
        */


    ui->mb->setStyleSheet("*{background-color:rgb(50,206,22)}");
    ui->fe->setStyleSheet("*{background-color:rgb(50,206,22)}");
     ui->b3->setStyleSheet("*{background-color:rgb(206,34,22)}");
     ui->b4->setStyleSheet("*{background-color:rgb(206,34,22)}");
     ui->b5->setStyleSheet("*{background-color:rgb(206,34,22)}");
     ui->b6->setStyleSheet("*{background-color:rgb(206,34,22)}");
     ui->b7->setStyleSheet("*{background-color:rgb(206,34,22)}");
     ui->b8->setStyleSheet("*{background-color:rgb(206,34,22)}");
     ui->b9->setStyleSheet("*{background-color:rgb(206,34,22)}");
     ui->b10->setStyleSheet("*{background-color:rgb(206,34,22)}");
     ui->b11->setStyleSheet("*{background-color:rgb(206,34,22)}");
     ui->b12->setStyleSheet("*{background-color:rgb(206,34,22)}");

}
void MainWindow::createActions()
{
    eliminarAct =new QAction(tr("Eliminar"), this);
    eliminarAct->setShortcuts(QKeySequence::Delete);
    connect(eliminarAct, &QAction::triggered, this, &MainWindow::eliminate);

    abrirAct =new QAction(tr("&Abrir"), this);
    abrirAct->setShortcuts(QKeySequence::Open);
    connect(abrirAct, &QAction::triggered, this, &MainWindow::open);

    leerAct =new QAction(tr("&leer"), this);
    connect(leerAct, &QAction::triggered, this, &MainWindow::read);

    editarAct =new QAction(tr("&editar"), this);
    connect(editarAct, &QAction::triggered, this, &MainWindow::edit);

    copiarAct =new QAction(tr("&Copiar"), this);
    copiarAct->setShortcuts(QKeySequence::Copy);
    connect(copiarAct, &QAction::triggered, this, &MainWindow::copy);

    pegarAct =new QAction(tr("&Pegar"), this);
    pegarAct->setShortcuts(QKeySequence::Paste);
    connect(pegarAct, &QAction::triggered, this, &MainWindow::paste);
}


void MainWindow::eliminate()
{
    f->eliminar(x,a);
    refresh();
}

void MainWindow::open()
{
    arch*t =f->Cargar(x,a);
    fold*f =dynamic_cast<fold*>(t);
    fold*t2 =a;
    a =f;
    a->ant =t2;
    refresh();
}

void MainWindow::on_regresar_clicked()
{
    a=r;
    refresh();
}

void MainWindow::edit()
{
    arch*t =f->Cargar(x,a);
    txt*f =dynamic_cast<txt*>(t);
    QString texto =QInputDialog::getText(this,"Escribir","Ingrese Texto:");
    f->setTxt(texto.toStdString());
}

void MainWindow::read()
{
    arch*t =f->Cargar(x,a);
    txt*f =dynamic_cast<txt*>(t);
    string tx =f->Txt();
    b.setText(tx.c_str());
    b.exec();
}
void MainWindow::createMenus()
{
    editMenu = ui->menuBar->addMenu(tr("&Edit"));
    editMenu->setEnabled(false);
    editMenu->addAction(abrirAct);
    editMenu->addAction(leerAct);
    editMenu->addSeparator();
    editMenu->addAction(editarAct);
    editMenu->addAction(eliminarAct);
    editMenu->addAction(copiarAct);
    editMenu->addAction(pegarAct);
    editMenu->addSeparator();
}

void MainWindow::copy()
{
    c =f->Cargar(x,a);
}

int MainWindow::buscar()
{
    QObject* senderObj = sender();
    if (senderObj->isWidgetType())
    {
        QPushButton* button = qobject_cast<QPushButton*>(senderObj);
        if(button!=NULL)
        {
            for(int x = 0;x<lb.size();x++){
                if(lb.at(x) == button)
                    return x;
            }
        }
    }
            return -1;
}


QTreeWidgetItem * MainWindow::PosicionArbol(QTreeWidgetItem* u)
{
    for(int q=0;q<itm3.size();q++){
        if(itm3.at(q)==u)
            itm2=itm3.at(q);

    }
    return itm2;
}

void MainWindow::paste()
{
    arch*n =c;
    f->pegar(n,a);
    refresh();
    c =NULL;
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(abrirAct);
    menu.addAction(leerAct);
    menu.addAction(editarAct);
    menu.addAction(eliminarAct);
    menu.addAction(copiarAct);
    menu.addAction(pegarAct);
    menu.exec(event->globalPos());
}


void MainWindow::addTitule(string n)
{
    le.append(new QLineEdit(this));
    le.at(cl)->setText(n.c_str());
    le.at(cl)->setGeometry(QRect(QPoint(X,Y+45),QSize(70,40)));
    le.at(cl)->setAlignment(Qt::AlignCenter);
    le.at(cl)->show();
    cl++;
}

void MainWindow::on_actionCARPETA_triggered()
{
        QString txt =QInputDialog::getText(this,"Carpeta","Nombre:");
        QString tip="Folder";
        f->Crear(a,txt.toStdString(),"folder");
        addTitule(txt.toStdString());
        lb.append(new QPushButton(this));
        lb.at(cb)->setGeometry(QRect(QPoint(X,Y),QSize(60, 60)));
        lb.at(cb)->setStyleSheet("border-image: url(:/image/Folder.png);");
        lb.at(cb)->show();
        connect(lb.at(cb), SIGNAL (released()),this, SLOT (habilitarCarpeta()));
        cb++;
        X=X+80;
        if(X>=1200){
            X=350;
            Y=Y+100;
        }
        itm3.append(addchild2(txt,tip));
        if(a->nom()=="Raiz"){
            addRoot(txt,tip);
        }
        else{
            PosicionArbol(a->itm2);
            addChild(itm2,txt,tip);
        }

        //lbloques[bloques]->setStyleSheet("*{background-color:rgb(206,34,22)}");
        refresh();
 }

void MainWindow::habilitarCarpeta()
{
    x=buscar();
    editMenu->setEnabled(true);
    abrirAct->setEnabled(true);
    editarAct->setEnabled(false);
    leerAct->setEnabled(false);
}

void MainWindow::habilitarArchivo()
{
    x=buscar();
    editMenu->setEnabled(true);
    abrirAct->setEnabled(false);
    editarAct->setEnabled(true);
    leerAct->setEnabled(true);
}

void MainWindow:: addRoot(QString name,QString Descripcion){
    QTreeWidgetItem *itm= new QTreeWidgetItem(ui->treeWidget);
    itm->setText(0,name);
    itm->setText(1,Descripcion);
    itm2=itm;
    itm3.append(itm);
    a->itm2=itm;
}

void MainWindow:: addChild(QTreeWidgetItem *parent, QString name,QString Descripcion){
    QTreeWidgetItem *itm=new QTreeWidgetItem();
    itm->setText(0,name);
    itm->setText(1,Descripcion);
    parent->addChild(itm);
}

QTreeWidgetItem *MainWindow::addchild2(QString name,QString Descripcion)
{
    QTreeWidgetItem *itm=new QTreeWidgetItem();
    itm->setText(0,name);
    itm->setText(1,Descripcion);
    return itm;
}

void MainWindow::refresh()
{
    for(int q=0;q<lb.size();q++)
    {
        lb.at(q)->close();
        le.at(q)->close();
    }
    for(int q=0;q<lb.size();q++)
    {
        lb.removeAt(q);
        le.removeAt(q);
    }
    cb=0;
    cl=0;
    X=350;
    Y=100;
    QList <arch*> lt;
    lt=f->Listar(a);

    for(int q=0; q<a->cant;q++){
        if(lt.at(q)->t()==0){
            addTitule(lt.at(q)->n());
            lb.append(new QPushButton(this));
            lb.at(cb)->setGeometry(QRect(QPoint(X,Y),QSize(60, 60)));
            lb.at(cb)->setStyleSheet("border-image: url(:/image/txt.png);");
            connect(lb.at(cb), SIGNAL (released()),this, SLOT (habilitarArchivo()));
            lb.at(cb)->show();
            cb++;
            X=X+80;
            if(X>=1200){
                X=350;
                Y=Y+100;
            }
        }
        else{
            addTitule(lt.at(q)->n());
            lb.append(new QPushButton(this));
            lb.at(cb)->setGeometry(QRect(QPoint(X,Y),QSize(60, 60)));
            lb.at(cb)->setStyleSheet("border-image: url(:/image/Folder.png);");
            lb.at(cb)->show();
            connect(lb.at(cb), SIGNAL (released()),this, SLOT (habilitarCarpeta()));
            cb++;
            X=X+80;
            if(X>=1200){
                X=350;
                Y=Y+100;
            }
        }
    }
    rt = a->dir();
    ui->lineEdit->setText(rt.c_str());
}

void MainWindow::on_actionARCHIVO_triggered()
{
    QString tx = QInputDialog::getText(this,"Archivo","Nombre del Archivo:");
    QString tip="Archivo";
    f->Crear(a,tx.toStdString(),"archivo");
    addTitule(tx.toStdString());
    lb.append(new QPushButton(this));
    lb.at(cb)->setGeometry(QRect(QPoint(X,Y),QSize(60, 60)));
    lb.at(cb)->setStyleSheet("border-image: url(:/image/txt.png);");
    connect(lb.at(cb), SIGNAL (released()),this, SLOT (habilitarArchivo()));
    lb.at(cb)->show();
    cb++;
    X=X+80;
    if(X>=1200){
        X=350;
        Y=Y+100;
    }
    itm3.append(addchild2(tx,tip));
    if(a->nom()=="Raiz"){
        addRoot(tx,tip);
    }
    else{
         addChild(itm2,tx,tip);
    }
    refresh();
}
