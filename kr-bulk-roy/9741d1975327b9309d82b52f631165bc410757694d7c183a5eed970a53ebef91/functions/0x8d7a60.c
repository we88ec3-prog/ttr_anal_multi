
void FUN_008d7a60(void)

{
  int in_EAX;
  
  if (*(code **)(in_EAX + 0x8c) != (code *)0x0) {
    (**(code **)(in_EAX + 0x8c))(in_EAX + 0x5c);
  }
  if (*(code **)(in_EAX + 0xf8) != (code *)0x0) {
    (**(code **)(in_EAX + 0xf8))(in_EAX + 200);
  }
  if (*(code **)(in_EAX + 0xc4) != (code *)0x0) {
    (**(code **)(in_EAX + 0xc4))(in_EAX + 0x94);
  }
  if (*(code **)(in_EAX + 300) != (code *)0x0) {
    (**(code **)(in_EAX + 300))(in_EAX + 0xfc);
  }
  FUN_008d6b00();
  return;
}

