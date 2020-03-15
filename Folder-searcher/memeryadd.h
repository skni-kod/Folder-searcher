#ifndef MEMERYADD_H
#define MEMERYADD_H
#endif // MEMERYADD_H
#include <QString>

QString *memeryadd(QString *tablica, int *size)
{

    QString *tab = new  QString[(*size + 5)]; // tu tworzymy tablice o 5 elementów wieksza
    for(int i=0; i< *size; i++)
    {
     *(tab + i) = *(tablica + i); // kopoiowanie tablicy mniejszej do wiekszej
    }
    *size = *size + 5; //zwieszkamy licznik wielkosci tablicy o 5
    delete[] tablica;
    return tab; // zwrot wskaznika do nowej tablicy

};
