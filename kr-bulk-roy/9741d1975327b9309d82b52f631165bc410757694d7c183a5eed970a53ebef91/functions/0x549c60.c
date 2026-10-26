
void FUN_00549c60(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined1 uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 extraout_EDX;
  int unaff_ESI;
  float10 fVar6;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093edde;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  iVar4 = FUN_0054aa60(param_2);
  uVar2 = FUN_00548d20(uVar3);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = extraout_EDX;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  uVar3 = (uint)*(ushort *)(*(int *)(unaff_ESI + 0x50) + 0x88);
  if ((((uVar3 < 10) && (iVar5 = uVar3 * 0x210 + DAT_00f94304, *(int *)(iVar5 + 0x5c) != 0)) &&
      (iVar5 != 0)) && (iVar5 + 500 != 0)) {
    if (param_3 == -1) {
      param_3 = *(int *)(*(int *)(unaff_ESI + 0x50) + 1000);
    }
    iVar5 = FUN_0054f270(*(undefined1 *)((uint)(*(char *)(iVar5 + 0x1f6) != '\0') + iVar5 + 500),
                         param_3);
    if (iVar5 != 0) {
      *(ushort *)(unaff_ESI + 0x72) =
           *(ushort *)(unaff_ESI + 0x72) ^ (*(ushort *)(unaff_ESI + 0x72) ^ uVar2) & 0x7fff;
      *(undefined4 *)(unaff_ESI + 0xac + *(int *)(unaff_ESI + 0x108) * 0x10) = 4;
    }
    if ((iVar4 != 0) && (iVar5 != 0)) {
      fVar6 = (float10)FUN_008fedca();
      uVar1 = FUN_004bb450((float)fVar6 + 1.5707964);
      *(undefined1 *)(unaff_ESI + 0x74) = uVar1;
      *(undefined1 *)(unaff_ESI + 0x4c) = 0;
    }
  }
  ExceptionList = local_14;
  return;
}

