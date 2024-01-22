# lab_1

Introduction
L'objectif de ce TP est de faire un introduction à la conception conjointe comprenant un FPGA et un Processeur Logiciel (Soft Processing System, ou SPS) Nios2.
Un SPS est une description de la manière dont il faut câbler un FPGA pour qu'il contienne un processeur. Cette description VHDL ou Verilog nous est transparente et nous nous conterons de gérer ses périphériques.
Nous allons lors de ce premier TP tout d'abord créer un système minimal contenant un Nios2 et une LED en tant que périphérique, et le processeur devra la faire clignoter à partir d'un code C.
Dans un second temps nous allons coder un chenillard sur 10 LEDs. Ensuite, nous instancierons un Bouton-Poussoir (BP) en tant que deuxième périphérique, l'allumage du chenillard sera contrôlé par ce BP avec gestion d'interruption.
Enfin, nous allons intancier comme périphériques au Nios2 les 10 SWitchs (SW) de la carte, 4 d'entre eux nous servirons à faire la gestion de la vistesse du chenillard sur 4 bits (16 vitesses différentes) en code C.




