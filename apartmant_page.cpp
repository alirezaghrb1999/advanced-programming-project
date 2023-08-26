#include "apartmant_page.h"

apartmant_page::apartmant_page(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant apartmant_page::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex apartmant_page::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex apartmant_page::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int apartmant_page::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int apartmant_page::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant apartmant_page::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
