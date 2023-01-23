using System;

class scriptureMemorizer
{
    private Scripture scripture;
    private List<string> scriptureTextList;
    bool retvalue = false;

    public scriptureMemorizer(Scripture _scripture)
    {
        scripture = _scripture;
        scriptureTextList = new List<string>();
        convertTextToList();
    }

    private void convertTextToList()
    {
        scriptureTextList = scripture.toString().Split(' ').ToList();
    }

    public void removeWordsFromText()
    {
        int numWordsToRemove = new Random().Next(3, 4);
        int wordsRemoved = 0;

        do
        {
            int rndIndex = new Random().Next(0, scriptureTextList.Count());
            if (scriptureTextList[rndIndex].Contains('_') == false)
            {   scriptureTextList[rndIndex] = new string('_', scriptureTextList[rndIndex].Length);
                wordsRemoved++;
            }
        } while (wordsRemoved != numWordsToRemove);
        
    }

    public string toString()
    {
        return string.Join(' ', scriptureTextList);
    }

    public bool hasWordsLeft()
    {
        foreach (string word in scriptureTextList)
        {
            if (word.Contains('_') == false)
            {
                retvalue = true;
                break;
            }
            else
            {
                retvalue = false;
            }
        }

        return retvalue;
    }
}