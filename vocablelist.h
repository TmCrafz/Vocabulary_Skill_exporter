#ifndef VOCABLELIST_H
#define VOCABLELIST_H

#include <QObject>

class VocableList : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit VocableList(QObject *parent = 0);

    enum datarole {headerTextRole = Qt::UserRole + 100,subHeaderTextrole = Qt::UserRole+101,IconRole = Qt::UserRole+102};

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
             const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option,
                  const QModelIndex &index ) const;

signals:

public slots:

};

#endif // VOCABLELIST_H
