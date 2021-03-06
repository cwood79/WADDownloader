#ifndef WAD_H
#define WAD_H

#include <QTextStream>

class Wad
{
   QString title;
   QString filename;
   QString dir;
   QString description;
   QString date;
   int filesize;
   QString author;
   double rating;

public:
    Wad();
    Wad(QString title, QString filename, QString dir, QString description, QString date, int filesize, QString author, double rating);

    void setTitle(QString title);
    void setFileName(QString filename);
    void setDir(QString dir);
    void setDescription(QString description);
    void setDate(QString date);
    void setFileSize(int filesize);
    void setAuthor(QString author);
    void setRating(double rating);

    QString getTitle();
    QString getFileName();
    QString getDir();
    QString getDescription();
    QString getDate();
    int getFileSize();
    QString getAuthor();
    double getRating();

};

#endif // WAD_H
