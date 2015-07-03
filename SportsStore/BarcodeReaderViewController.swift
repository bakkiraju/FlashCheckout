//
//  BarcodeReaderViewController.swift
//  FlashCheckout
//
//  Created by Bilahari Akkiraju on 5/9/15.
//  Copyright (c) 2015 shtick. All rights reserved.
//

import Foundation
import UIKit
import RSBarcodes


class BarcodeReaderViewController : RSCodeReaderViewController
{
    @IBOutlet weak var testLabel: UILabel!
    
    @IBOutlet weak var FlashToggle: UIButton!
    
    @IBOutlet weak var goBackToShopList: UIButton!
    
    
    @IBAction func toggleFlash(sender: AnyObject) {
    
        if (self.hasTorch()) {
           self.toggleTorch()
        }
    }
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
    
        view.bringSubviewToFront(testLabel)
        view.bringSubviewToFront(FlashToggle)
        view.bringSubviewToFront(goBackToShopList)

        self.focusMarkLayer.strokeColor = UIColor.redColor().CGColor
        
        self.cornersLayer.strokeColor = UIColor.yellowColor().CGColor
        
        self.tapHandler = { point in
            println(point)
        }
        
        self.barcodesHandler = { barcodes in
            
            // Get first barcode scanned into ViewController.shoppinglist
            for barcode in barcodes {
                
                println("Barcode found: type=" + barcode.type + " value=" + barcode.stringValue)
    
                var item = shopListItems.count;
                
                shopListItems.append("item" + toString(item+1) + ": " + barcode.stringValue)
                
                self.session.stopRunning()
                self.performSegueWithIdentifier("GoBackToShopList", sender: nil)
                
                return
            }
        }
        
    }
    
}