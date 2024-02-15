import { initializeApp } from 'https://www.gstatic.com/firebasejs/9.0.0/firebase-app.js';
import {
    collection,
    getDocs,
    getFirestore,
    addDoc
} from 'https://www.gstatic.com/firebasejs/9.0.0/firebase-firestore.js';

// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
    apiKey: "AIzaSyAtN6V6JTl5LVuL2HJUAp2jAVB4DovErG0",
    authDomain: "learn-97dfa.firebaseapp.com",
    projectId: "learn-97dfa",
    storageBucket: "learn-97dfa.appspot.com",
    messagingSenderId: "602777958012",
    appId: "1:602777958012:web:789669eaf4e9e5a2207bf9",
    measurementId: "G-N528KR2LS2"
}

//Start firebase
initializeApp(firebaseConfig)

//database obj
const db = getFirestore()

var IMEI = ""
var nodes = new Array()
var location = ""
var users = new Array()


document.getElementById("loginForm").addEventListener('submit', (event) => {
    event.preventDefault();
    alert(IMEI)
    IMEI = document.forms["loginForm"]["gwid"].value
    const col = collection(db, IMEI)

    getDocs(col).then((snapshot) => {
        if (!snapshot.empty) {
            console.log("Document data: ", snapshot.docs[0].data());




            document.getElementById("IMEI").innerHTML += IMEI


        } else {
            alert("IMEI not found!")
        }
    })
})