#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#define HAUT_FEN 1080
#define LARG_FEN 1920

#define BARRE_OUTIL "barre_outil_xp.png"
#define ICON_CMD1 "icon_cmd_deselect.png"
#define ICON_CMD2 "icon_cmd_select.png"
#define CMD "cmdXP2.png"
#define WALLPAPER "Windows-Xp-Bliss-Wallpaper.png"
#define WALLPAPER2 "wallpaper_trouer.png"
#define DOC_TEXT "doc_txt.png"
#define HIGHSCORE "notes.png"


#define WAIT 5
#define WAITLOSE 150

                    //les define ORIGINE X et Y sont susceptible de changer
#define LARGEURINTERF 981            //largeur de la zone de jeu atteignable par jouer)
#define HAUTEURINTERF 514            //hauteur de la zone de jeu visible par jouer)




#include <time.h>

//#include "fonctionPatterns.hpp"


#define ORIGINEYPERSO 34
#define ORIGINEYP2 -1100 //les define ORIGINE X et Y sont susceptible de changer
#define LARGEURINTERFJOUABLE 1200            //largeur de la zone de jeu atteignable par jouer)
#define HAUTEURINTERFJOUABLE 1027            //hauteur de la zone de jeu visible par jouer)





//valeur de pas
#define PASPERSODROIT 5
#define PASPERSOGAUCHE -5
#define PASPERSOHAUT -5
#define PASPERSOBAS 5



#define TAILLEBUGS 20

//region patterns
#define PATTY 0

//#define PAUSE 5

#define ATTENTEBUGS 250

#define HAUTEUROBSTACLE 50
#define TAILLEPERSO 20

#define LARGEURRECT1 600
#define LARGEURRECT2 200
#define LARGEURRECT3 50
#define LARGEURRECT4 400

#define ORIGINEX 364
#define ORIGINEY -900
#define ORIGINEYP3 -1500


#define TAILLEBUGS 20
#define DUREETIR 150
#define DISTPREV 150

using namespace sf;


typedef struct
{
    int nbRectangle;
    int vitesse;
    int difficulte;
    int origineX;
    int origineY;
    int espacement;
    int espacement2;
    int div;
    int pas_X;
    int pas_Y;
    int largeurrect1;
    int largeurrect2;
    int hauteurrect1;
    int hauteurrect2;
    int espacementlat;
    int hauteurPattern;
    int typepattern;
    int espacementlat2;

} Pattern;

typedef struct
{
    int x, y, vie, score;
    RectangleShape perso;
} Perso;

typedef struct
{
    int x, y, largTir, seq, pas, randTir, compteur, fin;
    CircleShape bug;
    RectangleShape tir;
} Bug;


Pattern choixpattern(int numPattern);
int dept (int y, int pas=3);

int alive(int xPerso, int yPerso, int xObstacle, int yObstacle, int largeurObstacle = 600, int hauteurObstacle = HAUTEUROBSTACLE);
Sprite creaSprite(Texture &texture, char path[]);
int ecranDemarrage(RenderWindow &app);

//Menu
void affiche (RenderWindow &fenetre, RectangleShape rect, int x, int y);
void menu( RenderWindow &fen, int lancement);
void dessineBase(RenderWindow &fen);
//Jeu
void jeu( RenderWindow &fen);
RectangleShape creeRectangle(int x, int y, int hauteur,int longueur);
int fin(int score, RenderWindow &app);
void compteARebours(RenderWindow &app, int hauteurApp, int largeurApp, Sprite wallpaper2, Sprite cmd, Sprite barre_outil, Sprite icon_cmd);
void affiche (RenderWindow &fenetre, RectangleShape rect, int x, int y);
//Bugs
void tirInsecte(RenderWindow &fenetre, Bug &bug, Perso &perso);
void affiche_insecte (RenderWindow &fenetre, Bug &bug, Perso &perso);
void mvtBug(RenderWindow &fenetre, Bug &bug);
int aliveBug(Perso &perso, Bug &bug);
int abs(int a);
//void affiche_insecte (RenderWindow &fenetre,CircleShape bugs, int x, int y);




#endif // FONCTIONS_H_INCLUDED
