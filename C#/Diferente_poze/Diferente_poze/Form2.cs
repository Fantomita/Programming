using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Diferente_poze
{
    public partial class Form2 : Form
    {
        int nr = 0, ok1 = 0, ok2 = 0, ok3 = 0, ok4 = 0, ok5 = 0, n = 5, t = 10;
        public Form2()
        {
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            label2.Text = "Time left: " + t.ToString();
            t--;
            if (t < 0 && nr < n)
            {
                label1.Left -= 80;
                label1.Text = "You lost! Try again!";
                timer1.Stop();
            }    
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form1 f = new Form1();
            f.Show();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            if (ok1 == 1 || t < 0)
                return;
            pictureBox1.Image = Image.FromFile("d1.png");
            nr++;
            label1.Text = nr.ToString() + " / 5";
            ok1 = 1;

            if (nr == n)
            {
                label1.Left -= 80;
                label1.Text = "You won! Congrats!";
                timer1.Stop();
            }
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            if (ok2 == 1 || t < 0)
                return;
            pictureBox2.Image = Image.FromFile("d2.png");
            nr++;
            label1.Text = nr.ToString() + " / 5";
            ok2 = 1;

            if (nr == n)
            {
                label1.Left -= 80;
                label1.Text = "You won! Congrats!";
                timer1.Stop();
            }
        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {
            if (ok3 == 1 || t < 0)
                return;
            pictureBox3.Image = Image.FromFile("d3.png");
            nr++;
            label1.Text = nr.ToString() + " / 5";
            ok3 = 1;

            if (nr == n)
            {
                label1.Left -= 80;
                label1.Text = "You won! Congrats!";
                timer1.Stop();
            }
        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {
            if (ok4 == 1 || t < 0)
                return;
            pictureBox4.Image = Image.FromFile("d4.png");
            nr++;
            label1.Text = nr.ToString() + " / 5";
            ok4 = 1;

            if (nr == n)
            {
                label1.Left -= 80;
                label1.Text = "You won! Congrats!";
                timer1.Stop();
            }
        }

        private void pictureBox5_Click(object sender, EventArgs e)
        {
            if (ok5 == 1 || t < 0)
                return;
            pictureBox5.Image = Image.FromFile("d5.png");
            nr++;
            label1.Text = nr.ToString() + " / 5";
            ok5 = 1;

            if (nr == n)
            {
                label1.Left -= 80;
                label1.Text = "You won! Congrats!";
                timer1.Stop();
            }
        }
    }
}
