#ifndef FILESEARCH_H
#define FILESEARCH_H
#endif // FILESEARCH_H
#include <QDir>
#include <QFile>
#include <memeryadd.h>
/*funkcja przeszukujaca katalog lub folder
 * path = sciezka do pliku np. C:/Windows/Boot ; zamaiast \ dajesz / przy kopiowaniu sciezek windowsowych i jest git
 * int *iter wskaznik na iterator typu int
 * int *size wskaznik na jakiegos inta ktory bedzie mowil ilo elementowa jest tablica
 * QString **tab wskaznik na wskaznik na dynamicznie zaalokowana tablice
 */

void filesearch(QString path, int *iter,int *size, QString **tab)
{
    QDir dir(path);
    if(dir.exists() == 1) // sprawdzamy czy pod scierzka
    {
        QStringList list = dir.entryList(); // tu jest tworzona lista scierzek do plikow lub folderwo w folderze
        for(int i = 2; i < list.size(); ++i)
        {
            filesearch(dir.path().append("/").append(list.at(i)), iter, size, tab); // rekurencja do nastepnego folderu
        }
    }
    else
    {
        if(*size-1 < (*iter)) //  spawdzenie czy funkcja nie wychodzi poza tablice bo wychodzenie poza tablice jest zle
        {
            *tab = memeryadd(*tab, size);
        }
        *(*tab + (*iter)) = path; // dodanie do tablicy nowej scierzki do pliku
        *iter = *iter + 1;
    }
};
