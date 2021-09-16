// Created by Quentin Pamart on 16/09/2021.
#pragma once

/**
 * Some functions to test
 */

float maxRatio(int x, int max){
    return 1 - (float) x / (float) max;
}

float ratioSqrt(int x, int max){
    return 1 - sqrt((float)x / (float)max);
}