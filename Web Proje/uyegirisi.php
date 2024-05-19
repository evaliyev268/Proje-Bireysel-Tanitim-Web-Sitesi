<<?php 
ob_start();
$uyEno='b231210565@sakarya.edu.tr';
$siFre='565012132';

if(isset($_POST['ugsbtn']))
{
$Uyeno=$_POST('uyeNo');
$sifre=$_GET('sifrE');

if($Uyeno==$uyEno || $sifre==$siFre)
{
    header('location:Main(+Hakkinda).html');
    
}

else{
    echo "Hata! Kullanıcı Adı Ve Ya Şifre Yanlış";
}
}



?>