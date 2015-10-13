namespace FirstProgram
{
    partial class GivenLessonInfo
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.labelSubjectName = new System.Windows.Forms.Label();
            this.labelTopics = new System.Windows.Forms.Label();
            this.tableWithLessonData = new System.Windows.Forms.TableLayoutPanel();
            this.PupilColumn = new System.Windows.Forms.Label();
            this.PresenceColumn = new System.Windows.Forms.Label();
            this.MarksColumn = new System.Windows.Forms.Label();
            this.tableWithLessonData.SuspendLayout();
            this.SuspendLayout();
            // 
            // labelSubjectName
            // 
            this.labelSubjectName.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.labelSubjectName.AutoSize = true;
            this.labelSubjectName.Location = new System.Drawing.Point(4, 4);
            this.labelSubjectName.Name = "labelSubjectName";
            this.labelSubjectName.Size = new System.Drawing.Size(46, 13);
            this.labelSubjectName.TabIndex = 0;
            this.labelSubjectName.Text = "Subject:";
            // 
            // labelTopics
            // 
            this.labelTopics.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.labelTopics.AutoSize = true;
            this.labelTopics.Location = new System.Drawing.Point(110, 4);
            this.labelTopics.Name = "labelTopics";
            this.labelTopics.Size = new System.Drawing.Size(48, 13);
            this.labelTopics.TabIndex = 1;
            this.labelTopics.Text = "Topic(s):";
            // 
            // tableWithLessonData
            // 
            this.tableWithLessonData.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tableWithLessonData.CellBorderStyle = System.Windows.Forms.TableLayoutPanelCellBorderStyle.Single;
            this.tableWithLessonData.ColumnCount = 3;
            this.tableWithLessonData.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 30F));
            this.tableWithLessonData.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 15F));
            this.tableWithLessonData.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 55F));
            this.tableWithLessonData.Controls.Add(this.PupilColumn, 0, 0);
            this.tableWithLessonData.Controls.Add(this.PresenceColumn, 1, 0);
            this.tableWithLessonData.Controls.Add(this.MarksColumn, 2, 0);
            this.tableWithLessonData.Location = new System.Drawing.Point(3, 36);
            this.tableWithLessonData.Name = "tableWithLessonData";
            this.tableWithLessonData.RowCount = 1;
            this.tableWithLessonData.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableWithLessonData.Size = new System.Drawing.Size(477, 26);
            this.tableWithLessonData.TabIndex = 2;
            // 
            // PupilColumn
            // 
            this.PupilColumn.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.PupilColumn.AutoSize = true;
            this.PupilColumn.Location = new System.Drawing.Point(56, 6);
            this.PupilColumn.Name = "PupilColumn";
            this.PupilColumn.Size = new System.Drawing.Size(30, 13);
            this.PupilColumn.TabIndex = 0;
            this.PupilColumn.Text = "Pupil";
            // 
            // PresenceColumn
            // 
            this.PresenceColumn.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.PresenceColumn.AutoSize = true;
            this.PresenceColumn.Location = new System.Drawing.Point(152, 6);
            this.PresenceColumn.Name = "PresenceColumn";
            this.PresenceColumn.Size = new System.Drawing.Size(52, 13);
            this.PresenceColumn.TabIndex = 1;
            this.PresenceColumn.Text = "Presence";
            // 
            // MarksColumn
            // 
            this.MarksColumn.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.MarksColumn.AutoSize = true;
            this.MarksColumn.Location = new System.Drawing.Point(327, 6);
            this.MarksColumn.Name = "MarksColumn";
            this.MarksColumn.Size = new System.Drawing.Size(36, 13);
            this.MarksColumn.TabIndex = 2;
            this.MarksColumn.Text = "Marks";
            // 
            // GivenLessonInfo
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.tableWithLessonData);
            this.Controls.Add(this.labelTopics);
            this.Controls.Add(this.labelSubjectName);
            this.Name = "GivenLessonInfo";
            this.Size = new System.Drawing.Size(483, 228);
            this.tableWithLessonData.ResumeLayout(false);
            this.tableWithLessonData.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelSubjectName;
        private System.Windows.Forms.Label labelTopics;
        private System.Windows.Forms.TableLayoutPanel tableWithLessonData;
        private System.Windows.Forms.Label PupilColumn;
        private System.Windows.Forms.Label PresenceColumn;
        private System.Windows.Forms.Label MarksColumn;
    }
}
