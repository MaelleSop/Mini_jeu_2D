# Bienvenue sur notre jeu Banana Feast réalisé en C++ et QT !

Pour pouvoir lancer le jeu, il vous suffit de lancer le fichier main.cpp si vous passer par CLion ou un autre EDI. Sinon dans la WSL vous devez exécuter les commandes suivantes après s'être déplacé dans le fichier contenant le projet :
Assurez-vous d'avoir QT d'installer sinon installez le.
```
sudo apt install qt6-base-dev
sudo apt install qt6-multimedia-dev
sudo apt install qt6-wayland

```
Si tout est bien installé vous pouvez maintenant lancé :
```
cmake .
make
./miniprojet
```

Les règles du jeu sont simples, vous incarnez un petit singe qui a faim. Votre but est donc de récupérer le plus de bananes possible tout en évitant les gorilles qui veulent vous les voler. 

Pour vous déplacer sur l'écran, vous pouvez utiliser les flèches gauche et droite de votre clavier. Votre score ainsi que votre pseudo (que vous entrez au début du jeu) sont affichés en haut de l'écran.

Vous pouvez aussi voir le meilleur score réalisé. À vous de le battre !

Lorsque vous touchez un gorille, alors votre partie est finie et votre score est enregistré si vous battez le meilleur score. 

Pensez à allumer le son de votre ordinateur pour une immersion totale.
