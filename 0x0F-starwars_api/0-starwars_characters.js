#!/usr/bin/node
/*
    Write a script that prints all characters of a Star Wars movie:
    The first positional argument passed is the Movie ID -
    example: 3 = “Return of the Jedi”
    Display one character name per line in the same order
    as the “characters” list in the /films/ endpoint
    You must use the Star wars API
    You must use the request module
*/

const request = require('request');

const arg = process.argv[2];
// console.log(arg);

if (arg < 1) {
  console.log('Error');
  process.exit(1);
}

const url = `https://swapi-api.hbtn.io/api/films/${arg.toString()}`;
let characters = [];

request(url, (err, resp, body) => {
  if (err || resp.statusCode !== 200) {
    console.log(err);
  } else {
    characters = JSON.parse(body).characters;
    // console.log(characters);
  }
  const size = characters.length;
  const array = Array(size).fill();
  let data = 0;
  for (let i = 0; i < size; i++) {
    request(characters[i], (error, response, bodyy) => {
      if (error || response.statusCode !== 200) {
        console.log(error);
      } else {
        array[i] = JSON.parse(bodyy).name;
        data++;
      }
      if (data === size) {
        array.map((name) => {
          console.log(name);
          return null;
        });
      }
    });
  }
});
