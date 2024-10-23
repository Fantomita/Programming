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
        int m = 0, s = 0;
        public Form1()
        {
            InitializeComponent();
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
            pictureBox1.Image = Image.FromFile("fructe.jpg");
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {

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
