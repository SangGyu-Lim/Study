using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NetworkManager : MonoBehaviour
{
    #region Singleton
    private static NetworkManager _instance;
    public static NetworkManager instance
    {
        get
        {
            if (_instance == null)
            {
                _instance = UnityEngine.Object.FindObjectOfType(typeof(NetworkManager)) as NetworkManager;

                GameObject go = new GameObject("NetworkManager");
                DontDestroyOnLoad(go);
                _instance = go.AddComponent<NetworkManager>();

            }

            return _instance;
        }
    }
    private void Awake()
    {
        _instance = this;
    }
    #endregion

    string url = "http://localhost:1337";
    //string url = "http://localhost:1337/?id=wwforever&password=cocos2dx";

    // 서버 호출할 api(서버단에 물어보면 됨.), 통신 성공시 callback 함수, 통신 실패시 callback 함수, 서버에 보낼 파라미터를 차례로 넣어줄것.(Dictionary의 경우 <int, string>형태로 넣어줄것.)
    public void Call()
    {
        StartCoroutine(CallRequest());
    }


    Dictionary<string, object> dic = new Dictionary<string, object>();
    IEnumerator CallRequest()
    {
        
        WWWForm form = new WWWForm();
        form.AddField("id", 17);
        /*form.AddField("api", api);

        int index = 0;

        Debug.LogError("add www field");
        // 필드 추가
        for (int i = 0; i < param.Length; ++i)
        {
            bool isDictionary = param[i].GetType().IsGenericType;

            if (isDictionary)
            {
                Dictionary<int, string> dt = (Dictionary<int, string>)param[i];

                for (int j = 0; j < dt.Count; ++j)
                {
                    form.AddField(string.Format("param{0}", ++index), dt[j]);
                    Debug.Log(dt[j]);
                }
            }
            else
            {
                form.AddField(string.Format("param{0}", ++index), param[i].ToString());
                Debug.Log(param[i]);
            }
        }
        */
        Debug.LogError("before return www");
        byte[] postData = form.data;
        //WWW www = new WWW(url);
        //WWW www = new WWW(url, form);
        WWW www = new WWW(url, postData);


        yield return www;

        Debug.LogError("after return www");
        // 통신 성공
        if (www.error == null && www.isDone)
        {
            Debug.LogError(www.text);

            
        }
        else
        {
            Debug.Log(www.text);
            Debug.Log("www error : " + www.error);

            
        }

    }
}