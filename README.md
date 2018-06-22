Unrecognized selector -[toKotlin:]
==================================

This repository illustrates a bug in the Kotlin-Native compiler when Kotlin
interfaces are implemented by Swift classes.

The Kotlin code is compiled as a framework in `shared`. To build, run:
```
./gradlew clean compileKonanCommonFramework
```

There is only one source file, `Samples.kt`, which is in the `common` module,
reproduced here:
```Kotlin
package com.github.damianw.unrecognizedselectortokotlin

interface SampleInterface {

    val someStrings: List<String>

}

fun SampleInterface.join(): String = someStrings.joinToString()
```

The output framework is actually already included in the sample project,
which is under `sample_project`. 

The relevant Swift file, `ViewController.swift`, is reproduced below:
```Swift
//
//  ViewController.swift
//  test_project
//

import CommonFramework
import UIKit

class SampleClass : USTKSampleInterface {
    let someStrings: [String]
    init(someStrings: [String]) {
        self.someStrings = someStrings
    }
}

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        let someInstance = SampleClass(someStrings: ["hello", "world"])
        print(USTK.join(someInstance))
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

}
```

Running the sample app throws the following error:
```
2018-06-22 15:27:21.075747-0700 test_project[95716:2209774] *** NSForwarding: warning: object 0x60c000235fc0 of class 'test_project.SampleClass' does not implement methodSignatureForSelector: -- trouble ahead
Unrecognized selector -[test_project.SampleClass toKotlin:]
2018-06-22 15:27:21.076331-0700 test_project[95716:2209774] Unrecognized selector -[test_project.SampleClass toKotlin:]
```
