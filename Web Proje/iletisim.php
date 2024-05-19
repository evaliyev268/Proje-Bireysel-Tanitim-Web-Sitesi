<?php 




 if(isset($_POST["sbmt1"]))
 {
$ad=$_POST["Adiniz"];
$soyad=$_POST["Soyadiniz"];
$email=$_POST["Emailadres"];
$müracaat=$_POST["mt"];
$makalet=$_POST["makaletipleri"];
$cinsiyyet=$_POST["Cinsiyyet"];
$mesaj=$_POST["mesajiniZ"];
 
 echo "Ad:";
 echo $ad;
 echo "<br>";
 echo "Soyad:"; 
 echo $soyad;
 echo "<br>";
 echo "E-Mail:";
 echo $email;
 echo "<br>";
 echo "Müracaat Tipi:";
 echo $müracaat;
 echo "<br>";
 echo "Makale Tipi";
 echo $makalet;
 echo "<br>";
 echo "Cinsiyyet";
 echo $cinsiyyet;
 echo "<br>"; 
 echo "Mesaj:";
 $mesaj;
 echo "<br>";

 }


 





?>