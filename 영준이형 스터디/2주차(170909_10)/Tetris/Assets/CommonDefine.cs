using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public enum BLOCK_TYPE
{
    I,
    T,
    L,
    J,
    S,
    Z,
    O,
    MAX
}

public enum STAGE_TYPE
{
    INTRO,
    GAME,
    MAX
}

public enum BACKGROUND_PIECE_TYPE
{
    BLANK,
    HOLD
}

public enum ARROW
{
    UP,
    DOWN,
    LEFT,
    RIGHT
}

public static class CommonDefine
{
    public static int MAX_BACKGROUND_WIDTH = 10;
    public static int MAX_BACKGROUND_HEIGHT = 16;

    public static float BLOCK_SIZE = 40f;

    public static float DEFAULT_MOVE_TIME = 0.6f;
    public static float FALL_DIRECTLY_MOVE_TIME = 0.001f;

    
    public static float DEFAULT_DOWN_ADD_SPEED_TIME = 0.0f;
    public static float DOWN_ADD_SPEED_TIME = 0.3f;

    public static int BLOCK_START_Y_POSITION = -2;
}
