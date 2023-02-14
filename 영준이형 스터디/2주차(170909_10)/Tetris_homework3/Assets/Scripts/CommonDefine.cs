using System.Collections;
using System.Collections.Generic;
using UnityEngine;

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
    WAIT,
    GAME,
    GAME_OVER,
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

    public static int MOVE_BACKGROUND_POSITION_X = -120;

    public static float BLOCK_SIZE = 40f;
    public static float OTHER_PLAYER_BLOCK_SIZE = 20f;

    public static float DEFAULT_MOVE_TIME = 0.6f;
    public static float FALL_DIRECTLY_MOVE_TIME = 0.001f;
    
    public static float DEFAULT_DOWN_ADD_SPEED_TIME = 0.0f;
    public static float DOWN_ADD_SPEED_TIME = 0.3f;

    public static int BLOCK_START_Y_POSITION = -2;

    public static int NEXT_BLOCK_POSITION_X = 11;
    public static int NEXT_BLOCK_POSITION_Y = 1;

    public static int DECREASE_ROW_SCORE = 10;

    public static int SECOND_TO_MINUTE_RATE_TIME = 60;

    public static int SPEED_UP_TIME = 30;
    public static float SPEED_UP_RATE = 0.5f;
}
