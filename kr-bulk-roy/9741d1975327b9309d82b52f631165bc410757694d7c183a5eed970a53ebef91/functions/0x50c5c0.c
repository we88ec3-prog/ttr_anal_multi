
void FUN_0050c5c0(int param_1)

{
  int in_EAX;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8;
  undefined1 local_7;
  
  if (in_EAX - 1U < 5) {
    if (*(char *)(param_1 + 0xc + in_EAX * 0x10) != '\0') {
      local_10 = 0x2a;
      local_c = 0;
      local_8 = (undefined1)in_EAX;
      local_7 = 1;
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&local_10,10);
      }
      FUN_004054c0();
      FUN_0058aad0(0xf4277);
      return;
    }
  }
  else {
    FUN_006edb60(&DAT_00c0ded8);
  }
  return;
}

