#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->lista = new lista_figura();
    this->board = new PaintBoard();
    this->board->setListaFiguras(this->lista);
    this->ui->gridLayout->addWidget(this->board,0,0,1,1);
    this->inicializar_colores();
    this->inicializar_posiciones();
    srand(time(0)); // Inicializar la semilla del random
    this->on_cmbTipoCara_currentIndexChanged(0);
    this->dibujar=false;
    this->actualizarTipoFigura("Ojos1");
    this->on_cmbRasgos_currentIndexChanged(0);
    this->establecerConexion();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->board;
    delete this->lista; // o  this->lista->limpiar();
}
void MainWindow::establecerConexion(){
    connect(ui->spinOjosH,SIGNAL(valueChanged(int)),this,
            SLOT(actualizarBord()));
    connect(ui->spinOjosW,SIGNAL(valueChanged(int)),this,
            SLOT(actualizarBord()));
    connect(ui->spinOjosX,SIGNAL(valueChanged(int)),this,
            SLOT(actualizarBord()));
    connect(ui->spinOjosY,SIGNAL(valueChanged(int)),this,
            SLOT(actualizarBord()));
    connect(ui->spinOjosX,SIGNAL(valueChanged(int)),this,
            SLOT(modificarX(int)));
    connect(ui->spinOjosY,SIGNAL(valueChanged(int)),this,
            SLOT(modificarY(int)));
    connect(ui->txtCara1,SIGNAL(textChanged(QString)),this,
            SLOT(actualizarCara()));
    connect(ui->txtCara2,SIGNAL(textChanged(QString)),this,
            SLOT(actualizarCara()));
    connect(ui->pbColor,SIGNAL(clicked()),this,
            SLOT(actualizarCara()));
    connect(ui->pbColor_2,SIGNAL(clicked()),this,
            SLOT(actualizarCara()));
    connect(ui->cmbTipoCara,SIGNAL(currentIndexChanged(int)),this,
            SLOT(actualizarCara()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,
            SLOT(actualizarTipoFigura(QString)));
    connect(ui->spinOjosH,SIGNAL(valueChanged(int)),this,
            SLOT(modificarH(int)));
    connect(ui->spinOjosW,SIGNAL(valueChanged(int)),this,
            SLOT(modificarW(int)));
    connect(ui->cmbRasgos,SIGNAL(highlighted(int)),this,
            SLOT(modificarPos()));

}

void MainWindow::inicializar_posiciones(){
    for(int i=0;i<ui->cmbRasgos->count();i++)
        this->posiciones.push_back(new Posiciones(200,200));
}
void MainWindow::modificarPos(){
    this->posiciones.at(ui->cmbRasgos->currentIndex())->pos=ui->comboBox->currentIndex();
}

void MainWindow::actualizarBord(){
    this->modificarRasgos(true);
}

void MainWindow::on_pbColor_clicked()
{
    QColor color = QColorDialog::getColor();
    QPalette pal = ui->lblColor->palette();
    pal.setColor(ui->lblColor->backgroundRole(),color);
    ui->lblColor->setPalette(pal);
    ui->lblColor->setAutoFillBackground(true);


    //ui->lblColor->setStyleSheet("background-color: green");

}



void MainWindow::inicializar_colores()
{

    QPalette pal = ui->lblFondo->palette();
    pal.setColor(ui->lblFondo->backgroundRole(),Qt::blue);
    ui->lblFondo->setPalette(pal);
    ui->lblFondo->setAutoFillBackground(true);

    pal = ui->lblColor->palette();
    pal.setColor(ui->lblColor->backgroundRole(),Qt::black);
    ui->lblColor->setPalette(pal);
    ui->lblColor->setAutoFillBackground(true);

}

void MainWindow::on_pbColor_2_clicked()
{
    QColor color = QColorDialog::getColor();
    QPalette pal = ui->lblFondo->palette();
    pal.setColor(ui->lblFondo->backgroundRole(),color);
    ui->lblFondo->setPalette(pal);
    ui->lblFondo->setAutoFillBackground(true);
}

void MainWindow::on_pbLimpiar_clicked()
{
    this->lista->limpiar();
    this->board->update();
}

void MainWindow::modificarCara(bool t){
    Cabeza *C=new Cabeza();

    if(t){
        int var=this->ui->cmbTipoCara->currentIndex();
        C->setTipo(var);
        QColor color = this->ui->lblColor->palette().background().color();
        QColor fondo = this->ui->lblFondo->palette().background().color();
        C->setColor(color);
        C->setFondo(fondo);
        C->setX(510/2);
        C->setY(410/2);
        if(var==0){
            C->setRadio1(ui->txtCara1->text().toInt());
        }else if(var==1){
            C->setAlto(ui->txtCara2->text().toInt());
            C->setAncho(ui->txtCara1->text().toInt());
        }else{
            C->setRadio1(ui->txtCara1->text().toInt());
            C->setRadio2(ui->txtCara2->text().toInt());
        }
    }

    this->lista->agregar(C,t);
    this->board->update();

}
void MainWindow::actualizarCara(QString t, int n){
    this->modificarCara(true);
}

void MainWindow::on_btnAniadir_clicked()
{
    this->modificarCara(false);
}

void MainWindow::on_cmbTipoCara_currentIndexChanged(int index)
{
    if(index==0){
        ui->lblCara1->setText("Radio: ");
        ui->lblCara2->hide();
        ui->txtCara2->hide();
        ui->txtCara1->setValidator(new QIntValidator(0,200,this));
        ui->txtCara1->setText("");
    }else if(index==1){
        ui->lblCara1->setText("Ancho: ");
        ui->lblCara2->setText("Alto: ");
        ui->lblCara2->show();
        ui->txtCara2->show();
        ui->txtCara1->setText("");
        ui->txtCara2->setText("");
        ui->txtCara1->setValidator(new QIntValidator(0,500,this));
        ui->txtCara2->setValidator(new QIntValidator(0,400,this));
    }else{
        ui->lblCara1->setText("Radio 1: ");
        ui->lblCara2->setText("Radio 2: ");
        ui->txtCara1->setText("");
        ui->txtCara2->setText("");
        ui->lblCara2->show();
        ui->txtCara2->show();
        ui->txtCara1->setValidator(0);
        ui->txtCara2->setValidator(0);
    }

}

void MainWindow::modificarRasgos(bool t){

    Rasgos *R=new Rasgos();
    R->setUrl(this->tipoRasgo);
    int val=ui->cmbRasgos->currentIndex();
    if(val==0){
        R->setTipoFigura('O');
    }else if(val==1){
        R->setTipoFigura('N');
    }else if(val==2){
        R->setTipoFigura('B');
    }else{
        R->setTipoFigura('H');
    }
    if(t){
        R->setX(ui->spinOjosX->value());
        R->setY(ui->spinOjosY->value());
        R->setAlto(ui->spinOjosH->value());
        R->setAncho(ui->spinOjosW->value());
    }

    this->lista->agregar(R,t);
    this->board->update();
}

void MainWindow::on_btnOjos_clicked()
{
    this->modificarRasgos(false);
}

void MainWindow::actualizarTipoFigura(QString t)
{
    this->tipoRasgo=":imagenes/";
    this->tipoRasgo+=this->ui->cmbRasgos->currentText();
    this->tipoRasgo+="/";
    this->tipoRasgo+=t;
    tipoRasgo+=".png";
    if(this->posiciones.at(ui->cmbRasgos->currentIndex())->alto==0 && this->posiciones.at(ui->cmbRasgos->currentIndex())->ancho==0){
        QPixmap pix(this->tipoRasgo);
        this->posiciones.at(ui->cmbRasgos->currentIndex())->alto=pix.height();
        this->posiciones.at(ui->cmbRasgos->currentIndex())->ancho=pix.width();
        this->actualizarDimensiones();
    }

    if(this->dibujar){
        this->actualizarBord();
    }else{
        this->dibujar=true;
    }

}
void MainWindow::actualizarDimensiones(){
    ui->spinOjosH->setValue(this->posiciones.at(ui->cmbRasgos->currentIndex())
                            ->alto);
    ui->spinOjosW->setValue(this->posiciones.at(ui->cmbRasgos->currentIndex())
                            ->ancho);
}

void MainWindow::modificarX(int x){
    this->posiciones.at(ui->cmbRasgos->currentIndex())->posX=x;
}
void MainWindow::modificarY(int y){
    this->posiciones.at(ui->cmbRasgos->currentIndex())->posY=y;
}
void MainWindow::modificarH(int h){
    this->posiciones.at(ui->cmbRasgos->currentIndex())->alto=h;
}
void MainWindow::modificarW(int w){
    this->posiciones.at(ui->cmbRasgos->currentIndex())->ancho=w;
}

void MainWindow::on_cmbRasgos_currentIndexChanged(int index)
{

    QString val2;
    int cant=0;
    ui->comboBox->clear();
    if(index==0){
        this->rasgo="Ojos";
        cant=10;

    }else if(index==1){
        this->rasgo="Nariz";
        cant=10;
    }else if(index==2){
        this->rasgo="Boca";
        cant=10;
    }else if(index==3){
        this->rasgo="Cabello";
        cant=10;
    }
    for(int i=1;i<=cant;i++){
        val2=this->rasgo;
        if(i<10){
            val2+=(i+'0');
        }else{
            char var[10];
            val2+=itoa(i,var,10);
        }
        ui->comboBox->addItem(val2);
    }
    ui->comboBox->setCurrentIndex(this->posiciones.at(index)
                                  ->pos);
    qDebug()<<this->posiciones.at(index)->pos;
    ui->spinOjosX->setValue(this->posiciones
                            .at(index)->posX);
    ui->spinOjosY->setValue(this->posiciones
                            .at(index)->posY);
    this->actualizarDimensiones();
}

void MainWindow::on_btnGuardarImagen_clicked()
{
    QString file=QFileDialog::getSaveFileName(this,tr("Output Image File"),QDir::currentPath(),
                   tr("PNG (*.png)"));
    QPixmap pix(ui->gridLayout->geometry().width(),ui->gridLayout->geometry().height());
    pix.fill(Qt::transparent);
    QPainter painter(&pix);
    if(this->lista!=0){
        lista->ir_a_inicio();
        for(int i=0;i<lista->getCuantos();i++){
            Figura *temp=lista->recuperar();
            if(temp!=0){
                temp->Dibujar(&painter);
            }
            lista->siguiente();
        }
    }
    pix.save(file);
}
