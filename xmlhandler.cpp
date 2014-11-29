#include "xmlhandler.h"
#include <QDomElement>
#include <QVector>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

XmlHandler::XmlHandler()
{
}

bool XmlHandler::saveToVsXml(QString learningListName, QVector<QVector<QString>> vocabularyList, QString filePath)
{
    QDomDocument document;
    QDomProcessingInstruction declaration = document.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
    document.insertBefore(declaration, QDomNode());
    QDomElement rootElement = document.createElement("vocabularyskill");
    document.appendChild(rootElement);
    QDomElement learningListElement = document.createElement("learning_list");
    learningListElement.setAttribute("name", learningListName);
    rootElement.appendChild(learningListElement);
    for (auto vocable : vocabularyList)
    {
        QDomElement vocableElement = document.createElement("vocable");
        vocableElement.setAttribute("known_word", vocable[0]);
        vocableElement.setAttribute("unknown_word", vocable[1]);
        rootElement.appendChild(vocableElement);
    }
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;
    else
    {
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        stream << document.toString();
        file.flush();
        file.close();

    }
    return true;
}


