
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e1c60(void)

{
  uint uVar1;
  int iVar3;
  uint uVar4;
  DWORD DVar5;
  DWORD DVar6;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  uint uVar2;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009442ee;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DVar5 = timeGetTime();
  *(DWORD *)(unaff_EDI + 0x5f64) =
       DVar5 + (*(int *)(unaff_EDI + 0x5f5c) - *(int *)(unaff_EDI + 0x5f60));
  DVar5 = timeGetTime();
  *(uint *)(unaff_EDI + 0x5f70) =
       (DVar5 - *(int *)(unaff_EDI + 0x5f6c)) / 1000 + *(int *)(unaff_EDI + 0x5f68);
  DVar5 = timeGetTime();
  uVar1 = *(uint *)(unaff_EDI + 0x68d8);
  uVar2 = *(uint *)(unaff_EDI + 0x68d8);
  iVar3 = *(int *)(unaff_EDI + 0x68dc);
  DVar6 = timeGetTime();
  *(DWORD *)(unaff_EDI + 0x68d8) = DVar6;
  *(undefined4 *)(unaff_EDI + 0x68dc) = 0;
  if ((DAT_00fab0d8 & 1) == 0) {
    DAT_00fab0d8 = DAT_00fab0d8 | 1;
    local_8 = 0;
    FUN_004dd4a0(uVar4);
    DAT_00fab0ec = 0;
    _DAT_00fab0f0 = 0;
    _DAT_00fab0f4 = 0;
    _atexit((_func_4879 *)&LAB_00bccdb0);
    local_8 = 0xffffffff;
  }
  FUN_004dd300(*(undefined4 *)(unaff_EDI + 0x5f70));
  FUN_004dad30(*(undefined4 *)(unaff_EDI + 0x5f70));
  FUN_004a4bb0(*(undefined4 *)(unaff_EDI + 0x6930));
  if (0.0 < *(float *)(unaff_EDI + 0x68d4)) {
    *(float *)(unaff_EDI + 0x68d4) =
         *(float *)(unaff_EDI + 0x68d4) -
         (float)((float10)CONCAT44(-(uint)(DVar5 < uVar1) - iVar3,DVar5 - uVar2) / (float10)1000.0);
  }
  ExceptionList = local_10;
  return;
}

