-- File:    Tplot.hs
-- Date:    may 2023
-- Coms:    Fichero Tplot.hs de la práctica 5 de la asignatura Tecnología de Programación. 

module Tplot where

import Turtle
import Data.Char

tplot :: Turtle -> String -> [Position]
tplot (paso,giro,(x,y),orn) [] = [(x,y)]    --coordenadas
tplot (paso,giro,(x,y),orn) (s:ms)  --secuencia
    | s == '>' = (x,y) : tplot(moveTurtle(paso,giro,(x,y),orn) Forward) ms
    | s == '+' = (x,y) : tplot(moveTurtle(paso,giro,(x,y),orn) TurnRight) ms
    | s == '-' = (x,y) : tplot(moveTurtle(paso,giro,(x,y),orn) TurnLeft) ms
    | s == 'F' = (x,y) : tplot(moveTurtle(paso,giro,(x,y),orn) Forward) ms
    | s == 'G' = (x,y) : tplot(moveTurtle(paso,giro,(x,y),orn) Forward) ms
    | isUpper s = (x,y) : tplot(moveTurtle(paso,giro,(x,y),orn) Forward) ms
    | otherwise = tplot(moveTurtle(paso,giro,(x,y),orn) Forward) ms
    
