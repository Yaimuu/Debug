#include "fonctions.h"

using namespace sf;

int dept(int y, int pas)
{
    y= y+pas;
    return y;
}

void affiche (RenderWindow &fenetre,RectangleShape rect, int x, int y)
{
    rect.setPosition(x,y);
    fenetre.draw(rect);
}

void menu(RenderWindow &fen, int lancement)
{
    int xTxt = 800, yTxt = 200;
    int xIcmd = 140, yIcmd = HAUT_FEN-26;
    int xBarre = 0, yBarre = HAUT_FEN-29;
    Texture barre_outil_tex;
    Sprite barre_outil = creaSprite(barre_outil_tex, BARRE_OUTIL);;
    Texture wallpaper_tex;
    Sprite wallpaper = creaSprite(wallpaper_tex, WALLPAPER);
    Texture doc_txt_tex;
    Sprite doc_txt = creaSprite(doc_txt_tex, DOC_TEXT);
    Texture icon_cmd_tex;
    Sprite icon_cmd = creaSprite(icon_cmd_tex, ICON_CMD1);
    doc_txt.setPosition(xTxt, yTxt);
    icon_cmd.setPosition(xIcmd, yIcmd);
    barre_outil.setPosition(xBarre, yBarre);
    fen.clear();
    //fen.draw(doc_txt);
    if(lancement == 1)
    {
        Texture cmd_tex;
        Sprite cmd = creaSprite(cmd_tex, CMD);
        cmd.setPosition(LARG_FEN/2 - 1205/2,0);
        //fen.draw(wallpaper2);
        fen.draw(cmd);
    }
    else
        fen.draw(wallpaper);
    fen.draw(barre_outil);
    fen.draw(icon_cmd);
    fen.display();
}

void jeu(RenderWindow &fen)
{
    dessineBase(fen);

}

Sprite creaSprite(Texture &texture, char path[])
{
    //Texture texture;
    if (!texture.loadFromFile(path))
        printf("Erreur de chargement de l'image %s !\n", path);
    Sprite sprite;
    sprite.setTexture(texture);
    return sprite;
}

void dessineBase(RenderWindow &fen)
{
    int xBarre = 0, yBarre = HAUT_FEN-29;
    int xIcmd = 140, yIcmd = HAUT_FEN-26;
    Texture wallpaper2_tex;
    Sprite wallpaper2 = creaSprite(wallpaper2_tex, WALLPAPER2);
    Texture barre_outil_tex;
    Sprite barre_outil = creaSprite(barre_outil_tex, BARRE_OUTIL);;
    barre_outil.setPosition(xBarre, yBarre);
    Texture icon_cmd_tex;
    Sprite icon_cmd = creaSprite(icon_cmd_tex, ICON_CMD1);
    icon_cmd.setPosition(xIcmd, yIcmd);
    Texture cmd_tex;
    Sprite cmd = creaSprite(cmd_tex, CMD);
    cmd.setPosition(LARG_FEN/2 - 1205/2,0);
    //fen.clear();
    fen.draw(wallpaper2);
    fen.draw(cmd);
    fen.draw(barre_outil);
    fen.draw(icon_cmd);
    //fen.display();
}

int ecranDemarrage(RenderWindow &app)
{

    Texture fond;
    if (!fond.loadFromFile("fondDemarrage.png")) {
        printf("Probleme de chargement");
    }
    SoundBuffer demarrage;
    if(!demarrage.loadFromFile("demarrage.wav")) {
        printf("Problemede chargement du son de demmarage");
    }
    Sound sonDemarrage;
    sonDemarrage.setBuffer(demarrage);
    sonDemarrage.play();
    while (sonDemarrage.getStatus() == Sound::Playing) {
    Sprite sFond;
    sFond.setTexture(fond);
    app.draw(sFond);
    app.display();
    }
    return 0;
}

int alive(int xPerso, int yPerso, int xObstacle, int yObstacle, int largeurObstacle, int hauteurObstacle)
{
    int alive = 0;
    if((xPerso <= (xObstacle+largeurObstacle) ) &&((xPerso+TAILLEPERSO)>=xObstacle) && ((yPerso)<=(yObstacle+hauteurObstacle)) && ((yPerso+TAILLEPERSO)>=yObstacle ))
    {
        alive = 1;
    }
    return alive;
}

