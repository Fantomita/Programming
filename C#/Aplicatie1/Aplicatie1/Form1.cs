using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Aplicatie1
{
    public partial class Form1 : Form
    {
        int m = 0, s = 0, nr = 0, ok, x = 0;
        Random rnd = new Random();
        int[] v = new int[5];
        Image[] img = new Image[5];
        public Form1()
        {
            InitializeComponent();
            timer1.Start();
            for (int i = 1; i <= 4; ++i)
            {
                do
                {
                    v[i] = rnd.Next(4) + 1;
                    ok = 1;
                    for (int j = 1; j < i; ++j)
                        if (v[i] == v[j])
                            ok = 0;
                } while (ok == 0);
            }
            img[1] = Image.FromFile("mar.jfif");
            img[4] = Image.FromFile("mar.jfif");
            img[2] = Image.FromFile("para.jpg");
            img[3] = Image.FromFile("para.jpg");
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            nr++;
            if (nr % 2 == 1)
            {
                pictureBox1.Image = img[v[1]];
                x = v[2];
            }
            else
            {
                nr = 0;
                if (x == v[4])
                {
                    pictureBox1.Visible = false;
                    pictureBox4.Visible = false;
                }
                else
                {
                    pictureBox1.Image = null;
                    pictureBox4.Image = null;
                }
            }
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            nr++;
            if (nr % 2 == 1)
                pictureBox2.Image = img[v[2]];
        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {
            nr++;
            if (nr % 2 == 1)
                pictureBox3.Image = img[v[3]];
        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {
            nr++;
            if (nr % 2 == 1)
                pictureBox4.Image = img[v[4]];
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            s++;
            m = m + (s / 60);
            s = s % 60;
            if (m <= 9)
                if (s <= 9)
                    label2.Text = "0" + m.ToString() + " : 0" + s.ToString();
                else
                    label2.Text = "0" + m.ToString() + " : " + s.ToString();
            else
                if (s <= 9)
                    label2.Text = m.ToString() + " : 0" + s.ToString();
            else
                label2.Text = m.ToString() + " : " + s.ToString();
        }
    }
}
