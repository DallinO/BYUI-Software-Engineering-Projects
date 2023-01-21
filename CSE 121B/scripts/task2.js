/* 
   Week 2 Task
   Dallin Olson
   01/14/2022 
*/

// Part 1

const myName = 'Dallin Olson';
document.querySelector('#name').textContent = myName;
const year = 2022;
document.querySelector('#year').textContent = year;
const myPicture = 'images/photo.jpg';

// Step 6: copy your image into the "images" folder

// Step 7: place the value of the picture variable into the HTML file (hint: document.querySelector().setAttribute())
document.querySelector('img').setAttribute('src', myPicture);


// Part 2

const favoriteFoods = ['Alfredo', 'Brisket', 'Fried Rice', 'Pie'];
document.querySelector('#food').textContent = favoriteFoods;
const anotherFavoriteFood = 'Burgers';
favoriteFoods.push(anotherFavoriteFood);
document.querySelector('#food').textContent = favoriteFoods; // Is there a way to turn into a callable function to repeat?
favoriteFoods.shift();
document.querySelector('#food').textContent = favoriteFoods;
favoriteFoods.pop();
document.querySelector('#food').textContent = favoriteFoods;


