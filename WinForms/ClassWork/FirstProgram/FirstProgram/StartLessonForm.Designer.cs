namespace FirstProgram
{
    partial class StartLessonForm
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
            this.labelSelectDate = new System.Windows.Forms.Label();
            this.dateTimePickerForLesson = new System.Windows.Forms.DateTimePicker();
            this.labelSelectTime = new System.Windows.Forms.Label();
            this.comboBoxWithScheduleTime = new System.Windows.Forms.ComboBox();
            this.buttonStartLesson = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // labelSelectDate
            // 
            this.labelSelectDate.AutoSize = true;
            this.labelSelectDate.Location = new System.Drawing.Point(46, 44);
            this.labelSelectDate.Name = "labelSelectDate";
            this.labelSelectDate.Size = new System.Drawing.Size(61, 13);
            this.labelSelectDate.TabIndex = 0;
            this.labelSelectDate.Text = "Select date";
            // 
            // dateTimePickerForLesson
            // 
            this.dateTimePickerForLesson.Location = new System.Drawing.Point(144, 41);
            this.dateTimePickerForLesson.Name = "dateTimePickerForLesson";
            this.dateTimePickerForLesson.Size = new System.Drawing.Size(200, 20);
            this.dateTimePickerForLesson.TabIndex = 1;
            this.dateTimePickerForLesson.ValueChanged += new System.EventHandler(this.dateTimePickerForLesson_ValueChanged);
            // 
            // labelSelectTime
            // 
            this.labelSelectTime.AutoSize = true;
            this.labelSelectTime.Location = new System.Drawing.Point(48, 82);
            this.labelSelectTime.Name = "labelSelectTime";
            this.labelSelectTime.Size = new System.Drawing.Size(59, 13);
            this.labelSelectTime.TabIndex = 2;
            this.labelSelectTime.Text = "Select time";
            // 
            // comboBoxWithScheduleTime
            // 
            this.comboBoxWithScheduleTime.FormattingEnabled = true;
            this.comboBoxWithScheduleTime.Location = new System.Drawing.Point(144, 79);
            this.comboBoxWithScheduleTime.Name = "comboBoxWithScheduleTime";
            this.comboBoxWithScheduleTime.Size = new System.Drawing.Size(200, 21);
            this.comboBoxWithScheduleTime.TabIndex = 3;
            this.comboBoxWithScheduleTime.SelectedIndexChanged += new System.EventHandler(this.comboBoxWithScheduleTime_SelectedIndexChanged);
            // 
            // buttonStartLesson
            // 
            this.buttonStartLesson.Location = new System.Drawing.Point(163, 185);
            this.buttonStartLesson.Name = "buttonStartLesson";
            this.buttonStartLesson.Size = new System.Drawing.Size(75, 23);
            this.buttonStartLesson.TabIndex = 4;
            this.buttonStartLesson.Text = "Start lesson";
            this.buttonStartLesson.UseVisualStyleBackColor = true;
            this.buttonStartLesson.Click += new System.EventHandler(this.buttonStartLesson_Click);
            // 
            // StartLessonForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(395, 220);
            this.Controls.Add(this.buttonStartLesson);
            this.Controls.Add(this.comboBoxWithScheduleTime);
            this.Controls.Add(this.labelSelectTime);
            this.Controls.Add(this.dateTimePickerForLesson);
            this.Controls.Add(this.labelSelectDate);
            this.Name = "StartLessonForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Start lesson";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelSelectDate;
        private System.Windows.Forms.DateTimePicker dateTimePickerForLesson;
        private System.Windows.Forms.Label labelSelectTime;
        private System.Windows.Forms.ComboBox comboBoxWithScheduleTime;
        private System.Windows.Forms.Button buttonStartLesson;
    }
}