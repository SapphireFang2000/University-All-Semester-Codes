import java.io.IOException;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class flashCardAssignment extends Application 
{
    @Override
    public void start(Stage primaryStage) throws IOException 
    {
      FXMLLoader loader =new FXMLLoader(getClass().getResource("card.fxml"));
        Parent root =loader.load();
        
        Scene scene = new Scene(root);
        
        primaryStage.setTitle("FlashCard");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
        
    public static void main(String[] args) 
    {
        launch(args);
    }
    
}
