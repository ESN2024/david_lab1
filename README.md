# Introduction
L'objectif de ce TP est de faire un introduction à la conception conjointe comprenant un FPGA et un Processeur Logiciel (Soft Processing System, ou SPS) Nios2.
Un SPS est une description de la manière dont il faut câbler un FPGA pour qu'il contienne un processeur. Cette description VHDL ou Verilog nous est transparente et nous nous conterons de gérer ses périphériques.
Nous allons lors de ce premier TP tout d'abord créer un système minimal contenant un Nios2 et une LED en tant que périphérique, et le processeur devra la faire clignoter à partir d'un code C.
Dans un second temps nous allons coder un chenillard sur 10 LEDs. Ensuite, nous instancierons un Bouton-Poussoir (BP) en tant que deuxième périphérique, l'allumage du chenillard sera contrôlé par ce BP avec gestion d'interruption.
Enfin, nous allons intancier comme périphériques au Nios2 les 10 SWitchs (SW) de la carte, 4 d'entre eux nous servirons à faire la gestion de la vistesse du chenillard sur 4 bits (16 vitesses différentes) en code C.

# 1. Système minimal
## 1.1. Description du système
Le système est schématisé figure 1. Dans ce schéma nous pouvons trouver le Nios2, sa mémoire RAM, un JTAG UART qui permettra avec le BLASTER USB de téléverser notre code C et de debug sur console avec *le Nios2 command shell* et le programme *nios2-terminal*. Nous trouvons aussi un bus Avalon pour assuer la communication ainsi qu'un PIO qui permettra de contrôler la LED.
![image](https://github.com/ESN2024/david_lab1/assets/124572489/e36e06b1-84fb-40ae-963d-e981dee50f39)
*Figure 1. Schéma de principe du système minimal.*

