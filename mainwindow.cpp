#include "mainwindow.h"
#include "ui_mainwindow.h"
#define N 3

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


void MainWindow::on_matriz_a11_valueChanged(const QString &a11) { ui->lbl_a11->setText("<h4>" + a11 + "</h4>"); }
void MainWindow::on_matriz_a12_valueChanged(const QString &a12) { ui->lbl_a12->setText("<h4>" + a12 + "</h4>"); }
void MainWindow::on_matriz_a13_valueChanged(const QString &a13) { ui->lbl_a13->setText("<h4>" + a13 + "</h4>"); }
void MainWindow::on_matriz_a14_valueChanged(const QString &a14) { ui->lbl_a14->setText("<h4>" + a14 + "</h4>"); }
void MainWindow::on_matriz_a21_valueChanged(const QString &a21) { ui->lbl_a21->setText("<h4>" + a21 + "</h4>"); }
void MainWindow::on_matriz_a22_valueChanged(const QString &a22) { ui->lbl_a22->setText("<h4>" + a22 + "</h4>"); }
void MainWindow::on_matriz_a23_valueChanged(const QString &a23) { ui->lbl_a23->setText("<h4>" + a23 + "</h4>"); }
void MainWindow::on_matriz_a24_valueChanged(const QString &a24) { ui->lbl_a24->setText("<h4>" + a24 + "</h4>"); }
void MainWindow::on_matriz_a31_valueChanged(const QString &a31) { ui->lbl_a31->setText("<h4>" + a31 + "</h4>"); }
void MainWindow::on_matriz_a32_valueChanged(const QString &a32) { ui->lbl_a32->setText("<h4>" + a32 + "</h4>"); }
void MainWindow::on_matriz_a33_valueChanged(const QString &a33) { ui->lbl_a33->setText("<h4>" + a33 + "</h4>"); }
void MainWindow::on_matriz_a34_valueChanged(const QString &a34) { ui->lbl_a34->setText("<h4>" + a34 + "</h4>"); }

void MainWindow::on_btn_calc_clicked()
{
    int i, j, k;
    float fator, soma;
    float res[N];
    float M[N][N+1];
    QString x, y, z = "";

    M[0][0] = ui->matriz_a11->value();
    M[0][1] = ui->matriz_a12->value();
    M[0][2] = ui->matriz_a13->value();
    M[0][3] = ui->matriz_a14->value();
    M[1][0] = ui->matriz_a21->value();
    M[1][1] = ui->matriz_a22->value();
    M[1][2] = ui->matriz_a23->value();
    M[1][3] = ui->matriz_a24->value();
    M[2][0] = ui->matriz_a31->value();
    M[2][1] = ui->matriz_a32->value();
    M[2][2] = ui->matriz_a33->value();
    M[2][3] = ui->matriz_a34->value();

    // ELIMINACAO PROGRESSIVA
    for(k = 0; k<N-1; k++){//Laco exterior se refere a coluna pivo que se altera. (linha pivo ou equacao pivo = equacao referencial para as eliminacoes)
        for(i = (k+1); i<N; i++){//Este laco se refere as linhas que sofrerao as eliminacoes, que sempre iniciarao na linha seguinte da linha pivo
            fator = M[i][k] / M[k][k];//fator de correcao que sera multiplicada pela linha pivo

    for(j=0; j<=N; j++){//loco interno se refere a cada coluna da linha que sofrerao modificacoes da linha i
                M[i][j] = M[i][j] - fator*M[k][j];
            }
        }
    }

    res[N-1] = M[N-1][N] / M[N-1][N-1]; // Primeria variavel que obtamos

    // SUBSTITUICAO PROGRESSIVA
    for(i=N-2; i>=0; i--){  //Laco exterior se refere a linha que recebera os valores das variaveis ja encontradas para descobrirmos  as outras. Ela se inicia na penultima linha e vai ate a primeira

        soma = 0;
        for(j=(i+1); j<N; j++){     //Laco interno se refere as colunas da linha i
            soma = soma + M[i][j]*res[j]; // soma todos os numeros da linha que ja tem o valor de x
        }
        res[i] = (M[i][N] - soma)/M[i][i]; // Calcula o x da coluna i
    }

    x = QString::number(res[0]);
    y = QString::number(res[1]);
    z = QString::number(res[2]);

    ui->lbl_x->setText("<h2>X = " + x + "</h2>");
    ui->lbl_y->setText("<h2>Y = " + y + "</h2>");
    ui->lbl_z->setText("<h2>Z = " + z + "</h2>");
}
