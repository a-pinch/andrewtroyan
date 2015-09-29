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
				<xsl:variable name="lectures" select="document(lectures/@location)/ArrayOfLecture/Lecture"/>
				<xsl:variable name="pupils" select="document(pupils/@location)/ArrayOfPupil"/>
				<xsl:variable name="groups" select="document(groups/@location)/ArrayOfStudyGroup"/>
				<xsl:variable name="subjects" select="document(subjects/@location)/ArrayOfSubject"/>
				<xsl:variable name="teachers" select="document(teachers/@location)/ArrayOfTeacher"/>
				<h1 style="text-align:center">School journal</h1>
				<h3 style="text-align:center">
					<xsl:value-of select="concat('Subject: ', $subjects/Subject[@SubjectID=$lectures/subjectID]/name, ', topic: ', $lectures/subjectTopic)"/>
				</h3>
				<h3 style="text-align:center">
					<xsl:value-of select="concat('Teacher: ', $teachers/Teacher[@TeacherID=$lectures/teacherID])"/>
				</h3>
				<table border="1" style="width:100%;text-align:center">
					<tr bgcolor="#9acd32">
						<th>Pupils</th>
						<th>Marks</th>
					</tr>
					<xsl:for-each select="$groups/StudyGroup[@GroupID=$lectures/groupID]/pupilIDs/int">
						<tr bgcolor="#66E0C2">
							<xsl:variable name="id" select="text()"/>
							<td>
								<xsl:value-of select="$pupils/Pupil[@PupilID=$id]"/>
							</td>
							<td>
								<xsl:for-each select="$lectures/marks/Mark">
									<xsl:if test="$id=pupilID">
										<xsl:value-of select="concat(point, ' (', markGround, ') ')"/>
									</xsl:if>
								</xsl:for-each>
							</td>
						</tr>
					</xsl:for-each>
				</table>
			</body>
		</html>
	</xsl:template>
</xsl:stylesheet>