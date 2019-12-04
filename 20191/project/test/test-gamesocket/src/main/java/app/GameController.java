package app;

import org.springframework.web.bind.annotation.*;

import jdk.internal.module.IllegalAccessLogger.Mode;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import java.util.ArrayList;
import java.util.List;

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

    private void khoiTao(List<Integer> list) {
        list.add(1);
        for (int i = 0; i < 5; i++) {
            list.add(5);
        }
        list.add(1);
        for (int i = 0; i < 5; i++) {
            list.add(5);
        }
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

    @RequestMapping("/go")
    public String render(Model model, @RequestParam(value = "index", required = true) int index, @RequestParam(value = "direction", required = true) String direction, @RequestParam (value = "orderUser", required = true) int orderUser)
            throws InterruptedException {
        String url = "http://localhost:8080/hello/render";
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

        return render(model);
    }

    @RequestMapping(value = "/ingame",method = RequestMethod.GET)
    public String ingame(Model model){
        if (this.check == false) {
            this.khoiTao(new ArrayList<>());
            this.check = true;
        }
        return render(model);
            
        
    }


    public String render(Model model){
        model.addAttribute("lists", list);
        model.addAttribute("diem1", pointUser1);
        model.addAttribute("diem2", pointUser2);
        model.addAttribute("u11", list.get(1));
        model.addAttribute("u12", list.get(2));
        model.addAttribute("u13", list.get(3));
        model.addAttribute("u14", list.get(4));
        model.addAttribute("u15", list.get(5));
        model.addAttribute("u21", list.get(7));
        model.addAttribute("u22", list.get(8));
        model.addAttribute("u23", list.get(9));
        model.addAttribute("u24", list.get(10));
        model.addAttribute("u25", list.get(11));
        model.addAttribute("Q1", list.get(0));
        model.addAttribute("Q2", list.get(6));
        return "ingame";

    }
    
}