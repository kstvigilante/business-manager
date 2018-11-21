import { FlowRouter } from 'meteor/kadira:flow-router';
import { BlazeLayout } from 'meteor/kadira:blaze-layout';

import "../../ui/layout/body/body.js";
import "../../pages/business/business.js"
import "../../pages/business-manager-home/business-manager-home.js"

FlowRouter.route('/', {
    name: 'App_business_manager_home',
    action() {
        BlazeLayout.render('App_body', { main: 'App_business_manager_home' });
    },
});

FlowRouter.route('/business', {
    name: 'App_business',
    action() {
        BlazeLayout.render('App_body', { main: 'App_business' });
    },
});