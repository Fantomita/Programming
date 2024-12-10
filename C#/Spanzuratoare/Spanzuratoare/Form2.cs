using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Spanzuratoare
{
    public partial class Form2 : Form
    {
        string[] cuv = new string[45];
        Label[] lit = new Label[16];
        int n = 0, i = 0, r, ok = 0, nr = 0, g = 0;
        char[] cv = new char[45];
        public Form2()
        {
            InitializeComponent();
            this.FormClosing += Form2_FormClosing;

            using (StreamReader f = new StreamReader(Path.GetFullPath("cuvinte.txt")))
            {
                n = Int32.Parse(f.ReadLine());
                while (((cuv[++i]) = f.ReadLine()) != null);
            }
            Random rnd = new Random();

            lit[1] = label32;
            lit[2] = label33;
            lit[3] = label34;
            lit[4] = label35;
            lit[5] = label36;
            lit[6] = label37;
            lit[7] = label38;
            lit[8] = label39;
            lit[9] = label40;
            lit[10] = label41;
            lit[11] = label42;
            lit[12] = label43;
            lit[13] = label44;
            lit[14] = label45;
            lit[15] = label46;

            for (i = 1; i <= 15; ++i)
                lit[i].Visible = false;

            r = rnd.Next(n) + 1;
            
            for (i = 1; i <= cuv[r].Length; ++i)
            {
                lit[i].Visible = true;
                cv[i - 1] = cuv[r][i - 1];
            }
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

        private void label1_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'A' || cv[i] == 'a')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1)
                    {
                        pictureBox1.Image = Image.FromFile("Sc.png");
                    }
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label1.Visible = false;
        }

        private void label2_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'Ă' || cv[i] == 'ă')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label2.Visible = false;
        }

        private void label3_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'Â' || cv[i] == 'â')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label3.Visible = false;
        }

        private void label4_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'B' || cv[i] == 'b')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label4.Visible = false;
        }

        private void label5_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'C' || cv[i] == 'c')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label5.Visible = false;
        }

        private void label6_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'D' || cv[i] == 'd')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label6.Visible = false;
        }

        private void label7_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'E' || cv[i] == 'e')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label7.Visible = false;
        }

        private void label8_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'f' || cv[i] == 'f')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label8.Visible = false;
        }

        private void label9_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'G' || cv[i] == 'g')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label9.Visible = false;
        }

        private void label10_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'H' || cv[i] == 'h')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label10.Visible = false;
        }

        private void label11_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'I' || cv[i] == 'i')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label11.Visible = false;
        }

        private void label12_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'Î' || cv[i] == 'î')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label12.Visible = false;
        }

        private void label13_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'J' || cv[i] == 'j')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label13.Visible = false;
        }

        private void label14_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'K' || cv[i] == 'k')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label14.Visible = false;
        }

        private void label15_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'L' || cv[i] == 'l')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label15.Visible = false;
        }

        private void label16_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'M' || cv[i] == 'm')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label16.Visible = false;
        }

        private void label17_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'N' || cv[i] == 'n')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label17.Visible = false;
        }

        private void label18_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'O' || cv[i] == 'o')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label18.Visible = false;
        }

        private void label19_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'P' || cv[i] == 'p')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label19.Visible = false;
        }

        private void label20_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'Q' || cv[i] == 'q')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label20.Visible = false;
        }

        private void label21_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'R' || cv[i] == 'r')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label21.Visible = false;
        }

        private void label22_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'S' || cv[i] == 's')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label22.Visible = false;
        }

        private void label23_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'Ș' || cv[i] == 'ș')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label23.Visible = false;
        }

        private void label24_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'T' || cv[i] == 't')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label24.Visible = false;
        }

        private void label25_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'Ț' || cv[i] == 'ț')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label25.Visible = false;
        }

        private void label26_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'U' || cv[i] == 'u')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label26.Visible = false;
        }

        private void label27_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'V' || cv[i] == 'v')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label27.Visible = false;
        }

        private void label28_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'W' || cv[i] == 'w')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label28.Visible = false;
        }

        private void label29_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'X' || cv[i] == 'x')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label29.Visible = false;
        }

        private void label30_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'Y' || cv[i] == 'y')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label30.Visible = false;
        }

        private void label31_Click(object sender, EventArgs e)
        {
            ok = 0;
            for (int i = 0; i < cv.Length; i++)
                if (cv[i] == 'Z' || cv[i] == 'z')
                {
                    lit[i + 1].Text = cv[i].ToString();
                    ok = 1;
                    g++;
                    if (g == cuv[r].Length)
                    {
                        label48.Visible = true;
                        //label47.Visible = true;
                    }
                }
            if (ok == 0)
            {
                nr++;
                if (nr > 5)
                {
                    pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                    label47.Visible = true;
                }
                else
                {
                    if (nr == 1) pictureBox1.Image = Image.FromFile("Sc.png");
                    if (nr == 2) pictureBox1.Image = Image.FromFile("Sct.png");
                    if (nr == 3) pictureBox1.Image = Image.FromFile("Sctms.png");
                    if (nr == 4) pictureBox1.Image = Image.FromFile("Sctmd.png");
                    if (nr == 5) pictureBox1.Image = Image.FromFile("Sctmdps.png");
                    if (nr == 6) pictureBox1.Image = Image.FromFile("Sctmdpd.png");
                }
            }
            label31.Visible = false;
        }
    }
}
