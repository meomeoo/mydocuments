package app;
import org.java_websocket.WebSocket;
import org.java_websocket.handshake.ClientHandshake;
import org.java_websocket.server.WebSocketServer;

import java.net.InetSocketAddress;
import java.util.HashSet;
import java.util.Set;
import java.util.List;
import com.google.gson.Gson;
import java.util.ArrayList;




public class WebsocketServer extends WebSocketServer {
    List<Integer> list = new ArrayList<>();


    private static int TCP_PORT = 4444;

    private static Set<WebSocket> conns;

    public WebsocketServer() {
        super(new InetSocketAddress(TCP_PORT));
        conns = new HashSet<>();
    }
    void khoiTao(List<Integer> list) {
        list.add(1);
        for (int i = 0; i < 5; i++) {
            list.add(5);
        }
        list.add(1);
        for (int i = 0; i < 5; i++) {
            list.add(5);
        }
        list.add(0);
        list.add(0);
        this.list = list;
    }

    @Override
    public void onOpen(WebSocket conn, ClientHandshake handshake) {
        conns.add(conn);
        System.out.println(conn);
        System.out.println("New connection from " + conn.getRemoteSocketAddress().getAddress().getHostAddress());
        khoiTao(list);
        String json = new Gson().toJson(list );
        WebsocketServer.send(json);
        
         
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