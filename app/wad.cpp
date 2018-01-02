#include "wad.h"

Wad::Wad() {

}

Wad::Wad(QString title, QString filename, QString description, QString date, int filesize, QString author, double rating) {

    this->title=title;
    this->filename=filename;
    this->description=description;
    this->date=date;
    this->filesize=filesize;
    this->author=author;
    this->rating=rating;
}


// returns a html representation of the wad file
QString Wad::toHTML() {
    //QString html = "<h1>" + this->title +"</h1>";
    QString html = "<table><tbody><tr><td>"+this->title + "<span> RATING:"+QString::number(this->rating)+" </span></td><td>FILENAME</td><td>"+this->filename+"</td></tr><tr><td>" + this->description+"</td><td>DATE</td><td>"+this->date+"</td></tr><tr><td>SIZE</td><td>"+QString::number(this->filesize)+"</td></tr><tr><td>AUTHOR</td><td>"+this->author+"</td></tr></tbody></table>";
    return html;
}


void Wad::setTitle(QString title) {
    this->title = title;
}

void Wad::setFileName(QString filename){
    this->filename = filename;
}

void Wad::setDescription(QString description){
    this->description = description;
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

QString Wad::getDescription(){
    return this->description;
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
