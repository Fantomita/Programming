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
        int n = 0, i = 0, r;
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
                lit[i].Visible = true;

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

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void label10_Click(object sender, EventArgs e)
        {

        }

        private void label11_Click(object sender, EventArgs e)
        {

        }

        private void label12_Click(object sender, EventArgs e)
        {

        }

        private void label13_Click(object sender, EventArgs e)
        {

        }

        private void label14_Click(object sender, EventArgs e)
        {

        }

        private void label15_Click(object sender, EventArgs e)
        {

        }

        private void label16_Click(object sender, EventArgs e)
        {

        }

        private void label17_Click(object sender, EventArgs e)
        {

        }

        private void label18_Click(object sender, EventArgs e)
        {

        }

        private void label19_Click(object sender, EventArgs e)
        {

        }

        private void label20_Click(object sender, EventArgs e)
        {

        }

        private void label21_Click(object sender, EventArgs e)
        {

        }

        private void label22_Click(object sender, EventArgs e)
        {

        }

        private void label23_Click(object sender, EventArgs e)
        {

        }

        private void label24_Click(object sender, EventArgs e)
        {

        }

        private void label25_Click(object sender, EventArgs e)
        {

        }

        private void label26_Click(object sender, EventArgs e)
        {

        }

        private void label27_Click(object sender, EventArgs e)
        {

        }

        private void label28_Click(object sender, EventArgs e)
        {

        }

        private void label29_Click(object sender, EventArgs e)
        {

        }

        private void label30_Click(object sender, EventArgs e)
        {

        }

        private void label31_Click(object sender, EventArgs e)
        {

        }
    }
}
