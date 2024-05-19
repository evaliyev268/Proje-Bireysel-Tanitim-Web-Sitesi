const j1form=document.getElementById('i1form');
const j1uyeno=document.getElementById('i1uyeno');
const j1sifre=document.getElementById('i1sifre');
const j1uyeno_error=document.getElementById('i1uyeno_error');
const j1sifre_error=document.getElementById('i1sifre_error');

j1form.addEventListener('submit',(e)=>{
    if(j1sifre.value===''||j1sifre.value==null)
        {
            e.preventDefault();
            j1sifre_error.innerHTML="Sifrenizi Giriniz";
        }
        else{
            j1sifre_error.innerHTML="";
        }
    
    if(j1uyeno.value.indexOf("@")==-1 )
        {
            e.preventDefault();
            j1uyeno_error.innerHTML="Uye No Giriniz";
        }
        else{
            j1uyeno_error.innerHTML="";
        }


    })