void affiche_insecte (RenderWindow &fenetre,CircleShape bugs, int x, int y)
{
    bugs.setPosition(x,y);
    fenetre.draw(bugs);

}

RectangleShape creeRectangle(int x, int y, int hauteur,int longueur)
{

    RectangleShape rect(Vector2f(hauteur,longueur));
    rect.setPosition(x,y);
    //rect.setOrigin(rayon,rayon);
    rect.setFillColor(Color(255, 255, 255));
    return rect;
}



//Définition des patterns
Pattern choixpattern(int numPattern)
{
    Pattern paterrnAffiche;
    switch (numPattern)
    {
    case 1:

     paterrnAffiche.typepattern = 1;
     paterrnAffiche.nbRectangle = 3;
     paterrnAffiche.vitesse;
     paterrnAffiche.difficulte;
     paterrnAffiche.origineX = ORIGINEX;
     paterrnAffiche.origineY = ORIGINEY;
     paterrnAffiche.espacement = 180;
     paterrnAffiche.espacement2 =0;
     paterrnAffiche.espacementlat =965;
     paterrnAffiche.div =2;
     paterrnAffiche.pas_X = 0;
     paterrnAffiche.pas_Y = 3;
     paterrnAffiche.largeurrect1 = LARGEURRECT1;
     paterrnAffiche.largeurrect2 = LARGEURRECT1;
     paterrnAffiche.hauteurrect1 = 50;
     paterrnAffiche.hauteurrect2 = 50;
     paterrnAffiche.hauteurPattern = 900;

     break;


    case 2:

     paterrnAffiche.typepattern = 1;
     paterrnAffiche.nbRectangle = 4;
     paterrnAffiche.vitesse;
     paterrnAffiche.difficulte;
     paterrnAffiche.origineX = ORIGINEX;
     paterrnAffiche.origineY = ORIGINEY;
     paterrnAffiche.espacement = 125;
     paterrnAffiche.espacement2 = 100;
     paterrnAffiche.espacementlat = 965;
     paterrnAffiche.div =3;
     paterrnAffiche.pas_X = 3;
     paterrnAffiche.pas_Y = 3;
     paterrnAffiche.largeurrect1=LARGEURRECT2;
     paterrnAffiche.largeurrect2=LARGEURRECT4;
     paterrnAffiche.hauteurrect1=50;
     paterrnAffiche.hauteurrect2=50;
     paterrnAffiche.hauteurPattern = 900;
     break;

    case 3:
     paterrnAffiche.typepattern = 1;
     paterrnAffiche.nbRectangle = 5;
     paterrnAffiche.vitesse;
     paterrnAffiche.difficulte;
     paterrnAffiche.origineX = ORIGINEX;
     paterrnAffiche.origineY = ORIGINEY;
     paterrnAffiche.espacement = 100;
     paterrnAffiche.espacement2 =0;
     paterrnAffiche.espacementlat =600;
     paterrnAffiche.div =3;
     paterrnAffiche.pas_X = 5;
     paterrnAffiche.pas_Y = 3;
     paterrnAffiche.largeurrect1 = LARGEURRECT1;
     paterrnAffiche.largeurrect2 = LARGEURRECT2;
     paterrnAffiche.hauteurrect1 = 50;
     paterrnAffiche.hauteurrect2 = 150;
     paterrnAffiche.hauteurPattern = 900;
     break;

     case 4:

     paterrnAffiche.typepattern = 1;
     paterrnAffiche.nbRectangle = 4;
     paterrnAffiche.vitesse;
     paterrnAffiche.difficulte;
     paterrnAffiche.origineX = -100+ORIGINEX;
     paterrnAffiche.origineY = ORIGINEY;
     paterrnAffiche.espacement = 125;
     paterrnAffiche.espacement2 = 100;
     paterrnAffiche.espacementlat = 600;
     paterrnAffiche.div =3;
     paterrnAffiche.pas_X = 3;
     paterrnAffiche.pas_Y = 3;
     paterrnAffiche.largeurrect1=LARGEURRECT2;
     paterrnAffiche.largeurrect2=LARGEURRECT4;
     paterrnAffiche.hauteurrect1=20;
     paterrnAffiche.hauteurrect2=20;
     paterrnAffiche.hauteurPattern = 900;

     break;

    case 5://case 1 ok
      paterrnAffiche.typepattern = 1;
     paterrnAffiche.nbRectangle = 3;
     paterrnAffiche.vitesse;
     paterrnAffiche.difficulte;
     paterrnAffiche.origineX = -300+ORIGINEX;
     paterrnAffiche.origineY = ORIGINEY;
     paterrnAffiche.espacement = 180;
     paterrnAffiche.espacement2 =0;
     paterrnAffiche.espacementlat =800;
     paterrnAffiche.div =2;
     paterrnAffiche.pas_X = 0;
     paterrnAffiche.pas_Y = 3;
     paterrnAffiche.largeurrect1 = LARGEURRECT1;
     paterrnAffiche.largeurrect2 = LARGEURRECT1;
     paterrnAffiche.hauteurrect1 = 100;
     paterrnAffiche.hauteurrect2 = 50;
     paterrnAffiche.hauteurPattern = 900;

     break;
    case 6://case 1 ok
      paterrnAffiche.typepattern = 1;
     paterrnAffiche.nbRectangle = 3;
     paterrnAffiche.vitesse;
     paterrnAffiche.difficulte;
     paterrnAffiche.origineX = ORIGINEX;
     paterrnAffiche.origineY = ORIGINEY;
     paterrnAffiche.espacement = 180;
     paterrnAffiche.espacement2 =0;
     paterrnAffiche.espacementlat =1200;
     paterrnAffiche.div =2;
     paterrnAffiche.pas_X = 0;
     paterrnAffiche.pas_Y = 3;
     paterrnAffiche.largeurrect1 = 120+LARGEURRECT1;
     paterrnAffiche.largeurrect2 = LARGEURRECT1;
     paterrnAffiche.hauteurrect1 = 100;
     paterrnAffiche.hauteurrect2 = 50;
     paterrnAffiche.hauteurPattern = 900;
     break;
   case 7://case 2ok
     paterrnAffiche.typepattern = 1;
     paterrnAffiche.nbRectangle = 4;
     paterrnAffiche.vitesse;
     paterrnAffiche.difficulte;
     paterrnAffiche.origineX = -300+ORIGINEX;
     paterrnAffiche.origineY = ORIGINEY;
     paterrnAffiche.espacement = 125;
     paterrnAffiche.espacement2 = 100;
     paterrnAffiche.espacementlat = 500;
     paterrnAffiche.div =3;
     paterrnAffiche.pas_X = 10;
     paterrnAffiche.pas_Y = 3;
     paterrnAffiche.largeurrect1=LARGEURRECT2;
     paterrnAffiche.largeurrect2=100+LARGEURRECT4;
     paterrnAffiche.hauteurrect1=50;
     paterrnAffiche.hauteurrect2=50;
     paterrnAffiche.hauteurPattern = 900;
     break;
   case 8://case 2 ok
     paterrnAffiche.typepattern = 1;
     paterrnAffiche.nbRectangle = 4;
     paterrnAffiche.vitesse;
     paterrnAffiche.difficulte;
     paterrnAffiche.origineX = -300+ORIGINEX;
     paterrnAffiche.origineY = ORIGINEY;
     paterrnAffiche.espacement = 125;
     paterrnAffiche.espacement2 = 100;
     paterrnAffiche.espacementlat = 1200;
     paterrnAffiche.div =3;
     paterrnAffiche.pas_X = 10;
     paterrnAffiche.pas_Y = 3;
     paterrnAffiche.largeurrect1=-50+LARGEURRECT2;
     paterrnAffiche.largeurrect2=100+LARGEURRECT4;
     paterrnAffiche.hauteurrect1=50;
     paterrnAffiche.hauteurrect2=50;
     paterrnAffiche.hauteurPattern = 900;
     break;

   case 9://case 3 ok
     paterrnAffiche.typepattern = 1;
     paterrnAffiche.nbRectangle = 5;
     paterrnAffiche.vitesse;
     paterrnAffiche.difficulte;
     paterrnAffiche.origineX = ORIGINEX;
     paterrnAffiche.origineY = ORIGINEY;
     paterrnAffiche.espacement = 100;
     paterrnAffiche.espacement2 =0;
     paterrnAffiche.espacementlat =600;
     paterrnAffiche.div =3;
     paterrnAffiche.pas_X = 5;
     paterrnAffiche.pas_Y = 3;
     paterrnAffiche.largeurrect1 = 500+LARGEURRECT1;
     paterrnAffiche.largeurrect2 = LARGEURRECT2;
     paterrnAffiche.hauteurrect1 = 50;
     paterrnAffiche.hauteurrect2 = 50;
     paterrnAffiche.hauteurPattern = 900;
     break;


     case 10://case 3 ok
     paterrnAffiche.typepattern = 1;
     paterrnAffiche.nbRectangle = 5;
     paterrnAffiche.vitesse;
     paterrnAffiche.difficulte;
     paterrnAffiche.origineX = ORIGINEX;
     paterrnAffiche.origineY = ORIGINEY;
     paterrnAffiche.espacement = 100;
     paterrnAffiche.espacement2 =0;
     paterrnAffiche.espacementlat =1000;
     paterrnAffiche.div =3;
     paterrnAffiche.pas_X = 5;
     paterrnAffiche.pas_Y = 3;
     paterrnAffiche.largeurrect1 = LARGEURRECT1;
     paterrnAffiche.largeurrect2 = LARGEURRECT2;
     paterrnAffiche.hauteurrect1 = 50;
     paterrnAffiche.hauteurrect2 = 50;
     paterrnAffiche.hauteurPattern = 900;
     break;
    case 11://case 2
     paterrnAffiche.typepattern = 2;
     paterrnAffiche.nbRectangle = 15;
     paterrnAffiche.vitesse;
     paterrnAffiche.difficulte;
     paterrnAffiche.origineX = 0+ORIGINEX;
     paterrnAffiche.origineY = ORIGINEY;
     paterrnAffiche.espacement = 0;
     paterrnAffiche.espacement2 =50;
     paterrnAffiche.espacementlat =80;
     paterrnAffiche.espacementlat2 =80;
     paterrnAffiche.div =4;
     paterrnAffiche.pas_X = 0;
     paterrnAffiche.pas_Y = 3;
     paterrnAffiche.largeurrect1 = 10;
     paterrnAffiche.largeurrect2 = 5;
     paterrnAffiche.hauteurrect1 = 500;
     paterrnAffiche.hauteurrect2 = 50;
     break;


    /*
    case 11:
    case 12:*/

    }
    return paterrnAffiche;
}




