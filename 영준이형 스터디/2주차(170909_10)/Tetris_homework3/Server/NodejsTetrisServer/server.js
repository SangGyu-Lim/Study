var express = require('express');
var app = express();

var server = require('http').createServer(app);
var io = require('socket.io').listen(server);

app.set('port', process.env.PORT || 999);
//server.us

var clients = [];

io.on('connection', function (socket) {

    var currentUser;

    socket.on('USER_CONNECT', function (data){
        console.log('user connected');

        console.log(data);

        var jsonData = JSON.parse(data);

        currentUser = {
            id: socket.id,
            name: jsonData.name
        };

        console.log('user id >> ' + currentUser.id + ' is connected...');

        // 클라에 아이디 저장
        socket.emit('USER_CONNECTED', currentUser);
        clients.push(currentUser);

    });

    socket.on('USER_READY', function () {
        console.log('user ready');

        for (var i = 0; i < clients.length; i++) {
            io.sockets.emit('USER_READY', clients[i]);
        }
    });

    socket.on('CHECK_MULTI', function (data) {
        console.log('check multi');

        if (clients.length === 2) {
            io.sockets.emit('GAME_START', null);
        }

    });


    socket.on('UPDATE_BLOCK', function (data) {
        console.log('update block');

        console.log(data);

        var jsonData = JSON.parse(data);
        socket.broadcast.emit('UPDATE_BLOCK', jsonData);
        
    });

    socket.on('GAME_OVER', function () {
        console.log('game over');

        socket.broadcast.emit('GAME_OVER', null);
    });

    socket.on('disconnect', function () {
        socket.broadcast.emit('USER_DISCONNECTED', currentUser);
        for (var i = 0; i < clients.length; i++)
        {
            if (clients[i].name === currentUser.name)
            {
                console.log('user ' + clients[i].name + ' disconnect...');
                clients.splice(i, 1);
            }
        }
    });
});

server.listen(app.get('port'), function () {
    console.log('--------- SERVER IS RUNNING -----------');
});



/*
var io = require('socket.io').listen(999);

io.sockets.on('connection', function (socket) {
    console.log('connection');

    socket.on('Msg', function (data) {
        console.log(data);
        socket.emit('MsgRes', data);
    });

    
    //socket.on('USER_CONNECT', function () {
    //    console.log('user connect');

    //    for (var i = 0; i < clients.length; i++)
    //    {
    //        socket.emit('USER_CONNECTED', {
    //            name: clients[i].name,
    //            id: clients[i].id
    //        });

    //        console.log('user name >> ' + clients[i].name + ' is connected...');
    //    }

    //});
    
});
*/









































/*
// 기본 웹 서버 방식
'use strict';
var http = require('http');
var url = require('url');
var port = process.env.PORT || 1337;
var qs = require('querystring');

var server = http.createServer();
server.listen(port, function ()
{
    console.log('Start Server Listen...');
});

server.on('request', function (req, res) {
    console.log('on request');

    if (req.method != 'POST') {
        console.log('not post');
        return;
    }

    var postData = '';
    req.on('error', (err) => {
        console.error(err);
    }).on('data', function (data) {
        postData += data;
        }).on('end', () => {
            var post = qs.parse(postData);
            console.log(post['id']);
            res.end('Hello ' + post['id']);
        });

    

});
*/