using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using System.IO;

public class gameManager : MonoBehaviour {

    public GameObject goblinObject;
    public GameObject monsterGeneratorObject;

    public Camera mainCamera;
    public Camera miniMapCamera;
    public Camera scoreCamera;

    public Text scoreText;
    int score = 0;
    public Text highScoreText;
    int highScore = 0;

    public Text timerText;

    const int MAX_TIMER = 60;
    int timer = 0;

    bool isScorePrint = true;

    const string fileName = "highscore.txt";

	// Use this for initialization
	void Start () {
        scoreCamera.gameObject.SetActive(false);
        highScoreText.text = "";
        
	}
	
	// Update is called once per frame
    void Update() {       

        // 뒤로가기 버튼 종료
        if (Application.platform == RuntimePlatform.Android)
        {
            if (Input.GetKey(KeyCode.Escape))
            {
                Application.Quit();
            }
        }       


        if (timer >= MAX_TIMER)
        {
            if (isScorePrint)
            {
                goblinObject.gameObject.GetComponent<goblin>().isContinue = false;
                monsterGeneratorObject.gameObject.GetComponent<monsterGenerator>().isContinue = false;
                monsterGeneratorObject.gameObject.GetComponent<monsterGenerator>().setIsContinue();

                mainCamera.gameObject.SetActive(false);
                miniMapCamera.gameObject.SetActive(false);

                scorePrint();
            }
            

            
        }
        else
        {
            timer = (int)Time.time;
            timerText.text = "Timer : " + timer.ToString();

            


            if (goblinObject.gameObject.GetComponent<goblin>().isCollision && monsterGeneratorObject.gameObject.GetComponent<monsterGenerator>().isCollision())
            {
                Debug.Log("gameManager collision");

                int hp = monsterGeneratorObject.gameObject.GetComponent<monsterGenerator>().getMonsterHp();
                hp -= goblinObject.gameObject.GetComponent<goblin>().attackPower;
                monsterGeneratorObject.gameObject.GetComponent<monsterGenerator>().setMonsterHp(hp);

                monsterGeneratorObject.gameObject.GetComponent<monsterGenerator>().setBackDir(goblinObject.gameObject.GetComponent<goblin>().getBackDir());

                if (hp <= 0)
                {
                    goblinObject.gameObject.GetComponent<goblin>().exp += monsterGeneratorObject.gameObject.GetComponent<monsterGenerator>().getMonsterExp();
                    goblinObject.gameObject.GetComponent<goblin>().updateGoblinInformation();

                    score = goblinObject.gameObject.GetComponent<goblin>().exp * 10;
                    scoreText.text = "Score : " + score.ToString();
                }
            }
        }        
	}

    void fileExistCheck()
    {
        string path = androidPathForDocumentsFile(fileName);

        if (!File.Exists(path))
        {
            

            Debug.Log("file not exist");
            FileStream fs = new FileStream(path, FileMode.Create);
            StreamWriter sw = new StreamWriter(fs);

            sw.Write(highScore.ToString());

            sw.Close();
            fs.Close();
        }
        else
        {
            Debug.Log("file exist");
        }
    }

    void fileLoad()
    {
        //StreamReader sr = new StreamReader(fileName);

        string path = androidPathForDocumentsFile(fileName);

        FileStream fs = new FileStream(path, FileMode.Open);
        StreamReader sr = new StreamReader(fs);
        
        highScore = int.Parse(sr.ReadLine());
        Debug.Log("high score(file load) : " + highScore.ToString());

        sr.Close();
        fs.Close();

    }

    void fileSave()
    {
        Debug.Log("high score(file save) : " + highScore.ToString());
        Debug.Log("score(file save) : " + score.ToString());

        string path = androidPathForDocumentsFile(fileName);
        if (score > highScore)
        {
            FileStream fs = new FileStream(path, FileMode.Create);
            StreamWriter sw = new StreamWriter(fs);

            sw.Write(score.ToString());

            sw.Close();
            fs.Close();
        }
    }

    void scorePrint()
    {
        fileExistCheck();
        fileLoad();
        fileSave();

        scoreCamera.gameObject.SetActive(true);
        timerText.text = "";
        highScoreText.text = "High Score : " + highScore.ToString();
        highScoreText.gameObject.SetActive(true);

        isScorePrint = false;
    }

    public string androidPathForDocumentsFile(string filename)
    {
        if (Application.platform == RuntimePlatform.Android)
        {
            string path = Application.persistentDataPath;
            path = path.Substring(0, path.LastIndexOf('/'));
            return Path.Combine(path, filename);
        }

        return "false";
    }

}
