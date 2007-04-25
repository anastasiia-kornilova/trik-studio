#ifndef REALREPOMODEL_H
#define REALREPOMODEL_H

#include <QtCore/QAbstractItemModel>
#include <QtCore/QModelIndex>
#include <QtCore/QVariant>
#include <QtSql/QSqlDatabase>

#include "realreporoles.h"

class RealRepoItem;

class RealRepoModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    RealRepoModel(QObject *parent = 0);
    ~RealRepoModel();

    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;

    QVariant data(const QModelIndex &index, int role) const;
    bool setData (const QModelIndex &index, const QVariant &value,
			int role = Qt::EditRole);

    QMap<int, QVariant> itemData ( const QModelIndex & index ) const;

//    bool dropMimeData(const QMimeData *data, Qt::DropAction action,
//		int row, int column, const QModelIndex &parent);
    
    bool insertRows (int row, int count,
			const QModelIndex &parent = QModelIndex());
    
    Qt::ItemFlags flags(const QModelIndex &index) const;
    Qt::DropActions supportedDropActions () const;

    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

	void insertChild(const QModelIndex &parent, int type);

public slots:
	void createSomeChild(const QModelIndex &parent);

private:
    RealRepoItem *rootItem;
    QSqlDatabase db;

    QModelIndex getIndexByItem(const RealRepoItem *item);
};

#endif
