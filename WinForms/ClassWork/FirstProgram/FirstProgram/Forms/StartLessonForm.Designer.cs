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
            this.labelWithSubjectName = new System.Windows.Forms.Label();
            this.labelWithGroupName = new System.Windows.Forms.Label();
            this.labelWithTopics = new System.Windows.Forms.Label();
            this.textBoxWithTopicNames = new System.Windows.Forms.TextBox();
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
            // labelWithSubjectName
            // 
            this.labelWithSubjectName.AutoSize = true;
            this.labelWithSubjectName.Location = new System.Drawing.Point(51, 119);
            this.labelWithSubjectName.Name = "labelWithSubjectName";
            this.labelWithSubjectName.Size = new System.Drawing.Size(46, 13);
            this.labelWithSubjectName.TabIndex = 5;
            this.labelWithSubjectName.Text = "Subject:";
            // 
            // labelWithGroupName
            // 
            this.labelWithGroupName.AutoSize = true;
            this.labelWithGroupName.Location = new System.Drawing.Point(144, 119);
            this.labelWithGroupName.Name = "labelWithGroupName";
            this.labelWithGroupName.Size = new System.Drawing.Size(39, 13);
            this.labelWithGroupName.TabIndex = 6;
            this.labelWithGroupName.Text = "Group:";
            // 
            // labelWithTopics
            // 
            this.labelWithTopics.AutoSize = true;
            this.labelWithTopics.Location = new System.Drawing.Point(51, 150);
            this.labelWithTopics.Name = "labelWithTopics";
            this.labelWithTopics.Size = new System.Drawing.Size(48, 13);
            this.labelWithTopics.TabIndex = 7;
            this.labelWithTopics.Text = "Topic(s):";
            // 
            // textBoxWithTopicNames
            // 
            this.textBoxWithTopicNames.Location = new System.Drawing.Point(116, 147);
            this.textBoxWithTopicNames.Name = "textBoxWithTopicNames";
            this.textBoxWithTopicNames.Size = new System.Drawing.Size(100, 20);
            this.textBoxWithTopicNames.TabIndex = 8;
            // 
            // StartLessonForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(395, 220);
            this.Controls.Add(this.textBoxWithTopicNames);
            this.Controls.Add(this.labelWithTopics);
            this.Controls.Add(this.labelWithGroupName);
            this.Controls.Add(this.labelWithSubjectName);
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
        private System.Windows.Forms.Label labelWithSubjectName;
        private System.Windows.Forms.Label labelWithGroupName;
        private System.Windows.Forms.Label labelWithTopics;
        private System.Windows.Forms.TextBox textBoxWithTopicNames;
    }
}