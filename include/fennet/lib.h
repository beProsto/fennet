/**
 * @file lib.h
 * @brief Main library file.
 */

#pragma once

#include "api.h"

/**
 * @brief Not
 *
 * Same as false.
 */
#define NAH 0
/**
 * @brief Yes
 *
 * Same as true.
 */
#define YUP 1

/**
 * @brief Tells me if i'm boring or not.
 *
 * Returns NAH if i'm not boring or YUP if i am boring.
 *
 * @return int
 */
int FEN_API
doesItLookLikeImBoring();