<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:output method="html" doctype-system="about:legacy-compat"/>
	<xsl:template match="/">
		<html>
			<svg width="{Wood/@width}" height="{Wood/@height}">
				<xsl:for-each select="Wood/tree">
					<xsl:for-each select="layer">
						<polygon points="{firstPointX},{firstPointY} {secondPointX},{secondPointY} {thirdPointX},{thirdPointY}" style="fill:green;stroke:black;stroke-width:1"/>
					</xsl:for-each>
					<rect x="{trunk/x}" y="{trunk/y}" width="{trunk/width}" height="{trunk/height}" style="fill:brown;stroke:black;stroke-width:1"/>
				</xsl:for-each>
			</svg>
		</html>
	</xsl:template>
</xsl:stylesheet>