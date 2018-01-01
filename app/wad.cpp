#include "wad.h"

Wad::Wad() {

}

Wad::Wad(QString title, QString filename, QString date, int filesize, QString author, double rating) {

    this->title=title;
    this->filename=filename;
    this->date=date;
    this->filesize=filesize;
    this->author=author;
    this->rating=rating;
}


void Wad::setTitle(QString title) {
    this->title = title;
}

void Wad::setFileName(QString filename){
    this->filename = filename;
}

void Wad::setDate(QString date) {
    this->date = date;
}

void Wad::setfileSize(int filesize) {
    this->filesize = filesize;
}

void Wad::setAuthor(QString author) {
    this->author = author;
}

void Wad::setRating(double rating) {
    this->rating = rating;
}

QString Wad::getTitle() {
    return this->title;
}

QString Wad::getFileName() {
    return this->filename;
}

QString Wad::getDate() {
    return this->date;
}

QString Wad::getAuthor() {
    return this->author;
}

double Wad::getRating() {
    return this->rating;
}
