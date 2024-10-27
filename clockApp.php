<meta http-equiv="refresh" content="5">

<?php
print "<h1 style='text-align:center;'>Arduino/Raspberry Pi Clock Control</h1>";
print "<br>";

$temp = file_get_contents("data.txt");
$clockControl;
$clockTrigger = $_GET["clockControl"];

if ($clockTrigger == "scene change" || $clockTrigger == "standard rotation"){
file_put_contents("clockStatus$clockStatus.txt", $clockTrigger);
}

$clockStatus = file_get_contents("clockStatus$clockStatus.txt");

if ($clockStatus == "scene change"){
	$clockControl = "standard rotation";
} else if ($clockStatus == "standard rotation"){
	$clockControl = "scene change";
} else {
	$clockControl = "neutral";
}
	
print "<p>CLock is ".$clockStatus."</p>";

print "<a href='fanApp.php?clockControl=".$clockControl."'>Turn Clock to ".$clockControl."</p></a>";

?>