#ifndef WAD_H
#define WAD_H

#include <QTextStream>

class Wad
{
   QString title;
   QString filename;
   QString date;  // storing date as string, might change this later
   int filesize;
   QString author;
   double rating;

public:
    Wad();
    Wad(QString title, QString filename, QString date, int filesize, QString author, double rating);
    void setTitle(QString title);
    void setFileName(QString filename);
    void setDate(QString date);
    void setfileSize(int filesize);
    void setAuthor(QString author);
    void setRating(double rating);

    QString getTitle();
    QString getFileName();
    QString getDate();
    int getfileSize();
    QString getAuthor();
    double getRating();

};

#endif // WAD_H
