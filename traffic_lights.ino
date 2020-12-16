// biến này lưu giá trị của biến trở.
int sensorValue = 0;

// khai báo led tại các chân
int redLight1 = 13;
int redLight2 = 12;
int greenLight1 = 8;
int greenLight2 = 7;
int yellowLight1 = 4;
int yellowLight2 = 2; 

//khai báo thời gian cho đèn xanh, đỏ, vàng
unsigned long greenTime, redTime, yellowTime = 5000;

void setup() {
  // nhận input từ A0
  pinMode(A0, INPUT);
  // output ra các LED đã khai báo
  pinMode(redLight1, OUTPUT);
  pinMode(redLight2, OUTPUT);
  pinMode(greenLight1, OUTPUT);
  pinMode(greenLight2, OUTPUT);
  pinMode(yellowLight1, OUTPUT);
  pinMode(yellowLight2, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  // đọc giá trị từ biến trở
 while(true) {
  sensorValue = analogRead(A0);
  // thời gian của đèn xanh sẽ tương ứng với khoảng 0 - 1023 nhận được từ biến trở. Tỉ lệ 1023:100000 
 greenTime = map(sensorValue,0,1023,0,100000);  
 
 Serial.println(greenTime);
 delay(500);
 }
  
 // greenTime = 5000;
    // tính thời gian dừng đèn đỏ
  redTime = greenTime + 5000;
  // bắt đầu đổi màu đèn
  
  // đèn đỏ 1 sáng, đèn xanh 2 sáng. Còn lại tắt.
  changeLights(HIGH, LOW, LOW, HIGH, LOW, LOW);
  delay(greenTime);
  // đèn đỏ 1 sáng, đèn vàng sáng. Còn lại tắt.
  changeLights(HIGH, LOW, LOW, LOW, LOW, HIGH);
  delay(yellowTime);
  // tương tự
  changeLights(LOW, HIGH, HIGH, LOW, LOW, LOW);
  delay(greenTime);
  changeLights(LOW, HIGH, LOW, LOW, HIGH, LOW);
  delay(yellowTime);
}

void changeLights(int r1, int r2, int g1, int g2, int y1, int y2){
  digitalWrite(redLight1, r1);
  digitalWrite(redLight2, r2);
  digitalWrite(greenLight1, g1);
  digitalWrite(greenLight2, g2);
  digitalWrite(yellowLight1, y1);
  digitalWrite(yellowLight2, y2);
}
