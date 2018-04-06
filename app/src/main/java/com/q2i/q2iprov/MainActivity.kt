package com.q2i.q2iprov

import android.content.Intent
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button
import com.q2i.q2iprov.R.id.container

import kotlinx.android.synthetic.main.activity_main.*
import org.jetbrains.anko.toast
class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        // Example of a call to a native method

    }
    fun click(v: View?) {

        when (v?.id) {
            R.id.button2 -> {

                val intent = Intent(this,LoginCASA::class.java)
                startActivity(intent)
            }

            else -> {
            }
        }
    }
//     fun click(){
//        val intent = Intent(this,LoginCASA::class.java)
//        startActivity(intent)
//    }
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
//    external fun stringFromJNI(): String
//
//    companion object {
//
//        // Used to load the 'native-lib' library on application startup.
//        init {
//            System.loadLibrary("native-lib")
//
//        }
//    }

}
