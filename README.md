<h1>🤖 Robot Autonome de Nettoyage de Sols 🧹</h1>

<p>Ce robot autonome est conçu pour nettoyer les sols à l'aide d'un système de serpillière rotative et d'une pompe à eau pour l'humidification. Contrôlé par un <strong>Arduino Nano</strong> et équipé d'un module Bluetooth <strong>HC-05</strong>, le robot peut être commandé à distance.</p>

<p>Le robot se déplace à l'aide de deux moteurs avec réducteur et évite les obstacles grâce à des capteurs à ultrasons. L'eau est pulvérisée sur le sol via un tuyau connecté à une petite bouteille faisant office de réservoir, tandis que la serpillière rotative nettoie efficacement la surface.</p>

<p>L'afficheur <strong>LCD</strong> fournit des informations en temps réel sur l'état du robot, et le module relais contrôle la pompe à eau. L'appareil est alimenté par des batteries <strong>lithium-ion</strong> et intègre des éléments de sécurité comme un interrupteur général et des boutons dédiés pour l'allumage et l'arrêt.</p>

<p>Pour plus de détails et une démonstration pratique, consultez cette vidéo :<br>
📺 <a href="https://youtu.be/ecNfo2phP6g?si=pkN76e_93W3H9zNL" target="_blank">Démo Robot de Nettoyage de Sols</a></p>

## Motivation

<p>Je développe ce robot Mop dans le but de simplifier les tâches de nettoyage au quotidien. En tant qu'étudiante passionnée par l'électronique et la programmation embarquée, ce projet me permet de mettre en pratique mes compétences tout en créant un outil utile pour la maison.</p>

## Architecture

<p>J’ai construit ce robot autour d’une carte <strong>Arduino Nano</strong> en y intégrant plusieurs modules essentiels :</p>

<ul>
  <li><strong>Un driver L293N</strong> pour contrôler deux moteurs à courant continu</li>
  <li><strong>Trois capteurs à ultrasons</strong> (gauche, milieu, droite) pour détecter les obstacles</li>
  <li><strong>Un module relais 5V</strong> pour activer une pompe à eau</li>
  <li><strong>Une pompe 12V</strong> pour pulvériser l’eau sur le sol</li>
  <li><strong>Une batterie 12V</strong> pour alimenter les moteurs et la pompe</li>
  <li><strong>Un régulateur 5V</strong> pour fournir l’alimentation de la carte Arduino et des capteurs</li>
</ul>

<p>J’ai veillé à ce que tous les composants partagent une masse commune (GND) pour garantir la stabilité électrique.</p>




<hr>

<h2>🔧 Composants nécessaires</h2>

<table border="1" cellspacing="0" cellpadding="6">
  <thead>
    <tr>
      <th>Produit</th>
      <th>Quantité</th>
      <th>Prix unitaire</th>
      <th>Prix total</th>
    </tr>
  </thead>
  <tbody>
    <tr><td>Carte de développement Arduino Nano + câble</td><td>1</td><td>29,36 lei</td><td>29,36 lei</td></tr>
    <tr><td>Module Bluetooth HC-05 avec adaptateur</td><td>1</td><td>28,09 lei</td><td>28,09 lei</td></tr>
    <tr><td>Capteur à ultrasons HC-SR04</td><td>3</td><td>6,49 lei</td><td>19,47 lei</td></tr>
    <tr><td>Moteur avec réducteur et roue</td><td>2</td><td>14,99 lei</td><td>29,98 lei</td></tr>
    <tr><td>Résistance 1.8KΩ 0.25W</td><td>5</td><td>0,10 lei</td><td>0,50 lei</td></tr>
    <tr><td>Résistance 1KΩ 0.25W</td><td>5</td><td>0,10 lei</td><td>0,50 lei</td></tr>
    <tr><td>Résistance 10KΩ 0.25W</td><td>5</td><td>0,10 lei</td><td>0,50 lei</td></tr>
    <tr><td>Pompe à eau/air à diaphragme 12V</td><td>1</td><td>27,93 lei</td><td>27,93 lei</td></tr>
    <tr><td>Module driver moteur L293D</td><td>1</td><td>16,04 lei</td><td>16,04 lei</td></tr>
    <tr><td>Support accumulateur 18650 3S</td><td>1</td><td>4,25 lei</td><td>4,25 lei</td></tr>
    <tr><td>Module relais 5V</td><td>1</td><td>6,55 lei</td><td>6,55 lei</td></tr>
    <tr><td>Bouton poussoir à verrouillage</td><td>1</td><td>0,95 lei</td><td>0,95 lei</td></tr>
    <tr><td>Plaque d'essai 400 points (breadboard)</td><td>1</td><td>6,37 lei</td><td>6,37 lei</td></tr>
    <tr><td>Régulateur de tension LM7805</td><td>1</td><td>2,03 lei</td><td>2,03 lei</td></tr>
    <tr><td>Barrette de broches mâles 2.54</td><td>1</td><td>2,02 lei</td><td>2,02 lei</td></tr>
    <tr><td>Barrette de broches femelles 2.54</td><td>1</td><td>1,00 lei</td><td>1,00 lei</td></tr>
    <tr><td>Connecteur PCB 2 broches 5mm</td><td>1</td><td>1,21 lei</td><td>1,21 lei</td></tr>
    <tr><td>40 câbles Dupont M-M 10 cm</td><td>1</td><td>7,60 lei</td><td>7,60 lei</td></tr>
    <tr><td>Support pour capteur ultrasons HC-SR04</td><td>3</td><td>4,95 lei</td><td>14,85 lei</td></tr>
    <tr><td>40 câbles Dupont F-M 30 cm</td><td>1</td><td>7,94 lei</td><td>7,94 lei</td></tr>
    <tr><td>Plaque PCB prototype 7x9</td><td>1</td><td>6,21 lei</td><td>6,21 lei</td></tr>
    <tr><td>Support accumulateur 18650 1S</td><td>3</td><td>1,71 lei</td><td>5,13 lei</td></tr>
    <tr><td>Afficheur LCD 1602 rétroéclairé</td><td>1</td><td>11,00 lei</td><td>11,00 lei</td></tr>
    <tr><td>Interrupteur KCD11 2 broches</td><td>1</td><td>0,62 lei</td><td>0,62 lei</td></tr>
    <tr><td>Plaque PCB prototype 9x15</td><td>1</td><td>10,03 lei</td><td>10,03 lei</td></tr>
    <tr><td>Tuyau 6x8mm pour pompe à eau</td><td>1</td><td>6,26 lei</td><td>6,26 lei</td></tr>
    <tr><td>Barrette femelle 2.54 (x3)</td><td>3</td><td>1,00 lei</td><td>3,00 lei</td></tr>
    <tr><td>Barrette mâle 2.54 (x2)</td><td>2</td><td>2,02 lei</td><td>4,04 lei</td></tr>
    <tr><td>Driver Moteur</td><td>1</td><td>11 lei</td><td>11 lei</td></tr>
    <tr><td>Tête de serpillière rotative</td><td>1</td><td>-</td><td>-</td></tr>
    <tr><td>Petite bouteille d'eau (réservoir) - 200 ml</td><td>1</td><td>-</td><td>-</td></tr>
  </tbody>
