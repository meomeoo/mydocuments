public class NhanVien1 {
    public void prin(){
        int a = 5, b=5;
        System.out.println(--a);
        System.out.println(b--);
        System.out.println(b);
    }


    public NhanVien1(String ten, double luongcoban, double hesoluong){        
        this.tenNhanVien1 = ten;
        this.luongCoBan = luongcoban;
        this.heSoLuong = hesoluong;

    }

    public NhanVien1(){
        this("khanh", 13, 13 );
    }

    public void setName(String ten, double luongcoban, double hesoluong){        
        this.tenNhanVien1 = ten;
        this.luongCoBan = luongcoban;
        this.heSoLuong = hesoluong;

    }


    public void setName(){
        setName("khanh", 14, 14 );
    }
  
    private String tenNhanVien1 ;
    private double luongCoBan ;
    private double heSoLuong ;
    public double LUONG_MAX = 10000;

    public void setTenNhanVien1 (String ten){
        tenNhanVien1 = ten;
    }

    public void setLuongCoBan( double luongcoban){
        luongCoBan = luongcoban;
    }

    public void setHeSoLuong( double hesoluong){
        heSoLuong = hesoluong;
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
        System.out.println(" ten cua nhan vien:" + tenNhanVien1); 
        System.out.println("luong cua nhan vien la:" + luongCoBan);
        System.out.println("he so luong:" + heSoLuong);
        
        
    }
    public static void main(String[] args){
        NhanVien1 NhanVien11 = new NhanVien1();
        NhanVien11.inTTin();
        NhanVien11.prin();

        
    }  
}
