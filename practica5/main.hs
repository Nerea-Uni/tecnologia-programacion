-- File:    main.hs
-- Date:    may 2023
-- Coms:    Fichero main.hs de la práctica 5 de la asignatura Tecnología de Programación. 

import SVG(savesvg)
import Turtle
import Tplot
import Lsystems

main = do 
    --Parte 1: Gráficos de Logo. Tortuga.
    let cuadrado = tplot (1,90,(0,0),90) ">+>+>+>+"
    let triangulo = tplot (1,120,(0,0),0) ">+>+>+"
    let circulo = tplot (1,1,(0,0),0) ">+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+"

    savesvg "cuadrado" cuadrado
    savesvg "triangulo" triangulo
    savesvg "circulo" circulo


    --Parte 2: Sistemas de Lindenmayer. L-Systems.
    let ck  = tplot (1,60,(0,0),0) (lsystem rulesKock "F" 3)
    let ckc = tplot (1,90,(0,0),0) (lsystem rulesKockC "F" 3)
    let ks  = tplot (1,60,(0,0),0) (lsystem rulesSnowflake "F++F++F" 3)
    let kas = tplot (1,60,(0,0),180) (lsystem rulesAntiSnowflake "F++F++F" 6)
    let im  = tplot (1,90,(0,0),0) (lsystem rulesIsla "F+F+F+F" 2)
    let ts  = tplot (1,120,(0,0),180) (lsystem rulesTriangulo "F-G-G" 4)
    let sa  = tplot (1,60,(0,0),0) (lsystem rulesArrowhead "F" 6)
    let ch  = tplot (1,90,(0,0),180) (lsystem rulesHilbert "f" 4)
    let cg  = tplot ((-1),(-60),(0,0),(-140)) (lsystem rulesGosper "F" 3)

    savesvg "Curva de Koch" ck
    savesvg "Curva de Koch cuadrada" ckc
    savesvg "Koch Snowflake" ks
    savesvg "Koch Anti-Snowflake" kas
    savesvg "Isla de Minkowski" im
    savesvg "Triangulo de Sierpinsky" ts
    savesvg "Sierpinsky Arrowhead" sa
    savesvg "Curva de Hilbert" ch
    savesvg "Curva de Gosper" cg
