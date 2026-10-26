
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int FUN_007438c0(int param_1)

{
  int iVar1;
  int iVar2;
  void *_Src;
  undefined4 uVar3;
  uint *in_ECX;
  uint local_5010;
  uint local_500c;
  undefined1 local_5008 [20480];
  undefined4 uStack_8;
  
  iVar1 = param_1;
  uStack_8 = 0x7438cd;
  iVar2 = FUN_00743980();
  if ((iVar2 != *(int *)(iVar1 + 4)) &&
     ((*(uint *)(iVar2 + 0x14) < in_ECX[1] ||
      ((*(uint *)(iVar2 + 0x14) <= in_ECX[1] && (*(uint *)(iVar2 + 0x10) <= *in_ECX)))))) {
    return iVar2 + 0x18;
  }
  _Src = (void *)FUN_00743120();
  local_5010 = *in_ECX;
  local_500c = in_ECX[1];
  FID_conflict__memcpy(local_5008,_Src,0x2800);
  uVar3 = FUN_00743e70(&local_5010);
  FUN_007439c0(&param_1,iVar2,uVar3);
  return param_1 + 0x18;
}

