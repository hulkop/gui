#include "savechanges.h"
#include "ui_savechanges.h"

SaveChanges::SaveChanges(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveChanges)
{
    ui->setupUi(this);
    connect(this->ui->cancel, SIGNAL(clicked(bool)), this, SLOT(close()));
}


QPushButton* SaveChanges::getSave() {
    return ui->save;
}


QPushButton*SaveChanges:: getDoNotSave() {
    return ui->doNotSave;
}


SaveChanges::~SaveChanges()
{
    delete ui;
}
