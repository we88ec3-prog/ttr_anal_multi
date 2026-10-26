
undefined4 FUN_008b8ce0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x5c), iVar1 != 0)) {
    uVar2 = (**(code **)(*(int *)(iVar1 + 0xc) + 0xc))(iVar1,param_2);
  }
  return uVar2;
}

