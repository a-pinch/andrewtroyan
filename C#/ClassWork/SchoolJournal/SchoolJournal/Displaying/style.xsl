<?xml version="1.0" encoding="UTF-8"?>

<!-- To see result open "entry.xml" in this directory via IE browser. -->

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:output method="html"/>
	<xsl:template match="/list">
	<body bgcolor="#E7E7DB">
		<xsl:variable name="lecture" select="document(lecture/@location)/Lecture"/>
		<xsl:variable name="pupils" select="document(pupils/@location)/ArrayOfPupil"/>
		<xsl:variable name="groups" select="document(groups/@location)/ArrayOfStudyGroup"/>
		<xsl:variable name="subjects" select="document(subjects/@location)/ArrayOfSubject"/>
		<xsl:variable name="teachers" select="document(teachers/@location)/ArrayOfTeacher"/>
		<h1 style="text-align:center">School journal</h1>
		<h3 style="text-align:center">
			<xsl:value-of select="concat('Subject: ', $subjects/Subject[@SubjectID=$lecture/subjectID]/name, ', topic: ', $lecture/subjectTopic)"/>
		</h3>
		<h3 style="text-align:center">
			<xsl:value-of select="concat('Teacher: ', $teachers/Teacher[@TeacherID=$lecture/teacherID])"/>
		</h3>
		<table border="1" style="width:100%;text-align:center">
			<tr bgcolor="#9acd32">
				<th>Pupils</th>
				<th>Marks</th>
			</tr>
			<xsl:for-each select="$groups/StudyGroup[@GroupID=$lecture/groupID]/pupilIDs/int">
				<tr bgcolor="#66E0C2">
					<xsl:variable name="id" select="text()"/>
					<td>
						<xsl:value-of select="$pupils/Pupil[@PupilID=$id]"/>
					</td>
					<td>
						<xsl:for-each select="$lecture/marks/Mark">
							<xsl:if test="$id=pupilID">
								<xsl:value-of select="concat(point, ' (', markGround, ') ')"/>
							</xsl:if>
						</xsl:for-each>
					</td>
				</tr>
			</xsl:for-each>
		</table>
	</body>
	</xsl:template>
</xsl:stylesheet>