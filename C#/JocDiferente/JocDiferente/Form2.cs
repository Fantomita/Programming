using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics.Eventing.Reader;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.AxHost;

namespace JocDiferente
{
    public partial class Form2 : Form
    {
        int t = 0, tmax = 120, ok = 0, tries = 0, previousClickedIndex = 0, found = 0;
        PictureBox previousClickedBox = null;
        int[] v = new int[13];
        Image[] img = new Image[13];
        Random rnd = new Random();

        public Form2()
        {
            InitializeComponent();
            InitializePictures();
            this.FormClosing += Form2_FormClosing;
            InitializeRandomValues();

            button2.Visible = false;
            label3.Visible = false;

            ShowImagesAtStart();
        }

        private void Form2_FormClosing(object sender, FormClosingEventArgs e)
        {
            Application.Exit();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form1 f = new Form1();
            f.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form2 f = new Form2();
            f.Show();
        }

        private void InitializePictures()
        {
            img[1] = img[12] = Image.FromFile("mar.jpg");
            img[2] = img[11] = Image.FromFile("para.jpg");
            img[3] = img[10] = Image.FromFile("kaki.jpg");
            img[4] = img[9] = Image.FromFile("lebenita.jpg");
            img[5] = img[8] = Image.FromFile("struguri.jpg");
            img[6] = img[7] = Image.FromFile("pepene.jpg");
        }

        private void InitializeRandomValues()
        {
            for (int i = 1; i <= 12; ++i)
            {
                do
                {
                    v[i] = rnd.Next(12) + 1;
                    ok = 1;
                    for (int j = 1; j < i; ++j)
                    {
                        if (v[i] == v[j])
                            ok = 0;
                    }
                } while (ok == 0);
            }
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

        private void pictureBox9_Click(object sender, EventArgs e)
        {
            HandlePictureBoxClick(pictureBox9, 9);
        }

        private void pictureBox10_Click(object sender, EventArgs e)
        {
            HandlePictureBoxClick(pictureBox10, 10);
        }

        private void pictureBox11_Click(object sender, EventArgs e)
        {
            HandlePictureBoxClick(pictureBox11, 11);
        }

        private void pictureBox12_Click(object sender, EventArgs e)
        {
            HandlePictureBoxClick(pictureBox12, 12);
        }

        private async void HandlePictureBoxClick(PictureBox pb, int index)
        {
            if (pb == null) return;

            if (previousClickedIndex == 0)
            {
                pb.Image = img[v[index]];
                previousClickedIndex = index;
                previousClickedBox = pb;
            }
            else
            {
                if (index == previousClickedIndex) return;

                tries++;
                label2.Text = "Încercări: " + tries.ToString();

                pb.Image = img[v[index]];
                SetPictureBoxState(false);

                await Task.Delay(500);

                if (v[index] + v[previousClickedIndex] == 13)
                {
                    pb.Hide();
                    previousClickedBox.Hide();

                    found++;

                    if (found == 6)
                    {
                        timer1.Stop();

                        label3.Text = "Ai câștigat!\nÎntoarce-te la meniu sau joacă din nou!";
                        label3.Visible = true;
                        button2.Visible = true;
                    }
                }
                else
                {
                    pb.Image = Image.FromFile("carte.jpg");
                    previousClickedBox.Image = Image.FromFile("carte.jpg");
                }

                previousClickedBox = null;
                previousClickedIndex = 0;

                if (tries == 20 && label3.Visible == false)
                {
                    timer1.Stop();

                    label3.Visible = true;
                    button2.Visible = true;

                    pictureBox1.Visible = true;
                    pictureBox2.Visible = true;
                    pictureBox3.Visible = true;
                    pictureBox4.Visible = true;
                    pictureBox5.Visible = true;
                    pictureBox6.Visible = true;
                    pictureBox7.Visible = true;
                    pictureBox8.Visible = true;
                    pictureBox9.Visible = true;
                    pictureBox10.Visible = true;
                    pictureBox11.Visible = true;
                    pictureBox12.Visible = true;
                }

                SetPictureBoxState(true);
            }
        }

        private void SetPictureBoxState(bool state)
        {
            pictureBox1.Enabled = state;
            pictureBox2.Enabled = state;
            pictureBox3.Enabled = state;
            pictureBox4.Enabled = state;
            pictureBox5.Enabled = state;
            pictureBox6.Enabled = state;
            pictureBox7.Enabled = state;
            pictureBox8.Enabled = state;
            pictureBox9.Enabled = state;
            pictureBox10.Enabled = state;
            pictureBox11.Enabled = state;
            pictureBox12.Enabled = state;
        }

        private async void ShowImagesAtStart()
        {
            pictureBox1.Image = img[v[1]];
            pictureBox2.Image = img[v[2]];
            pictureBox3.Image = img[v[3]];
            pictureBox4.Image = img[v[4]];
            pictureBox5.Image = img[v[5]];
            pictureBox6.Image = img[v[6]];
            pictureBox7.Image = img[v[7]];
            pictureBox8.Image = img[v[8]];
            pictureBox9.Image = img[v[9]];
            pictureBox10.Image = img[v[10]];
            pictureBox11.Image = img[v[11]];
            pictureBox12.Image = img[v[12]];

            await Task.Delay(1000);

            pictureBox1.Image = Image.FromFile("carte.jpg");
            pictureBox2.Image = Image.FromFile("carte.jpg");
            pictureBox3.Image = Image.FromFile("carte.jpg");
            pictureBox4.Image = Image.FromFile("carte.jpg");
            pictureBox5.Image = Image.FromFile("carte.jpg");
            pictureBox6.Image = Image.FromFile("carte.jpg");
            pictureBox7.Image = Image.FromFile("carte.jpg");
            pictureBox8.Image = Image.FromFile("carte.jpg");
            pictureBox9.Image = Image.FromFile("carte.jpg");
            pictureBox10.Image = Image.FromFile("carte.jpg");
            pictureBox11.Image = Image.FromFile("carte.jpg");
            pictureBox12.Image = Image.FromFile("carte.jpg");   
        }


        private void timer1_Tick(object sender, EventArgs e)
        {
            t++;
            int min = t / 60;
            int sec = t % 60;

            label1.Text = $"Timp: {min:D2}:{sec:D2}";

            if (min == tmax / 60 && sec == tmax % 60)
            {
                timer1.Stop();

                label3.Visible = true;
                button2.Visible = true;

                pictureBox1.Visible = false;
                pictureBox2.Visible = false;
                pictureBox3.Visible = false;
                pictureBox4.Visible = false;
                pictureBox5.Visible = false;
                pictureBox6.Visible = false;
                pictureBox7.Visible = false;
                pictureBox8.Visible = false;
                pictureBox9.Visible = false;
                pictureBox10.Visible = false;
                pictureBox11.Visible = false;
                pictureBox12.Visible = false;
            }
        }
    }
}