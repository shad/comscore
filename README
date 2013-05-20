comScore Module
===============

To build your project, you will need to do the following.  The framework is 
referenced there during the link phase of the build.

1. Create directory /opt/frameworks
2. ln -s comScore.framework /opt/frameworks/comScore.framework


To Use
======

1. Put the module whever you put your modules
2. Add the following line in your tiapp.xml
    <module version="0.1" platform="iphone">com.foodonthetable.comscore</module>
    
3. Add code like this to your app.js

    require('com.foodonthetable.comscore').start({
      appName:'Your App',
      customerC2:'1234567',
      providerSecret:'YOUR_SECRET_PROVIDER_CODE'
    });
