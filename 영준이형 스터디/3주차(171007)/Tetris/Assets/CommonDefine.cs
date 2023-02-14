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
    public static float CREATE_BACKGROUND_MOVE_POSITION = -82f;

    public static float BLOCK_SIZE = 40f;

    public static float DEFAULT_MOVE_TIME = 0.6f;
    public static float FALL_DIRECTLY_MOVE_TIME = 0.001f;
    
    public static float DEFAULT_DOWN_ADD_SPEED_TIME = 0.0f;
    public static float DOWN_ADD_SPEED_TIME = 0.3f;

    public static int BLOCK_START_Y_POSITION = -2;

    public static float LEVEL_UP_SECOND = 10f;//10초마다 레벨업.
    public static int MAX_GAME_LEVEL = 10; //최대레벨

    public static float LEVEL_UP_SPEED_RATIO = 0.5f;//레벨업당 증가되는 속도.
    public static int DELETE_ONEROW_SCORE = 10;//한줄당 증가 스코어
}
