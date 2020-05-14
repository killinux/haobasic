//http://www.blogjava.net/linli/archive/2014/10/21/418910.html  
var express = require('express'),  
app = express(),  
server = require('http').createServer(app);  
server.listen(3000);  
app.get('/', function(req, res) {  
    res.sendFile(__dirname + '/webrtc6.html');  
});  
var WebSocketServer = require('ws').Server,  
wss = new WebSocketServer({server: server});  
ws_map = new Map(),
wss.on('connection', function(ws) {  
 //   console.log('connection:');  
    console.log('connection:\t'+JSON.stringify(ws,null,'\t'));  
    ws.on('message', function(message) {  
        var json = JSON.parse(message);  
        console.log('conn map length: ' + ws_map.size );  
        console.log("json:"+json.event+",name:"+json.name+",role:"+json.role);  
		var thisrole = "callee";
		var wsname;
		if(json.role!=null && json.role == "caller"){
			wsname=json.name+"callee";
		}else{
			wsname=json.name+"caller";
		}
		if(json.event != 'connect'){
			console.log("wsname:"+wsname);
			var otherwx = ws_map.get(wsname);
			if(otherwx){
				otherwx.send(message, function (error) {
          		    if (error) {
          		        console.log('Send message error (' + desc + '): ', error);
          		    }
          		});
			}else{
				console.error("error:not find the connection:"+wsname);
			}
		}else{
			console.log("will add "+json.name+json.role);
			ws_map.set(json.name+json.role,ws)
		}
    });  
});  
wss.on("close",function(ws){
	console.log("close-----");
})
