#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_pushButton_gerar_clicked()
{
    try
    {
        bool ok;
        int tamanho_array = ui->lineEdit_qtd_elementos->text().toInt(&ok);
        if (!ok){
            throw QString("Quantidade de elementos inválida");
        }
        Conjunto conj(tamanho_array);
        QString saida_vetor = "";
        for (int i = 0; i < tamanho_array; ++i){
            saida_vetor += "|" + QString::number(conj.getVetor()[i]) + "| ";
        }
        ui->textEdit_dados_aleatorios->setText(saida_vetor);
        auto start = std::chrono::high_resolution_clock::now();
        conj.selectionSort();
        auto finish = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
        saida_vetor = "";
        for (int i = 0; i < tamanho_array; ++i){
            saida_vetor += "|" + QString::number(conj.getVetorSelectionSort()[i]) + "| ";
        }
        ui->textEdit_selection_sort->setText(saida_vetor);
        ui->textEdit_selection_sort_nmr_execucoes->setText(QString::number(conj.getNmrExecucoes()));
        ui->textEdit_selection_sort_tempo_execucoes->setText(QString::number(duration.count()) + "µs");

        start = std::chrono::high_resolution_clock::now();
        conj.insertionSort();
        finish = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
        saida_vetor = "";
        for (int i = 0; i < tamanho_array; ++i){
            saida_vetor += "|" + QString::number(conj.getVetorInsertionSort()[i]) + "| ";
        }
        ui->textEdit_insertion_sort->setText(saida_vetor);
        ui->textEdit_insertion_sort_nmr_execucoes->setText(QString::number(conj.getNmrExecucoes()));
        ui->textEdit_insertion_sort_tempo_execucoes->setText(QString::number(duration.count()) + "µs");

        start = std::chrono::high_resolution_clock::now();
        conj.bubbleSort();
        finish = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
        saida_vetor = "";
        for (int i = 0; i < tamanho_array; ++i){
            saida_vetor += "|" + QString::number(conj.getVetorBubbleSort()[i]) + "| ";
        }
        ui->textEdit_bubble_sort->setText(saida_vetor);
        ui->textEdit_bubble_sort_nmr_execucoes->setText(QString::number(conj.getNmrExecucoes()));
        ui->textEdit_bubble_sort_tempo_execucoes->setText(QString::number(duration.count()) + "µs");

        start = std::chrono::high_resolution_clock::now();
        conj.mergeSort();
        finish = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
        saida_vetor = "";
        for (int i = 0; i < tamanho_array; ++i){
            saida_vetor += "|" + QString::number(conj.getVetorMergeSort()[i]) + "| ";
        }
        ui->textEdit_merge_sort->setText(saida_vetor);
        ui->textEdit_merge_sort_nmr_execucoes->setText(QString::number(conj.getNmrExecucoes()));
        ui->textEdit_merge_sort_tempo_execucoes->setText(QString::number(duration.count()) + "µs");

        start = std::chrono::high_resolution_clock::now();
        conj.heapSort();
        finish = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
        saida_vetor = "";
        for (int i = 0; i < tamanho_array; ++i){
            saida_vetor += "|" + QString::number(conj.getVetorHeapSort()[i]) + "| ";
        }
        ui->textEdit_heap_sort->setText(saida_vetor);
        ui->textEdit_heap_sort_nmr_execucoes->setText(QString::number(conj.getNmrExecucoes()));
        ui->textEdit_heap_sort_tempo_execucoes->setText(QString::number(duration.count()) + "µs");

        start = std::chrono::high_resolution_clock::now();
        conj.quickSort();
        finish = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
        saida_vetor = "";
        for (int i = 0; i < tamanho_array; ++i){
            saida_vetor += "|" + QString::number(conj.getVetorQuickSort()[i]) + "| ";
        }
        ui->textEdit_quick_sort->setText(saida_vetor);
        ui->textEdit_quick_sort_nmr_execucoes->setText(QString::number(conj.getNmrExecucoes()));
        ui->textEdit_quick_sort_tempo_execucoes->setText(QString::number(duration.count()) + "µs");
    }
    catch(QString& e)
    {
        QMessageBox::critical(this, "ERRO", e);
    }
}


void MainWindow::on_lineEdit_qtd_elementos_returnPressed()
{
    on_pushButton_gerar_clicked();
}

