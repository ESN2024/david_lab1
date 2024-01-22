# Introduction
L'objectif de ce TP est de faire un introduction à la conception conjointe comprenant un FPGA et un Processeur Logiciel (Soft Processing System, ou SPS) Nios2.

Un SPS est une description de la manière dont il faut câbler un FPGA pour qu'il contienne un processeur. Cette description VHDL ou Verilog nous est transparente et nous nous conterons de gérer ses périphériques.

Nous allons lors de ce premier TP tout d'abord créer un système minimal contenant un Nios2 et une LED en tant que périphérique, et le processeur devra la faire clignoter à partir d'un code C.

Dans un second temps nous allons coder un chenillard sur 10 LEDs. Ensuite, nous instancierons un Bouton-Poussoir (BP) en tant que deuxième périphérique, l'allumage du chenillard sera contrôlé par ce BP avec gestion d'interruption.

Enfin, nous allons intancier comme périphériques au Nios2 les 10 SWitchs (SW) de la carte, 4 d'entre eux nous servirons à faire la gestion de la vistesse du chenillard sur 4 bits (16 vitesses différentes) en code C.

# 1. Description du système
Le système est schématisé figure 1. Dans ce schéma nous pouvons trouver le Nios2, sa mémoire RAM, un JTAG UART qui permettra avec le BLASTER USB de téléverser notre code C et de debug sur console avec *le Nios2 command shell* et le programme *nios2-terminal*. Nous trouvons aussi un bus Avalon pour assuer la communication ainsi que 3 PIOs qui permettront de contrôler les interfaces utilisateur de la carte.
![image](https://github.com/ESN2024/david_lab1/assets/124572489/d0f4dc68-929b-4e74-b47d-84d8fc66b83c)
*Figure 1. Schéma de principe du système minimal.*

Les autres choses importantes à remarquer sont les différentes régions : la région blanche correspond à ce qui est câblé en Hardware sur la carte de développement. la région verte correspond quand à elle à ce qui est câblé sur le FPGA en HDL. Enfin, la partie bleue correspond à ce qui a été intancié par Qsys, nous avons utilisé ici des blocs IP (Intellectual Property) qui sont des descriptions VHDL de systèmes HDL complexes et fiables, comme notre Nios2.

Pour finir sur la figure 1, il reste à décrire les différents outils qui ont été utilisés pour réaliser ce système. Commençons par le plus large pour zoomer en profondeur. Tout d'abord, la carte : nous nous sommes servis de la carte de développement DE10 Lite, nous nous sommes donc équipés de sa *Datasheet*. Se trouve ensuite le FPGA : pour câbler le FPGA, nous utilisons *Quartus* et nous programmons en *HDL*. La gestion des interfaces entre ces deux régions se fait sur l'outil *Pin Planner* de Quartus. Nous avons enfin utilisé l'outil *Platform Designer* pour intancier les blocs IP qui nous intéressaient. L'interface entre ces deux régions se faire par programmation HDL sous Quartus.
