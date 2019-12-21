package app;
import org.java_websocket.WebSocket;
import org.java_websocket.handshake.ClientHandshake;
import org.java_websocket.server.WebSocketServer;

import java.net.InetSocketAddress;
import java.util.HashSet;
import java.util.Set;

public class WebsocketServer extends WebSocketServer {

    private static int TCP_PORT = 4444;

    private static Set<WebSocket> conns;

    public WebsocketServer() {
        super(new InetSocketAddress(TCP_PORT));
        conns = new HashSet<>();
    }

    @Override
    public void onOpen(WebSocket conn, ClientHandshake handshake) {
        conns.add(conn);
        System.out.println(conn);
        System.out.println("New connection from " + conn.getRemoteSocketAddress().getAddress().getHostAddress());
         
    }

    @Override
    public void onClose(WebSocket conn, int code, String reason, boolean remote) {
        conns.remove(conn);
        System.out.println("Closed connection to " + conn.getRemoteSocketAddress().getAddress().getHostAddress());
    }

    @Override
    public void onMessage(WebSocket conn, String message) {
        WebsocketServer.send(message);
    }

    @Override
    public void onError(WebSocket conn, Exception ex) {
        //ex.printStackTrace();
        if (conn != null) {
            conns.remove(conn);
            // do some thing if required
        }
        System.out.println("ERROR from " + conn.getRemoteSocketAddress().getAddress().getHostAddress());
    }

    static public void send(String message){
        System.out.println("send to client:"+ message);
        for (WebSocket sock : conns) {
            sock.send(message);
        }

    }
}