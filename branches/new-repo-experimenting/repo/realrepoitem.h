#ifndef REALREPOITEM_H
#define REALREPOITEM_H

#include <QtCore/QHash>
#include <QtSql/QSqlQuery>

class RealRepoItem
{
public:
    enum NodeType { Undefined = 0, Root = 1, Category = 2, Element = 3,
	Diagram = 10, Class = 11, Package = 12, Link = 13
    };

    RealRepoItem(NodeType type, int row, int id, RealRepoItem *parent = 0);
    RealRepoItem(int row, RealRepoItem *parent);
    ~RealRepoItem();

    RealRepoItem *child(int i);
    RealRepoItem *parent()		    { return parentItem; };
    
    int row() const				    { return rowNumber; };
    int rowCount() const;

    QString name() const		    { return m_name; };
    int id() const				    { return m_id; };
    NodeType type() const		    { return m_type; };

	QVariant property(int key);
	bool setProperty(int key, const QVariant &data);

    void setName(QString name);
    void setId(int id);
    void setType(NodeType type);

    bool insertChild(int row, int count);
	bool createChild(int row, int type);

    void updateData();
    void childrenCleanup();

private:
    QSqlQuery childQuery;
    QHash<int,RealRepoItem*> childItems;
    RealRepoItem *parentItem;

    int rowNumber;
    int childCount;

    QString m_name;
    int m_id;
    NodeType m_type;

    QString childTableName;
//	QString query __attribute((deprecated));
};

// FIXME: only one open DB
extern QHash<int,QList<RealRepoItem *> > listByUuid;
extern QHash<int,QList<QPersistentModelIndex> > indexByUuid;

#endif
