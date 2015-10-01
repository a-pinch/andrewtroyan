$(document).ready(function()
{
	$("polygon").click(function(){
		$("polygon").attr("style", "fill:red");
		alert("text");
	});
	
	$("circle").attr("opacity", "0.5");
	var amount = parseInt($("circle:last").attr("id"));
	
	function getRandomInt(min, max)
	{
		return Math.floor(Math.random() * (max - min + 1)) + min;
	}
	
	setInterval(function()
	{
		for(var i = 0; i <= amount; ++i)
		{
			var t="#"+i;
			var x = parseInt($(t).attr("cx"));
			var y = parseInt($(t).attr("cy"));
			x = (x + getRandomInt(-10, 10)) % 3000 ;
			y = (y + 5) % 2000;
			$(t).attr("cx", x);
			$(t).attr("cy", y);
			
		}
	},50);
});