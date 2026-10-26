
int FUN_00405300(int param_1)

{
  undefined4 *puVar1;
  int in_EAX;
  
  FUN_004026e0(in_EAX,0,0xffffffff);
  if ((undefined4 *)(param_1 + 0x1c) != (undefined4 *)(in_EAX + 0x1c)) {
    puVar1 = *(undefined4 **)(in_EAX + 0x1c);
    FUN_00405100(*puVar1,puVar1,param_1);
  }
  if (param_1 + 0x28 != in_EAX + 0x28) {
    FUN_006d7120(**(undefined4 **)(param_1 + 0x2c),*(undefined4 **)(param_1 + 0x2c));
    FUN_00405270(in_EAX + 0x28);
  }
  return param_1;
}

