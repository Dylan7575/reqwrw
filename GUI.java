/**
 * Created by dylanlafrenz on 11/6/16.
 */
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.net.Socket;

public class GUI extends Frame implements MouseListener {
    public static void main(String args[]){
        GUI f = new GUI();
    }
    public GUI(){
        Button b = new Button("Year");
        b.setName("Year");
        b.setBounds(30,40,80,30);
        b.addMouseListener(this);
        add(b);

        Button m = new Button("Month");
        m.setName("Year");
        m.setBounds(30,80,80,30);
        m.addMouseListener(this);
        add(m);

        Button d = new Button("Day");
        d.setName("Year");
        d.setBounds(30,120,80,30);
        d.addMouseListener(this);
        add(d);

        Button h = new Button("Hour");
        h.setName("Year");
        h.setBounds(30,160,80,30);
        h.addMouseListener(this);
        add(h);

        Button a = new Button("Minute");
        a.setName("Year");
        a.setBounds(30,200,80,30);
        a.addMouseListener(this);
        add(a);

        Button s = new Button("Second");
        s.setName("Year");
        s.setBounds(30,240,80,30);
        s.addMouseListener(this);
        add(s);







        setSize(300,300);
        setLayout(null);

        setVisible(true);
    }
    public void mousePressed(MouseEvent e) {
    }

    public void mouseReleased(MouseEvent e) {

    }

    public void mouseEntered(MouseEvent e) {

    }

    public void mouseExited(MouseEvent e) {

    }

    public void mouseClicked(MouseEvent e) {
       String f =e.getComponent().getName();
        TextField temp = new TextField();
        try{
            Socket connectSocket = new Socket("127.0.0.1",23660);


        }
        catch(Exception n){
            temp.setText("error");
        }

        temp.setText("2016");
        temp.setEditable(false);
        temp.setBounds(170,125,100,100);
        add(temp);

    }
}
