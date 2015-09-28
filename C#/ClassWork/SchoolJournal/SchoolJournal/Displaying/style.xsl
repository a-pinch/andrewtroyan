<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:output method="html"/>
	<xsl:template match="/list">
		<xsl:variable name="lecture">
			<xsl:value-of select="document(lecture/@location)/Lecture"/>
		</xsl:variable>
		<xsl:variable name="pupils">
			<xsl:value-of select="document(pupils/@location)/ArrayOfPupil"/>
		</xsl:variable>
		<xsl:variable name="groups">
			<xsl:value-of select="document(groups/@location)/ArrayOfStudyGroup"/>
		</xsl:variable>
		<xsl:variable name="subjects">
			<xsl:value-of select="document(subjects/@location)/ArrayOfSubject"/>
		</xsl:variable>
		<xsl:variable name="teachers">
			<xsl:value-of select="document(teachers/@location)/ArrayOfTeacher"/>
		</xsl:variable>
		<h1 style="text-align:center">School journal</h1>
	</xsl:template>
</xsl:stylesheet>