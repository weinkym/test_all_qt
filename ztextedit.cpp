#include "ztextedit.h"
#include <QDebug>
#include <QTextBlock>
#include <QTextList>

ZTextEdit::ZTextEdit(QWidget *parent)
    :QTextEdit(parent)
{
    m_isTextChanged = true;
    insertImage(":/images/1.png");
    insertImage(":/images/1.png");
    insertImage(":/images/1.png");

    connect(this,SIGNAL(textChanged()),this,SLOT(onTextChanged()));
}

ZTextEdit::~ZTextEdit()
{
    //
}

void ZTextEdit::insertAllText(const QString &text)
{
    QTextCursor cursor = this->textCursor();
    addContext(cursor,text,";");
    updateTextCursor(cursor);

//    QString key = ";";
//    QStringList list = text.split(key);
//    int count = list.count();
//    for(int i = 0; i < count; ++i)
//    {

//        cursor.insertText(list.at(i));
//        if(i < count - 1)
//        {
//            cursor.insertImage(":/images/1.png");
//        }
//    }
//    this->setTextCursor(cursor);
//    int index = text.indexOf(key,pos);
//    QString src = text.mid(pos,index);
//    if(!src.isEmpty())
//    {
//        cursor.insertText(src);
//    }
//    while(index >= 0)
//    {
//        cursor.insertImage(":/images/1.png");
//        pos = key.length() + index;
//        index = text.indexOf(key,pos);
//    }
}

void ZTextEdit::insertImage(const QString &fileName)
{
    QTextCursor cursor = this->textCursor();
    cursor.insertImage(fileName);
//    this->setTextCursor(cursor);
    updateTextCursor(cursor);
}

void ZTextEdit::addContext(QTextCursor &cursor, const QString &src, const QString &rm)
{
//    QString rm = ";";
    QStringList list = src.split(rm);
    int count = list.count();
    for(int i = 0; i < count; ++i)
    {
        cursor.beginEditBlock();
        cursor.insertText(list.at(i));
        cursor.endEditBlock();
        if(i < count - 1)
        {
            cursor.beginEditBlock();
            QTextImageFormat textImageFormat;
            textImageFormat.setName(":/images/1.png");
            cursor.insertImage(textImageFormat);
            cursor.endEditBlock();
        }
    }
}

void ZTextEdit::updateTextCursor(const QTextCursor &cursor)
{
    disconnect(this,SIGNAL(textChanged()),this,SLOT(onTextChanged()));
    this->setTextCursor(cursor);
    connect(this,SIGNAL(textChanged()),this,SLOT(onTextChanged()));
}