</table>


## Diagramme fonctionnel (block diagram)

```text
           +--------------------+
           |    Batterie 12V    |
           +---------+----------+
                     |
                +----v----+
                | L293N    |<-------------+----------------+
                | Motor    |              |                |
                | Driver   |          +---v---+        +---v---+
                +----+-----+          | Moteur|        | Moteur|
                     |                | gauche|        | droit |
                     |                +-------+        +-------+
                     |
               +-----v------+
               | Arduino    |
               | Nano       |
               +------------+
              /   |   |   \  
             /    |   |    \ 
   +--------v+ +--v--+ +--v--+ +--------v--------+
   | Capteur | |Captr| |Captr| |   Pin Sortie    |
   | gauche  | |milieu| |droite| | vers relais    |
   +---------+ +------+ +------+ +--------+--------+
                                         |
                                    +----v----+
                                    | Relais   |
                                    |  5V      |
                                    +----+-----+
                                         |
                                    +----v----+
                                    | Pompe    |
                                    |  12V     |
                                    +---------+
```

# Cleaning Robot Project

## Libraries

| **Library**        | **Description**                               | **Usage**                                                                                     |
|--------------------|-----------------------------------------------|-----------------------------------------------------------------------------------------------|
| **NewPing**        | Library for interfacing ultrasonic sensors    | Used for measuring distance with ultrasonic sensors.                                          |
| **LiquidCrystal**  | Library for interfacing LCD screens (optional)           | Used to display information (like distance readings or status messages) on an LCD screen.     |

---

## Log

| **Week**           | **Date Range**  | **Summary**                                                                                               |
|--------------------|-----------------|-----------------------------------------------------------------------------------------------------------|
| **Week 6**         | 6 - 12 May      | Initial setup of robot and hardware configuration. Testing basic motor movements and manual control mode. |
| **Week 7**         | 13 - 19 May     | Developed automatic mode logic based on ultrasonic sensor readings. Added basic obstacle avoidance.       |
| **Week 20**        | 20 - 26 May     | Fine-tuned motor control and obstacle detection. Completed final tests for manual and automatic modes.   |

---

## Code Overview

### Pin Initialization

- **Ultrasonic Sensors:**
  - `echo_L`, `trig_L`: Left sensor pins.
  - `echo_M`, `trig_M`: Middle sensor pins.
  - `echo_R`, `trig_R`: Right sensor pins.
  
- **Motor Control:**
  - `L1`, `L2`, `R1`, `R2`: Motor control pins (for controlling the left and right motors).
  
- **Button and Pump:**
  - `button`: Pin for switching between manual and automatic modes.
  - `pump`: Pin for controlling a water pump or spray mechanism.

### Motor Control

- The robot uses two motors to move forward, backward, left, and right. Speed is controlled using PWM signals (range from 125 to 255).
- `motor_speed`: Variable to set the motor speed.

### Manual Mode

- In **manual mode**, the robot listens for serial commands to control movement and the pump via Bluetooth.
- Commands include:
  - `F`: Move forward
  - `B`: Move backward
  - `L`: Turn left
  - `R`: Turn right
  - `S`: Stop
  - `P`: Turn on the pump
  - `p`: Turn off the pump
  - `1`, `2`, `3`: Set motor speed

### Automatic Mode

- The robot uses three ultrasonic sensors to detect obstacles.
- If the middle sensor detects an obstacle (distance less than 20 cm), the robot will attempt to avoid it by turning left or right, depending on the available space.
- The robot moves forward if no obstacles are detected.

### Sensor Readings

- Distance measurements are performed using the `ping_cm()` function from the `NewPing` library for each of the three ultrasonic sensors.
