#include "conjunto.h"

Conjunto::Conjunto(int& tamanho_array):
    vetor(0),
    vetor_selection_sort(0),
    vetor_insertion_sort(0),
    vetor_bubble_sort(0),
    vetor_merge_sort(0),
    vetor_heap_sort(0),
    vetor_quick_sort(0),
    tamanho_vetor(0),
    nmr_execucoes(0)
{
    if (tamanho_array <= 0){
        throw QString("Erro: tamanho invalido");
    }
    tamanho_vetor = tamanho_array;
    try{
        vetor = new int[tamanho_vetor];
        vetor_selection_sort = new int[tamanho_vetor];
        vetor_insertion_sort = new int[tamanho_vetor];
        vetor_bubble_sort = new int[tamanho_vetor];
        vetor_merge_sort = new int[tamanho_vetor];
        vetor_heap_sort = new int[tamanho_vetor];
        vetor_quick_sort = new int[tamanho_vetor];
        srand(time(0));
        for (int i = 0; i < tamanho_vetor; ++i){
            ++nmr_execucoes;
            vetor_quick_sort[i] = vetor_heap_sort[i] = vetor_merge_sort[i] = vetor_bubble_sort[i] = vetor_insertion_sort[i] = vetor_selection_sort[i] = vetor[i] = rand() % 1001;
        }
    }catch(std::bad_alloc &e){
        throw QString("Erro: memoria insuficiente");
    }
}

int Conjunto::getTamanhoVetor() const{
    return tamanho_vetor;
}

int* Conjunto::getVetor() const{
    return vetor;
}

int* Conjunto::getVetorSelectionSort() const{
    return vetor_selection_sort;
}

int* Conjunto::getVetorInsertionSort() const{
    return vetor_insertion_sort;
}

int* Conjunto::getVetorBubbleSort() const{
    return vetor_bubble_sort;
}

int* Conjunto::getVetorMergeSort() const{
    return vetor_merge_sort;
}

int* Conjunto::getVetorHeapSort() const{
    return vetor_heap_sort;
}

int* Conjunto::getVetorQuickSort() const{
    return vetor_quick_sort;
}

int Conjunto::getNmrExecucoes() const{
    return nmr_execucoes;
}

void Conjunto::selectionSort(){
    if (tamanho_vetor <= 0 || !vetor_selection_sort){
        throw QString("Erro: vetor vazio ou tamanho invalido");
    }
    if (nmr_execucoes){
        nmr_execucoes = 0;
    }
    for (int indice = 0; indice < tamanho_vetor - 1; ++indice){
        int min_idc = indice;
        for (int i = indice + 1; i < tamanho_vetor; ++i){
            if (vetor_selection_sort[i] < vetor_selection_sort[min_idc]){
                min_idc = i;
            }
            ++nmr_execucoes;
        }
        int temp = vetor_selection_sort[indice];
        vetor_selection_sort[indice] = vetor_selection_sort[min_idc];
        vetor_selection_sort[min_idc] = temp;
    }
}

void Conjunto::insertionSort(){
    if (tamanho_vetor <= 0 || !vetor_insertion_sort){
        throw QString("Erro: vetor vazio ou tamanho invalido");
    }
    if (nmr_execucoes){
        nmr_execucoes = 0;
    }
    for (int step = 1; step < tamanho_vetor; ++step){
        int key = vetor_insertion_sort[step];
        int j = step - 1;
        while (key < vetor_insertion_sort[j] && j >= 0){
            vetor_insertion_sort[j + 1] = vetor_insertion_sort[j];
            --j;
            ++nmr_execucoes;
        }
        vetor_insertion_sort[j + 1] = key;
    }
}

void Conjunto::bubbleSort(){
    if (tamanho_vetor <= 0 || !vetor_bubble_sort){
        throw QString("Erro: vetor vazio ou tamanho invalido");
    }
    if (nmr_execucoes){
        nmr_execucoes = 0;
    }
    bool swapped = false;
    for (int i = 0; i < tamanho_vetor - 1; ++i){
        swapped = false;
        for (int j = 0; j < tamanho_vetor - i - 1; ++j){
            if (vetor_bubble_sort[j] > vetor_bubble_sort[j + 1]){
                int temp = vetor_bubble_sort[j];
                vetor_bubble_sort[j] = vetor_bubble_sort[j + 1];
                vetor_bubble_sort[j + 1] = temp;
                swapped = true;
            }
            ++nmr_execucoes;
        }
        if (!swapped){
            return;
        }
    }
}

