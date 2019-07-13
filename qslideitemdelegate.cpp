#include "qslideitemdelegate.h"
#include <QSlider>

QSlideItemDelegate::QSlideItemDelegate(QObject *parent)
    :QStyledItemDelegate (parent)
{

}

QWidget *QSlideItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(parent);
    Q_UNUSED(index);
    Q_UNUSED(option);
    QSlider *slider=new QSlider(parent);
    slider->setOrientation(Qt::Horizontal);
    slider->setAutoFillBackground(true);
    return slider;
}

void QSlideItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QSlider *slider=static_cast<QSlider *>(editor);
    if(nullptr==slider) return;
    slider->setValue(index.data().toInt());
}

void QSlideItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSlider *slider=static_cast<QSlider *>(editor);
    if(nullptr==slider) return;
    model->setData(index, slider->value());
}

void QSlideItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}

void QSlideItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyledItemDelegate::paint(painter, option, index);
}
