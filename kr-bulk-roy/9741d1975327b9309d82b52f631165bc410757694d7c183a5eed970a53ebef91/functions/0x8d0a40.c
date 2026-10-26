
undefined4 FUN_008d0a40(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 != 0) {
    iVar1 = *(int *)(param_1 + 0xc);
    if (*(uint *)(iVar1 + 4) <
        (uint)((int)*(short *)(iVar1 + 0x16) + *(short *)(iVar1 + 0x3a) + param_2)) {
      uVar2 = FUN_008bc9a0(iVar1,param_2,0);
      return uVar2;
    }
  }
  return 0;
}