void Conjunto::mergeSort(){
    if (tamanho_vetor <= 0 || !vetor_merge_sort){
        throw QString("Erro: vetor vazio ou tamanho invalido");
    }
    if (nmr_execucoes){
        nmr_execucoes = 0;
    }
    mergeSort(vetor_merge_sort, 0, tamanho_vetor - 1);
}

void Conjunto::mergeSort(int *array, int inicio, int fim){
    if (inicio < fim){
        int meio = (inicio + fim) / 2;
        mergeSort(array, inicio, meio);
        mergeSort(array, meio + 1, fim);
        merge(array, inicio, meio, fim);
    }
}

void Conjunto::merge(int *array, int& inicio, int& meio, int& fim){
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    int *L = new int[n1];
    int *M = new int[n2];
    for (int i = 0; i < n1; ++i){
        L[i] = array[inicio + i];
    }
    for (int i = 0; i < n2; ++i){
        M[i] = array[meio + 1 + i];
    }
    int i = 0, j = 0, k = inicio;
    while(i < n1 && j < n2){
        if(L[i] <= M[j]){
            array[k] = L[i];
            ++i;
        }else{
            array[k] = M[j];
            ++j;
        }
        ++k;
    }
    while (i < n1){
        array[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2){
        array[k] = M[j];
        ++j;
        ++k;
    }
    delete[] L;
    delete[] M;
}

void Conjunto::heapSort(){
    if (tamanho_vetor <= 0 || !vetor_heap_sort){
        throw QString("Erro: vetor vazio ou tamanho invalido");
    }
    if (nmr_execucoes){
        nmr_execucoes = 0;
    }
    heapSort(vetor_heap_sort, tamanho_vetor);
}

void Conjunto::heapSort(int *array, int& tamanho_vetor){
    for (int i = tamanho_vetor/2 - 1; i >= 0; --i){
        heapify(array, tamanho_vetor, i);
    }
    for (int i = tamanho_vetor - 1; i >= 0; --i){
        std::swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

void Conjunto::heapify(int *array, int& tamanho_vetor, int indice){
    int largest = indice;
    int left = 2*indice+1;
    int right = 2*indice+2;
    if (left < tamanho_vetor && array[left] > array[largest]){
        largest = left;
    }
    if (right < tamanho_vetor && array[right] > array[largest]){
        largest = right;
    }
    if (largest != indice){
        std::swap(array[indice], array[largest]);
        heapify(array, tamanho_vetor, largest);
    }
}

void Conjunto::quickSort(){
    if (tamanho_vetor <= 0 || !vetor_quick_sort){
        throw QString("Erro: vetor vazio ou tamanho invalido");
    }
    if (nmr_execucoes){
        nmr_execucoes = 0;
    }
    quickSort(vetor_quick_sort, 0, tamanho_vetor - 1);
}

void Conjunto::swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Conjunto::partition(int *array, int& low, int& high){
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; ++j){
        if (array[j] <= pivot){
            ++i;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void Conjunto::quickSort(int *array, int low, int high){
    if (low < high){
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

Conjunto::~Conjunto()
{
    if (vetor){
        delete[] vetor;
        vetor = 0;
    }
    if (vetor_selection_sort){
        delete[] vetor_selection_sort;
        vetor_selection_sort = 0;
    }
    if (vetor_insertion_sort){
        delete[] vetor_insertion_sort;
        vetor_insertion_sort = 0;
    }
    if (vetor_bubble_sort){
        delete[] vetor_bubble_sort;
        vetor_bubble_sort = 0;
    }
    if (vetor_merge_sort){
        delete[] vetor_merge_sort;
        vetor_merge_sort = 0;
    }
    if (vetor_heap_sort){
        delete[] vetor_heap_sort;
        vetor_heap_sort = 0;
    }
    if (vetor_quick_sort){
        delete[] vetor_quick_sort;
        vetor_quick_sort = 0;
    }
}
