
void FUN_008c34c0(int param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  
  if (param_3 == '\0') {
    iVar1 = (**(code **)(param_1 + 0x1fc))(param_1,0x68686561,param_2,0);
    if (iVar1 != 0) {
      return;
    }
    param_1 = param_1 + 0xd8;
  }
  else {
    iVar1 = (**(code **)(param_1 + 0x1fc))(param_1,0x76686561);
    if (iVar1 != 0) {
      return;
    }
    param_1 = param_1 + 0x128;
  }
  iVar1 = FUN_008bacd0(param_2,&DAT_00bd8030,param_1);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  return;
}