int fin(int score, RenderWindow &app) {
        char stringScore[50];
        char phrase1[] = "A problem has been detected and windows has been shut down to prevent damage to your brain";
        char phrase2[] = "*** STOP: 0xFFFFFFFF (0xFFFFFFFF, 0xUUUUUUUU, 0xUUUUUUUU, 0xUUUUUUUU).";
        char phrase3[] = "* Do not press Q to quit this insane game";
        char phrase4[] = "* Press R to restart the best game ever";
        int rejouer;
        sprintf(stringScore, "** You lost with a score of %i", score);
        Texture fin;
    if(!fin.loadFromFile("fin.png")) {
        printf("Probleme de chargement de l'image");
    }
    Sprite imgFin;
    imgFin.setTexture(fin);
    Font courier;
    if(!courier.loadFromFile("courbd.ttf")) {
        printf("Probleme de chargement de la police");
    }
    SoundBuffer sonErreur;
    if(!sonErreur.loadFromFile("sonErreur.wav")) {
        printf("Probleme de chargement du sonErreur");
    }
    Sound erreur;
    erreur.setBuffer(sonErreur);
    Text txt1;
    txt1.setFont(courier);
    txt1.setString(phrase1);
    txt1.setCharacterSize(25);
    txt1.setPosition(150, 150);
    Text txt2;
    txt2.setFont(courier);
    txt2.setString(phrase2);
    txt2.setCharacterSize(25);
    txt2.setPosition(150, 220);
    Text txt3;
    txt3.setFont(courier);
    txt3.setString(phrase3);
    txt3.setCharacterSize(25);
    txt3.setPosition(150, 295);
    Text txt4;
    txt4.setFont(courier);
    txt4.setString(phrase4);
    txt4.setCharacterSize(25);
    txt4.setPosition(150, 325);
    Text txtScore;
    txtScore.setString(stringScore);
    txtScore.setFont(courier);
    txtScore.setCharacterSize(25);
    txtScore.setPosition(150, 250);
    txtScore.setColor(Color(255, 255, 255));
    app.draw(imgFin);
    app.draw(txt1);
    app.draw(txt2);
    app.draw(txt3);
    app.draw(txt4);
    app.draw(txtScore);
    app.display();
    erreur.play();
    sleep(milliseconds(220));
    erreur.play();
    sleep(milliseconds(220));
    erreur.play();
    sleep(milliseconds(220));


    Event event;


    while(app.isOpen()) {

        if (Keyboard::isKeyPressed(Keyboard::R)) {
            rejouer = 1;
            break;
        }
        if (Keyboard::isKeyPressed(Keyboard::Q)) {
            app.close();
            break;
        }
        while(app.pollEvent(event)) {
            if (event.type == Event::Closed) {
                app.close();
            }
        }
    }
    return rejouer;
}


