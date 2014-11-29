#ifndef XMLHANDLER_H
#define XMLHANDLER_H
#include <QString>

class XmlHandler
{
public:
    XmlHandler();
    bool saveToVsXml(QString learningListName, QVector<QVector<QString>> vocabularyList, QString filePath);
};

#endif // XMLHANDLER_H
