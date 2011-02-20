/*
Copyright (c) 2010-2011, Peter Hajas
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Peter Hajas nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL PETER HAJAS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#import "MNAlertData.h"

#define kPendingActive 0
#define kSentActive 1
#define kDismissActive 2

@class MNAlertDashboardViewController;
@protocol MNAlertDashboardViewControllerProtocol
- (void)actionOnAlertAtIndex:(int)index inArray:(int)array;
- (NSMutableArray *)getPendingAlerts;
- (NSMutableArray *)getSentAwayAlerts;
- (NSMutableArray *)getDismissedAlerts;
@end

@interface MNAlertDashboardViewController : NSObject <UITableViewDelegate, UITableViewDataSource>
{
	UISegmentedControl *picker;
	UITableView *tableView;
	UIWindow *window;
	NSMutableArray *activeArrayReference;
	
	int activeArray;
	
	id <MNAlertDashboardViewControllerProtocol> _delegate;
}

-(void)toggleDashboard;
-(void)hideDashboard;
-(void)showDashboard;
-(void)activeArrayChanged:(id)sender;

@property (nonatomic, retain) UISegmentedControl *picker;
@property (nonatomic, retain) UITableView *tableView;
@property (nonatomic, retain) UIWindow *window;

@property (nonatomic, retain) id <MNAlertDashboardViewControllerProtocol> delegate;

@end