void compteARebours(RenderWindow &app, int hauteurApp, int largeurApp, Sprite wallpaper2, Sprite cmd, Sprite barre_outil, Sprite icon_cmd) {
    Font courier;
    char txtCompteur[2];
    if(!courier.loadFromFile("courbd.ttf")) {
        printf("Probleme de chargement de la police");
    }

    SoundBuffer sonCompteur;
    if(!sonCompteur.loadFromFile("sonCompteur.wav")) {
        printf("Probleme de chargement du sonCompteur");
    }
    SoundBuffer sonGo;
    if(!sonGo.loadFromFile("sonGo.wav")) {
        printf("Probleme de chargement du sonGo");
    }

    Sound go;
    Sound compteur;
    go.setBuffer(sonGo);
    compteur.setBuffer(sonCompteur);
    Text compteARebours;
    sprintf(txtCompteur, "3");
    compteARebours.setString(txtCompteur);
    compteARebours.setPosition(ORIGINEX + (1200/2), 500);
    compteARebours.setCharacterSize(50);
    compteARebours.setFont(courier);
    compteARebours.setColor(Color(0, 0, 255));
    app.clear();
    app.draw(wallpaper2);
    app.draw(cmd);
    app.draw(barre_outil);
    app.draw(icon_cmd);
    app.draw(compteARebours);
    app.display();
    compteur.play();
    sleep(milliseconds(1000));
    app.clear();
    sprintf(txtCompteur, "2");
    compteARebours.setString(txtCompteur);
    compteARebours.setColor(Color(255, 255, 255));
    app.draw(wallpaper2);
    app.draw(cmd);
    app.draw(barre_outil);
    app.draw(icon_cmd);
    app.draw(compteARebours);
    app.display();
    compteur.play();
    sleep(milliseconds(1000));
    app.clear();
    sprintf(txtCompteur, "1");
    compteARebours.setString(txtCompteur);
    compteARebours.setColor(Color(255, 0, 0));
    app.draw(wallpaper2);
    app.draw(cmd);
    app.draw(barre_outil);
    app.draw(icon_cmd);
    app.draw(compteARebours);
    app.display();
    compteur.play();
    sleep(milliseconds(1000));
    app.clear();
    sprintf(txtCompteur, "GO");
    compteARebours.setString(txtCompteur);
    compteARebours.setColor(Color(0, 255, 0));
    compteARebours.setPosition(ORIGINEX + (1200/2) - 20, 500);
    app.draw(compteARebours);
    app.draw(wallpaper2);
    app.draw(cmd);
    app.draw(barre_outil);
    app.draw(icon_cmd);
    app.display();
    go.play();
    sleep(milliseconds(1000));
    app.clear();

}

