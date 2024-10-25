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
        int[] v = new int[9];
        Image[] img = new Image[9];
        PictureBox firstClicked = null;
        PictureBox secondClicked = null;
        public Form1()
        {
            InitializeComponent();
            timer1.Start();
            for (int i = 1; i <= 8; ++i)
            {
                do
                {
                    v[i] = rnd.Next(8) + 1;
                    ok = 1;
                    for (int j = 1; j < i; ++j)
                        if (v[i] == v[j])
                            ok = 0;
                } while (ok == 0);
            }

            img[1] = img[8] = Image.FromFile("mar.png");
            img[2] = img[7] = Image.FromFile("para.png");
            img[3] = img[6] = Image.FromFile("struguri.png");
            img[4] = img[5] = Image.FromFile("banana.png");
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            pictureBox1.SizeMode = PictureBoxSizeMode.Zoom;
            pictureBox2.SizeMode = PictureBoxSizeMode.Zoom;
            pictureBox3.SizeMode = PictureBoxSizeMode.Zoom;
            pictureBox4.SizeMode = PictureBoxSizeMode.Zoom;
            pictureBox5.SizeMode = PictureBoxSizeMode.Zoom;
            pictureBox6.SizeMode = PictureBoxSizeMode.Zoom;
            pictureBox7.SizeMode = PictureBoxSizeMode.Zoom;
            pictureBox8.SizeMode = PictureBoxSizeMode.Zoom;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            HandlePictureBoxClick(pictureBox1, 1);
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            HandlePictureBoxClick(pictureBox2, 2);
        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {
            HandlePictureBoxClick(pictureBox3, 3);
        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {
            HandlePictureBoxClick(pictureBox4, 4);
        }

        private void pictureBox5_Click(object sender, EventArgs e)
        {
            HandlePictureBoxClick(pictureBox5, 5);
        }

        private void pictureBox6_Click(object sender, EventArgs e)
        {
            HandlePictureBoxClick(pictureBox6, 6);
        }

        private void pictureBox7_Click(object sender, EventArgs e)
        {
            HandlePictureBoxClick(pictureBox7, 7);
        }

        private void pictureBox8_Click(object sender, EventArgs e)
        {
            HandlePictureBoxClick(pictureBox8, 8);
        }

        private async void HandlePictureBoxClick(PictureBox clickedPictureBox, int index)
        {
            DisableAllPictureBoxes();

            nr++;
            //label3.Text = "Clicked on: " + index + " and the number of clicks is: " + nr;
            if (nr % 2 == 1)
            {
                clickedPictureBox.Image = img[v[index]];
                firstClicked = clickedPictureBox;

                x = index;
            }

            else
            {
                clickedPictureBox.Image = img[v[index]];
                secondClicked = clickedPictureBox;

                await Task.Delay(500);
                if (v[x] == 9 - v[index])
                {
                    firstClicked.Visible = false;
                    secondClicked.Visible = false;
                }
                else
                {
                    firstClicked.Image = null;
                    secondClicked.Image = null;
                }


                firstClicked = null;
                secondClicked = null;
                nr = 0;
            }

            EnableAllPictureBoxes();
        }

        private void DisableAllPictureBoxes()
        {
            pictureBox1.Enabled = false;
            pictureBox2.Enabled = false;
            pictureBox3.Enabled = false;
            pictureBox4.Enabled = false;
            pictureBox5.Enabled = false;
            pictureBox6.Enabled = false;
            pictureBox7.Enabled = false;
            pictureBox8.Enabled = false;
        }

        private void EnableAllPictureBoxes()
        {
            pictureBox1.Enabled = true;
            pictureBox2.Enabled = true;
            pictureBox3.Enabled = true;
            pictureBox4.Enabled = true;
            pictureBox5.Enabled = true;
            pictureBox6.Enabled = true;
            pictureBox7.Enabled = true;
            pictureBox8.Enabled = true;
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
