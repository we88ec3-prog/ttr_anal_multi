
undefined4 FUN_00549e10(void)

{
  float *pfVar1;
  bool bVar2;
  int iVar3;
  int unaff_ESI;
  float10 fVar4;
  undefined1 local_19;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  
  local_10 = *(float *)(unaff_ESI + 100) - *(float *)(*(int *)(unaff_ESI + 0x50) + 0xa0);
  local_c = *(float *)(unaff_ESI + 0x68) - *(float *)(*(int *)(unaff_ESI + 0x50) + 0xa4);
  local_18 = local_c * local_c + local_10 * local_10;
  if ((*(int *)(unaff_ESI + 0xac + *(int *)(unaff_ESI + 0x108) * 0x10) == 1) && (5.0 < local_18)) {
    *(undefined4 *)(unaff_ESI + 0xac + *(int *)(unaff_ESI + 0x108) * 0x10) = 2;
  }
  if (*(float *)(unaff_ESI + 0x7c + *(int *)(unaff_ESI + 0x10c) * 0x10) < local_18) {
    *(undefined4 *)(unaff_ESI + (*(int *)(unaff_ESI + 0x108) + 0xb) * 0x10) = 0;
    *(undefined4 *)(unaff_ESI + 0xac + *(int *)(unaff_ESI + 0x108) * 0x10) = 3;
  }
  iVar3 = *(int *)(unaff_ESI + 0xac + *(int *)(unaff_ESI + 0x108) * 0x10);
  if ((iVar3 != 2) && (iVar3 != 3)) {
    return 0;
  }
  local_19 = *(undefined1 *)(*(int *)(unaff_ESI + 0x50) + 0xb0);
  bVar2 = true;
  iVar3 = FUN_005495f0(unaff_ESI);
  if (((iVar3 != -1) &&
      (pfVar1 = (float *)(unaff_ESI + 0xa8 + iVar3 * 0x10), pfVar1 != (float *)0x0)) &&
     (local_18 = *pfVar1, local_18 != 0.0)) {
    iVar3 = FUN_0040f060();
    FUN_0082ef00(&local_18);
    if ((local_10 != *(float *)(iVar3 + 0xc)) && (*(int *)((int)local_10 + 0x10) != 0)) {
      local_18 = *(float *)(unaff_ESI + 100) - *(float *)(*(int *)(unaff_ESI + 0x50) + 0xa0);
      local_14 = *(float *)(unaff_ESI + 0x68) - *(float *)(*(int *)(unaff_ESI + 0x50) + 0xa4);
      local_10 = local_14 * local_14 + local_18 * local_18;
      if (5.0 < local_10) {
        iVar3 = FUN_0040f060();
        if (*(int *)(iVar3 + 0xa4) != 0) {
          iVar3 = FUN_0082d790(*(int *)(iVar3 + 0xa4),&local_10,
                               *(undefined4 *)(*(int *)(unaff_ESI + 0x50) + 0xa0),
                               *(undefined4 *)(*(int *)(unaff_ESI + 0x50) + 0xa4),
                               *(undefined4 *)(unaff_ESI + 100),*(undefined4 *)(unaff_ESI + 0x68));
          if (iVar3 != 0) {
            if (iVar3 - 1U < 3) {
              fVar4 = (float10)FUN_0049aeb0();
              local_19 = FUN_004bb450((float)fVar4);
            }
            goto LAB_0054a004;
          }
        }
        fVar4 = (float10)FUN_0049aeb0();
        local_19 = FUN_004bb450((float)fVar4);
        goto LAB_0054a004;
      }
      local_19 = *(undefined1 *)(*(int *)(unaff_ESI + 0x54) + 0xb0);
    }
  }
  bVar2 = false;
LAB_0054a004:
  *(ushort *)(unaff_ESI + 0x72) = (ushort)bVar2 << 0xf;
  *(undefined1 *)(unaff_ESI + 0x74) = local_19;
  if (!bVar2) {
    *(undefined4 *)(unaff_ESI + 0xac + *(int *)(unaff_ESI + 0x108) * 0x10) = 1;
    return 0;
  }
  return 1;
}

