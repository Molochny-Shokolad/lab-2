#define WIFI_SSID "**********"
#define WIFI_PASS "**********"
#define BOT_TOKEN "***********************************************"
#include <FastBot.h>
FastBot bot(BOT_TOKEN);
void setup() {
    connectWiFi();
    bot.attach(newMsg);
}
void newMsg(FB_msg& msg) {
    String tem = "("+msg.chatID+", "+msg.username+", "+msg.text+")";
    if(msg.text == "Hello") {
        String otp = "Привет!";
        bot.sendMessage(otp, msg.chatID);
        otp = "На сообщение отправить == "+otp;
        Serial.println(tem+otp);
    }
    Serial.println(tem);
}
void loop() {
    bot.tick();
}
void connectWiFi() {
    delay(2000);
    Serial.begin(115200);
    Serial.println();
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        if (millis() > 15000) ESP.restart();
    }
    Serial.println("Connected");
}