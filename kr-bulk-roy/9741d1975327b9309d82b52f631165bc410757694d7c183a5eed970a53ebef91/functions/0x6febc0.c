
undefined4 * FUN_006febc0(int param_1,void *param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  size_t unaff_EDI;
  
  if (0xffffffed < unaff_EDI + 1) {
    FUN_006f8b60(param_1,"memory allocation error: block too big");
  }
  puVar3 = (undefined4 *)FUN_00700880(param_1,0,0,unaff_EDI + 0x11);
  puVar3[3] = unaff_EDI;
  puVar3[2] = param_3;
  *(byte *)((int)puVar3 + 5) = *(byte *)(*(int *)(param_1 + 0x10) + 0x14) & 3;
  *(undefined1 *)(puVar3 + 1) = 4;
  *(undefined1 *)((int)puVar3 + 6) = 0;
  FID_conflict__memcpy(puVar3 + 4,param_2,unaff_EDI);
  *(undefined1 *)((int)puVar3 + unaff_EDI + 0x10) = 0;
  piVar1 = *(int **)(param_1 + 0x10);
  param_3 = param_3 & piVar1[2] - 1U;
  *puVar3 = *(undefined4 *)(*piVar1 + param_3 * 4);
  *(undefined4 **)(*piVar1 + param_3 * 4) = puVar3;
  piVar1[1] = piVar1[1] + 1;
  uVar2 = piVar1[2];
  if ((uVar2 < (uint)piVar1[1]) && ((int)uVar2 < 0x3fffffff)) {
    FUN_006feb00(param_1,uVar2 * 2);
  }
  return puVar3;
}

