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
