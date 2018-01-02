#ifndef WAD_H
#define WAD_H

#include <QTextStream>

class Wad
{
   QString title;
   QString filename;
   QString description;
   QString date;  // storing date as string, might change this later
   int filesize;
   QString author;
   double rating;

public:
    Wad();
    Wad(QString title, QString filename, QString description, QString date, int filesize, QString author, double rating);
    QString toHTML();

    void setTitle(QString title);
    void setFileName(QString filename);
    void setDescription(QString description);
    void setDate(QString date);
    void setfileSize(int filesize);
    void setAuthor(QString author);
    void setRating(double rating);

    QString getTitle();
    QString getFileName();
    QString getDescription();
    QString getDate();
    int getfileSize();
    QString getAuthor();
    double getRating();

};

#endif // WAD_H
