#include "tubes.h"

void inputProject(ListProject &LP){
    createListProject(LP);
    adrProject P;
    infoTypeProject X;

    X.project_ID = "P07";
    X.project_name = "Prototype B-342";
    X.status = "Pending";
    X.startDate = "25-09-2005";
    X.finishDate = "-";
    P = createElementProject(X);
    insertFirstProject(LP, P);

    X.project_ID = "P06";
    X.project_name = "The Immortal Shroom";
    X.status = "Finished";
    X.startDate = "01-01-2005";
    X.finishDate = "12-05-2005";
    P = createElementProject(X);
    insertFirstProject(LP, P);

    X.project_ID = "P05";
    X.project_name = "Super Mega Lazer 3.0";
    X.status = "Pending";
    X.startDate = "10-04-2006";
    X.finishDate = "-";
    P = createElementProject(X);
    insertFirstProject(LP, P);

    X.project_ID = "P04";
    X.project_name = "Alien Radar";
    X.status = "Pending";
    X.startDate = "10-04-2006";
    X.finishDate = "-";
    P = createElementProject(X);
    insertFirstProject(LP, P);

    X.project_ID = "P03";
    X.project_name = "Mini Nuke (TOP SECRET)";
    X.status = "Finished";
    X.startDate = "31-12-2004";
    X.finishDate = "12-7-2005";
    P = createElementProject(X);
    insertFirstProject(LP, P);

    X.project_ID = "P02";
    X.project_name = "Kapal Lawd";
    X.status = "Pending";
    X.startDate = "05-11-2005";
    X.finishDate = "-";
    P = createElementProject(X);
    insertFirstProject(LP, P);

    X.project_ID = "P01";
    X.project_name = "Mind Controlling Hat";
    X.status = "Pending";
    X.startDate = "14-07-2005";
    X.finishDate = "-";
    P = createElementProject(X);
    insertFirstProject(LP, P);

}

