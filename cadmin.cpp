#include "cadmin.h"
#include <QDebug>

/*cadmin::cadmin()
{

} */
int cadmin::authentification()
{

    int count=0;



    QSqlQuery query;
    query.prepare("select * from LOGIN where  (Username=:Username) and (Password=:Password) ");
    query.bindValue(":Username",Username);
    query.bindValue(":Password",Password);
    query.exec();
            while(query.next())
                {
                    count++;

                }
                return (count);


}
