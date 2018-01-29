#include "wad.h"

// Class to represent wad files
Wad::Wad() {

}

Wad::Wad(QString title, QString filename, QString dir, QString description, QString date, int filesize, QString author, double rating) {

    this->title=title;
    this->filename=filename;
    this->dir = dir;
    this->description=description;
    this->date=date;
    this->filesize=filesize;
    this->author=author;
    this->rating=rating;
}

// Accessors/Mutators
void Wad::setTitle(QString title) {

    this->title = title;
}

void Wad::setFileName(QString filename){
    this->filename = filename;
}

void Wad::setDir(QString dir){
    this->dir = dir;
}

void Wad::setDescription(QString description){
    this->description = description;
}

void Wad::setDate(QString date) {
    this->date = date;
}

void Wad::setFileSize(int filesize) {
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

QString Wad::getDir(){
    return this->dir;
}

QString Wad::getDescription(){
    return this->description;
}

QString Wad::getDate() {
    return this->date;
}

int Wad::getFileSize() {
    return this->filesize;
}

QString Wad::getAuthor() {
    return this->author;
}

double Wad::getRating() {
    return this->rating;
}
