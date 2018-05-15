#include "fonctions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace sf;



int main()
{
    srand(time(NULL));
    const int PATERNSMAX =10;
    float deadZone = 15.0;

    //Fichiers
    FILE * scores;
    scores = fopen("highscores.txt" , "r+");
    if (scores == NULL)
    {
        fclose(scores);
        scores = fopen("highscores.txt" , "w+");
        for(int i = 0; i<10; i++)
        {
            fprintf(scores, "%s", "0\n");
        }
    }
    fclose(scores);

    //Bugs Nouveaux
    Bug bug1, bug2;

    //Joueur Nouveau
    Perso perso1;

    //Sprites
    Texture texturePerso;
    if(!texturePerso.loadFromFile("perso.png")) {
        printf("textureperso non chargee");
    }
    perso1.perso.setTexture(&texturePerso);
    int xBarre = 0, yBarre = HAUT_FEN-29;
    int xIcmd = 140, yIcmd = HAUT_FEN-26;
    int xFondJeu1 = 365, xFondJeu2 = 365;
    int yFondJeu1 = 34, yFondJeu2 = 34 - 993;
    Texture wallpaper2_tex;
    Sprite wallpaper2 = creaSprite(wallpaper2_tex, WALLPAPER2);
    Texture barre_outil_tex;
    Sprite barre_outil = creaSprite(barre_outil_tex, BARRE_OUTIL);
    barre_outil.setPosition(xBarre, yBarre);
    Texture icon_cmd_tex;
    Sprite icon_cmd = creaSprite(icon_cmd_tex, ICON_CMD1);
    icon_cmd.setPosition(xIcmd, yIcmd);
    Texture icon_cmd2_tex;
    Sprite icon_cmd2 = creaSprite(icon_cmd_tex, ICON_CMD2);
    icon_cmd2.setPosition(xIcmd, yIcmd);
    Texture cmd_tex;
    Sprite cmd = creaSprite(cmd_tex, CMD);
    cmd.setPosition(LARG_FEN/2 - 1205/2,0);
    Texture high_tex;
    Sprite high = creaSprite(high_tex, HIGHSCORE);
    high.setPosition(LARG_FEN/2 - 1205/2 - 250,200);
    Texture txtFondJeu;
    if (!txtFondJeu.loadFromFile("fondJeu.png"))
        printf("Probleme de chargement de fondJeu");
    Sprite fondJeu1;
    fondJeu1.setTexture(txtFondJeu);
    fondJeu1.setPosition(365, 34);
    Sprite fondJeu2;
    fondJeu2.setTexture(txtFondJeu);
    fondJeu2.setPosition(365, 34);

    //Musiques et Sons
    Music musiqueJeu;
    if (!musiqueJeu.openFromFile("musique.wav")) {
        printf("pb chargement musique");
    }
    musiqueJeu.setVolume(50);
    int rejouer = 0;

    RenderWindow app(VideoMode(LARG_FEN, HAUT_FEN), "SFML window", Style::Fullscreen  );
    ecranDemarrage(app);


    //for(int i = 0; i<=str; i++)
    //printf("\n%i", strcmp("29", "58"));

    reset:
    //Ecriture highscores
    scores = fopen("highscores.txt" , "r+");
    char highscore[11][1000];
    char test1[1000] = "";
    char test2[1000] = "";
    char highs[1000] = "";
    //int pos = ftell();
    fgets(highs, 10, scores);
    /*for(int i = 0; i<=10; i++)
    {
        fgets(highscore[i], 10, scores);
        printf("%s", highscore[i]);
    }*/
    fclose(scores);
    //strcpy(highs, highscore[0]);
    int cpt = 0;
    Font courier;
    if(!courier.loadFromFile("courbd.ttf")) {
        printf("Probleme de chargement de la police");
    }
    Text highsc;
    highsc.setFont(courier);
    highsc.setString(highs);
    highsc.setCharacterSize(25);
    highsc.setPosition(LARG_FEN/2 + 10 - 1205/2 - 250,250);
    highsc.setColor(Color(255, 0, 0));
    //Bug1
    bug1.x = 0;
    bug1.y =  0;
    bug1.largTir = 1;
    bug1.seq = 0;
    bug1.pas = -1;
    bug1.randTir = 0;
    bug1.compteur = 0;
    bug1.fin = 0;
    bug1.bug.setRadius(TAILLEBUGS);
    bug1.tir = creeRectangle(0, bug1.y + TAILLEBUGS/2, app.getSize().x, bug1.largTir);
    //Bug2
    bug2.x = LARGEURINTERF-2*TAILLEBUGS + 934;
    bug2.y =  HAUTEURINTERF-2*TAILLEBUGS;
    bug2.largTir = 1;
    bug2.seq = 0;
    bug2.pas = -1;
    bug2.randTir = 0;
    bug2.compteur = 0;
    bug2.fin = 0;
    bug2.bug.setRadius(TAILLEBUGS);
    bug2.tir = creeRectangle(0, bug2.y + TAILLEBUGS/2, app.getSize().x, bug2.largTir);
    //Perso
    perso1.perso.setSize(Vector2f(TAILLEPERSO,TAILLEPERSO));
    perso1.x = (LARGEURINTERFJOUABLE/2)-(TAILLEPERSO/2)+ ORIGINEX;
    perso1.y = HAUTEURINTERFJOUABLE-TAILLEPERSO;
    perso1.score = 0;
    char sco[10] = "";
    Text scoreAct;
    scoreAct.setFont(courier);
    scoreAct.setString(sco);
    scoreAct.setCharacterSize(25);
    scoreAct.setPosition(LARG_FEN/2 + 10 - 1205/2 - 250,300);
    scoreAct.setColor(Color(255, 0, 0));
    //Reste
    int ajout_Pas = 0;
    int pointAccel = 0;
    int lancement = 0;
    int continuer = 0;
    int jouer = 1;
    //Pattern
    Pattern paternAffiche = choixpattern(1);
    Pattern paternAffiche1 = choixpattern(1);
    int posYRect[2*paternAffiche.nbRectangle], posXRect[2*paternAffiche.nbRectangle];
    int hauteurrect[2*paternAffiche.nbRectangle],largeurrect[2*paternAffiche.nbRectangle];
    int largR = 0, hautR = 0;
    int posYRectP1[2*paternAffiche1.nbRectangle], posXRectP1[2*paternAffiche1.nbRectangle];
    int hauteurrectP1[2*paternAffiche1.nbRectangle],largeurrectP1[2*paternAffiche1.nbRectangle];
    int largRP1 = 0, hautRP1 = 0;
    int yP1 = -1000,iP1 = 0, posrectYP1 = 0,posrectXP1 = 0,xP1 = 1;
    int y = 0,i = 0, posrectY = 0,posrectX = 0,x = 1;
    char nomRect[7];
    int numPattern = 0;

    if (rejouer == 1) {
        rejouer = 0;
        goto restart;
    }
    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed || event.type == Keyboard::isKeyPressed(Keyboard::Space))
                app.close();
            switch (event.type)
            {

            case Event::MouseButtonPressed:
                if((event.MouseButtonPressed && (Mouse::getPosition(app).y >= HAUT_FEN - 26 && Mouse::getPosition(app).x >= 140 && Mouse::getPosition(app).x <= 140 + 160) ||  (Keyboard::isKeyPressed(Keyboard::Right))) && lancement == 0)
                {
                    /*printf("Click on x : %i \n", Mouse::getPosition(app).x);
                    printf("Click on y : %i \n", Mouse::getPosition(app).y);*/
                  app.clear();  lancement = 1;
                }
                else if(event.MouseButtonPressed && (Mouse::getPosition(app).y >= HAUT_FEN - 26 && Mouse::getPosition(app).x >= 140 && Mouse::getPosition(app).x <= 140 + 160) && lancement == 1)
                {
                    lancement = 0;
                }
                break;
            }
        }
        if(lancement == 0)
        {
            menu(app, lancement);
        }
        else
        {
            restart:
            jouer = 0;
            compteARebours(app, ORIGINEY, ORIGINEX, wallpaper2, cmd, barre_outil, icon_cmd);
            musiqueJeu.play();
            while (app.isOpen())
    {
        if (yFondJeu1 >= 1020) {
            yFondJeu1 = -964+34;
        }
        if (yFondJeu2 >= 1020) {
            yFondJeu2 = -964+34;
        }
        yFondJeu1 += 1;
        yFondJeu2 += 1;
        fondJeu1.setPosition(xFondJeu1, yFondJeu1);
        fondJeu2.setPosition(xFondJeu2, yFondJeu2);
        app.draw(fondJeu1);
        app.draw(fondJeu2);

        Event event;
        while (app.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                app.close();
                break;
            }
        }
        //Joystick
        if (((Joystick::getAxisPosition(0, Joystick::X)) > deadZone && ((perso1.x+TAILLEPERSO) < (LARGEURINTERFJOUABLE+ORIGINEX)))
            )  {
            perso1.x += (Joystick::getAxisPosition(0, Joystick::X)/30);
        }

        if (((Joystick::getAxisPosition(0, Joystick::X)) < -deadZone && (perso1.x > ORIGINEX))
            )  {
            perso1.x += (Joystick::getAxisPosition(0, Joystick::X)/30);
        }
        if ((Joystick::getAxisPosition(0, Joystick::Y)) > deadZone && ((perso1.y+TAILLEPERSO) < HAUTEURINTERFJOUABLE)) {
            perso1.y += (Joystick::getAxisPosition(0, Joystick::Y)/30);
        }

        if ((Joystick::getAxisPosition(0, Joystick::Y)) < -deadZone && (perso1.y > ORIGINEYPERSO)) {
            perso1.y += (Joystick::getAxisPosition(0, Joystick::Y)/30);
        }
        //Clavier
        //Flèches directionnelles
        if ( ((Keyboard::isKeyPressed(Keyboard::Right)) || (Keyboard::isKeyPressed(Keyboard::D))) && ((perso1.x+TAILLEPERSO) < (LARGEURINTERFJOUABLE+ORIGINEX)) )     // essayer de virer la latence (du a windobs
        {
            perso1.x= dept(perso1.x, PASPERSODROIT);
        }
        else if (((Keyboard::isKeyPressed(Keyboard::Left)) || (Keyboard::isKeyPressed(Keyboard::Q))) && (perso1.x > ORIGINEX) )     //emplacement interface en y
        {
            perso1.x= dept(perso1.x, PASPERSOGAUCHE);
        }
        if (((Keyboard::isKeyPressed(Keyboard::Up)) || (Keyboard::isKeyPressed(Keyboard::Z))) &&(perso1.y > ORIGINEYPERSO))
        {
            perso1.y = dept(perso1.y, PASPERSOHAUT);
        }
        else if (((Keyboard::isKeyPressed(Keyboard::Down)) || (Keyboard::isKeyPressed(Keyboard::S))) && ((perso1.y+TAILLEPERSO) < HAUTEURINTERFJOUABLE) )     //emplacement interface en y
        {
            perso1.y = dept(perso1.y, PASPERSOBAS);
        }

        if (pointAccel >= 10000)
        {
            ajout_Pas ++;
            pointAccel = 0;
        }


        if ((posrectY-paternAffiche.hauteurPattern)>= HAUTEURINTERFJOUABLE)
        {

            y = ORIGINEYPERSO;
            numPattern = rand()%((0,PATERNSMAX)+1);
            //numPattern ++;
            paternAffiche = choixpattern(numPattern);
            //y = y - paternAffiche.hauteurPattern;
            x = 0;

        }
        if ((posrectYP1-paternAffiche1.hauteurPattern)>= HAUTEURINTERFJOUABLE)
        {

            yP1 = ORIGINEYPERSO;
            numPattern = rand()%((0,PATERNSMAX)+1);
            //numPattern ++;
            paternAffiche1 = choixpattern(numPattern);
            //yP1 = yP1 - paternAffiche1.hauteurPattern;
            xP1 = 0;

        }
        //appelle fonction pattern avec i

        /*      if (y >= HAUTEURINTERFJOUABLE )
              {
                  section = sectionSuivante(section,i);
                  y = ORIGINEY;
                  yP2 = ORIGINEYP2;
                  pasTampon = pasP1;
                  pasP1 = pasP2;
                  pasP2 = pasTampon;

              }
        */

        //  printf("%c\n", section);        //pour choix de la section?

        for(i=0; i<=paternAffiche.nbRectangle; i++)
        {
            sprintf(nomRect,"rect%i",i);
            if(paternAffiche.typepattern == 1 )
            {
                if ((i%paternAffiche.div) == 0)
                {
                    posrectY = paternAffiche.origineY+i*paternAffiche.espacement+y;
                    posrectX = paternAffiche.origineX;
                    posrectX += x;
                    largR =paternAffiche.largeurrect1;
                    hautR =paternAffiche.hauteurrect1;

                    if (posrectX >= LARGEURINTERFJOUABLE+ORIGINEX)
                        x= -x;



                }


                else
                {
                    posrectY = paternAffiche.origineY+i*paternAffiche.espacement+y;
                    posrectX = -i*paternAffiche.espacement2+paternAffiche.espacementlat;
                    largR =paternAffiche.largeurrect2;
                    hautR =paternAffiche.hauteurrect2;
                }

               /* RectangleShape nomRect = creeRectangle(posrectX,(posrectY),largR,hautR);
                affiche(app,nomRect,posrectX,posrectY);
                posYRect[i] = posrectY;
                posXRect[i] = posrectX;
                hauteurrect[i] = hautR;
                largeurrect[i] = largR;
                //printf("\n%i %i\n ",posYRect[i],posXRect[i]);
*/

                RectangleShape nomRect = creeRectangle(posrectX,(posrectY),largR,hautR);
                affiche(app,nomRect,posrectX,posrectY);
                posYRect[i] = posrectY;
                posXRect[i] = posrectX;
                hauteurrect[i] = hautR;
                largeurrect[i] = largR;





            }
            else if(paternAffiche.typepattern == 2 )
            {
                if ((i%2/*paterrnAffiche.div*/) == 0)
                {
                    posrectY = paternAffiche.origineY+i*paternAffiche.espacement+y;
                    posrectX = paternAffiche.origineX+i*paternAffiche.espacementlat2;
                    posrectX -= x;
                    largR =paternAffiche.largeurrect1;
                    hautR =paternAffiche.hauteurrect1;

                    if (posrectX >= 1400 )
                        x= -x;



                }
                else //if ((i%paterrnAffiche.div) <= 2)
                {
                    posrectY = paternAffiche.origineY+i*paternAffiche.espacement+y;
                    posrectX = paternAffiche.origineX + i*paternAffiche.espacementlat;
                    posrectX += x;
                    largR =paternAffiche.largeurrect1;
                    hautR =paternAffiche.hauteurrect1;

                    if (posrectX <= -200 )
                        x= -x;



                }

                RectangleShape nomRect = creeRectangle(posrectX,(posrectY),largR,hautR);
                affiche(app,nomRect,posrectX,posrectY);
                posYRect[i] = posrectY;
                posXRect[i] = posrectX;
                hauteurrect[i] = hautR;
                largeurrect[i] = largR;





            }


        }


        // if (y >= HAUTEURINTERF+900)
        // {
        //     y = 0;
        // }
        // else
        // {
        y=y+paternAffiche.pas_Y+ajout_Pas;

        x=dept(x,paternAffiche.pas_X);
        // }



        //hitbox pattern2
        for (i=0; i<=paternAffiche.nbRectangle; i++)
        {

            if ( (alive(perso1.x, perso1.y, posXRect[i], posYRect[i], largeurrect[i],hauteurrect[i])))
            {
                if(atoi(highs) < perso1.score && cpt == 0)
                    {
                        scores = fopen("highscores.txt" , "w+");
                        //printf("\n%i", perso1.score);
                        fprintf(scores, "%i", perso1.score);
                        fgets(highs, 10, scores);
                        //strcpy(test1, highscore[i]);
                        fclose(scores);
                    }
                printf("%s\n",highs);
                musiqueJeu.stop();
                continuer = fin(perso1.score, app);

                if (continuer == 1) {
                        rejouer = 1;
                goto reset;
            }
            }     //mettre un intersect
        }



                for(i=0; i<=paternAffiche1.nbRectangle; i++)
        {
            sprintf(nomRect,"rect%i",i);
            if(paternAffiche1.typepattern == 1 )
            {
                if ((i%paternAffiche1.div) == 0)
                {
                    posrectYP1 = paternAffiche1.origineY+i*paternAffiche1.espacement+yP1;
                    posrectXP1 = paternAffiche1.origineX;
                    posrectXP1 += xP1;
                    largRP1 =paternAffiche1.largeurrect1;
                    hautRP1 =paternAffiche1.hauteurrect1;

                    if (posrectXP1 >= LARGEURINTERFJOUABLE+ORIGINEX)
                        xP1= -xP1;



                }


                else
                {
                    posrectYP1 = paternAffiche1.origineY+i*paternAffiche1.espacement+yP1;
                    posrectXP1 = -i*paternAffiche1.espacement2+paternAffiche1.espacementlat;
                    largRP1 =paternAffiche1.largeurrect2;
                    hautRP1 =paternAffiche1.hauteurrect2;
                }

               /* RectangleShape nomRect = creeRectangle(posrectX,(posrectY),largR,hautR);
                affiche(app,nomRect,posrectX,posrectY);
                posYRect[i] = posrectY;
                posXRect[i] = posrectX;
                hauteurrect[i] = hautR;
                largeurrect[i] = largR;
                //printf("\n%i %i\n ",posYRect[i],posXRect[i]);
*/

                RectangleShape nomRect = creeRectangle(posrectXP1,(posrectYP1),largRP1,hautRP1);
                affiche(app,nomRect,posrectXP1,posrectYP1);
                posYRectP1[i] = posrectYP1;
                posXRectP1[i] = posrectXP1;
                hauteurrectP1[i] = hautRP1;
                largeurrectP1[i] = largRP1;






            }
            else if(paternAffiche1.typepattern == 2 )
            {
                if ((i%2/*paterrnAffiche.div*/) == 0)
                {
                    posrectYP1 = paternAffiche1.origineY+i*paternAffiche1.espacement+y;
                    posrectXP1 = paternAffiche1.origineX+i*paternAffiche1.espacementlat2;
                    posrectXP1 -= xP1;
                    largRP1 =paternAffiche1.largeurrect1;
                    hautRP1 =paternAffiche1.hauteurrect1;

                    if (posrectXP1 >= 1400 )
                        x= -x;



                }
                else //if ((i%paterrnAffiche.div) <= 2)
                {
                    posrectYP1 = paternAffiche1.origineY+i*paternAffiche1.espacement+y;
                    posrectXP1 = paternAffiche1.origineX + i*paternAffiche1.espacementlat;
                    posrectXP1 += xP1;
                    largRP1 =paternAffiche1.largeurrect1;
                    hautRP1 =paternAffiche1.hauteurrect1;

                    if (posrectXP1 <= -200 )
                        xP1= -xP1;



                }
                RectangleShape nomRect = creeRectangle(posrectXP1,(posrectYP1),largRP1,hautRP1);
                affiche(app,nomRect,posrectXP1,posrectYP1);
                posYRectP1[i] = posrectYP1;
                posXRectP1[i] = posrectXP1;
                hauteurrectP1[i] = hautRP1;
                largeurrectP1[i] = largRP1;






            }


        }


        // if (y >= HAUTEURINTERF+900)
        // {
        //     y = 0;
        // }
        // else
        // {
        yP1=yP1+paternAffiche1.pas_Y+ajout_Pas;

        xP1=dept(xP1,paternAffiche1.pas_X);
        // }



        //hitbox pattern2
        for (i=0; i<=paternAffiche1.nbRectangle; i++)
        {

            if ( (alive(perso1.x, perso1.y, posXRectP1[i], posYRectP1[i], largeurrectP1[i],hauteurrectP1[i])) || bug1.fin == 1 || bug2.fin == 1)
            {

                if(atoi(highs) < perso1.score && cpt == 0)
                    {
                        scores = fopen("highscores.txt" , "w+");
                        fprintf(scores, "%i", perso1.score);
                        fgets(highs, 10, scores);
                        fclose(scores);
                    }
                printf("%s\n",highs);
                musiqueJeu.stop();
                continuer = fin(perso1.score, app);

                if (continuer == 1)
                {
                    rejouer = 1;
                    goto reset;
                }
            }     //mettre un intersect
        }
        sprintf(sco, "%i", perso1.score);
        scoreAct.setString(sco);


// creaation d'une fonction void pour l'affichage des blocs  (void afficheobstacle (int x, int y) )


        // Clear screen


        // Draw the sprite



        //perso.setPosition(xPlayer,yPlayer);

        //app.draw(perso);
        app.draw(wallpaper2);
        app.draw(cmd);
        app.draw(barre_outil);
        app.draw(icon_cmd2);
        app.draw(high);
        app.draw(highsc);
        app.draw(scoreAct);

        perso1.perso.setPosition(perso1.x,perso1.y);
        app.draw(perso1.perso);
        if(perso1.score >= 5000)
        {
            affiche_insecte(app, bug1, perso1);
            affiche_insecte(app, bug2, perso1);
        }

        app.display();
        perso1.score++;
        pointAccel ++;
        sleep(milliseconds(WAIT));

        app.clear();
    }
    }
}
    return EXIT_SUCCESS;

}
