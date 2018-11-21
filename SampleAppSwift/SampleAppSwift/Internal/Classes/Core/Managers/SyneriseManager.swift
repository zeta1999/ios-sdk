//
//  SyneriseManager.swift
//  SampleAppSwift
//
//  Created by Synerise
//  Copyright (c) 2018 Synerise. All rights reserved.
//

import Foundation
import SyneriseSDK
import Swinject

class SyneriseManager {
    
    var settingsService: SettingsService!
    
    private let clientApiKey: String

    // MARK: - Initializers

    init(clientApiKey: String) {
        self.clientApiKey = clientApiKey
    }

    // MARK: - Public

    func initialize() {
        DebugUtils.print("SyneriseSDK initializing | Client API Key: \(clientApiKey)")
        Synerise.initialize(clientApiKey: clientApiKey)
        Synerise.setDelegate(self)
        
        Synerise.notificationServiceSettings.disableInAppAlerts = settingsService.get(.syneriseDisableInAppAlertsKey) ?? false
        Synerise.notificationServiceSettings.appGroupIdentifier = "group.com.synerise.sdk.sample"
        
        Tracker.setLoggingEnabled(true)
        Tracker.setAutoTrackMode(.fine)
        
        Client.setLoggingEnabled(true)

        Injector.setLoggingEnabled(true)
        Injector.setAutomatic(true)
        
        var trackerConfiguration = TrackerConfiguration()
        trackerConfiguration.autoFlushTimeout = 1
        trackerConfiguration.minBatchSize = 1
        trackerConfiguration.maxBatchSize = 100
        
        Tracker.setConfiguration(trackerConfiguration)
        Tracker.setLoggingEnabled(true)
        Tracker.setAutoTrackMode(.fine)
    }
    
    func isSignedIn() -> Bool {
        return Client.isSignedIn()
    }
    
    func signOut() {
        Client.signOut()
    }
}

extension SyneriseManager: SyneriseDelegate {
    func snr_handledAction(url: URL) {
        if UIApplication.shared.canOpenURL(url) {
            if #available(iOS 10, *) {
                UIApplication.shared.open(url, options: [:], completionHandler: nil)
            } else {
                UIApplication.shared.openURL(url)
            }
        }
    }

    func snr_handledAction(deepLink: String) {
        let viewController = DebugTextViewController(text: "DEEP LINKING")
        viewController.view.backgroundColor = UIColor.lightGray
        
        ApplicationController.resolve().appRouter.rootViewController?.present(viewController, animated: true, completion: {
            viewController.dismiss(animated: true, completion: nil)
        })
    }
}

extension SyneriseManager: NotificationServiceDelegate {

    func notificationService(_ notificationService: NotificationService, didReceiveToken token: String, origin: NotificationService.TokenOrigin) {
        if origin == NotificationService.TokenOrigin.firebase {
            Client.registerForPush(registrationToken: token,
                                    success: { (_) in
                                        DebugUtils.print("Synerise push registration success")
            },
                                    failure: { (error) in
                                        DebugUtils.print("Synerise push registration failure: \(error.localizedDescription)")
            })
        }
    }

    func notificationService(_ notificationService: NotificationService, didReceiveNotification notification: NotificationService.Notification) {
        let userInfo = notification.userInfo
        let isSyneriseNotification: Bool = Synerise.isSyneriseNotification(userInfo)
        if isSyneriseNotification {
            Synerise.handleNotification(userInfo)
        } else {

        }
    }
    
    func notificationService(_ notificationService: NotificationService, didReceiveNotificationResponse response: UNNotificationResponse, notification: NotificationService.Notification) {
        let userInfo = notification.userInfo
        let isSyneriseNotification: Bool = Synerise.isSyneriseNotification(userInfo)
        if isSyneriseNotification {
            Synerise.handleNotification(userInfo, actionIdentifier: response.actionIdentifier)
        }
    }
}

extension SyneriseManager: Registerable {
    static func register(inContainer container: Container) {
        container.register(SyneriseManager.self) { _ in
            let serviceProvider = container.resolve(ServiceProvider.self)
            let settingsService = serviceProvider!.getSettingsService()
            
            guard let clientApiKey: String = settingsService.get(SettingsServiceKey.syneriseClientAPIKey) else {
                fatalError()
            }
            
            return SyneriseManager(
                clientApiKey: clientApiKey
            )
        }
        .initCompleted({ (resolver, syneriseManager) in
            let serviceProvider = container.resolve(ServiceProvider.self)
            let settingsService = serviceProvider!.getSettingsService()
            
            syneriseManager.settingsService = settingsService
        })
        .inObjectScope(.container)
    }
}

extension SyneriseManager: Resolvable {
    typealias ObjectType = SyneriseManager

    static func resolve() -> ObjectType {
        return Administrator.assembly.resolve(SyneriseManager.self)!
    }
}
