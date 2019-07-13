#ifndef QSLIDEITEMDELEGATE_H
#define QSLIDEITEMDELEGATE_H

#include <QObject>
#include <QWidget>
#include <QStyledItemDelegate>

class QSlideItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    QSlideItemDelegate(QObject *parent=nullptr);

    virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    virtual void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

};

#endif // QSLIDEITEMDELEGATE_H
