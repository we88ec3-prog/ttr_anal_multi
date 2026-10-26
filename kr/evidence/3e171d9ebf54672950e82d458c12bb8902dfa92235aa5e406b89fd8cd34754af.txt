
void FUN_00544020(void)

{
  int in_EAX;
  undefined2 local_c;
  undefined2 local_a;
  undefined2 local_8;
  
  local_a = *(undefined2 *)(in_EAX + 0xf4);
  local_8 = *(undefined2 *)(in_EAX + 0xf6);
  local_c = 0x1c;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_c,6);
  }
  return;
}

