/* Lesson 4 */

/* DATA */

// Step 1 - 5

let personalData = {
    name: 'Dallin Olson',
    photo: 'images/Logo.jpg',
    favoriteFoods: [
        'Fettucini',
        'Pot roast',
        'Breaded Chicken Marinara',
        'Pistachio Ice Cream',
        'Salsa Omlette'
    ],
    hobbies: [
        'Music Production',
        'Gaming',
        'Carpentry'
    ]
};

// Step 6 - 9
personalData.placesLived = [
    {
        place: 'Lakenheath AFB, UK',
        length: '7 years'
    },
    {
        place: 'Okinawa, Japan',
        length: '5 years'
    },
    {
        place: 'Honolulu, HI',
        length: '3 years'
    },
    {
        place: 'Ellensburg, WA',
        length: '1 year'
    },
    {
        place: 'Forest grove, OR',
        length: '6 years'
    }
]


/* OUTPUT */

// Step 1
document.querySelector('#name').textContent = personalData.name;

// Step 2
document.querySelector('#photo').setAttribute('src', personalData.photo);

// Step 3
document.querySelector('#photo').setAttribute('alt', personalData.name);

// Step 4 - 5
personalData.favoriteFoods.forEach((food) => {
    let favoriteFoodElem = document.createElement('li');
    favoriteFoodElem.textContent = food;
    document.querySelector('#favorite-foods').appendChild(favoriteFoodElem);
});

// Step 6 - 7
personalData.hobbies.forEach((hobby) => {
    let hobbyElem = document.createElement('li');
    hobbyElem.textContent = hobby;
    document.querySelector('#hobbies').appendChild(hobbyElem);
});


// Step 8 - 9
personalData.placesLived.forEach((placeLived) => {
    let placesLivedPlace = document.createElement('dt');
    placesLivedPlace.textContent = placeLived.place;
    
    let placesLivedLength = document.createElement('dd');
    placesLivedLength.textContent = placeLived.length;
   
    document.querySelector('#places-lived').appendChild(placesLivedPlace);
    document.querySelector('#places-lived').appendChild(placesLivedLength);
})

