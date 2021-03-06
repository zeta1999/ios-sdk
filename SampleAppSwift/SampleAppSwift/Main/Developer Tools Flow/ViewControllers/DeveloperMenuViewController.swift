//
//  DeveloperMenuViewController.swift
//  SampleAppSwift
//
//  Created by Synerise
//  Copyright (c) 2018 Synerise. All rights reserved.
//

import UIKit
import SyneriseSDK
import Crashlytics

protocol DeveloperMenuViewControllerDelegate: class {
    func resetApplicationWasPressed(_ developerMenuViewController: DeveloperMenuViewController)
}

class DeveloperMenuViewController: DefaultViewController {
    
    weak var delegate: DeveloperMenuViewControllerDelegate?

    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.navigationItem.title = "VIEW_CONTROLLER_DEVELOPER_MENU_TITLE".localized()
        
        prepareLeftMenuButton()
        prepareBackButton()
    }
    
    @IBAction func showChat() {
        let chat = Chat(trackerKey: "EFC7C4F2-6F57-4A5A-ACD0-D339C7BCADF2")
        chat.navigationBarBackgroundColor = UIColor.gray
        chat.navigationBarTitle = "Chat"
        chat.navigationBarTitleColor = UIColor.white
        chat.closeButtonHorizontalAlignment = .left
        chat.closeButtonImage = UIImage(named: "icon_close_black_small")!
        chat.closeButtonTintColor = UIColor.lightGray
        chat.load()
        chat.show()
    }
    
    @IBAction func switchToSyneriseMobileApps1() {
        let clientApiKey: String = Configuration.SyneriseSDK.clientAPIKey1
        
        showLoading()
        Synerise.changeClientApiKey(clientApiKey)
        
        let settingsService = ServiceProvider.resolve().getSettingsService()
        settingsService.set(clientApiKey, forKey: SettingsServiceKey.syneriseClientAPIKey)
    
        DispatchQueue.main.asyncAfter(deadline: .now() + 1) {
            self.hideLoading()
            self.showSuccessInfo("Current Synerise SDK profile", text: "Synerise Mobile Apps 1", debug: false)
        }
    }
    
    @IBAction func switchToSyneriseMobileApps2() {
        let clientApiKey: String = Configuration.SyneriseSDK.clientAPIKey2
        
        showLoading()
        Synerise.changeClientApiKey(clientApiKey)
        
        let settingsService = ServiceProvider.resolve().getSettingsService()
        settingsService.set(clientApiKey, forKey: SettingsServiceKey.syneriseClientAPIKey)
        
        DispatchQueue.main.asyncAfter(deadline: .now() + 1) {
            self.hideLoading()
            self.showSuccessInfo("Current Synerise SDK profile", text: "Synerise Mobile Apps 2", debug: false)
        }
    }
    
    @IBAction func resetApplication() {
        delegate?.resetApplicationWasPressed(self)
        
        Crashlytics.sharedInstance().crash()
    }
    
    @IBAction func executeCrash() {
        let exception = NSException(name: NSExceptionName.genericException, reason: "Synerise Test Crash", userInfo: nil)
        exception.raise()
    }
    
    @IBAction func removeAllKeychainData() {
        let secItemClasses = [kSecClassGenericPassword, kSecClassInternetPassword, kSecClassCertificate, kSecClassKey, kSecClassIdentity]
        for itemClass in secItemClasses {
            let spec: NSDictionary = [kSecClass: itemClass]
            SecItemDelete(spec)
        }
        
        NSException(name: NSExceptionName.genericException, reason: "Restart after removing all items in Keychain                       ", userInfo: nil).raise()
    }
}

extension DeveloperMenuViewController: ChatDelegate {
    func snr_chatIsLoading(isLoading: Bool) {

    }

    func snr_chatDidLoad() {

    }

    func snr_chatDidNotLoad(error: Error) {

    }
}
