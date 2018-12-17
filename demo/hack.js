/*****************************************************************************
 * Copyright (c) 2018, Dubo Dubon Duponey <dubodubonduponey+github@pm.me>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

/*
BEWARE: HACK #1 - on windows, QT 5.0.2, if the object node has flexible dimensions,
QtWebKit is gonna crash.
In order to obtain a flexible widget (eg: width=75%), the following script helper is provided.
This is not bullet-proof, but should work with percented width/height and in-flow, no kinky positioning.
In case you would want to do some more kinky resizing stuff, and still count on the node to adapt,
you should call:
node.crashing && node.forceResize()
whenever you need it to refresh itself.
*/

var chuckyTheEnforcer = function(node){
    var parentStyle = getComputedStyle(node.parentNode);
    if(node.originalWidth)
        node.style.width = (parseInt(parentStyle.width, 10) * node.originalWidth) + 'px';
    if(node.originalHeight)
        node.style.height = (parseInt(parentStyle.height, 10) * node.originalHeight) + 'px';
    // Dare to comment this out, and it will crash again. Interesting stuff, right?
    var query = [parentStyle.width, parentStyle.height];
};

var forceManualResize = function(node){
    if(node.originalWidth === undefined){
        node.originalWidth = node.style.width.match(/([0-9-]+)%$/);
        node.originalHeight = node.style.height.match(/([0-9-]+)%$/);
        if(node.originalWidth)
            node.originalWidth = node.originalWidth.pop() / 100;
        if(node.originalHeight)
            node.originalHeight = node.originalHeight.pop() / 100;
            console.warn("hohoho", node.originalWidth, node.originalHeight);
        if(node.originalWidth || node.originalHeight){
            chuckyTheEnforcer(node);
            node.forceResize = chuckyTheEnforcer.bind({}, node);
            window.addEventListener('resize', node.forceResize, false);
        }
    }
};

window.addEventListener('load', function(){
    var videos = document.getElementsByTagName('object');
    for(var x = 0; x < videos.length; x++){
        if(videos[x].crashing)
            forceManualResize(videos[x]);
    }
}, true);

document.addEventListener('DOMNodeInserted', function(e){
    if(e.target.crashing)
        forceManualResize(e.target);
}, true);



/*
BEWARE: HACK #2 - on windows (again!) I couldn't find a way to be notified
of mousemove events occuring on the video node, which is quite annoying if one
wants to show / hide some UI with a fullscreen video.
The following hack palliate that, if needed by the platform.
Do nothing otherwise.
*/

//document.addEventListener('mousemove', function(e){
//    console.warn('move on document', e.clientX, e.clientY);
//}, true);



var checkInfluence = function(){
    var candidate = document.querySelector('object[type="video/x-dubo"]');
    return (candidate && candidate.underTheInfluence.length)? candidate.underTheInfluence : false;
};

var lastX;
var lastY;
var poller;

var sayHello = function(x, y){
    var evt = document.createEvent('MouseEvents');
    evt.initMouseEvent('mousemove', true, false, window, 0, x, y, x, y, false, false, false, false, 0, null);
    document.dispatchEvent(evt);
};

var pollFun = function(){
    var newC = checkInfluence();
    if(newC[0] != lastX || newC[1] != lastY)
        sayHello(newC[0], newC[1]);
    lastX = newC[0];
    lastY = newC[1];
};

var startPoller = function(newC, e){
    console.warn('Trying my best to still forward mouse events');
    lastX = newC[0];
    lastY = newC[1];
    poller = window.setInterval(pollFun, 100);
};

var stopPoller = function(){
    window.clearInterval(poller);
};

document.addEventListener('mouseover', function(e){
    stopPoller();
}, true);

document.addEventListener('mouseout', function(e){
    if(!e.relatedTarget){
        var newC = checkInfluence();
        if(newC)
            startPoller(newC, e);
    }    
}, true);

