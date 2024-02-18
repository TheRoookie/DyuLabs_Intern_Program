import { initializeApp } from 'https://www.gstatic.com/firebasejs/9.0.0/firebase-app.js';
import {
    collection,
    getDocs,
    doc, getDoc, addDoc, updateDoc, deleteDoc, query, where, orderBy,
    getFirestore,
    onSnapshot
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
var profile = { hi: "Hello" }
var users = new Array()
var pass = ""

document.getElementById("loginForm").addEventListener('submit', (event) => {
    event.preventDefault()
    IMEI = document.forms["loginForm"]["gwid"].value
    const col = collection(db, IMEI)

    onSnapshot(col, (snapshot) => {

        if (!snapshot.empty) {
            nodes = snapshot.docs
            //get the profile document from col
            var prof_doc = doc(db, IMEI + "/profile")
            getDoc(prof_doc).then((profile_doc) => {
                console.log(profile_doc.data())
                profile = profile_doc.data()

                let prof_page = document.getElementById("Profile")
                prof_page.innerHTML = ""
                let kido = document.createElement('div')
                kido.innerHTML += "Location : " + profile.location + "<br>"
                kido.innerHTML += 'User 1 : ' + profile.user1 + '<br>'
                kido.innerHTML += 'User 2 : ' + profile.user2 + '<br>'
                prof_page.appendChild(kido)
            })




            let node = document.getElementById("nodes")
            node.innerHTML = ""
            for (let i = 0; i < nodes.length - 1; i++) {
                let kid = document.createElement('div')

                kid.innerHTML += ("Node Unique ID : " + nodes[i].id + "<br>")
                kid.innerHTML += ("Active Time : " + nodes[i].data().activeTime + "<br>")
                kid.innerHTML += ("Installation Time : " + nodes[i].data().installationTime + "<br>")
                kid.innerHTML += ("Load : " + nodes[i].data().load + "<br>")
                kid.innerHTML += ("MacID : " + nodes[i].data().macID + "<br>")
                kid.innerHTML += ("Update Time : " + nodes[i].data().load + "<br>")




                kid.innerHTML += "<br>*******************<br>"
                node.appendChild(kid)
            }



            document.getElementById("IMEI").innerHTML = IMEI


        } else {
            alert("IMEI not found!")
        }
    })

})