int abs(int a)
{
    if(a < 0)
        a = -a;
    return a;
}

int aliveBug(Perso &perso, Bug &bug)
{
    int alive = 0;
    if((perso.x <= (0+1200) ) && ((perso.x+TAILLEPERSO)>=0) && ((perso.y)<=(bug.y+bug.largTir)) && ((perso.y+TAILLEPERSO)>=bug.y ))
    {
        alive = 1;
    }
    return alive;
}

/*void affiche (RenderWindow &fenetre,RectangleShape rect, int x, int y)
{
    rect.setPosition(x,y);
    fenetre.draw(rect);
}*/

void tirInsecte(RenderWindow &fenetre, Bug &bug, Perso &perso)
{
    RectangleShape tir(Vector2f(fenetre.getSize().x, bug.largTir));
    if(bug.largTir <= 20)
        bug.largTir++;
    if(bug.randTir <= 0 && bug.y > 2*HAUTEURINTERFJOUABLE/3)
    {
        bug.randTir = rand() % (2*HAUTEURINTERFJOUABLE/3-HAUTEURINTERFJOUABLE/4) + HAUTEURINTERFJOUABLE/4;
        //bug.compteur = 0;
    }

    /*if(bug.compteur >= DUREETIR)
    {
        bug.compteur = 0;
        //bug.randTir = 0;
    }*/

    if(bug.compteur >= DUREETIR && bug.y <= 2*HAUTEURINTERFJOUABLE/3)
    {
        bug.compteur = 0;
        bug.randTir = -200;
    }


    if(abs(bug.y - bug.randTir) <= DISTPREV)
    {
        bug.bug.setFillColor(Color::Red);
        fenetre.draw(bug.bug);
        //printf("y : %i\n", bug.y);
    }

    if(bug.y <= bug.randTir && bug.compteur <= DUREETIR)
    {
        bug.tir = creeRectangle(0, bug.y + TAILLEBUGS/2, fenetre.getSize().x, bug.largTir);
        //affiche(fenetre, tir, 0, bug.y);
        if ( (aliveBug(perso, bug)))
            {
                //printf ("vous avez perdu avec un score de : %i", perso.score);
                //fenetre.close();
                bug.fin = 1;
            }

        bug.tir.setFillColor(Color::Red);
        fenetre.draw(bug.tir);
        bug.bug.setFillColor(Color::Red);
        fenetre.draw(bug.bug);
        bug.compteur++;
    }
    bug.bug.setFillColor(Color::White);
    bug.tir.setFillColor(Color::White);
    //printf("compt : %i\n", bug.compteur);
    /*if(bug.y <= 20 + randTir)
    {
        tir = creeRectangle(0, bug.y + TAILLEBUGS/2, fenetre.getSize().x, bug.largTir);
        fenetre.draw(tir);
    }*/
}

