const jform=document.getElementById('iform');
const jad=document.getElementById('iad');
const jsoyad=document.getElementById('isoyad');
const jemail=document.getElementById('iemail');
const jcheckbox=document.getElementById('icheckbox');
const jradio=document.getElementById('iradio');
const jtexta=document.getElementById('itexta');
const jpass=document.getElementById('ipass');
const joption=document.getElementById('ioption');

const jad_error=document.getElementById('iad_error');
const jsoyad_error=document.getElementById('isoyad_error');
const jemail_error=document.getElementById('iemail_error');
const jcheckbox_error=document.getElementById('icheckbox_error');
const jradio_error=document.getElementById('iradio_error');
const jtexta_error=document.getElementById('itexta_error');
const jpass_error=document.getElementById('ipass_error');
const joption_error=document.getElementById('ioption_error');



jform.addEventListener('submit',(e)=>{
if(jad.value===''||jad.value==null)
    {
        e.preventDefault();
        jad_error.innerHTML="Adınızı Giriniz";
    }
    else{
        jad_error.innerHTML="";
    }

if(jemail.value.indexOf("@")==-1 )
    {
        e.preventDefault();
        jemail_error.innerHTML="Email'nizi Eksiksiz Bir Biçimde Giriniz ";
    }
    else{
        jemail_error.innerHTML="";
    }

    if(jsoyad.value===''||jsoyad.value==null)
        {
            e.preventDefault();
            jsoyad_error.innerHTML="Soyadınızı Giriniz";
        }
    else{
        jsoyad_error.innerHTML="";
    }

    if(jcheckbox.value!='a1')
        {
            e.preventDefault();
            jcheckbox_error.innerHTML="Lütfen En Az 1'ni Seçiniz";
        }
    else{
        jcheckbox_error.innerHTML="";
    }



    /*if()
        {
            
           e.preventDefault();
            joption_error.innerHTML=joption.value;
        }
    else{
         
    }
    */

    if(jtexta.value===''||jtexta.value==null)
        {
            e.preventDefault();
            jtexta_error.innerHTML="Lütfen Bu  Kısmı Doldurunuz";
        }
    else{
        jtexta_error.innerHTML=jtexta.value;
    }

})
