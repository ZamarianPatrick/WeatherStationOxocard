let socket = new WebSocket("ws://" + window.location.hostname + ":5567");

let icons = {
    'foggy' : '<img src="https://drive.google.com/thumbnail?id=11DHL6SP4VCoBy_yEwokTx8gmHMALKr9m" alt="">',
    'rain' : '<img src="https://drive.google.com/thumbnail?id=1MrhLy0m1aYF5YrM4PuyLR66D9M_DXVGa" alt="">',
    'snow' : '<img src="https://drive.google.com/thumbnail?id=1-1WzdbMN2wJQA9ifZfsVNH_X9HJODlCm" alt="">',
    'sun' : '<img src="https://drive.google.com/thumbnail?id=1B4gGCeGBSqc_-MoeRfbXInkbGnxTEPWM" alt="">',
    'cloud' : '<img src="https://drive.google.com/thumbnail?id=19nMIfbYuPuBJw27ChQ877tiEXmXBGaWA" alt="">',
}

socket.onopen = function(e){
    console.log("opened");
}

socket.onmessage = function(e){
    let split = e.data.split(";");
    let cmd = split[0];

    let title = "Home";

    let elContent = document.getElementById('dynamic');

    switch(cmd){
        case "0":
            title = "Temperatur"

            var image = getImage(split[2]);

            if(!!elContent){
                elContent.innerHTML = image + '<br><span class="dynamic-value">' + split[1] + ' &deg;C</span>';
            }
            break;
        
        case "1":
            title = "Luftfeuchtigkeit"

            var image = getImage(split[2]);

            if(!!elContent){
                elContent.innerHTML = image + '<br><span class="dynamic-value">' + split[1] + ' %</span>';
            }

            break;

        case "2":
            title = "Zeit"

            if(!!elContent){
                elContent.innerHTML = '<span class ="dynamic-value">' + split[1] + "</span>";
            }
            break;

        case "3":
            title = "Raumtemperatur"

            if(!!elContent){
                elContent.innerHTML = '<span class = "dynamic-value">' + split[1] + " &deg;C</span>";
            }
            break;

        case "4":
            title = "Raum Luftfeuchtigkeit"

            if(!!elContent){
                elContent.innerHTML = '<span class = "dynamic-value">' + split[1] + " %</span>";
            }
            break;
    
        default:
            break;
    }

    var elTitle = document.getElementById('title');
    
    if(!!elTitle){
        elTitle.innerHTML = title;
    }

    console.log("r: " + e.data);
}

socket.onclose = function(e){
    console.log("closed");
}

socket.onerror = function(e){
    console.log("failed to connect");
}

function getImage(icon){
    let iconId = parseInt(icon);
    let image = "";

    if(iconId == 1 || iconId == 2){
        image = icons['sun'];
    }else if(iconId == 3 || iconId == 4 || iconId == 5){
        image = icons['cloud'];
    }else if(iconId == 7 || iconId == 12 || iconId == 15){
        image = icons['snow'];
    }else if(iconId == 8 || iconId == 14){
        image = icons['foggy'];
    }else if(iconId == 10 || iconId == 11 || iconId == 6 || iconId == 13){
        image = icons['rain'];
    }

    return image;
}