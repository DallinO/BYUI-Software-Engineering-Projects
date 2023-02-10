using System;

public class Reference
{
    private string _reference;
    private string _book;
    private string _chapter;
    private string _verse1;
    private string _verse2;

    public Reference(string verse1)
    {
        _verse1 = verse1;
        _verse2 = null;
    }
    public Reference(string verse1, string verse2)
    {
        _verse1 = verse1;
        _verse2 = verse2;
    }

    public string GetReference()
    {
        if (_verse2 != null)
        {
            _reference = $"{_book} {_chapter}:{_verse1}-{_verse2}";
        }
        else
        {
            _reference = $"{_book} {_chapter}:{_verse1}";
        }
        return _reference;
    }


}
