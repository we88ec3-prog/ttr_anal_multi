
int FUN_008f1a40(void)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EBX;
  int unaff_ESI;
  undefined2 *puVar5;
  uint local_c;
  int local_8;
  
  uVar3 = *(undefined4 *)(unaff_EBX + 0x1c);
  local_8 = (**(code **)(unaff_ESI + 0x1fc))();
  if (local_8 != 0) {
    *(undefined4 *)(unaff_ESI + 0x284) = 0;
    *(undefined4 *)(unaff_ESI + 0x288) = 0;
    return 0;
  }
  *(uint *)(unaff_ESI + 0x284) = local_c >> 1;
  uVar3 = FUN_008bc7d0(uVar3,2,0,local_c >> 1,0,&local_8);
  *(undefined4 *)(unaff_ESI + 0x288) = uVar3;
  if ((local_8 == 0) && (local_8 = FUN_008babe0(), local_8 == 0)) {
    puVar5 = *(undefined2 **)(unaff_ESI + 0x288);
    puVar1 = puVar5 + *(int *)(unaff_ESI + 0x284);
    for (; puVar5 < puVar1; puVar5 = puVar5 + 1) {
      uVar2 = FUN_008b9960();
      *puVar5 = uVar2;
    }
    FUN_008baca0();
    if (*(char *)(unaff_ESI + 0x2a0) != '\0') {
      iVar4 = FUN_008f0fe0();
      return iVar4;
    }
  }
  return local_8;
}

