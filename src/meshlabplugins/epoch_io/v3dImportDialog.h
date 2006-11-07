#ifndef V3DIMPORTER_DIALOG_H
#define V3DIMPORTER_DIALOG_H

// for options on decimator
#include <QDialog>
#include "ui_v3dImportDialog.h"
#include "epoch_reconstruction.h"

class v3dImportDialog : public QDialog, public Ui::v3dImportDialog {

Q_OBJECT

public:
  v3dImportDialog() : QDialog()
  {
    setupUi( this );
    subsampleSpinBox->setValue(2);
    minCountSpinBox->setValue(3);
    er=0;
	}

public:
  void setEpochReconstruction(EpochReconstruction *_er,CallBackPos *cb);

public slots:
void on_selectButton_clicked();
void on_imageTableWidget_itemClicked(QTableWidgetItem * item );
void on_imageTableWidget_itemSelectionChanged();
void on_imageTableWidget_itemDoubleClicked(QTableWidgetItem * item );
private:
EpochReconstruction *er;
QString erCreated;
QSize imgSize;

private slots:
  void on_mergeResolutionSpinBox_valueChanged(int);
  void on_subsampleSpinBox_valueChanged(int);
  void on_minCountSlider_valueChanged(int);
  void on_minCountSpinBox_valueChanged(int);
};

#endif 
