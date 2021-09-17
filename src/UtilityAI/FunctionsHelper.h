// Created by Quentin Pamart on 16/09/2021.
#pragma once

/**
 * Some functions to test
 */


/**
 * Linear curve
 * @param x
 * @param max
 * @return
 */
float ratioLinear(int x, int max){
    return 1 - (float) x / (float) max;
}

/**
 * Square root curve
 * @param x
 * @param max
 * @return
 */
float ratioSqrt(int x, int max){
    return 1 - sqrt((float)x / (float)max);
}

/**
 * Square curve
 * @param x
 * @param max
 * @return
 */
float ratioSq(int x, int max){
    return 1 - pow((float)x / (float)max, 2);
}