void affiche_insecte (RenderWindow &fenetre, Bug &bug, Perso &perso)
{
    bug.bug.setPosition(bug.x,bug.y);
    mvtBug(fenetre, bug);
    fenetre.draw(bug.bug);
    tirInsecte(fenetre, bug, perso);
}

void mvtBug(RenderWindow &fenetre, Bug &bug)
{
    if(bug.y <= bug.randTir && bug.pas < 0)
    {
        if(bug.seq >= ATTENTEBUGS && bug.y != -25)
        {

            bug.y = dept(bug.y,bug.pas);
            //bug.seq = 0;
        }
        else if(bug.seq <= ATTENTEBUGS)
        {
            bug.seq++;
            //printf("%i ", bug.seq);
        }
        else
        {
            bug.seq = 0;
            bug.pas = -bug.pas;
            //printf("Pas : %i \n", bug.pas);
            //printf("%i ", bug.seq);
        }
    }

    else
    {
        if(bug.y <= 0 && bug.pas <= 0)
        {
            bug.pas = -bug.pas;
            bug.seq = 0;
            //printf("Pas : %i \n", bug.pas);
        }
        if(bug.y >= HAUTEURINTERFJOUABLE && bug.pas >= 0)
            bug.pas = -bug.pas;
        bug.y = dept(bug.y,bug.pas);
        //printf("Pas : %i \n", bug.pas);
    }

    /*if (sequence1 > ATTENTEBUGS || (bug.y> (HAUTEURINTERFJOUABLE/2)))
        {
            bug.y = dept(bug.y,-1);
        }
        else
        {
            sequence1 ++;
        }*/
}
