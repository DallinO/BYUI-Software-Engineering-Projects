using System;

public class Word
{
    
    private string _word;
    private bool _isHidden;

    public Word(string word)
    {
        _word = word;
        _isHidden = false;
    }

    public void Set_IsHidden(bool isHidden)
    {
        _isHidden = isHidden;
    }
    public bool Get_IsHidden()
    {  
        return _isHidden;
    }

    public void DisplayWord()
    {
        if (_isHidden == true)
        {
            foreach (char letter in _word)
            {
                Console.Write("_");
            }
        }
        else
        {
            Console.Write(_word);
        }
    }
}
