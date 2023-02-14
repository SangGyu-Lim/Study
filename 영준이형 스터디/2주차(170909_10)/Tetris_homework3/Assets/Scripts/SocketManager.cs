using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using SocketIOClient;
using System;
using LitJson;

public class SocketManager : MonoBehaviour {

    #region SingleTon

    public static SocketManager instance = null;

    private void Awake()
    {
        if (instance == null)
        {
            instance = this;
        }
    }

    #endregion

    //string url = "http://127.0.0.1:999/";
    string url = "http://192.168.0.10:999/";
    public Client Socket { get; private set; }

    #region Socket EventHandler
    private void SocketOpened(object sender, EventArgs e)
    {
        Debug.Log("Socket Connected!");
    }
    private void SocketMessage(object sender, MessageEventArgs e)
    {
        Debug.Log(e.Message);
    }
    private void SocketConnectionClosed(object sender, EventArgs e)
    {
        Debug.Log("Socket Closed!");
    }
    private void SocketError(object sender, ErrorEventArgs e)
    {
        Debug.Log(e.Message);
    }
#endregion

    private void OnDisable()
    {
        Socket.Close();
    }

    void Start()
    {
        
    }

    public void StartMulti()
    {
        Socket = new Client(url);
        Socket.Opened += SocketOpened;
        Socket.Message += SocketMessage;
        Socket.SocketConnectionClosed += SocketConnectionClosed;
        Socket.Error += SocketError;
        Socket.Connect();

        Socket.On("USER_CONNECTED", OnUserConnected);
        Socket.On("USER_READY", OnUserReady);
        Socket.On("GAME_START", OnGameStart);
        Socket.On("UPDATE_BLOCK", OnUpdateBlock);
        Socket.On("GAME_OVER", OnGameOver);

        StartCoroutine(ConnectToServer());
    }

    public void EndMulti()
    {
        Socket.Close();
    }

    IEnumerator ConnectToServer()
    {
        yield return new WaitForSeconds(0.5f);

        Dictionary<string, string> data = new Dictionary<string, string>();
        data["name"] = "test";

        string str = JsonMapper.ToJson(data);
        Socket.Emit("USER_CONNECT", str);

        yield return new WaitForSeconds(0.5f);

        Socket.Emit("USER_READY", null);

        yield return new WaitForSeconds(0.5f);

        Socket.Emit("CHECK_MULTI", null);
    }

    public void UpdateBlock()
    {
        Dictionary<string, BACKGROUND_PIECE_TYPE> data = new Dictionary<string, BACKGROUND_PIECE_TYPE>();

        for (int i = 0; i < CommonDefine.MAX_BACKGROUND_WIDTH; ++i)
        {
            for (int j = 0; j < CommonDefine.MAX_BACKGROUND_HEIGHT; ++j)
            {
                data[string.Format("{0},{1}", i, j)] = UIBackgroundManager.instance.GetCurrentBlockType(i, j);
            }
        }

        string str = JsonMapper.ToJson(data);
        Socket.Emit("UPDATE_BLOCK", str);
    }

    public void CallGameOver()
    {
        Socket.Emit("GAME_OVER", null);
    }

#region SocketOn
    void OnUserConnected(SocketIOClient.Messages.IMessage e)
    {
        Debug.LogWarning("OnUserCoConnected");
        Debug.Log("get the message from server is" + e.MessageText);

        string temp = e.Json.args[0].ToString();
        Dictionary<string, string> data = new Dictionary<string, string>();
        data = JsonMapper.ToObject<Dictionary<string, string>>(temp);

        Debug.Log(string.Format("{0}", data["id"]));

    }

    void OnUserReady(SocketIOClient.Messages.IMessage e)
    {
        Debug.LogWarning("OnUserReady");
        Debug.Log("get the message from server is" + e.MessageText);

        string temp = e.Json.args[0].ToString();
        Dictionary<string, string> data = new Dictionary<string, string>();
        data = JsonMapper.ToObject<Dictionary<string, string>>(temp);

        Debug.Log(string.Format("{0}", data["id"]));
    }

    void OnGameStart(SocketIOClient.Messages.IMessage e)
    {
        Debug.LogWarning("OnGameStart");

        GameManager.instance.CallGameStart();
    }

    void OnUpdateBlock(SocketIOClient.Messages.IMessage e)
    {
        Debug.LogWarning("OnUpdateBlock");

        string temp = e.Json.args[0].ToString();
        Dictionary<string, BACKGROUND_PIECE_TYPE> data = new Dictionary<string, BACKGROUND_PIECE_TYPE>();
        data = JsonMapper.ToObject<Dictionary<string, BACKGROUND_PIECE_TYPE>>(temp);

        for (int i = 0; i < CommonDefine.MAX_BACKGROUND_WIDTH; ++i)
        {
            for (int j = 0; j < CommonDefine.MAX_BACKGROUND_HEIGHT; ++j)
            {
                UIBackgroundManager.instance.UpdateOtherPlayerGameBlock(i, j, data[string.Format("{0},{1}", i, j)]);
            }
        }
    }

    void OnGameOver(SocketIOClient.Messages.IMessage e)
    {
        Debug.LogWarning("OnGameOver");

        GameManager.instance.CallGameOver();
    }

    #endregion

}
