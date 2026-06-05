# Write your MySQL query statement bel
#SELECT POPULATION,gdp from world;
#select name,population,area from world where population>25000000 and area>3000000;
SELECT name,population,area FROM world WHERE population >= 25000000 or area >= 3000000;
