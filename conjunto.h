#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <time.h>
#include <iostream>
#include <QString>

class Conjunto
{
private:
    int *vetor;
    int *vetor_selection_sort;
    int *vetor_insertion_sort;
    int *vetor_bubble_sort;
    int *vetor_merge_sort;
    int *vetor_heap_sort;
    int *vetor_quick_sort;
    int tamanho_vetor;
    int nmr_execucoes;
public:
    Conjunto(int& tamanho_array);
    ~Conjunto();
    int getTamanhoVetor() const;
    int *getVetor() const;
    int* getVetorSelectionSort() const;
    int* getVetorInsertionSort() const;
    int* getVetorBubbleSort() const;
    int* getVetorMergeSort() const;
    int* getVetorHeapSort() const;
    int* getVetorQuickSort() const;
    int getNmrExecucoes() const;
    void selectionSort();
    void insertionSort();
    void bubbleSort();
    void mergeSort();
    void mergeSort(int *array, int inicio, int fim);
    void merge(int *array, int& inicio, int& meio, int& fim);
    void heapSort();
    void heapSort(int *array, int& tamanho_vetor);
    void heapify(int *array, int& tamanho_vetor, int indice);
    void quickSort();
    void quickSort(int *array, int low, int high);
    int partition(int *array, int& low, int& high);
    void swap(int *a, int *b);
};

#endif // CONJUNTO_H
