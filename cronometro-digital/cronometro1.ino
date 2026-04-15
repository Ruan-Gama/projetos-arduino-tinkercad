int A = 10;
int B = 11;
int C = 12;
int D = 13;

void setup()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
}

void loop()
{
  for(int i=9;i>=0;i--){
    switch(i){
    case 0: exiba(0,0,0,0); break;
    case 1: exiba(0,0,0,1); break;
    case 2: exiba(0,0,1,0); break;
    case 3: exiba(0,0,1,1); break;
    case 4: exiba(0,1,0,0); break;
    case 5: exiba(0,1,0,1); break;
    case 6: exiba(0,1,1,0); break;
    case 7: exiba(0,1,1,1); break;
    case 8: exiba(1,0,0,0); break;
    case 9: exiba(1,0,0,1); break;
  }
    delay(1000);
  }
}

void exiba(int d, int c, int b, int a)
{
  digitalWrite(A,a);
  digitalWrite(B,b);
  digitalWrite(C,c);
  digitalWrite(D,d);
}

/*
void zero()
{
  digitalWrite(A,0);
  digitalWrite(B,0);
  digitalWrite(C,0);
  digitalWrite(D,0);
}

void sete()
{
  digitalWrite(A,1);
  digitalWrite(B,1);
  digitalWrite(C,1);
  digitalWrite(D,0);
}
*/