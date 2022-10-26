package com.example.ques_answer

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.CheckBox
import android.widget.TextView

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val result = findViewById<TextView>(R.id.Result_Tv)
        val answer_one = findViewById<CheckBox>(R.id.checkBox1)
        val answer_two = findViewById<CheckBox>(R.id.checkBox2)
        val answer_three = findViewById<CheckBox>(R.id.checkBox3)

        val submit = findViewById<Button>(R.id.submit_btn)

        submit.setOnClickListener {


             if(answer_one.isChecked){
                result.text = "Right Answer!"
            }
             if(answer_two.isChecked || answer_three.isChecked){
                 result.text = "Wrong Answer!"
             }

            if((answer_one.isChecked && answer_two.isChecked && answer_three.isChecked) || (answer_one.isChecked && answer_two.isChecked) ||
                (answer_two.isChecked && answer_three.isChecked) || (answer_one.isChecked && answer_three.isChecked)){
                result.text = "Please Select Only One Option!"
            }
            if(!answer_one.isChecked && !answer_two.isChecked && !answer_three.isChecked){
                result.text = "Please Choose One Option!"
            }



        }


    }
}