using System;

class Reference
{
    private string book, chapter, verse;

    public Reference (string _book, string _chapter, string _verse)
    {
        book = _book;
        chapter = _chapter;
        verse = _verse;
    }

    public string toString()
    {
        return string.Format("{0} {1}:{2}", book, chapter, verse);
    }
}