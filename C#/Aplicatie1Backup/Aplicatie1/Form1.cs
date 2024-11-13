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
        int m = 0, s = 0, nr = 0, ok, x = 0, n = 4, tmax = 60, nrp = 0;
        Random rnd = new Random();
        int[] v = new int[5];
        Image[] img = new Image[5];
        public Form1()
        {
            InitializeComponent();
            timer1.Start();
            label3.Visible = false;
            label3.Text = "Ati pierdut!";
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

            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox2.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox3.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox4.SizeMode = PictureBoxSizeMode.StretchImage;

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
            this.Hide();
            Form2 f = new Form2();
            f.Show();
        }

        private async void pictureBox1_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = img[v[1]];
            nr++;
            //label1.Text = nr.ToString() + " " + x.ToString() + " " + v[1].ToString();
            if (nr % 2 == 1)
                x = v[1];
            else
            {
                await Task.Delay(500);
                nr = 0;
                if (x + v[1] == n + 1)
                {
                    pictureBox1.Visible = false;
                    if (x == v[2]) pictureBox2.Visible = false;
                    if (x == v[3]) pictureBox3.Visible = false;
                    if (x == v[4]) pictureBox4.Visible = false;
                    nrp += 2;
                    if (nrp == n)
                    {
                        label3.Text = "Ati castigat!";
                        label3.Visible = true;
                    }
                }
                else
                {
                    if (x == v[1]) { pictureBox1.Image = null; pictureBox1.BackColor = Color.LightBlue; }
                    if (x == v[2]) { pictureBox2.Image = null; pictureBox2.BackColor = Color.LightBlue; }
                    if (x == v[3]) { pictureBox3.Image = null; pictureBox3.BackColor = Color.LightBlue; }
                    if (x == v[4]) { pictureBox4.Image = null; pictureBox4.BackColor = Color.LightBlue; }
                    pictureBox1.Image = null;
                    pictureBox1.BackColor = Color.LightBlue;
                }
            }
        }

        private async void pictureBox2_Click(object sender, EventArgs e)
        {
            pictureBox2.Image = img[v[2]];
            nr++;
            //label1.Text = nr.ToString() + " " + x.ToString() + " " + v[2].ToString();
            if (nr % 2 == 1)
                x = v[2];
            else
            {
                await Task.Delay(500);
                nr = 0;
                if (x + v[2] == n + 1)
                {
                    pictureBox2.Visible = false;
                    if (x == v[1]) pictureBox1.Visible = false;
                    if (x == v[3]) pictureBox3.Visible = false;
                    if (x == v[4]) pictureBox4.Visible = false;
                    nrp += 2;
                    if (nrp == n)
                    {
                        label3.Text = "Ati castigat!";
                        label3.Visible = true;
                    }
                }
                else
                {
                    if (x == v[1]) { pictureBox1.Image = null; pictureBox1.BackColor = Color.LightBlue; }
                    if (x == v[2]) { pictureBox2.Image = null; pictureBox2.BackColor = Color.LightBlue; }
                    if (x == v[3]) { pictureBox3.Image = null; pictureBox3.BackColor = Color.LightBlue; }
                    if (x == v[4]) { pictureBox4.Image = null; pictureBox4.BackColor = Color.LightBlue; }
                    pictureBox2.Image = null;
                    pictureBox2.BackColor = Color.LightBlue;
                }
            }
        }

        private async void pictureBox3_Click(object sender, EventArgs e)
        {
            pictureBox3.Image = img[v[3]];
            nr++;
            //label1.Text = nr.ToString() + " " + x.ToString() + " " + v[3].ToString();
            if (nr % 2 == 1)
                x = v[3];
            else
            {
                await Task.Delay(500);
                nr = 0;
                if (x + v[3] == n + 1)
                {
                    if (x == v[1]) pictureBox1.Visible = false;
                    if (x == v[2]) pictureBox2.Visible = false;
                    if (x == v[4]) pictureBox4.Visible = false; 
                    pictureBox2.Visible = false;
                    pictureBox3.Visible = false;
                    nrp += 2;
                    if (nrp == n)
                    {
                        label3.Text = "Ati castigat!";
                        label3.Visible = true;
                    }
                }
                else
                {
                    if (x == v[1]) { pictureBox1.Image = null; pictureBox1.BackColor = Color.LightBlue; }
                    if (x == v[2]) { pictureBox2.Image = null; pictureBox2.BackColor = Color.LightBlue; }
                    if (x == v[3]) { pictureBox3.Image = null; pictureBox3.BackColor = Color.LightBlue; }
                    if (x == v[4]) { pictureBox4.Image = null; pictureBox4.BackColor = Color.LightBlue; }
                    pictureBox3.Image = null;
                    pictureBox3.BackColor = Color.LightBlue;
                }
            }
        }

        private async void pictureBox4_Click(object sender, EventArgs e)
        {
            nr++;
            //label1.Text = nr.ToString() + " " + x.ToString() + " " + v[4].ToString();
            pictureBox4.Image = img[v[4]];
            if (nr % 2 == 1)
                x = v[4];
            else
            {
                await Task.Delay(500);
                nr = 0;
                if (x + v[4] == n + 1)
                {
                    if (x == v[1]) pictureBox1.Visible = false;
                    if (x == v[3]) pictureBox3.Visible = false;
                    if (x == v[2]) pictureBox2.Visible = false;
                    pictureBox4.Visible = false;
                    nrp += 2;
                    if (nrp == n)
                    {
                        label3.Text = "Ati castigat!";
                        label3.Visible = true;
                    }
                }
                else
                {
                    if (x == v[1]) { pictureBox1.Image = null; pictureBox1.BackColor = Color.LightBlue; }
                    if (x == v[3]) { pictureBox3.Image = null; pictureBox3.BackColor = Color.LightBlue; }
                    if (x == v[2]) { pictureBox2.Image = null; pictureBox2.BackColor = Color.LightBlue; }
                    if (x == v[4]) { pictureBox4.Image = null; pictureBox4.BackColor = Color.LightBlue; }
                    pictureBox4.Image = null;
                    pictureBox4.BackColor = Color.LightBlue;
                }
            }
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
            if (m == tmax / 60 && s == 0)
            {
                pictureBox1.Visible = false;
                pictureBox2.Visible = false;
                pictureBox3.Visible = false;
                pictureBox4.Visible = false;

                label3.Visible = true;
            }

        }
    }
}
