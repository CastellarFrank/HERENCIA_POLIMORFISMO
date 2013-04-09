#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QValidator>
#include <cstdlib>
#include <ctime>
#include "lista_figura.h"
#include "paintboard.h"
#include "figura.h"
#include "cabeza.h"
#include "rasgos.h"
#include <QImage>
#include <QFileDialog>
#include <QPixmap>
#include <QSound>
#include <QStringList>


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void inicializar_colores();
    void inicializar_posiciones();

private:
    Ui::MainWindow *ui;
    lista_figura *lista;
    PaintBoard *board;
    QColor currentColor, backGroundColor;
    QValidator *validator;
    QString tipoRasgo;
    QString rasgo;
    QList<Posiciones*>posiciones;
    void modificarRasgos(bool t);
    void modificarCara(bool t);
    void establecerConexion();
    void actualizarDimensiones();
    bool dibujar;


private slots:
    void on_btnGuardarImagen_clicked();
    void on_cmbRasgos_currentIndexChanged(int index);
    void on_btnOjos_clicked();
    void on_cmbTipoCara_currentIndexChanged(int index);
    void on_btnAniadir_clicked();
    void on_pbLimpiar_clicked();
    void on_pbColor_2_clicked();
    void on_pbColor_clicked();
    void actualizarBord();
    void actualizarCara(QString t=" ",int n=0);
    void modificarX(int x);
    void modificarY(int y);
    void modificarH(int h);
    void modificarW(int w);
    void modificarPos();
    void actualizarTipoFigura(QString t);
};

#endif // MAINWINDOW_H
