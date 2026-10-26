
void FUN_004f3000(undefined4 param_1,char param_2,undefined4 param_3)

{
  int iVar1;
  undefined2 local_16;
  undefined4 local_14;
  uint local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = FUN_00404ba0();
  local_8 = *(undefined4 *)(iVar1 + 0x5f50);
  local_16 = 0xb3;
  local_14 = param_1;
  local_10 = (uint)(param_2 == '\0');
  local_c = param_3;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_16,0x12);
  }
  return;
}

