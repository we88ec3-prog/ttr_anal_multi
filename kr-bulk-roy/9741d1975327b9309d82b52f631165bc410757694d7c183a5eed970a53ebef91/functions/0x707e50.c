
undefined4 FUN_00707e50(int param_1)

{
  char *_Filename;
  undefined4 *puVar1;
  FILE *pFVar2;
  undefined4 uVar3;
  char *local_8;
  
  _Filename = (char *)FUN_006f6210(param_1);
  puVar1 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
  if (((puVar1 < *(undefined4 **)(param_1 + 8)) && (puVar1 != &DAT_00c0bfc8)) &&
     (0 < *(int *)(*(int *)(param_1 + 0xc) + 0x18))) {
    local_8 = (char *)FUN_006f6210(param_1);
  }
  else {
    local_8 = "r";
  }
  puVar1 = (undefined4 *)FUN_00707a00();
  pFVar2 = _fopen(_Filename,local_8);
  *puVar1 = pFVar2;
  if (pFVar2 == (FILE *)0x0) {
    uVar3 = FUN_007077c0(0);
    return uVar3;
  }
  return 1;
}

