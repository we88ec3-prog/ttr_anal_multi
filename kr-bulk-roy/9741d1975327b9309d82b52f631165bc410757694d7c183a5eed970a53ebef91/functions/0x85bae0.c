
/* WARNING: Removing unreachable block (ram,0x0085bb3b) */
/* WARNING: Removing unreachable block (ram,0x0085bb40) */

undefined4 FUN_0085bae0(void)

{
  byte bVar1;
  void *_Dst;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  int unaff_EDI;
  bool bVar5;
  undefined1 local_4c [36];
  int local_28;
  undefined1 local_20 [4];
  uint local_1c;
  int local_10;
  byte *local_c;
  uint local_8;
  
  FUN_0085e020(unaff_EDI + 0x20,&local_10,*(undefined4 *)(unaff_EDI + 0x20),
               *(undefined4 *)(unaff_EDI + 0x24));
  _Dst = *(void **)(unaff_EDI + 0x10);
  if (_Dst != *(void **)(unaff_EDI + 0x14)) {
    FID_conflict__memcpy(_Dst,*(void **)(unaff_EDI + 0x14),0);
    *(void **)(unaff_EDI + 0x14) = _Dst;
  }
  if (*(int *)(unaff_EDI + 0x8c) != *(int *)(unaff_EDI + 0x90)) {
    *(int *)(unaff_EDI + 0x90) = *(int *)(unaff_EDI + 0x8c);
  }
  (**(code **)(**(int **)(unaff_EDI + 4) + 0xc))(*(int **)(unaff_EDI + 4),local_20);
  local_8 = 0;
  if (local_1c != 0) {
    do {
      iVar2 = (**(code **)(**(int **)(unaff_EDI + 4) + 0x20))(*(int **)(unaff_EDI + 4),0,local_8);
      local_10 = iVar2;
      if (iVar2 != 0) {
        (**(code **)(**(int **)(unaff_EDI + 4) + 0x10))(*(int **)(unaff_EDI + 4),iVar2,local_4c);
        iVar2 = (**(code **)(**(int **)(unaff_EDI + 4) + 0x4c))
                          (*(int **)(unaff_EDI + 4),iVar2,"UIWidget");
        local_c = (byte *)0x0;
        (**(code **)(**(int **)(unaff_EDI + 4) + 0xcc))(*(int **)(unaff_EDI + 4),iVar2,&local_c);
        if (iVar2 != 0) {
          pbVar4 = &DAT_00c54728;
          pbVar3 = local_c;
          do {
            bVar1 = *pbVar3;
            bVar5 = bVar1 < *pbVar4;
            if (bVar1 != *pbVar4) {
LAB_0085bc01:
              iVar2 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
              goto LAB_0085bc06;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar3[1];
            bVar5 = bVar1 < pbVar4[1];
            if (bVar1 != pbVar4[1]) goto LAB_0085bc01;
            pbVar3 = pbVar3 + 2;
            pbVar4 = pbVar4 + 2;
          } while (bVar1 != 0);
          iVar2 = 0;
LAB_0085bc06:
          if (iVar2 == 0) {
            pbVar3 = local_c;
            do {
              bVar1 = *pbVar3;
              pbVar3 = pbVar3 + 1;
            } while (bVar1 != 0);
            if ((int)pbVar3 - (int)(local_c + 1) == 4) goto LAB_0085bc42;
          }
        }
        if (((*(int *)(unaff_EDI + 8) == 2) || (local_28 != 1)) &&
           (iVar2 = FUN_0085b6c0(), iVar2 == 0)) {
          FUN_0085ad50();
        }
      }
LAB_0085bc42:
      local_8 = local_8 + 1;
    } while (local_8 < local_1c);
  }
  return 1;
}

