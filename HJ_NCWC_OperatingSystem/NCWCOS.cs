using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HJ_NCWC_OperatingSystem
{
    public partial class NCWCOSform : Form
    {
        public NCWCOSform()
        {
            InitializeComponent();
        }

        private void btnMapping_Click(object sender, EventArgs e)
        {
            csPCIform.MappingForm mappingForm = new csPCIform.MappingForm();
            mappingForm.Show();
        }

        private void btnRoute_Click(object sender, EventArgs e)
        {
            HJ_MakeRoute.MakeRouteForm makerouteForm = new HJ_MakeRoute.MakeRouteForm();
            makerouteForm.Show();
        }

        private void btnDrive_Click(object sender, EventArgs e)
        {
            Sayakachandeista sayaka = new Sayakachandeista();
            sayaka.Show();
        }

    }
}
