using System;

public class Scripture
{

    private string _scripture = "";
    public List<Word> _wordList = new List<Word>();
    private Reference rfr;

    public Scripture(string reference, string scripture)
    {
        rfr = new Reference(reference);
        _scripture = scripture;
        string[] _wordListArray = _scripture.Split(" ");
        foreach (string word in _wordListArray)
        {

            Word wrd = new Word(word);
            _wordList.Add(wrd);
        }
    }

    public void DisplayWords()
    {
        foreach (Word word in _wordList)
        {
            word.DisplayWord();
            Console.Write(" ");
        }
    }

    public List<Word> GetVisableWords()
    {
        List<Word> _visibleWords = new List<Word>();
        foreach (Word word in _wordList)
        {
            if (word.Get_IsHidden() == false)
            {
                _visibleWords.Add(word);
            }
        }
        return _visibleWords;
    }

    public void Reset()
    {
        foreach(Word word in _wordList)
        {
            word.Set_IsHidden(false);
        }
    }

}