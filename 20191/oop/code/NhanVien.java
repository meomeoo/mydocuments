public class NhanVien {
  
    private String tenNhanVien ;
    private double luongCoBan ;
    private double heSoLuong ;
    public double LUONG_MAX = 10000;

    public void setTenNhanVien (String ten){
        tenNhanVien = ten;
    }

    public void setLuongCoBan( double luongcoban){
        luongCoBan = luongcoban;
    }

    public void setHeSoLuong( double hesoluong){
        heSoLuong = hesoluong;
    }

    public NhanVien set(String ten, double luongcoban, double hesoluong){
        setTenNhanVien(ten);
        setLuongCoBan(luongcoban);
        setHeSoLuong(hesoluong);
        return this;
    }

    public boolean tangLuong (double heso){
        heSoLuong = heSoLuong + heso;
        if(tinhLuong() > LUONG_MAX ){
            System.out.println("khong thay doi he so luong!");
            heSoLuong = heSoLuong - heso;
            return false;
        }
        else 
            return true;
    }

    public double tinhLuong() {
        return luongCoBan * heSoLuong;
    }

    public void inTTin(){
        System.out.println(" ten cua nhan vien:" + tenNhanVien); 
        System.out.println("luong cua nhan vien la:" + luongCoBan);
        System.out.println("he so luong:" + heSoLuong);
        
    }


    public static void main(String[] args){
    NhanVien nhanvien1 = new NhanVien();
    nhanvien1.set("dinh ngoc khanh", 12 ,12).inTTin();
} 
}



    
