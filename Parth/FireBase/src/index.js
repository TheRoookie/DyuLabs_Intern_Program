import { initializeApp } from "firebase/app"
import {
    collection,
    getDocs,
    getFirestore,
    addDoc
} from "firebase/firestore"

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

// colection ref
const col = collection(db, "books")

//doc
getDocs(col)
    .then((snap) => {
        let cole = []
        snap.docs.forEach((doc) => {
            cole.push({
                ...doc.data(), id: doc.id
            })
        })
        console.log(cole)
    })
    .catch(err => {
        console.log("Custom Error =>" + err)
    })
//Add document
const addData = document.querySelector('.add')
alert(addData)
addData.addEventListener('submit', (e) => {
    e.preventDefault()
    addDoc(col, {
        title: addData.title.value,
        author: addData.author.value
    })
        .then(() => {
            addData.reset()
        })
})