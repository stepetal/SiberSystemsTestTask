#ifndef VALIDATIONLINEEDIT_H
#define VALIDATIONLINEEDIT_H

#include <QLineEdit>
#include <QDebug>

class ValidationLineEdit : public QLineEdit
{
    Q_OBJECT
    QString currentStyleSheet;
    Q_PROPERTY(QString CustomStyleSheet READ getCustomStyleSheet WRITE setCustomStyleSheet);
public:
    ValidationLineEdit(QWidget *parent = nullptr);
    void setValid(){ setStyleSheet("background-color: white; color: black"); }
    void setNonValid(){ setStyleSheet("background-color: #ff4d4d;"); } // resembles red color
    void setCustomStyleSheet(const QString& style){ this->setStyleSheet(style); currentStyleSheet = style; }
    QString getCustomStyleSheet(){ return currentStyleSheet; }
};

#endif // VALIDATIONLINEEDIT_H
