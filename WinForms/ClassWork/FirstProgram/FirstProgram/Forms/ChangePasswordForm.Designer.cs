namespace FirstProgram
{
    partial class ChangePasswordForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.textBoxForOldPassword = new System.Windows.Forms.TextBox();
            this.textBoxForNewPassword = new System.Windows.Forms.TextBox();
            this.labelOldPassword = new System.Windows.Forms.Label();
            this.labelNewPassword = new System.Windows.Forms.Label();
            this.buttonChangePassword = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // textBoxForOldPassword
            // 
            this.textBoxForOldPassword.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.textBoxForOldPassword.Location = new System.Drawing.Point(127, 30);
            this.textBoxForOldPassword.Name = "textBoxForOldPassword";
            this.textBoxForOldPassword.Size = new System.Drawing.Size(145, 20);
            this.textBoxForOldPassword.TabIndex = 0;
            this.textBoxForOldPassword.UseSystemPasswordChar = true;
            // 
            // textBoxForNewPassword
            // 
            this.textBoxForNewPassword.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.textBoxForNewPassword.Location = new System.Drawing.Point(127, 74);
            this.textBoxForNewPassword.Name = "textBoxForNewPassword";
            this.textBoxForNewPassword.Size = new System.Drawing.Size(145, 20);
            this.textBoxForNewPassword.TabIndex = 1;
            this.textBoxForNewPassword.UseSystemPasswordChar = true;
            // 
            // labelOldPassword
            // 
            this.labelOldPassword.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.labelOldPassword.AutoSize = true;
            this.labelOldPassword.Location = new System.Drawing.Point(31, 33);
            this.labelOldPassword.Name = "labelOldPassword";
            this.labelOldPassword.Size = new System.Drawing.Size(71, 13);
            this.labelOldPassword.TabIndex = 2;
            this.labelOldPassword.Text = "Old password";
            // 
            // labelNewPassword
            // 
            this.labelNewPassword.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.labelNewPassword.AutoSize = true;
            this.labelNewPassword.Location = new System.Drawing.Point(30, 77);
            this.labelNewPassword.Name = "labelNewPassword";
            this.labelNewPassword.Size = new System.Drawing.Size(72, 13);
            this.labelNewPassword.TabIndex = 3;
            this.labelNewPassword.Text = "New pasword";
            // 
            // buttonChangePassword
            // 
            this.buttonChangePassword.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonChangePassword.Location = new System.Drawing.Point(103, 123);
            this.buttonChangePassword.Name = "buttonChangePassword";
            this.buttonChangePassword.Size = new System.Drawing.Size(75, 23);
            this.buttonChangePassword.TabIndex = 4;
            this.buttonChangePassword.Text = "Change";
            this.buttonChangePassword.UseVisualStyleBackColor = true;
            this.buttonChangePassword.Click += new System.EventHandler(this.buttonChangePassword_Click);
            // 
            // ChangePasswordForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 162);
            this.Controls.Add(this.buttonChangePassword);
            this.Controls.Add(this.labelNewPassword);
            this.Controls.Add(this.labelOldPassword);
            this.Controls.Add(this.textBoxForNewPassword);
            this.Controls.Add(this.textBoxForOldPassword);
            this.Name = "ChangePasswordForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Changing password";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBoxForOldPassword;
        private System.Windows.Forms.TextBox textBoxForNewPassword;
        private System.Windows.Forms.Label labelOldPassword;
        private System.Windows.Forms.Label labelNewPassword;
        private System.Windows.Forms.Button buttonChangePassword;
    }
}