#include "qmylistmodel.h"

QMyListModel::QMyListModel(QObject *parent)
    :QAbstractListModel(parent)
{
    list << 33 << 55 << 77;

}

int QMyListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return list.count();
}

QVariant QMyListModel::data(const QModelIndex &index, int role) const
{
    if(false==index.isValid()) return QVariant();

    switch(role)
    {
    default: return QVariant();
    case Qt::DisplayRole: return list.at(index.row());
    }
}

bool QMyListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(false==index.isValid()) return false;

    switch(role)
    {
    default: return false;
    case Qt::EditRole: list.replace(index.row(), value.toInt()); break;
    }
    return true;
}

Qt::ItemFlags QMyListModel::flags(const QModelIndex &index) const
{
    if(false==index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}
