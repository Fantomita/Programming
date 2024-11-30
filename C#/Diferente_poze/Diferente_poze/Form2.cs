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
        int nr = 0, ok1 = 0, ok2 = 0, ok3 = 0, ok4 = 0, ok5 = 0, ok6 = 0, ok7 = 0, ok8 = 0, n = 8, t = 60;

        private void label2_Click(object sender, EventArgs e)
        {

        }

        public Form2()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void timer3_Tick(object sender, EventArgs e)
        {
            t--;
            if(t <= 0 && nr < n)
            {
                label1.Left -= 110;
                label1.Text = "Ati pierdut! Mai incearcati!";
                timer3.Stop();
                pictureBox1.Enabled = false;
                pictureBox2.Enabled = false;
                pictureBox3.Enabled = false;
                pictureBox4.Enabled = false;
                pictureBox5.Enabled = false;
            }
            label2.Text = "Timp ramas :" + t.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form1 f = new Form1();
            f.Show();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Image.FromFile("d1.png");
            if(ok1 == 0)
            {
                nr++;
                if (nr < n)
                    label1.Text = nr.ToString() + " / 8";
                else
                {
                    label1.Left -= 100;
                    label1.Text = "Ati castigat! Felicitari!";
                    timer1.Stop();
                }
                ok1 = 1;
            }
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            pictureBox2.Image = Image.FromFile("d2.png");
            if (ok2 == 0)
            {
                nr++;
                if (nr < n)
                    label1.Text = nr.ToString() + " / 8";
                else
                {
                    label1.Left -= 100;
                    label1.Text = "Ati castigat! Felicitari!";
                    timer1.Stop();
                }
                ok2 = 1;
            }
        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {
            pictureBox3.Image = Image.FromFile("d3.png");
            if (ok3 == 0)
            {
                nr++;
                if (nr < n)
                    label1.Text = nr.ToString() + " / 8";
                else
                {
                    label1.Left -= 100;
                    label1.Text = "Ati castigat! Felicitari!";
                    timer1.Stop();
                }
                ok3 = 1;
            }
        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {
            pictureBox4.Image = Image.FromFile("d4.png");
            if (ok4 == 0)
            {
                nr++;
                if (nr < n)
                    label1.Text = nr.ToString() + " / 8";
                else
                {
                    label1.Left -= 100;
                    label1.Text = "Ati castigat! Felicitari!";
                    timer1.Stop();
                }
                ok4 = 1;
            }
        }

        private void pictureBox5_Click(object sender, EventArgs e)
        {
            pictureBox5.Image = Image.FromFile("d5.png");
            if(ok5 == 0)
            {
                nr++;
                if (nr < n)
                    label1.Text = nr.ToString() + " / 8";
                else
                {
                    label1.Left -= 100;
                    label1.Text = "Ati castigat! Felicitari!";
                    timer1.Stop();
                }
                ok5 = 1;
            }
        }

        private void pictureBox6_Click(object sender, EventArgs e)
        {
            pictureBox6.Image = Image.FromFile("d6.png");
            if (ok6 == 0)
            {
                nr++;
                if (nr < n)
                    label1.Text = nr.ToString() + " / 8";
                else
                {
                    label1.Left -= 100;
                    label1.Text = "Ati castigat! Felicitari!";
                    timer1.Stop();
                }
                ok6 = 1;
            }
        }

        private void pictureBox7_Click(object sender, EventArgs e)
        {
            pictureBox7.Image = Image.FromFile("d7.png");
            if (ok7 == 0)
            {
                nr++;
                if (nr < n)
                    label1.Text = nr.ToString() + " / 8";
                else
                {
                    label1.Left -= 100;
                    label1.Text = "Ati castigat! Felicitari!";
                    timer1.Stop();
                }
                ok7 = 1;
            }
        }

        private void pictureBox8_Click(object sender, EventArgs e)
        {
            pictureBox8.Image = Image.FromFile("d8.png");
            if (ok8 == 0)
            {
                nr++;
                if (nr < n)
                    label1.Text = nr.ToString() + " / 8";
                else
                {
                    label1.Left -= 100;
                    label1.Text = "Ati castigat! Felicitari!";
                    timer1.Stop();
                }
                ok8 = 1;
            }
        }
    }
}
