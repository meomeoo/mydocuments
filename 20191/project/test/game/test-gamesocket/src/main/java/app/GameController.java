package app;

import java.lang.InterruptedException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import java.io.*;
import java.net.*;
import java.util.Scanner;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;
import app.WebsocketServer;
import ch.qos.logback.core.joran.conditional.ElseAction;

import com.google.gson.Gson;

@Controller
@RequestMapping("/game")
public class GameController {

    private static java.util.List<Integer> list = new ArrayList<>();
    private static boolean check = false;
    private static int order = 0;
    private static int pointUser1 = 0;
    private static boolean runAgain = true;
    private static boolean stop = false;
    private static int pointUser2 = 0;
    private static int indexReal;
    private static boolean Quan1 = true;
    private static boolean Quan2 = true;

    public final static byte[] BUFFER = new byte[1000]; // Vùng đệm chứa dữ liệu cho gói tin nhận

    private void khoiTao(List<Integer> list) {
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

    private int checkVitriTru1(int viTriNow, String orient) {
        if (viTriNow == 0 && orient.equals("left"))
            return 11;
        if (viTriNow == 11 && orient.equals("right"))
            return 0;
        if (orient.equals("left"))
            return viTriNow - 1;
        if (orient.equals("right"))
            return viTriNow + 1;
        return 0;
    }

    private void law(int orderUser, String derection, int indexReal) {
        runAgain = false;
        int viTriT1 = checkVitriTru1(indexReal, derection);
        int viTriT2 = checkVitriTru1(viTriT1, derection);
        if ((viTriT1 == 0 || viTriT1 == 6) && list.get(viTriT1) != 0) {
            runAgain = false;
        } else {
            if ((viTriT1 == 1 || viTriT1 == 11 || viTriT1 == 7 || viTriT1 == 5) && (viTriT2 == 0 || viTriT2 == 6)
                    && list.get(viTriT1) == 0 && list.get(viTriT2) != 0 && Quan1 == true && Quan2 == true) {
                if (orderUser == 0) {
                    pointUser1 = pointUser1 + list.get(viTriT2) + 9;
                    list.set(viTriT2, 0);
                }
                ;
                if (orderUser == 1) {
                    pointUser2 = pointUser2 + list.get(viTriT2) + 9;
                    list.set(viTriT2, 0);
                }
                ;
                runAgain = false;
                Quan1 = viTriT2 != 0 ? false : true;
                Quan2 = viTriT2 != 6 ? false : true;
                if (runAgain == false)
                    law(orderUser, derection, viTriT2);
            }
            if (list.get(viTriT1) == 0 && list.get(viTriT2) != 0) {
                if (orderUser == 0) {
                    pointUser1 = pointUser1 + list.get(viTriT2);
                    list.set(viTriT2, 0);
                }
                ;
                if (orderUser == 1) {
                    pointUser2 = pointUser2 + list.get(viTriT2);
                    list.set(viTriT2, 0);
                }
                ;
                runAgain = false;
                if (runAgain == false)
                    law(orderUser, derection, viTriT2);
            }
            if ((list.get(viTriT1) == 0 && list.get(viTriT2) == 0))
                runAgain = false;
            if ((list.get(viTriT1) != 0 && list.get(viTriT2) != 0))
                runAgain = true;
            if (list.get(0) == 0 && list.get(6) == 0) {
                for (int i = 1; i <= 5; i++)
                    pointUser1 = pointUser1 + list.get(i);
                for (int i = 6; i <= 11; i++)
                    pointUser2 = pointUser2 + list.get(i);
                stop = true;
                runAgain = false;
            }
        }
    }

    private boolean checkRun(int index, int orderUser) {
        if (list.get(index) == 0 && orderUser == 0)
            return false;
        if (list.get(index + 6) == 0 && orderUser == 1)
            return false;
        return true;
    }

    public void go(int index, String direction, int orderUser) throws InterruptedException {
        if (this.check == false) {
            this.khoiTao(new ArrayList<>());
            this.check = true;
        }
        if (checkRun(index, orderUser) != false) {

            indexReal = index;
            indexReal = orderUser == 0 ? index : index + 6;
            if (order == orderUser) {

                if (list.get(1) == 0 && list.get(2) == 0 && list.get(3) == 0 && list.get(4) == 0 && list.get(5) == 0
                        && orderUser == 0) {
                    list.set(1, 1);
                    list.set(2, 1);
                    list.set(3, 1);
                    list.set(4, 1);
                    list.set(5, 1);
                }
                if (list.get(7) == 0 && list.get(8) == 0 && list.get(9) == 0 && list.get(10) == 0 && list.get(11) == 0
                        && orderUser == 1) {
                    list.set(7, 1);
                    list.set(8, 1);
                    list.set(9, 1);
                    list.set(10, 1);
                    list.set(11, 1);
                }
                while (runAgain == true && stop != true) {
                    if (orderUser == 0 && index >= 1 && index <= 5) {
                        int a = list.get(indexReal);
                        list.set(indexReal, 0);
                        if (direction.equals("right")) {
                            for (int i = 0; i < a; i++) {
                                indexReal = indexReal == 11 ? 0 : ++indexReal;
                                list.set(indexReal, list.get(indexReal) + 1);
                            }
                            law(orderUser, direction, indexReal);
                            if (runAgain == false) {
                                order = 1;
                            }
                        } else if (direction.equals("left")) {
                            for (int i = 0; i < a; i++) {
                                indexReal = indexReal == 0 ? 11 : --indexReal;
                                list.set(indexReal, list.get(indexReal) + 1);
                            }
                            law(orderUser, direction, indexReal);
                            if (runAgain == false) {
                                order = 1;
                            }
                        }
                    } else if (orderUser == 1 && index >= 1 && index <= 5) {
                        int a = list.get(indexReal);
                        list.set(indexReal, 0);
                        if (direction.equals("left")) {
                            for (int i = 0; i < a; i++) {
                                indexReal = indexReal == 0 ? 11 : --indexReal;
                                list.set(index, list.get(index) + 1);
                            }
                            law(orderUser, "right", indexReal);
                            if (runAgain == false) {
                                order = 0;
                            }
                        } else if (direction.equals("right")) {
                            for (int i = 0; i < a; i++) {
                                indexReal = indexReal == 11 ? 0 : ++indexReal;
                                list.set(indexReal, list.get(indexReal) + 1);
                            }
                            law(orderUser, direction, indexReal);
                            if (runAgain == false) {
                                order = 0;
                            }
                        }
                    }
                    indexReal++;
                }
            }
        }

        runAgain = true;

    }

    @RequestMapping(value = "/ingame", method = RequestMethod.GET)
    public String ingame(Model model) {
        if (this.check == false) {
            this.khoiTao(new ArrayList<>());
            this.check = true;
        }

        return "ingame";
    }

    @RequestMapping(value = "/socket", method = RequestMethod.GET)
    public void socket() throws IOException, InterruptedException {

        // Create DatagramSocket and get ip
        DatagramSocket ss = new DatagramSocket(1234);
        InetAddress ip = InetAddress.getLocalHost();

        System.out.println("Running UnSyncChatServer.java");

        System.out.println("Server is Up....");

        // Create a sender thread
        // with a nested runnable class definition
        Thread ssend;
        ssend = new Thread(new Runnable() {
            @Override
            public void run() {
            

                try {
                    while (true) {
                        synchronized (this)

                        {
                            DatagramPacket incoming = new DatagramPacket(BUFFER, BUFFER.length);
                            ss.receive(incoming); // Chờ nhận gói tin gởi đến
                            String message = new String(incoming.getData(), 0, incoming.getLength());
                            String json;
                            char[] mes = message.toCharArray();
                            int[] d = new int[3];
                            int n = 0;
                            System.out.println("Received from Bot:");
                            for (int i = 0; i < mes.length; i++) {
                                if (mes[i] <= '9' && mes[i] >= '0') {
                                    d[n] = mes[i] - '0';

                                    System.out.print(d[n]+ ",");
                                    ++n;
                                    
                                }
                            }
                            System.out.println();


                            if(d[1] == 0 && stop == false && d[1]<6 && d[1]>1){
                                go(d[0], "left", d[2]);
                                list.set(12,pointUser1);
                                list.set(13,pointUser2);
                                json = new Gson().toJson(list );
                                WebsocketServer.send(json);
                            }
                            else if(d[1] == 1 && stop == false ){
                                go(d[0], "right", d[2]);
                                list.set(12,pointUser1);
                                list.set(13,pointUser2);
                                json = new Gson().toJson(list );
                                WebsocketServer.send(json);
                            }
                            else if (stop == true){
                                list.set(12,pointUser1);
                                list.set(13,pointUser2);
                                for(int i = 0; i<12;++i){
                                    list.set(i, 0);
                                }
                                json = new Gson().toJson(list );

                            }else{
                                String not = "0";
                                DatagramPacket outsending = new DatagramPacket(not.getBytes(), not.getBytes().length,
                                    incoming.getAddress(), incoming.getPort());

                               // send the new packet
                                ss.send(outsending);

                                System.out.println("Server says to Client: " + not);
                                continue;
                            }
                            
                            
                            // scan new message to send
                            DatagramPacket outsending = new DatagramPacket(json.getBytes(), json.getBytes().length,
                                    incoming.getAddress(), incoming.getPort());

                            // send the new packet
                            ss.send(outsending);

                            System.out.println("Server says to Client: " + json);

                            // exit condition
                            if ((message).equals("bye")) {
                                System.out.println("Server" + " exiting... ");
                                break;
                            }
                            System.out.println("Waiting for" + " client response... ");
                        }
                    }
                }

                catch (Exception e) {
                    System.out.println("Exception occured");
                }
            }
        });

        ssend.start();

        ssend.join();
    }

}
