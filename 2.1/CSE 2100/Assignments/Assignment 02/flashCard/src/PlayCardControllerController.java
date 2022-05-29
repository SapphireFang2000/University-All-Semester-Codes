import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.URL;
import static java.time.Clock.system;
import java.util.ArrayList;
import java.util.ResourceBundle;
import java.util.Scanner;
import static javafx.application.Platform.exit;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.stage.FileChooser;
import javafx.stage.Stage;

public class PlayCardControllerController implements Initializable 
{
    @FXML
    private TextField tfQuestionSpace;
    @FXML
    private Button btExit;
    @FXML
    private Button btFile;
    @FXML
    private Button btHome;
    @FXML
    private Button btShowAns;
    FileChooser fileChooser = new FileChooser();
    ArrayList<String> string = new ArrayList<String>();
    private int count = 1;

    @Override
    public void initialize(URL url, ResourceBundle rb) 
    {
       
    }

    @FXML
    private void questionSpaceFunc(ActionEvent event) 
    {
        
    }

    @FXML
    private void showAnsFunc(ActionEvent event) 
    {
        if (count != string.size()) 
        {
            if (count % 2 == 0 || count == 0) 
            {
                tfQuestionSpace.setText(string.get(count));
                count++;

            } 
            else 
            {
                tfQuestionSpace.setText(string.get(count));
                count++;
            }
        } 
        else 
        {
            btShowAns.setDisable(true);
            tfQuestionSpace.setDisable(true);
        }
    }

    @FXML
    private void fileFunc(ActionEvent event) 
    {
      try 
      {
        Stage primaryStage = (Stage) ((Node) event.getSource()).getScene().getWindow();
        File myObj = fileChooser.showOpenDialog(primaryStage);
        Scanner myReader = new Scanner(myObj);
        while (myReader.hasNextLine()) 
        {
            String data = myReader.nextLine();
            string.add(data);
        }
        tfQuestionSpace.setText(string.get(0));
        myReader.close();
      } 
      catch (FileNotFoundException e) 
      {
        e.printStackTrace();
      }   
    }

    @FXML
    private void homeFunc(ActionEvent event) throws IOException 
    {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("card.fxml"));
        Parent root = loader.load();

        Scene scene = new Scene(root);

        Stage stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
        stage.setScene(scene);
        stage.setTitle("Flashcard");
        stage.show();

    }

    @FXML
    private void exitFunc(ActionEvent event) 
    {
        exit();
    }

}
