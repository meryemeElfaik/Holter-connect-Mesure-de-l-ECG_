# Holter-connect-Mesure-de-l-ECG_
Ce projet est dans le cadre de produire un prototype de holter connecté qui
remonte des événements caractéristiques comme des dépassements de seuils de
fréquence cardiaque et qui enregistre localement l’ECG du patient.



## 1. Fonctionnalité et résultat attendues
 -Une station de mesure de l’ECG construite autours d’une association Arduino
THE THINGS UNO / Raspberry Pi, d’une carte amplification AD8232 ECG.
- Une passerelle LoRa The Things Network assure la collecte des données de la station et les acheminent vers le Cloud.
- L’accès à distance aux données de surveillance sera assuré par un site web.
- Un site web local assurera un accès aux enregistrements de l’ECG et à sa
mesure en direct et périodiquement.
- Les seuils limites doivent pouvoir être fixées à distance

# Fonctionnalités obligatoires : 

''''''Développer une interface de supervision et configuration locale qui permet''''
- d'accéder aux mesures directement issues de l’ECG.
- de tracer l’évolution de l’ECG en direct.
- d'accéder aux mesures historisées sur une période réglabe.
- de tracer l’ECG enregistré sur cette période.
- de "monitorer" la liaison LoRa (Afficher le RSSI et le SNR)

 Développer une interface de supervision et configuration distante qui permet :
- d'accéder aux mesures de la fréquence cardiaque issues du cloud TTN.
- d'accéder aux mesures de la fréquence cardiaque historisées sur une période réglable (horodatage 
début et fin)
- de "monitorer" la liaison LoRa (Afficher le RSSI et le SNR)
- de régler les seuils limites pour la surveillance du rythme cardiaque (pouls)

## 2. Matériels et Technologies utilisées

- Langage de programmation C++, Javascript.
- Une passerelle LoRa The Things Network.
- Carte Arduino THE THINGS UNO. 
- Carte Raspberry Pi 2B. 
- le capteur AD8232 ECG 


# Sommaire
- Branchement des capteurs. 
- Récupération des mesures du capteur.
- Envoie des mesures au serveurs The Things Network (TTN).
- Réception et Décodages des données au niveau du serveur TTN.
- Afficher sur l'interface en utilisant Node-red.
# Usage
## 1. Branchement des capteurs
Le capteur AD8232 ECG

## 2. Envoie des mesures au serveurs The Things Network (TTN).

Programme Arduino pour récupérer les mesures à partir du port série et les envoyer au serveur TTN

#### Dépendances requises :
- Téléchargez et installez l'IDE ARDUINO
- Télécharger et installer la librairie ```<TheThingsNetwork>``` à partir d'Arduino :
Croquis --> Inclure une bibliothèque --> Gérer les bibliothèques  puis recherchez <TheThingsNetwork>

#### Fonctionnement :
A partir de votre PC et sur l'IDE Arduino :
- Choisissez le type de la carte que vous allez utiliser : Outils --> Type de carte --> Arduino Leonardo
- Choisissez le port de communication : Outils --> Port
- Lancez le code Arduino : LoRa.ino

## 3. Affichage sur l'interface graphique.
A partir de la Raspberry :
- Récupérer l'adresse IP de la Raspberry.
- Lancez Node-RED 
bash
node-red-start
- Accédez à l'interface web du Node-RED par : ```@IP_Raspberry:1880```

#### Dépendances requises :
A partir de ```Manage palette``` installez :
- node-red-node-serialport
- node-red-dashboard
- node-red-contrib-ui-led
#### Encadrants
- Gozlan Philippe.
- Silanus Marc.
# Contributeur
#### Etudiants
- Meryeme EL FAIK.
- Zineb OUBRAHIM