void ZTextEdit::onTextChanged()
{
//   disconnect(this,SIGNAL(textChanged()),this,SLOT(onTextChanged()));
   QTextCursor cursor(this->document());
   QTextBlock block = cursor.block();
   QString key = ";";
   //===========================
   if (!block.isValid())
           return;
//   qDebug()<<__LINE__<<block.blockNumber();
//   cursor.select(QTextCursor::WordUnderCursor);
//   cursor.deleteChar();
//   updateTextCursor(cursor);
//   return;
   // QTextLayout 下一级是 QTextBlock..
       // QTextBlock 的下一级又是QTextFragment..
//       QTextBlock::iterator it;
//       for (it = block.begin(); !(it.atEnd()); ++it)
//       {
//           QTextFragment fragment = it.fragment();
//           if (!fragment.isValid())
//               continue;
//           // 获取文本
//           QString text = fragment.text();
//           qDebug()<<__LINE__<<text;
//           if(text.contains(key))
//           {
//               cursor.select(QTextCursor::WordUnderCursor);
//               cursor.deleteChar();
//           }
//           if (text.isEmpty())
//               continue;
           // 获取文本格式
//           QTextCharFormat chf = fragment.charFormat();
//           int lineNoBegin = layout->lineForTextPosition(fragment.position() - block.position()).lineNumber();
//           int lineNoEnd = layout->lineForTextPosition(fragment.position() + fragment.length() - 1 - block.position()).lineNumber();
//           int j = fragment.position();
//           for (int i = lineNoBegin; i <= lineNoEnd; i++)
//           {
//               QTextLine line = layout->lineAt(i);
//               // 计算输出位置X
//               qreal offset = alignPos(layout->textOption().alignment(), sizeToFill.width(), line.naturalTextWidth());
//               outPos.setX(outPos.x() + offset);
//               outPos.setY(baseLine.y());
//               // 获取属于本行的文本
//               QString textOnLine;
//               while(j < fragment.position() + fragment.length())
//               {
//                   int c = block.position();
//                   int d = line.textStart() + line.textLength();
//                   if (j < c + d)
//                       textOnLine.append(text[j - fragment.position()]);
//                   else
//                       break;
//                   j++;
//               }
//               // 绘制属于本行的Fragment中的文本
////               drawText(painter, outPos, textOnLine, chf, brush);
//               qDebug()<<__LINE__<<textOnLine;
//               // 有换行的话，要更新BaseLine的Y及outPos的X
//               if(i < lineNoEnd)
//               {
//                   // 更新基线位置Y
//                   baseLine.setY(baseLine.y() + line.height());
//                   outPos.setX(baseLine.x());
//               }
//           }
//       }
//       updateTextCursor(cursor);
//       return;
   //===============================
   QString src = block.text();
qDebug()<<__LINE__<<src;
   if(src.contains(key))
   {
//       src.remove(key);
//       cursor.select(QTextCursor::BlockUnderCursor);
//       for(int i = 0; i < key.length(); ++i)
//       {
           QTextBlockFormat blockFmt = cursor.blockFormat();

                       QTextList *list = cursor.currentList();
                       if (list && cursor.atBlockStart()) {
                           list->remove(cursor.block());
                       } else if (cursor.atBlockStart() && blockFmt.indent() > 0) {
                           blockFmt.setIndent(blockFmt.indent() - 1);
                           cursor.setBlockFormat(blockFmt);
                       } else {
                           cursor.deletePreviousChar();
                       }
//       }
//       addContext(cursor,src,key);
       updateTextCursor(cursor);
   }
//   cursor.movePosition(QTextCursor::Start,QTextCursor::MoveAnchor);
//   while(!cursor.atEnd())
//   {
//       cursor.movePosition(QTextCursor::NextBlock,QTextCursor::MoveAnchor);
//   }
//       qDebug()<<__LINE__<<cursor.blockNumber();;
//               qDebug()<<__LINE__<<cursor.isNull();;
//               cursor.movePosition(QTextCursor::NextBlock,QTextCursor::MoveAnchor);
//               qDebug()<<__LINE__<<cursor.atEnd();;


//       cursor.isNull();
//   this->setTextCursor(cursor);
//    m_isTextChanged = !m_isTextChanged;
//    QString text = this->toPlainText();
//    QString key = "uuu";
//    if(text.contains(key))
//    {
//        qDebug()<<__LINE__;
//        QTextCursor cursor = this->textCursor();
//        QTextBlock textBlock = cursor.block();
//        QString src = textBlock.text();
//        if(src.contains(key))
//        {
////            src.remove(key);
//            cursor.select(QTextCursor::BlockUnderCursor);
//            cursor.deleteChar();
////            this->setTextCursor(cursor);
////            cursor.insertText(src);
////            cursor.insertImage(":/images/1.png");
//            insertAllText(src);
//        }

//        cursor.movePosition(QTextCursor::Start,QTextCursor::MoveAnchor);
//        QTextCursor cursor2 = this->document()->find(key,cursor,QTextDocument::FindBackward);
//        if(cursor2)
//        {
//            QTextBlock textBlock = cursor2.block();
//            qDebug()<<textBlock.text();
//        }
//        QTextBlock textBlock = cursor.block();
//        qDebug()<<textBlock.text();
//        cursor.select(QTextCursor::Document);
//        cursor.deletePreviousChar();
//        cursor.beginEditBlock();
//        cursor.insertText("Hello");
//        cursor.insertText("World");
//        cursor.endEditBlock();

//        cursor.deleteChar();
//        this->textCursor().setPosition(1,QTextCursor::MoveAnchor);
//        bool isOk = cursor.movePosition(QTextCursor::StartOfWord,QTextCursor::MoveAnchor,3);
//        qDebug()<<"isOk"<<isOk;
//        this->setTextCursor(cursor);
//    }
connect(this,SIGNAL(textChanged()),this,SLOT(onTextChanged()));
}
