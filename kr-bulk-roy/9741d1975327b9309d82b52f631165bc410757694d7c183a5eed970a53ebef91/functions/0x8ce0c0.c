
int FUN_008ce0c0(uint *param_1,int *param_2)

{
  uint uVar1;
  int in_ECX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint *unaff_ESI;
  uint uVar4;
  int iVar5;
  
  uVar4 = *param_1;
  uVar1 = FUN_008bc7d0();
  unaff_ESI[3] = uVar1;
  if (in_ECX == 0) {
    uVar1 = FUN_008bc7d0();
    unaff_ESI[2] = uVar1;
    uVar1 = FUN_008bc7d0();
    unaff_ESI[6] = uVar1;
    unaff_ESI[4] = unaff_ESI[3] + uVar4 * 4;
    puVar2 = (undefined4 *)unaff_ESI[2];
    *unaff_ESI = uVar4;
    unaff_ESI[1] = 0;
    unaff_ESI[5] = 0;
    unaff_ESI[7] = 0;
    puVar3 = (undefined4 *)param_1[2];
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar2 = *puVar3;
      puVar2[1] = puVar3[1];
      puVar2[4] = puVar3[2];
      puVar2 = puVar2 + 7;
      puVar3 = puVar3 + 3;
    }
    if (param_2 != (int *)0x0) {
      iVar5 = *param_2;
      unaff_ESI[8] = (uint)param_2;
      for (; iVar5 != 0; iVar5 = iVar5 + -1) {
        FUN_008ce060();
      }
    }
    uVar4 = *unaff_ESI;
    if ((unaff_ESI[1] != uVar4) && (uVar1 = 0, uVar4 != 0)) {
      do {
        FUN_008cdfe0();
        uVar1 = uVar1 + 1;
      } while (uVar1 < uVar4);
    }
  }
  return in_ECX;
}

