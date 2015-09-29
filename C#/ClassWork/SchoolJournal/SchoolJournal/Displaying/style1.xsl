<?xml version="1.0" encoding="UTF-8"?>

<!-- To see result open "entry.xml" in this directory via IE browser. -->

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  	<xsl:output method="html" doctype-system="about:legacy-compat"/>

	<xsl:template match="/list">
		<html>
			<head>
				<title>School journal</title>
			</head>
			<body bgcolor="#E7E7DB">
				<xsl:variable name="lectures" select="document(lectures/@location)/ArrayOfLecture"/>
				<xsl:variable name="pupils" select="document(pupils/@location)/ArrayOfPupil"/>
				<xsl:variable name="groups" select="document(groups/@location)/ArrayOfStudyGroup"/>
				<xsl:variable name="subjects" select="document(subjects/@location)/ArrayOfSubject"/>
				<xsl:variable name="teachers" select="document(teachers/@location)/ArrayOfTeacher"/>
				<h1 style="text-align:center">School journal</h1>
				<xsl:for-each select="$groups/StudyGroup">
					<xsl:variable name="group_id" select="@GroupID"/>
					<table border="1" style="width:100%;text-align:center">
						<tr bgcolor="#9acd32">
							<th><xsl:value-of select="concat('Group ', name)"/></th>
							<xsl:for-each select="$lectures/Lecture[groupID=$group_id]">
								<th><xsl:value-of select="substring(date, 1, 10)"/></th>
							</xsl:for-each>
						</tr>
						<xsl:for-each select="pupilIDs/int">
							<tr>
								<xsl:variable name="pupil_id" select="text()"/>
								<td><xsl:value-of select="$pupils/Pupil[@PupilID=$pupil_id]"/></td>
								<xsl:for-each select="$lectures/Lecture[groupID=$group_id]">
									<td>
										<xsl:for-each select="marks/Mark[pupilID=$pupil_id]">
											<xsl:if test="position() != '1'">, </xsl:if>
											<xsl:value-of select="concat(point, ' (', markGround, ')')"/>
										</xsl:for-each>
									</td>
								</xsl:for-each>
							</tr>
						</xsl:for-each>
					</table>
					<br/>
					<table border="1" style="width:100%;text-align:center">
						<tr bgcolor="#9acd32">
							<th>Date</th>
							<th>Teacher</th>
							<th>Subject</th>
							<th>Topics</th>
						</tr>
						<xsl:for-each select="$lectures/Lecture[groupID=$group_id]">
							<xsl:variable name="teacher_id" select="teacherID"/>
							<xsl:variable name="subject_id" select="subjectID"/>
							<tr>
								<td><xsl:value-of select="substring(date, 1, 10)"/></td>
								<td><xsl:value-of select="$teachers/Teacher[@TeacherID=$teacher_id]"/></td>
								<td><xsl:value-of select="$subjects/Subject[@SubjectID=$subject_id]/name"/></td>
								<td>
									<xsl:for-each select="subjectTopics/string">
										<xsl:if test="position() != '1'">, </xsl:if>
										<xsl:value-of select="."/>
									</xsl:for-each>
								</td>
							</tr>
						</xsl:for-each>
					</table>
					<br/>
					<br/>
				</xsl:for-each>
			</body>
		</html>
	</xsl:template>
</xsl:stylesheet>