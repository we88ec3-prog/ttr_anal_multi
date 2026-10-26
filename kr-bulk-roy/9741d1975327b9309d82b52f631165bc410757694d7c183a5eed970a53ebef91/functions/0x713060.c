
void FUN_00713060(int *param_1)

{
  int in_EAX;
  undefined4 local_20 [2];
  undefined8 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = 0;
  local_c = 0xffffffff;
  local_10 = 0xffffffff;
  local_20[0] = 5;
  if (in_EAX == 0) {
    if (((*param_1 != 5) || (param_1[4] != -1)) || (param_1[5] != -1)) {
      FUN_007126a0();
    }
    FUN_00712ea0(0x12,param_1,local_20);
  }
  else {
    if (in_EAX == 1) {
      FUN_00712ce0();
      return;
    }
    if (in_EAX == 2) {
      FUN_007126a0();
      FUN_00712ea0(0x14,param_1,local_20);
      return;
    }
  }
  return;
}

