const form = document.querySelector('form')
const gallery = document.querySelector('.showlarimg-container');


form.addEventListener('submit',(e)=>{
    
    e.preventDefault();
    let query=form.querySelector('input').value;
    form.querySelector('input').value='';
    
    if(query==''){
        query="nothing";
    }
    tvShowlari(query);
    
}
)


async function tvShowlari(query){
    const res=await fetch(`https://api.tvmaze.com/search/shows?q=${query}`);
    const shows=await res.json();
    
    makeImages(shows);
}

function makeImages(shows) {
    for(let show of shows)
    {
        if(show.show.image)
        {   
            console.log(show.show.image.medium);
            const img = document.createElement('img');
            img.src=show.show.image.medium;
            gallery.append(img);
        }
    }
}