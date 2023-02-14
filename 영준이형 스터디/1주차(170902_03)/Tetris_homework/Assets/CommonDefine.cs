using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public enum MOVE_ARROW
{
    LEFT,
    RIGHT,
    DOWN,
    ROTATE,
    MAX
}

public enum BLOCK_TYPE
{
    T,
    I,
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

public static class CommonDefine
{
    public static int MAX_BACKGROUND_WIDTH = 10;
    public static int MAX_BACKGROUND_HEIGHT = 16;

    public static float BLOCK_SIZE = 40f;
    public static float BLOCK_RANGE = 0.0625f;

    public static float DEFAULT_MOVE_TIME = 0.25f;
    //public static float DEFAULT_MOVE_TIME = 100000.25f;
}
