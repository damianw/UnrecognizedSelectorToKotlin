package com.github.damianw.unrecognizedselectortokotlin

interface SampleInterface {

    val someStrings: List<String>

}

fun SampleInterface.join(): String = someStrings.joinToString()
