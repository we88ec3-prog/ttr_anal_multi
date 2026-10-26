
undefined4 FUN_008c4880(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (0xffff < param_2) {
    return 0;
  }
  if ((*(byte *)(param_1 + 0x14) & 1) != 0) {
    uVar1 = FUN_008c41a0(param_1,&param_2);
    return uVar1;
  }
  uVar1 = FUN_008c4370(param_1,&param_2,0);
  return uVar1;
}

