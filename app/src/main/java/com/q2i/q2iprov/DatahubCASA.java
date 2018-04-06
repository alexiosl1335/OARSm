package com.q2i.q2iprov;

public class DatahubCASA {

private static String url_conversations = "";
private static String url_profile = "";
private static String url_journals = "";
private static String url_calendar ="";
private static String url_login ="https://www.q2i-casa.com/api/v1/auth/sign_in";

public DatahubCASA(){

}


public boolean authenticate(){




    return false;

}
//    public native User User();

    static {
        System.loadLibrary("native-lib");
    }
}
