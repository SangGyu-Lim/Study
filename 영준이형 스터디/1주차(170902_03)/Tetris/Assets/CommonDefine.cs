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

public static class CommonDefine
{
    public static int MAX_BACKGROUND_WIDTH = 10;
    public static int MAX_BACKGROUND_HEIGHT = 16;

    public static float BLOCK_SIZE = 40f;

    public static float DEFAULT_MOVE_TIME = 0.5f;
}
