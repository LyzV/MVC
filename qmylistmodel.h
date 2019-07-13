#ifndef QMYLISTMODEL_H
#define QMYLISTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>

class QMyListModel : public QAbstractListModel
{
    Q_OBJECT

    QList<int> list;
public:
    QMyListModel(QObject *parent=nullptr);


    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    virtual Qt::ItemFlags flags(const QModelIndex &index) const;



};

#endif // QMYLISTMODEL_H
