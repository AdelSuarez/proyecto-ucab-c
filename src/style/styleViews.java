
package style;
import java.awt.Image;
import java.awt.Toolkit;
import javax.swing.JFrame;

public class styleViews extends javax.swing.JFrame{
    
    public static void configuracionesVentana(JFrame ventana,int ancho, int altura, String titulo){
        ventana.setSize(ancho, altura);
        ventana.setResizable(false);
        ventana.setTitle(titulo);
        ventana.setLocationRelativeTo(null);
    }

    public Image getIconImage(String urlImage) {
        Image retValue = Toolkit.getDefaultToolkit().getImage(ClassLoader.getSystemResource(urlImage));
        return retValue;
    }
    
}
