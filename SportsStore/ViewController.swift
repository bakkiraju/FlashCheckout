//
//  ViewController.swift
//  SportsStore
//
//  Created by Bilahari Akkiraju on 5/3/15.
//  Copyright (c) 2015 shtick. All rights reserved.
//

import UIKit
import AVFoundation

var shopListItems = [String]();

class ViewController: UIViewController, UITableViewDelegate, UITableViewDataSource, AVCaptureMetadataOutputObjectsDelegate

{

    @IBOutlet weak var RecentsBarItem: UITabBarItem!
    
    var captureSession:AVCaptureSession?
    
    var videoPreviewLayer:AVCaptureVideoPreviewLayer?
    
    var qrCodeFrameView:UIView?
    
    var estimatedRowHeightCache:NSMutableDictionary?

    @IBOutlet weak var shopListTbl: UITableView!
    
       
    // put height to cache
    func putEstimatedCellHeightToCache(indexPath:NSIndexPath, height:CGFloat) {
        initEstimatedRowHeightCacheIfNeeded()
        self.estimatedRowHeightCache!.setValue(Float(height),forKey:String(indexPath.row));
    }
    
    // get height from cache
    func getEstimatedCellHeightFromCache(indexPath:NSIndexPath , defaultHeight:CGFloat)->CGFloat
    {
        self.initEstimatedRowHeightCacheIfNeeded();
        
        var estimatedHeight : NSNumber?
        
        if (estimatedRowHeightCache != nil) {
            if (estimatedRowHeightCache!.valueForKey(String(indexPath.row)) == nil) {
                return defaultHeight;
            }
            
            estimatedHeight = estimatedRowHeightCache!.valueForKey(String(indexPath.row))! as? NSNumber
        }
        
        
       if (estimatedHeight != nil) {
            println("cached: %f", estimatedHeight!.floatValue);
           return  CGFloat(estimatedHeight!.floatValue);
        }
        
        println("not cached: %f", defaultHeight)
        
        return defaultHeight;
    }
    
    
    // check if height is on cache
    func isEstimatedRowHeightInCache(indexPath:NSIndexPath)->Bool
    {
        if (self.getEstimatedCellHeightFromCache(indexPath,defaultHeight: 0.0) > 0.0) {
            return true
        }
        return false
    }
    
    // init cache
    func initEstimatedRowHeightCacheIfNeeded() {
        if (self.estimatedRowHeightCache == nil) {
            self.estimatedRowHeightCache = NSMutableDictionary()
       }
    }
    
    // custom [self.tableView reloadData]
    func tableViewReloadData() {
        // clear cache on reload
        self.estimatedRowHeightCache = NSMutableDictionary()
        shopListTbl.reloadData()
    }
    
    func tableView(tableView:UITableView, numberOfRowsInSection section: Int) -> Int
    {
        return shopListItems.count;
    }
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell
    {
        var cell = UITableViewCell(style: UITableViewCellStyle.Default, reuseIdentifier: "Cell")
        
        cell.textLabel?.text = shopListItems[indexPath.row];
        
        if (!self.isEstimatedRowHeightInCache(indexPath)) {
           // CGSize cellSize = [cell systemLayoutSizeFittingSize:CGSizeMake(self.view.frame.size.width, 0) withHorizontalFittingPriority:1000.0 verticalFittingPriority:50.0];
            
            var cellSize: CGSize = cell.systemLayoutSizeFittingSize(CGSizeMake(self.view.frame.size.width, 0), withHorizontalFittingPriority: 1000.0, verticalFittingPriority: 50.0)
            
            self.putEstimatedCellHeightToCache(indexPath, height:cellSize.height);
        }
        
        return cell;
    }
    
    func tableView(tableView: UITableView, commitEditingStyle editingStyle: UITableViewCellEditingStyle, forRowAtIndexPath indexPath: NSIndexPath) {
        
        if editingStyle == UITableViewCellEditingStyle.Delete
        {
            shopListItems.removeAtIndex(indexPath.row)
            
            shopListTbl.reloadData()
        }
    }
    
    
    func tableView(tableView: UITableView, estimatedHeightForRowAtIndexPath indexPath: NSIndexPath) -> CGFloat {
        return getEstimatedCellHeightFromCache(indexPath, defaultHeight:41.5);
    }
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    
    override func viewDidAppear(animated: Bool) {
        
        shopListTbl.reloadData()
        
    }
}

