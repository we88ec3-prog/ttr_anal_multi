
void FUN_007f7450(undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int unaff_ESI;
  int iVar3;
  
  puVar1 = (undefined4 *)FUN_00891268(0x78);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[0x1c] = 0;
    puVar1[0x1a] = 0;
    puVar1[0x1d] = 0;
    puVar1[1] = 0;
    puVar1[0x1b] = 2;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[3] = 0;
    iVar2 = (param_2 + -1) * unaff_ESI;
    puVar1[5] = iVar2;
    iVar3 = unaff_ESI * param_2 + -1;
    iVar2 = iVar2 + iVar3 + unaff_ESI + -1;
    puVar1[4] = unaff_ESI + -1;
    puVar1[6] = iVar3;
    puVar1[2] = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
  }
  *param_1 = puVar1;
  FUN_007ffa00();
  FUN_007ffd20(param_3);
  param_1[1] = (unaff_ESI + -1) * (param_2 + -1) * 6;
  return;
}

