import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.application.Platform;
import static javafx.application.Platform.exit;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Iterator;
import javafx.stage.FileChooser;
import javafx.stage.Window;

public class CreatCardController implements Initializable 
{
    @FXML
    private TextField tfQuestion;
    @FXML
    private TextField tfAnswer;
    @FXML
    private Button btNext;
    @FXML
    private Button btSave;

    @FXML
    private Button btHome;

    ArrayList<Card> cardList = new ArrayList<Card>();

    FileChooser fileChooser = new FileChooser();
    private Window primaryStage;

    @Override
    public void initialize(URL url, ResourceBundle rb) 
    {
        // TODO
    }

    @FXML
    private void questionFunc(ActionEvent event) 
    {
        
    }

    @FXML
    private void answerFunc(ActionEvent event) 
    {
        
    }

    @FXML
    void saveFunc(ActionEvent event) throws IOException 
    {
        File file = fileChooser.showSaveDialog(new Stage());

        if (file != null) 
        {
            SaveSystem(file);
        }

    }

    @FXML
    void homeFunc(ActionEvent event) throws IOException 
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
    void nextFunc(ActionEvent event) 
    {
        Card card = new Card(tfQuestion.getText(), tfAnswer.getText());
        cardList.add(card);
        tfQuestion.clear();
        tfAnswer.clear();
    }

    private void SaveSystem(File file) throws IOException 
    {
        BufferedWriter writer = new BufferedWriter(new FileWriter(file));
        Iterator<Card> cardIterator = cardList.iterator();
        while (cardIterator.hasNext()) 
        {
            Card c = (Card) cardIterator.next();
            writer.write(c.getQuestion() + "\n");
            writer.write(c.getAnswer() + "\n");
        }
        writer.close();
    }

}
