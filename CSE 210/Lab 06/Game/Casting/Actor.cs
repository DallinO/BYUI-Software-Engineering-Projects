using System.Collections.Generic;
using Unit05.Game.Casting;
using Raylib_cs;

namespace Unit05.Game.Casting
{
    public class Actor
    {
        private string text = "";
        private int fontSize = Constants.FONT_SIZE;
        Color color = Constants.WHITE;
        private Point position = new Point(0, 0);
        private Point velocity = new Point(0, 0);

        public Actor()
        {
        }

        public virtual void MoveNext()
        {
            int x = ((position.GetX() + velocity.GetX()) + Constants.MAX_X) % Constants.MAX_X;
            int y = ((position.GetY() + velocity.GetY()) + Constants.MAX_Y) % Constants.MAX_Y;
            position = new Point(x, y);
        }

        public void SetColor(Color color)
        {
            this.color = color;
        }

        public void SetFontSize(int fontSize)
        {
            this.fontSize = fontSize;
        }

        public void SetPosition(Point position)
        {
            this.position = position;
        }

        public void SetText(string text)
        {
            this.text = text;
        }

        public void SetVelocity(Point velocity)
        {
            this.velocity = velocity;
        }

        public Color GetColor()
        {
            return color;
        }

        public int GetFontSize()
        {
            return fontSize;
        }

        public Point GetPosition()
        {
            return position;
        }

        public string GetText()
        {
            return text;
        }

        public Point GetVelocity()
        {
            return velocity;
        }
    }
}