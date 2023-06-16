#ifndef __DINPUT_HORIDIVAPS4_H__
#define __DINPUT_HORIDIVAPS4_H__
#include <psp2kern/ctrl.h>
#include "dpad_angle.h"

uint8_t horiDivaps4_processReport(Controller *c, size_t length)
{
    process_dpad_angle(c, 5);

    if (bit(c->buffer+5, 7))
      c->controlData.buttons |= SCE_CTRL_TRIANGLE;
    if (bit(c->buffer+5, 6))
      c->controlData.buttons |= SCE_CTRL_CIRCLE;
    if (bit(c->buffer+5, 5))
      c->controlData.buttons |= SCE_CTRL_CROSS;
    if (bit(c->buffer+5, 4))
      c->controlData.buttons |= SCE_CTRL_SQUARE;

    if (bit(c->buffer+6, 0))
      c->controlData.buttons |= SCE_CTRL_L1;
    if (bit(c->buffer+6, 1))
      c->controlData.buttons |= SCE_CTRL_R1;

    if (bit(c->buffer + 6, 6))
      c->controlData.buttons |= SCE_CTRL_L3;
    if (bit(c->buffer + 6, 7))
      c->controlData.buttons |= SCE_CTRL_R3;

    if (bit(c->buffer+6, 2))
    {
      c->controlData.buttons |= SCE_CTRL_LTRIGGER;
      c->controlData.lt = c->buffer[8];
    }

    if (bit(c->buffer+6, 3))
    {
      c->controlData.buttons |= SCE_CTRL_RTRIGGER;
      c->controlData.rt = c->buffer[9];
    }

    if (bit(c->buffer + 6, 5))
      c->controlData.buttons |= SCE_CTRL_START;
    if (bit(c->buffer + 6, 4))
      c->controlData.buttons |= SCE_CTRL_SELECT;

    if (bit(c->buffer + 7, 0))
      c->controlData.buttons |= SCE_CTRL_PSBUTTON;

    c->controlData.leftX  = c->buffer[1];
    c->controlData.leftY  = c->buffer[2];

    c->controlData.rightX = c->buffer[3];
    c->controlData.rightY = c->buffer[4];

    return 1;
}

#endif
