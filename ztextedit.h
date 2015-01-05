#ifndef ZTEXTEDIT_H
#define ZTEXTEDIT_H

#include <QTextEdit>

class ZTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    ZTextEdit(QWidget* parent = 0);
    ~ZTextEdit();
    void insertAllText(const QString& text);
    void insertImage(const QString& fileName);

private:
    void addContext(QTextCursor& cursor,const QString& src,const QString& rm);
    void updateTextCursor(const QTextCursor& cursor);

protected slots:
    void onTextChanged();

private:
    bool m_isTextChanged;

};

#endif // ZTEXTEDIT_H
