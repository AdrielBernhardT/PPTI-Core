    // Show Menu
const navMenu = document.getElementById('nav-menu'),
      navToggle = document.getElementById('nav-toggle'),
      navClose = document.getElementById('nav-close')

//  Menu show 
if(navToggle){
    navToggle.addEventListener('click', () =>{
        navMenu.classList.add('show-menu')
    })
}

// Menu hidden
if(navClose){
    navClose.addEventListener('click', () =>{
        navMenu.classList.remove('show-menu')
    })
}

// Remove Menu
const navLink = document.querySelectorAll('.nav__link')

const linkAction = () =>{
    const navMenu = document.getElementById('nav-menu')
    // When we click on each nav__link, we remove the show-menu class
    navMenu.classList.remove('show-menu')
}
navLink.forEach(n => n.addEventListener('click', linkAction))

// Change background header
const blurHeader = () =>{
    const header = document.getElementById('header')
    this.scrollY >= 50 ? header.classList.add('blur-header') 
        : header.classList.remove('blur-header')
}
window.addEventListener('scroll', blurHeader)

document.querySelectorAll(".agent__content").forEach((agent) => {
    const toggleButton = agent.querySelector(".left__content");
    const descSlide = agent.querySelector(".right__content");

    if (toggleButton && descSlide) {
        toggleButton.addEventListener("click", () => {
            // Tutup semua right sebelum membuka yang baru
            document.querySelectorAll(".right__content").forEach((desc) => {
                if (desc !== descSlide) {
                    desc.classList.remove("show-desc");
                }
            });

            // Toggle desc untuk agent yang diklik
            descSlide.classList.toggle("show-desc");
        });

        // Tutup deskripsi jika diklik
        descSlide.addEventListener("click", () => {
            descSlide.classList.remove("show-desc");
        });
    }
});