
undefined4 * FUN_007ffb50(undefined4 param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_ESI;
  int unaff_EDI;
  
  puVar1 = (undefined4 *)FUN_00891268(0x78);
  puVar3 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[0x1a] = 0;
    puVar1[0x1c] = 0;
    puVar1[0x1d] = 0;
    puVar1[0x1b] = 2;
    puVar1[1] = param_1;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar3 = puVar1;
  }
  puVar3[3] = param_2;
  iVar2 = param_2 + param_3 + unaff_EDI + unaff_ESI;
  puVar3[4] = param_3;
  puVar3[2] = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
  puVar3[5] = unaff_EDI;
  puVar3[6] = unaff_ESI;
  return puVar3;
}

