#ifndef POST
#define POST
#include <QString>
#include <QDateTime>

class Post{
private:
    QDateTime pushTime;
    QString description, title;


public:
    Post (QDateTime pushTime, QString description, QString title)
    {
        this->pushTime = pushTime;
        this->description = description;
        this->title = title;
    }

    QDateTime getPushTime()
    {
        return pushTime;
    }

    QDateTime getPushTime()
    {
        return pushTime;
    }

    QString getTitle()
    {
        return title;
    }

    QString getDescription()
    {
        return description;
    }

};

#endif // POST

