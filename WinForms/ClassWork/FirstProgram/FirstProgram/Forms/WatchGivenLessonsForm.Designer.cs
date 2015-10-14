namespace FirstProgram
{
    partial class WatchGivenLessonsForm
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
            this.LabelSelectDate = new System.Windows.Forms.Label();
            this.comboBoxWithGivenLessonsDates = new System.Windows.Forms.ComboBox();
            this.labelWithGroupName = new System.Windows.Forms.Label();
            this.labelWithSubjectName = new System.Windows.Forms.Label();
            this.labelWithTopics = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // LabelSelectDate
            // 
            this.LabelSelectDate.AutoSize = true;
            this.LabelSelectDate.Location = new System.Drawing.Point(12, 19);
            this.LabelSelectDate.Name = "LabelSelectDate";
            this.LabelSelectDate.Size = new System.Drawing.Size(64, 13);
            this.LabelSelectDate.TabIndex = 0;
            this.LabelSelectDate.Text = "Select date:";
            // 
            // comboBoxWithGivenLessonsDates
            // 
            this.comboBoxWithGivenLessonsDates.FormattingEnabled = true;
            this.comboBoxWithGivenLessonsDates.Location = new System.Drawing.Point(82, 16);
            this.comboBoxWithGivenLessonsDates.Name = "comboBoxWithGivenLessonsDates";
            this.comboBoxWithGivenLessonsDates.Size = new System.Drawing.Size(121, 21);
            this.comboBoxWithGivenLessonsDates.TabIndex = 1;
            this.comboBoxWithGivenLessonsDates.SelectedIndexChanged += new System.EventHandler(this.comboBoxWithGivenLessonsDates_SelectedIndexChanged);
            // 
            // labelWithGroupName
            // 
            this.labelWithGroupName.AutoSize = true;
            this.labelWithGroupName.Location = new System.Drawing.Point(203, 52);
            this.labelWithGroupName.Name = "labelWithGroupName";
            this.labelWithGroupName.Size = new System.Drawing.Size(39, 13);
            this.labelWithGroupName.TabIndex = 4;
            this.labelWithGroupName.Text = "Group:";
            // 
            // labelWithSubjectName
            // 
            this.labelWithSubjectName.AutoSize = true;
            this.labelWithSubjectName.Location = new System.Drawing.Point(12, 52);
            this.labelWithSubjectName.Name = "labelWithSubjectName";
            this.labelWithSubjectName.Size = new System.Drawing.Size(46, 13);
            this.labelWithSubjectName.TabIndex = 2;
            this.labelWithSubjectName.Text = "Subject:";
            // 
            // labelWithTopics
            // 
            this.labelWithTopics.AutoSize = true;
            this.labelWithTopics.Location = new System.Drawing.Point(105, 52);
            this.labelWithTopics.Name = "labelWithTopics";
            this.labelWithTopics.Size = new System.Drawing.Size(48, 13);
            this.labelWithTopics.TabIndex = 3;
            this.labelWithTopics.Text = "Topic(s):";
            // 
            // WatchGivenLessonsForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(719, 309);
            this.Controls.Add(this.labelWithTopics);
            this.Controls.Add(this.labelWithSubjectName);
            this.Controls.Add(this.labelWithGroupName);
            this.Controls.Add(this.comboBoxWithGivenLessonsDates);
            this.Controls.Add(this.LabelSelectDate);
            this.Name = "WatchGivenLessonsForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Lessons";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label LabelSelectDate;
        private System.Windows.Forms.ComboBox comboBoxWithGivenLessonsDates;
        private System.Windows.Forms.Label labelWithGroupName;
        private System.Windows.Forms.Label labelWithSubjectName;
        private System.Windows.Forms.Label labelWithTopics;
    }
}