namespace FirstProgram
{
    partial class LessonInProgressForm
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
            this.labelDate = new System.Windows.Forms.Label();
            this.labelStartTime = new System.Windows.Forms.Label();
            this.labelGroup = new System.Windows.Forms.Label();
            this.labelTeacher = new System.Windows.Forms.Label();
            this.labelSubject = new System.Windows.Forms.Label();
            this.labelTopics = new System.Windows.Forms.Label();
            this.buttonEndAndSave = new System.Windows.Forms.Button();
            this.tableWithLessonInfo = new System.Windows.Forms.TableLayoutPanel();
            this.labelPupil = new System.Windows.Forms.Label();
            this.labelPresence = new System.Windows.Forms.Label();
            this.labelMarks = new System.Windows.Forms.Label();
            this.tableWithLessonInfo.SuspendLayout();
            this.SuspendLayout();
            // 
            // labelDate
            // 
            this.labelDate.AutoSize = true;
            this.labelDate.Location = new System.Drawing.Point(12, 9);
            this.labelDate.Name = "labelDate";
            this.labelDate.Size = new System.Drawing.Size(33, 13);
            this.labelDate.TabIndex = 0;
            this.labelDate.Text = "Date:";
            // 
            // labelStartTime
            // 
            this.labelStartTime.AutoSize = true;
            this.labelStartTime.Location = new System.Drawing.Point(76, 9);
            this.labelStartTime.Name = "labelStartTime";
            this.labelStartTime.Size = new System.Drawing.Size(54, 13);
            this.labelStartTime.TabIndex = 1;
            this.labelStartTime.Text = "Start time:";
            // 
            // labelGroup
            // 
            this.labelGroup.AutoSize = true;
            this.labelGroup.Location = new System.Drawing.Point(12, 32);
            this.labelGroup.Name = "labelGroup";
            this.labelGroup.Size = new System.Drawing.Size(39, 13);
            this.labelGroup.TabIndex = 2;
            this.labelGroup.Text = "Group:";
            // 
            // labelTeacher
            // 
            this.labelTeacher.AutoSize = true;
            this.labelTeacher.Location = new System.Drawing.Point(76, 32);
            this.labelTeacher.Name = "labelTeacher";
            this.labelTeacher.Size = new System.Drawing.Size(50, 13);
            this.labelTeacher.TabIndex = 3;
            this.labelTeacher.Text = "Teacher:";
            // 
            // labelSubject
            // 
            this.labelSubject.AutoSize = true;
            this.labelSubject.Location = new System.Drawing.Point(12, 54);
            this.labelSubject.Name = "labelSubject";
            this.labelSubject.Size = new System.Drawing.Size(46, 13);
            this.labelSubject.TabIndex = 4;
            this.labelSubject.Text = "Subject:";
            // 
            // labelTopics
            // 
            this.labelTopics.AutoSize = true;
            this.labelTopics.Location = new System.Drawing.Point(76, 54);
            this.labelTopics.Name = "labelTopics";
            this.labelTopics.Size = new System.Drawing.Size(48, 13);
            this.labelTopics.TabIndex = 5;
            this.labelTopics.Text = "Topic(s):";
            // 
            // buttonEndAndSave
            // 
            this.buttonEndAndSave.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonEndAndSave.Location = new System.Drawing.Point(404, 12);
            this.buttonEndAndSave.Name = "buttonEndAndSave";
            this.buttonEndAndSave.Size = new System.Drawing.Size(172, 55);
            this.buttonEndAndSave.TabIndex = 6;
            this.buttonEndAndSave.Text = "End and save";
            this.buttonEndAndSave.UseVisualStyleBackColor = true;
            // 
            // tableWithLessonInfo
            // 
            this.tableWithLessonInfo.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tableWithLessonInfo.CellBorderStyle = System.Windows.Forms.TableLayoutPanelCellBorderStyle.Single;
            this.tableWithLessonInfo.ColumnCount = 4;
            this.tableWithLessonInfo.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableWithLessonInfo.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 15F));
            this.tableWithLessonInfo.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 15F));
            this.tableWithLessonInfo.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 45F));
            this.tableWithLessonInfo.Controls.Add(this.labelPupil, 0, 0);
            this.tableWithLessonInfo.Controls.Add(this.labelPresence, 1, 0);
            this.tableWithLessonInfo.Controls.Add(this.labelMarks, 2, 0);
            this.tableWithLessonInfo.Location = new System.Drawing.Point(13, 82);
            this.tableWithLessonInfo.Name = "tableWithLessonInfo";
            this.tableWithLessonInfo.RowCount = 1;
            this.tableWithLessonInfo.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableWithLessonInfo.Size = new System.Drawing.Size(563, 28);
            this.tableWithLessonInfo.TabIndex = 7;
            // 
            // labelPupil
            // 
            this.labelPupil.AutoSize = true;
            this.labelPupil.Dock = System.Windows.Forms.DockStyle.Fill;
            this.labelPupil.Location = new System.Drawing.Point(4, 1);
            this.labelPupil.Name = "labelPupil";
            this.labelPupil.Size = new System.Drawing.Size(133, 26);
            this.labelPupil.TabIndex = 0;
            this.labelPupil.Text = "Pupil";
            this.labelPupil.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // labelPresence
            // 
            this.labelPresence.AutoSize = true;
            this.labelPresence.Dock = System.Windows.Forms.DockStyle.Fill;
            this.labelPresence.Location = new System.Drawing.Point(144, 1);
            this.labelPresence.Name = "labelPresence";
            this.labelPresence.Size = new System.Drawing.Size(77, 26);
            this.labelPresence.TabIndex = 1;
            this.labelPresence.Text = "Presence";
            this.labelPresence.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // labelMarks
            // 
            this.labelMarks.AutoSize = true;
            this.tableWithLessonInfo.SetColumnSpan(this.labelMarks, 2);
            this.labelMarks.Dock = System.Windows.Forms.DockStyle.Fill;
            this.labelMarks.Location = new System.Drawing.Point(228, 1);
            this.labelMarks.Name = "labelMarks";
            this.labelMarks.Size = new System.Drawing.Size(331, 26);
            this.labelMarks.TabIndex = 2;
            this.labelMarks.Text = "Marks";
            this.labelMarks.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // LessonInProgressForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(588, 329);
            this.Controls.Add(this.tableWithLessonInfo);
            this.Controls.Add(this.buttonEndAndSave);
            this.Controls.Add(this.labelTopics);
            this.Controls.Add(this.labelSubject);
            this.Controls.Add(this.labelTeacher);
            this.Controls.Add(this.labelGroup);
            this.Controls.Add(this.labelStartTime);
            this.Controls.Add(this.labelDate);
            this.Name = "LessonInProgressForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Lesson";
            this.tableWithLessonInfo.ResumeLayout(false);
            this.tableWithLessonInfo.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelDate;
        private System.Windows.Forms.Label labelStartTime;
        private System.Windows.Forms.Label labelGroup;
        private System.Windows.Forms.Label labelTeacher;
        private System.Windows.Forms.Label labelSubject;
        private System.Windows.Forms.Label labelTopics;
        private System.Windows.Forms.Button buttonEndAndSave;
        private System.Windows.Forms.TableLayoutPanel tableWithLessonInfo;
        private System.Windows.Forms.Label labelPupil;
        private System.Windows.Forms.Label labelPresence;
        private System.Windows.Forms.Label labelMarks;
    }
}