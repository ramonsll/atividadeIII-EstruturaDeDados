#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Ordem {
public:
    int tam;
public:
    int *Lista;
    Ordem();
    ~Ordem();

    void Entrada();                 
    void Saida(int n) const;
    void Bubble(int n);
    void Insertion(int n);
    void Selection(int n);

    void Intercala(int p, int q, int r);
    void Merge(int p, int r);
    int Separa(int p, int r);
    void Quick(int p, int r);

    void Aleatorio(int n);          
    int MenuOrdenar(void) const;
};

/* --- Implementação --- */

Ordem::Ordem() {
    tam = 0;
    Lista = NULL;
}

Ordem::~Ordem() {
    if (Lista != NULL)
        delete [] Lista;
    Lista = NULL;
    tam = 0;
}

/* INSERIR LISTA  */
void Ordem::Entrada() {
    int n = 10; 

    if (Lista != NULL)
        delete [] Lista;

    Lista = new int[n];
    tam = n;

    for (int i = 0; i < n; ++i)
        Lista[i] = rand() % 100; // valores de 0 a 99

}

/* Saída */
void Ordem::Saida(int n) const {
    if (Lista == NULL || n <= 0) {
        cout << "(Vetor vazio)\n";
        return;
    }
    cout << "Vetor: ";
    for (int i = 0; i < n; ++i)
        cout << Lista[i] << " ";
    cout << "\n\n";
}

/* Bubble Sort */
void Ordem::Bubble(int n) {
    if (Lista == NULL || n <= 1) return;

    for (int i = 0; i < n - 1; ++i) {
        bool trocou = false;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (Lista[j] > Lista[j+1]) {
                int aux = Lista[j];
                Lista[j] = Lista[j+1];
                Lista[j+1] = aux;
                trocou = true;
            }
        }
        if (!trocou) break;
    }
}

/* Insertion Sort */
void Ordem::Insertion(int n) {
    if (Lista == NULL || n <= 1) return;

    for (int i = 1; i < n; ++i) {
        int key = Lista[i];
        int j = i - 1;

        while (j >= 0 && Lista[j] > key) {
            Lista[j+1] = Lista[j];
            j--;
        }
        Lista[j+1] = key;
    }
}

/* Selection Sort */
void Ordem::Selection(int n) {
    if (Lista == NULL || n <= 1) return;

    for (int i = 0; i < n - 1; ++i) {
        int idxMin = i;
        for (int j = i + 1; j < n; ++j)
            if (Lista[j] < Lista[idxMin])
                idxMin = j;

        int aux = Lista[i];
        Lista[i] = Lista[idxMin];
        Lista[idxMin] = aux;
    }
}

/* Funções do Merge */
void Ordem::Intercala(int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; ++i) L[i] = Lista[p + i];
    for (int j = 0; j < n2; ++j) R[j] = Lista[q + 1 + j];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) Lista[k++] = L[i++];
        else Lista[k++] = R[j++];
    }

    while (i < n1) Lista[k++] = L[i++];
    while (j < n2) Lista[k++] = R[j++];

    delete [] L;
    delete [] R;
}

void Ordem::Merge(int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        Merge(p, q);
        Merge(q + 1, r);
        Intercala(p, q, r);
    }
}

/* QuickSort */
int Ordem::Separa(int p, int r) {
    int pivot = Lista[r];
    int i = p - 1;

    for (int j = p; j < r; ++j) {
        if (Lista[j] <= pivot) {
            i++;
            int aux = Lista[i];
            Lista[i] = Lista[j];
            Lista[j] = aux;
        }
    }

    int aux = Lista[i+1];
    Lista[i+1] = Lista[r];
    Lista[r] = aux;

    return i + 1;
}

void Ordem::Quick(int p, int r) {
    if (p < r) {
        int q = Separa(p, r);
        Quick(p, q - 1);
        Quick(q + 1, r);
    }
}

/* Gera vetor aleatório */
void Ordem::Aleatorio(int n) {
    if (Lista != NULL)
        delete [] Lista;

    Lista = new int[n];
    tam = n;

    for (int i = 0; i < n; ++i)
        Lista[i] = rand() % 1000;

    
}

/* Menu */
int Ordem::MenuOrdenar(void) const {
    cout << "===============================\n";
    cout << "       MENU DE ORDENACAO\n";
    cout << "===============================\n";
    cout << "[1] INSERIR LISTA \n";
    cout << "[2] BUBBLE SORT\n";
    cout << "[3] INSERTION SORT\n";
    cout << "[4] SELECTION SORT\n";
    cout << "[5] MERGE SORT\n";
    cout << "[6] QUICK SORT\n";
    cout << "[7] SAIR\n";
    cout << "Opcao: ";
    int op;
    cin >> op;
    return op;
}

/* Main */
int main() {
    srand((unsigned) time(NULL)); // inicializa RNG uma vez
    Ordem ord;
    int opc;

    while (true) {
        opc = ord.MenuOrdenar();

        switch (opc) {

            case 1:  // INSERIR agora GERA automatico (10 numeros) — sem pedir nada
                ord.Entrada();
                ord.Saida(ord.tam);
                break;

            case 2:
                if (ord.Lista == NULL) { cout << "Lista vazia!\n"; break; }
                ord.Bubble(ord.tam);
                ord.Saida(ord.tam);
                break;

            case 3:
                if (ord.Lista == NULL) { cout << "Lista vazia!\n"; break; }
                ord.Insertion(ord.tam);
                ord.Saida(ord.tam);
                break;

            case 4:
                if (ord.Lista == NULL) { cout << "Lista vazia!\n"; break; }
                ord.Selection(ord.tam);
                ord.Saida(ord.tam);
                break;

            case 5:
                if (ord.Lista == NULL) { cout << "Lista vazia!\n"; break; }
                ord.Merge(0, ord.tam - 1);
                ord.Saida(ord.tam);
                break;

            case 6:
                if (ord.Lista == NULL) { cout << "Lista vazia!\n"; break; }
                ord.Quick(0, ord.tam - 1);
                ord.Saida(ord.tam);
                break;

            case 7: {
                cout << "Saindo...\n";
                return 0;
            }
            default:
                cout << "Opcao invalida!\n";
        }
    }

    return 0;
}
