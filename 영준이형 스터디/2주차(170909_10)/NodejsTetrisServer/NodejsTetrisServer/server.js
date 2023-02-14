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
