package com.q2i.q2iprov;
import android.os.StrictMode;

import java.net.*;
import java.io.*;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

public class DatahubCASA {


private static String url_login ="https://www.q2i-casa.com/api/v1/auth/sign_in";
public static String res="";
public static List<String> field = new LinkedList<String>();

    public DatahubCASA(){

}


public Map<String, List<String>> authenticate(String email, String password)throws MalformedURLException, IOException, UnsupportedEncodingException{
//    StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
//    StrictMode.setThreadPolicy(policy);
    String res = "";

    BufferedReader reader=null;


        // Defined URL  where to send data
        URL url = new URL(this.url_login);
        String data = URLEncoder.encode("email", "UTF-8")
                + "=" + URLEncoder.encode(email, "UTF-8");

        data += "&" + URLEncoder.encode("password", "UTF-8") + "="
                + URLEncoder.encode(password, "UTF-8");
        // Send POST data request

        URLConnection conn = url.openConnection();
        conn.setDoOutput(true);
        OutputStreamWriter wr = new OutputStreamWriter(conn.getOutputStream());
        wr.write( data );
        wr.flush();

        // Get the server response

        reader = new BufferedReader(new InputStreamReader(conn.getInputStream()));
        StringBuilder sb = new StringBuilder();
        String line = null;

        // Read Server Response
        while((line = reader.readLine()) != null)
        {
            // Append server response in string
            sb.append(line + "\n");
        }
        this.res=sb.toString();
        conn.getHeaderFields();
        String expiry = conn.getHeaderField("expiry");
        String token = conn.getHeaderField("access-token");
        String client =  conn.getHeaderField("client");
        String uid = conn.getHeaderField("uid");
        String content = conn.getHeaderField("Content-Type");

        this.field.add(expiry);//0
        this.field.add(token);//1
        this.field.add(client);//2
        this.field.add(uid);//3
        this.field.add(content);//4



    return         conn.getHeaderFields();




}
public String getUser(){
    return this.res;
}
public List<String> getStuff()
{
    return this.field;
}//    public native void CreateUser(String my_name,String my_provider_id,String my_username, String my_lastname);
//    public native String getProvider_id();
//    public native String getGender();
//    public native String getBirthdate();
//    public native String getLastName();
//    public native String getName();
//    public native String Email();
//    public native String Username();


    static {
        System.loadLibrary("native-lib");
    }



}
