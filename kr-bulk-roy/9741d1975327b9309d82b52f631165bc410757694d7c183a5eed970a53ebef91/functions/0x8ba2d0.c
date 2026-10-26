
void FUN_008ba2d0(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x1c);
    FUN_008b97c0(param_1);
    if (param_2 == 0) {
      FUN_008b9f80(uVar1,param_1);
    }
  }
  return;
}

